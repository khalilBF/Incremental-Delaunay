#include "visualiseur.h"
#include "ui_visualiseur.h"

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

#include <QRect>

Visualiseur::Visualiseur(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Visualiseur)
{
    ui->setupUi(this);
    scene = new QGraphicsScene() ;
    this->setScene(scene);
    this->scale( 0.3 , -0.3 );

    pointsOriginaux.clear();

    this->reseau.pileSwap.clear();
    this->reseau.points.clear();
    this->reseau.triangles.clear();

}

Visualiseur::~Visualiseur()
{
    delete ui;
}

void Visualiseur::chargerPoints3D()
{

    QString nomFichier = QFileDialog::getOpenFileName(this,
                                            tr("open file"),
                                            "./",
                                            "text file (*.txt)");
    QFile* fichier = new QFile(nomFichier);
    if (fichier->open(QIODevice::ReadOnly)){

        QTextStream textstream(fichier);
        QStringList stringList ;
        int i = 0;

        while (!textstream.atEnd()) {
            i++ ;
            QString line = textstream.readLine();
            stringList = line.split("\t");

            if(i!=1){

                Point3D point ;
                point.setCoordinates(stringList.at(1).toFloat() ,
                                     stringList.at(2).toFloat() ,
                                     stringList.at(3).toFloat() ,
                                     1 );
                pointsOriginaux.push_back(point);
                point.afficher();

            }else{
                pointsOriginaux.clear();
            }

        }
        fichier->close();
        calculerLimites();
        creerPointsTriangulation();
        calculerCentroide();

        triangulationDelaunay(); // calcul effectué une seule fois
        initialiserVue();
        reTracer();
    }
    else{
        QMessageBox::information(0,"error",fichier->errorString());
    }

}

void Visualiseur::reTracer()
{

    if (reseau.points.size() > 3){


        qDebug() << "redessiner" << reseau.points.size();
        scene->clear();
        for (int i=3 ; i< reseau.points.size() ; i++){
            scene->addEllipse(reseau.points[i].x()-4 , reseau.points[i].y()-4 , 8 , 8 , QPen(Qt::black) , QBrush(Qt::black)) ;
        }

        QPolygonF P ;
        Triangle T ;
        QPointF p, q ;
        T.definirTopologie(0,0,0,0,0,0,0);
        for (int i=0 ; i< reseau.triangles.size() ; i++ ){
            P.clear();
            T.copierDe(reseau.triangles[i]);

            P.push_back(reseau.points[T.sommets[0]]);
            P.push_back(reseau.points[T.sommets[1]]);
            P.push_back(reseau.points[T.sommets[2]]);

            if (T.estExtremal()){

                for (int a = 0 ; a < 3 ; a ++  ){

                    for(int k=0 ; k<3 ; k++ ){
                        if((T.sommets[a] == k)){
                            if((T.sommets[(a+1)%3] != (k+1)%3 )&&(T.sommets[(a+2)%3]== (k+2)%3 )
                                    &&(T.sommets[(a+1)%3] != (k+2)%3 )&&(T.sommets[(a+2)%3]== (k+1)%3 )){
                                p = reseau.points[T.sommets[1]];
                                q = reseau.points[T.sommets[2]];
                                scene->addLine(p.x() , p.y() , q.x() , q.y() , QPen(Qt::blue)) ;
                            }
                        }
                    }
                }
            }else {
                scene->addPolygon(P, QPen(Qt::blue)) ;

            }
        }
    }

}

void Visualiseur::calculerLimites()
{
    if(!pointsOriginaux.isEmpty()){
        Xmax = Xmin = pointsOriginaux[0].x() ;
        Ymin = Ymax = pointsOriginaux[0].y() ;
        for (int i=0 ; i< pointsOriginaux.size() ; i++){

            (Xmax < pointsOriginaux[i].x() ) ? Xmax = pointsOriginaux[i].x() : 1 ;
            (Xmin > pointsOriginaux[i].x() ) ? Xmin = pointsOriginaux[i].x() : 1 ;
            (Ymax < pointsOriginaux[i].y() ) ? Ymax = pointsOriginaux[i].y() : 1 ;
            (Ymin > pointsOriginaux[i].y() ) ? Ymin = pointsOriginaux[i].y() : 1 ;

        }
    }


}

void Visualiseur::creerPointsTriangulation()
{
    Point3D P ;
    float epsilon = 1 ;

    P.setCoordinates(1.5*Xmax - 0.5*Xmin + 2* epsilon , Ymin-epsilon , 1 , 1 );
    pointsOriginaux.push_front(P);
    P.setCoordinates(1.5*Xmin - 0.5*Xmax - 2* epsilon  , Ymin - epsilon , 1 , 1);
    pointsOriginaux.push_front(P);
    P.setCoordinates(0.5 * (Xmin + Xmax )  , 2*Ymax - Ymin + 2*epsilon  , 1 , 1);
    pointsOriginaux.push_front(P);

}

