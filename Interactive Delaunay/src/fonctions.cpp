#include <fonctions.h>

#include <QDebug>




void fonctionsCommunes::Frame(QGraphicsScene *scene, QVector<Triangle> &triangles, QVector<QPointF> &points)
{
    QPointF p1 = QPointF(240 , 0 ) ;
    QPointF p2 = QPointF(0 , 440 ) ;
    QPointF p3 = QPointF(-240 ,0 ) ;

    //---intiialiser le triangle à dessiner
    QPolygonF P ;
    P.push_back(p1);
    P.push_back(p2);
    P.push_back(p3);

    //---initialiser l'ensemble des points
    points.clear();
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);

    //---initialiser le réseau de triangles
    triangles.clear();
    Triangle T ;
    T.id  = 0 ;
    T.sommets[0] = 0 ;
    T.sommets[1] = 1 ;
    T.sommets[2] = 2 ;
    T.adjacents[0] = -1 ;
    T.adjacents[1] = -1 ;
    T.adjacents[2] = -1 ;
    T.caclulerCentreCirconscrit(points);



    triangles.push_back(T);

    //---initialiser la scène dans le viewer
    scene->clear();
    scene->addPolygon(P , QPen(Qt::red , 1  , Qt::DashLine )) ;


}


int fonctionsCommunes::Walk(QPointF &p, QVector<QPointF> &points, QVector<Triangle> &triangles, QVector<int> &trace)
{
    bool B = false ;
    trace.clear();

    int prochainTriangle = 0  ;
    trace.push_back(prochainTriangle);
    B = triangles[0].inTriangle(p , points , prochainTriangle ) ;
    if(prochainTriangle>=0){
        trace.push_back(prochainTriangle);
    }
    //qDebug( )  << B << prochainTriangle ;
    //*
    while( (!B) && (prochainTriangle >= 0 )  ){

        B = triangles[prochainTriangle].inTriangle(p , points , prochainTriangle ) ;
        trace.push_back(prochainTriangle);

    }

    return prochainTriangle ;
//*/


}


void fonctionsCommunes::Insert(QPointF &p, QVector<QPointF> &points, QVector<Triangle> &triangles , QVector<QPoint>& pile )
{

    // vérifier si le point p existe déjà dans l'ensemble des points
    for (int i = 0 ; i< points.size() ; i++  ){

        if ( p == points[i] ){
            // si le point existe dans l'ensemble de points, inutile de continuer
            return ;
        }

    }

    // si on a passé l'ancien return, c'est que p est nouveau et il faut l'insérer dans la topologie

    int idWalk = fonctionsCommunes::Walk( p , points, triangles ) ;


    //*
    // on mémorise les anciennes tailles des vecteurs
    int N = points.size() ;
    int M = triangles.size() ;
    points.push_back(p); // le point p est maintenant d'indice N

    Triangle T , T_aux;
    // stocker le triangle d'indice idWalk dans T
    triangles[idWalk].copierVers(T);

    //*
    // modifier triangles[idWalk]
    triangles[idWalk].sommets[0] = N ;
    triangles[idWalk].adjacents[1] = M ;
    triangles[idWalk].adjacents[2] = M+1;
    triangles[idWalk].caclulerCentreCirconscrit(points);
    triangles[idWalk].calculerCentroide(points);

    // Préparer et insérer le premier nouveau triangle
    T_aux.id = M ; // indice du triangle, il est égal à M car le dernier triangle jusqu'à présent est d'indice M-1
    T_aux.sommets[0] = N ;
    T_aux.sommets[1] = T.sommets[2] ;
    T_aux.sommets[2] = T.sommets[0] ;
    T_aux.adjacents[0] = T.adjacents[1] ;
    T_aux.adjacents[1] = M+1 ;
    T_aux.adjacents[2] = idWalk ;
    T_aux.caclulerCentreCirconscrit(points);
    T_aux.calculerCentroide(points);

    triangles.push_back(T_aux);

    // Préparer et insérer le second nouveau triangle
    T_aux.id = M+1 ;
    T_aux.sommets[0] = N ;
    T_aux.sommets[1] = T.sommets[0] ;
    T_aux.sommets[2] = T.sommets[1] ;
    T_aux.adjacents[0] = T.adjacents[2] ;
    T_aux.adjacents[1] = idWalk ;
    T_aux.adjacents[2] = M ;
    T_aux.caclulerCentreCirconscrit(points);
    T_aux.calculerCentroide(points);

    triangles.push_back(T_aux);

    // Stocker les changements
    //pile.clear();

    if (triangles[M+1].adjacents[0] >= 0){
        pile.push_back(QPoint(M+1 , triangles[M+1].adjacents[0]));
    }
    if (triangles[M].adjacents[0] >= 0){
        pile.push_back(QPoint(M , triangles[M].adjacents[0]));
    }
    if (T.adjacents[0] >= 0){
        pile.push_back(QPoint(idWalk , T.adjacents[0]));
    }

    //Mise à jour des anciens voisins
    Triangle Adjacent ;
    int aa  ;
    if (T.adjacents[1] >= 0){
        triangles[T.adjacents[1]].copierVers(Adjacent);
        aa = Adjacent.trouverVoisinSachantId(idWalk) ;
        triangles[T.adjacents[1]].adjacents[aa] = M ;
    }

    if (T.adjacents[2] >= 0){
        triangles[T.adjacents[2]].copierVers(Adjacent);
        aa = Adjacent.trouverVoisinSachantId(idWalk) ;
        triangles[T.adjacents[2]].adjacents[aa] = M+1 ;
    }

}


