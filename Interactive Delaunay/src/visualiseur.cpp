#include "visualiseur.h"
#include "ui_visualiseur.h"

#include <QDebug>

Visualiseur::Visualiseur(QWidget *parent) :
    QGraphicsView(parent),
    ui(new Ui::Visualiseur)
{
    ui->setupUi(this);

    scene = new QGraphicsScene() ;
    scene->clear();

    this->setScene(scene);
    this->scale(1 , -1 );

    setMouseTracking(true);

    fonctionsCommunes::Frame(scene , triangles , points ) ;
    triangles[0].copierVers(triangleUniversel);

    pile.clear();
    trajectoireWalk.clear();

    //initialisation de l'affichage
    afficherCentres = true ;
    afficherCercle = true ;
    afficherPlusProcheVoisin = false ;
    afficherSommets = true ;
    afficherTriangulation = true ;
    afficherVoisinsConnectes = false ;
    afficherVoronoi = false ;
    afficherWalk = false ;

    ui->checkBoxCentres->setChecked(afficherCentres);
    ui->checkBoxSwap->setChecked(afficherCercle);
    ui->checkBoxPPVoisin->setChecked(afficherPlusProcheVoisin);
    ui->checkBoxSommets->setChecked(afficherSommets);
    ui->checkBoxTriangles->setChecked(afficherTriangulation);
    ui->checkBoxImmediats->setChecked(afficherVoisinsConnectes);
    ui->checkBoxVoronoi->setChecked(afficherVoronoi);
    //ui->checkBoxWalk->setChecked(afficherWalk);

}

Visualiseur::~Visualiseur()
{
    delete ui;
}

void Visualiseur::mouseMoveEvent(QMouseEvent *event)
{
    this->setEnabled(false);
    curseur = this->mapToScene(event->x() , event->y() ) ;
    ui->labelPos->setText( QString::number(curseur.x()) + ";" + QString::number( curseur.y() ) );

    int a = -1 ;
    trajectoireWalk.clear();
    trajectoireWalk.push_back(0);
    if (triangleUniversel.inTriangle(curseur , points )){
        a = fonctionsCommunes::Walk(curseur , points , triangles , trajectoireWalk ) ;
        miseAJourGraphique();
    }

    this->setEnabled(true);
}

void Visualiseur::mouseReleaseEvent(QMouseEvent *event)
{

    curseur = this->mapToScene(event->x() , event->y() ) ;
    //points.push_back(curseur);
    this->setDisabled(true);
    if (triangleUniversel.inTriangle(curseur, points)){
        pile.clear();
        fonctionsCommunes::Insert(curseur , points , triangles , pile );

        scene->addEllipse( curseur.x()-1 , curseur.y() +1 ,  2 ,2  ) ;

        fonctionsCommunes::Optim(triangles , points , pile ) ;
        afficherTopologie();
    }





    miseAJourGraphique();
    this->setDisabled(false);
}

void Visualiseur::miseAJourGraphique()
{
    scene->clear();



    QPolygonF Polygone ;
    if(afficherTriangulation){
        for (int i=0 ; i < triangles.size() ; i++ ){
            triangles[i].transformerEnPolygone(Polygone , points);
            scene->addPolygon(Polygone , QPen(Qt::blue , 1 )) ;
        }
    }

    if(afficherCentres){
        for (int i=0 ; i < triangles.size() ; i++ ){
            QGraphicsTextItem* texte = new QGraphicsTextItem();
            texte->scale(1 , -1 );
            texte->setPlainText(QString::number(i));
            texte->setPos(triangles[i].centroide.x()-1 , triangles[i].centroide.y() - 1);
            scene->addItem(texte);
        }
    }

    if(afficherSommets){
        for (int i=0 ; i < points.size() ; i++ ){
            QGraphicsTextItem* texte = new QGraphicsTextItem();
            texte->scale(1 , -1 );
            texte->setPlainText(QString::number(i));
            texte->setDefaultTextColor(Qt::red);
            texte->setPos(points[i].x()-1 , points[i].y() - 1);
            scene->addItem(texte);
        }
    }

    if (afficherCercle){
        int id_triangle = fonctionsCommunes::Walk(curseur , points , triangles ) ;
        scene->addEllipse(triangles[id_triangle].centre[0] -triangles[id_triangle].R ,
                          triangles[id_triangle].centre[1] -triangles[id_triangle].R ,
                          2*triangles[id_triangle].R , 2*triangles[id_triangle].R , QPen(Qt::gray)) ;

    }

    if (afficherWalk && (!trajectoireWalk.isEmpty()) && (triangleUniversel.inTriangle(curseur , points ))){
        for (int i=0 ; i< trajectoireWalk.size() ; i ++ ){
            QPolygonF P ;
            triangles[trajectoireWalk[i]].transformerEnPolygone(P , points );

            scene->addPolygon(P , QPen(Qt::black) , QBrush(QColor(0, 0,200, 30))) ;

        }
    }

    if (afficherVoronoi && (triangles.size()> 1 )){
        Voronoi.clear();
        fonctionsCommunes::Voronoi( Voronoi , triangles ) ;
        for (int i = 0 ; i < Voronoi.size() ; i ++ ){
            scene->addLine(Voronoi[i] , QPen(Qt::red)) ;
        }
    }

    if (afficherPlusProcheVoisin){
        fonctionsCommunes::PlusProcheVoisin( curseur , triangles , points , procheVoisin  ) ;
        scene->addEllipse(procheVoisin.x() - 4 , procheVoisin.y() - 4 , 8 , 8 , QPen(Qt::red , 6)) ;
    }



}

void Visualiseur::afficherTopologie()
{
    for (int i= 0 ; i < triangles.size() ; i++){
        qDebug() << triangles[i].sommets[0]
                 << triangles[i].sommets[1]
                 << triangles[i].sommets[2]
                 << triangles[i].adjacents[0]
                 << triangles[i].adjacents[1]
                 << triangles[i].adjacents[2];
    }

}

void Visualiseur::on_checkBoxPPVoisin_clicked(bool checked)
{
    afficherPlusProcheVoisin = checked ;
}

void Visualiseur::on_checkBoxImmediats_clicked(bool checked)
{
    afficherVoisinsConnectes = checked ;
}

void Visualiseur::on_checkBoxTriangles_clicked(bool checked)
{
    afficherTriangulation = checked ;
}

void Visualiseur::on_checkBoxVoronoi_clicked(bool checked)
{
    afficherVoronoi = checked ;
}

void Visualiseur::on_checkBoxSwap_clicked(bool checked)
{
    afficherCercle = checked ;
}

void Visualiseur::on_checkBoxCentres_clicked(bool checked)
{
    afficherCentres = checked ;
}

void Visualiseur::on_checkBoxSommets_clicked(bool checked)
{
    afficherSommets = checked ;
}