void Visualiseur::recadrer()
{
    reTracer();
    preparerVue();
}

void Visualiseur::triangulationDelaunay()
{

    if (pointsOriginaux.size() > 3 ){

        //----------Initialisation
        this->reseau.pileSwap.clear();
        this->reseau.points.clear();
        this->reseau.triangles.clear();
        //----------initialiser la topologie du triangle universel
        Triangle universel = Triangle(0) ;
        universel.definirTopologie(0,0,1,2,-1,-1,-1);
        this->reseau.triangles.push_back(universel);

        //----------initialiser les points correspondants au triangle universel
        Point3D P ;
        P = pointsOriginaux[0] ;
        this->reseau.points.push_back(QPointF(P.x() , P.y()));
        P = pointsOriginaux[1] ;
        this->reseau.points.push_back(QPointF(P.x() , P.y()));
        P = pointsOriginaux[2] ;
        this->reseau.points.push_back(QPointF(P.x() , P.y()));

        //qDebug() << reseau.points ;

        //----------Calculer le premier cercle circonscrit
        this->reseau.cercleCirconscrit();

        //----------Insersion point à point
        QPointF p ;
        //qDebug() << pointsOriginaux.size();
        reseau.pointsCoincidants = 0 ;
        for (int i = 3 ; i< pointsOriginaux.size() ; i++ ){
            p = QPointF(pointsOriginaux[i].x() , pointsOriginaux[i].y()) ;
            //qDebug() << p ;
            //qDebug() << reseau.dansFrame(p);
            if (reseau.dansFrame(p)){
                reseau.insert(p);
                this->reseau.cercleCirconscrit();
                this->reseau.optim();

            }
        }
    }
}

void Visualiseur::preparerVue()
{
    if (reseau.points.size()>=3){

        float mx , my , Mx , My ;

        mx = Mx = reseau.points[3].x() ;
        my = My = reseau.points[3].y() ;

        for (int i=3 ; i< reseau.points.size() ; i++){
            (Mx < reseau.points[i].x() ) ? Mx = reseau.points[i].x() : 1 ;
            (mx > reseau.points[i].x() ) ? mx = reseau.points[i].x() : 1 ;
            (My < reseau.points[i].y() ) ? My = reseau.points[i].y() : 1 ;
            (my > reseau.points[i].y() ) ? my = reseau.points[i].y() : 1 ;
        }

        topleftx = mx ;
        toplefty = my ;
        width = My - my ;
        height = Mx - mx ;
        setSceneRect(topleftx , toplefty , width , height );
    }

}

void Visualiseur::initialiserVue()
{
    if (pointsOriginaux.size()>=3){

        MatriceTransformation Persp ;
        Persp.Perspective( ((Xmax + Ymax)/2) );

        reseau.points.clear();

        float mx , my , Mx , My ;
        Point3D P ;
        P = Persp * pointsOriginaux[3] ;
        mx = Mx = P.x() / P.T() ;
        my = My = P.y() / P.T() ;

        for (int i=0 ; i< pointsOriginaux.size() ; i++){

            P = Persp * pointsOriginaux[i] ;

            if (P.T()!=0){
                P /= P.T() ;
            }

            QPointF Q ;
            Q.setX(P.x());
            Q.setY(P.y());

            reseau.points.push_back( Q );

            if (i >= 3){
                (Mx < reseau.points[i].x() ) ? Mx = reseau.points[i].x() : 1 ;
                (mx > reseau.points[i].x() ) ? mx = reseau.points[i].x() : 1 ;
                (My < reseau.points[i].y() ) ? My = reseau.points[i].y() : 1 ;
                (my > reseau.points[i].y() ) ? my = reseau.points[i].y() : 1 ;
            }


        }

        topleftx = mx ;
        toplefty = my ;
        width = My - my ;
        height = Mx - mx ;
        setSceneRect(topleftx , toplefty , width , height );
    }
}

void Visualiseur::calculerCentroide()
{

    Point3D p ;
    p.setCoordinates(0,0,0,0);
    if(pointsOriginaux.size() > 3 ){
        int j = 0 ;
        for (int i=3 ; i< pointsOriginaux.size() ; i++){
            p = p + pointsOriginaux[i] ;
            j = j +1 ;

        }
        p = p / j ;
        emit centre(p);
    }
    float d = (Xmin + Xmin)/2 ;
    emit distancePerspective(d);
}