int fonctionsCommunes::Walk(QPointF &p, QVector<QPointF> &points, QVector<Triangle> &triangles)
{
    bool B = false ;
    int prochainTriangle = 0  ;
    B = triangles[0].inTriangle(p , points , prochainTriangle ) ;

    while( (!B) && (prochainTriangle >= 0 )  ){
        B = triangles[prochainTriangle].inTriangle(p , points , prochainTriangle ) ;
    }

    return prochainTriangle ;

}


void fonctionsCommunes::Swap(int idA, int idB, QVector<QPointF>& points ,
                             QVector<Triangle>& triangles , QVector<QPoint> &pile)
{
    if((idA < 0 )||(idB < 0) ){
        return ;
    }
    // vérifier si les deux triangles sont encore des voisins

    if (idA > triangles.size() || idB > triangles.size() ) {
        return ;
    }

    Triangle A , B ;
    triangles[idA].copierVers(A);
    triangles[idB].copierVers(B);
    qDebug() << "from swap " << A.id << B.id ;
    // Le nouveau point est le point non commun appartenant à T1
    int NP = A.nonCommun(B.id) ;
    // Le point PNC est le point Non commun appartenant à T2
    int PNC = B.nonCommun(A.id) ;

    //Trouver la position de NP et PNC dans le tableau de sommets
    int a = A.trouverSommetSachantValeur(NP) ;
    int b = B.trouverSommetSachantValeur(PNC) ;

    // compléter selon le tableau du cours et avec permutations circulaires
    // trois configurations de A sont possibles : NP PC1 PC2 T2 T3 T4
    //--------------------------------------------PC2 NP PC1 T4 T2 T3
    //--------------------------------------------PC1 PC2 NP T3 T4 T2
    // Dans ce qui suit , nous allons simplifier le problème en une seule configuration NP PC1 PC2 T2 T3 T4

    Triangle A2 ;
    int k = 0 ;
    for (int i = a ; i < 3 ; i++ ){
        A2.sommets[k] = A.sommets[i%3];
        A2.adjacents[k] = A.adjacents[i%3] ;
        k += 1 ;
    }
    A2.id = A.id ;

    // Pareil pour B , Les configurations sont  : PNC PC2 PC1 T1 T5 T6
    //--------------------------------------------PC1 PNC PC2 T6 T1 T5
    //--------------------------------------------PC2 PC1 PNC T5 T6 T1

    k = 0 ;
    Triangle B2 ;
    for(int i = b ; i < 3 ; i++ ){

        B2.sommets[k] = B.sommets[i%3] ;
        B2.adjacents[k]= B.adjacents[i%3] ;
        k += 1 ;

    }
    B2.id = B.id ;

    //----------------------Étape de Swap (selon le cours )
    // SA = triangle A swappé
    // SB = triangle B swappé
    //-------------------------
    // initialement A2: NP PC1 PC2 T2 T3 T4
    //              B2: PNC PC2 PC1 T1 T5 T6
    // Swap         SA: NP PNC PC2 T6 T3 T2
    //              SB: NP PC1 PNC T5 T1 T4

    Triangle SA , SB ;

    SA.id = A2.id ;

    SA.sommets[0] = A2.sommets[0] ;
    SA.sommets[1] = B2.sommets[0] ;
    SA.sommets[2] = A2.sommets[2] ;

    SA.adjacents[0] = B2.adjacents[2] ;
    SA.adjacents[1] = A2.adjacents[1] ;
    SA.adjacents[2] = A2.adjacents[0] ;

    //-----passage par variable
    SA.caclulerCentreCirconscrit(points);
    SA.calculerCentroide(points);
    SA.copierVers(triangles[idA]);

    //---de même pour SB
    SB.id = B2.id ;

    SB.sommets[0] = A2.sommets[0] ;
    SB.sommets[1] = A2.sommets[1] ;
    SB.sommets[2] = B2.sommets[0] ;

    SB.adjacents[0] = B2.adjacents[1] ;
    SB.adjacents[1] = B2.adjacents[0] ;
    SB.adjacents[2] = A2.adjacents[2] ;

    SB.caclulerCentreCirconscrit(points);
    SB.calculerCentroide(points);

    SB.copierVers(triangles[idB]);

    //-------------Fin Swap

    // mise à jour des triangles adjacents T4 et T6
    Triangle T4 , T6 ;
    int aa ;
    //-----------cas T4
    if ( SB.adjacents[2] >= 0){
        triangles[SB.adjacents[2]].copierVers(T4);
        qDebug() << "SB id " << SB.id <<  "t4 id " << T4.id ;
        //----chercher T1
        aa = T4.trouverVoisinSachantId(idA) ;
        qDebug() << "aa" << aa << "correspond à idA";
        triangles[SB.adjacents[2]].adjacents[aa] = idB ;
    }
    //-----------cas de T6
    if ( SA.adjacents[0] >= 0){
        triangles[SA.adjacents[0]].copierVers(T6);
        //----chercher T2
        aa = T6.trouverVoisinSachantId(idB) ;
        triangles[SA.adjacents[0]].adjacents[aa] = idA ;
    }

    //Mise à jour de la pile
    //insersion des couples idA,t3 ; idA,t6 ; idB, t4 ; idB, t5


    if (SA.adjacents[0] >= 0 ){
        pile.push_back(QPoint(idA , SA.adjacents[0] ));
    }
    if (SA.adjacents[1] >= 0 ){
        pile.push_back(QPoint(idA , SA.adjacents[1] ));
    }
    if (SB.adjacents[0] >= 0 ){
        pile.push_back(QPoint(idB , SA.adjacents[1] ));
    }
    if (SB.adjacents[2] >= 0 ){
        pile.push_back(QPoint(idB , SA.adjacents[1] ));
    }


}


void fonctionsCommunes::Optim(QVector<Triangle> &triangles, QVector<QPointF> &points, QVector<QPoint> &pile)
{


    while (!pile.isEmpty()){
        QPoint f = pile[pile.size()-1] ;
        int x = f.x() ;
        int y = f.y() ;
        qDebug() << "pile " << x << y ;
        pile.pop_back();
        int idNonCommun = triangles[y].nonCommun(x) ; //chercher l'indice du point de f.y non commun avec f.x
        qDebug() << idNonCommun << ": idNonCommun";
        if ( (idNonCommun>0) && ((triangles[x].trouverVoisinSachantId(y)) >= 0 ) && ((triangles[y].trouverVoisinSachantId(x))>=0) )   {
            qDebug( ) << "swaping " << f.x() << f.y() ;

            if (triangles[x].inCircle( idNonCommun , points )){
                fonctionsCommunes::Swap(f.x() , f.y(), points ,triangles , pile ) ;
            }

        }

    }


}


void fonctionsCommunes::Voronoi(QVector<QLineF> &V, QVector<Triangle> &triangles)
{

    for (int i = 0 ; i < triangles.size() ; i ++ ){
        V.push_back(QLineF(triangles[i].centre[0] , triangles[i].centre[1] , triangles[triangles[i].adjacents[0]].centre[0] , triangles[triangles[i].adjacents[0]].centre[1])  );
        V.push_back(QLineF(triangles[i].centre[0] , triangles[i].centre[1] , triangles[triangles[i].adjacents[1]].centre[0] , triangles[triangles[i].adjacents[1]].centre[1])  );
        V.push_back(QLineF(triangles[i].centre[0] , triangles[i].centre[1] , triangles[triangles[i].adjacents[2]].centre[0] , triangles[triangles[i].adjacents[2]].centre[1])  );
    }

}


void fonctionsCommunes::PlusProcheVoisin(QPointF &p, QVector<Triangle> &triangles, QVector<QPointF> &points , QPointF& procheVoisin )
{
    //--appeler cette fonction uniquement lorsque le curseur est surement dans le triangle universel

    int id  = fonctionsCommunes::Walk( p , points , triangles ) ;

    //selectionner les points entourant le triangle d'indice id

    float dm = 100;
    float d ;
    int k = 0 ;
    int a = 0 ;
    QPointF ref ;
    for (int i = 0 ; i<3 ; i++ ){

        for (int j = 0 ; j<3 ; j ++ ){

            if(triangles[id].adjacents[i]>=0){
                a = triangles[triangles[id].adjacents[i]].sommets[j] ;
                ref = points[a] - p ;
                d = ref.x()*ref.x() + ref.y()*ref.y() ;
                if (d < dm){
                    dm = d ;
                    k = a ;
                }
            }



        }

    }

    procheVoisin = points[k] ;

}


void fonctionsCommunes::VoisinsConnectes(int id, QVector<QPointF> &points, QVector<Triangle> &triangles, QVector<int> conectes)
{


    int a = fonctionsCommunes::Walk( points[id] , points , triangles) ;
    if (a<0){
        return ;
    }else{
        int b = triangles[a].adjacents[0] ;
        if (b >= 0 ){
            conectes.push_back(triangles[triangles[a].adjacents[0]].nonCommun(a)) ;
        }
        b = triangles[a].adjacents[1] ;
        if (b >= 0 ){
            conectes.push_back(triangles[triangles[a].adjacents[1]].nonCommun(a)) ;
        }
        b = triangles[a].adjacents[2] ;
                if (b >= 0 ){
                    conectes.push_back(triangles[triangles[a].adjacents[2]].nonCommun(a)) ;
        }
    }



}
