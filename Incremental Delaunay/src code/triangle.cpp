#include "triangle.h"
#include <QDebug>

Triangle::Triangle(int id)
{
    this->id = id ;
    for (int i=0 ; i <3 ; i++ ){

        this->sommets[i] = -1 ;
        this->adjacents[i] = -1 ;

    }
    this->centroid = QPointF(0,0) ;
    this->Xc = 0 ;
    this->Yc = 0 ;
    this->R = 0 ;

}

Triangle::Triangle()
{
    this->definirTopologie(-1,-1,-1,-1,-1,-1,-1);
}

void Triangle::afficher()
{
    qDebug()  << "from triangle: "<< this->id
              << "sommets:" << this->sommets[0] << this->sommets[1]<< this->sommets[2]
              << "adjacents:" << this->adjacents[0] << this->adjacents[1]<< this->adjacents[2]
              << "cercle:" << this->Xc << this->Yc << this->R
              << "centroide" << this->centroid ;
}

void Triangle::definirCommeUniversel()
{
    this->definirTopologie(0 , 0 ,1,2,-1,-1,-1);
}

void Triangle::definirTopologie(int id, int s1, int s2, int s3, int ta1, int ta2, int ta3)
{
    this->id = id ;
    this->sommets[0] = s1 ;
    this->sommets[1] = s2 ;
    this->sommets[2] = s3 ;
    this->adjacents[0] = ta1 ;
    this->adjacents[1] = ta2 ;
    this->adjacents[2] = ta3 ;
    this->Xc = 0 ;
    this->Yc = 0 ;
    this->R = 0 ;
    this->centroid = QPointF() ;
}

void Triangle::copierVers(Triangle &T)
{

    T.id = this->id ;

    T.sommets[0] = this->sommets[0] ;
    T.sommets[1] = this->sommets[1] ;
    T.sommets[2] = this->sommets[2] ;

    T.adjacents[0] = this->adjacents[0] ;
    T.adjacents[1] = this->adjacents[1] ;
    T.adjacents[2] = this->adjacents[2] ;

    T.centroid = this->centroid ;
    T.Xc = this->Xc ;
    T.Yc = this->Yc ;
    T.R = this->R ;

}

void Triangle::copierDe(Triangle &T)
{
    T.copierVers(*this);

}

int Triangle::trouverAdjacent(int adjId)
{

    for (int i= 0 ; i < 3 ; i++ ){

        if( this->adjacents[i] == adjId ){
            return i ;
        }
    }
    return -2 ; // code de non adjacents adjId trouvés

}

int Triangle::trouverSommet(int sommetId)
{
    for (int i= 0 ; i < 3 ; i++ ){

        if( this->sommets[i] == sommetId ){
            return i ;
        }
    }
    return -2 ; // code de non adjacents adjId trouvés
}

bool Triangle::estAdjacentA(Triangle &T)
{
    bool b ;
    //chercher l'indice de T dans les adjacents de 'this'
    int a = this->trouverAdjacent(T.id) ;
    (a < 0) ? ( b = false) : (b = true) ;
    return b ;
}

int Triangle::pointNonCommun(Triangle &T)
{
    int a ; //indice de non adjacence: le sommet non commun est d'indice -2
    bool b = this->estAdjacentA(T) ;
    (b) ? a = this->sommets[this->trouverAdjacent(T.id)] : a = -2 ;
    return a ;


}

void Triangle::permut(int id)
{
    Triangle T(0) ;
    this->copierVers(T);
    int k = 0 ;
    //qDebug() << "permut " << id ;
    for (int i=id ; i< id + 3 ; i++){

        this->sommets[k] = T.sommets[i%3] ;
        this->adjacents[k] = T.adjacents[(i)%3] ;
        k += 1 ;
    }

}

void Triangle::swap(Triangle &T , QVector<QPoint> &voisins , QVector<QPoint> &swapsFutures)
{

    if (this->estAdjacentA(T)) {
        //permutations circulaires pour rendre les points non communs au début des structures

        //qDebug() << "triangle.swap: triangle initiaux " ;
        //this->afficher();
        //T.afficher();

        this->permut(this->trouverAdjacent(T.id));
        T.permut(T.trouverAdjacent(this->id));
        //qDebug() << "triangle.swap: permutation ";
        //this->afficher() ;
        //T.afficher() ;

        Triangle Aux(0) ;
        this->copierVers(Aux);

        this->sommets[0] = Aux.sommets[2] ;
        this->sommets[1] = Aux.sommets[0] ;
        this->sommets[2] = T.sommets[0] ;
        this->adjacents[2] = this->adjacents[1] ;
        this->adjacents[1] = T.adjacents[2] ;

        T.sommets[0] = Aux.sommets[1] ;
        T.sommets[1] = this->sommets[2] ;
        T.sommets[2] = this->sommets[1] ;
        T.adjacents[2] = T.adjacents[1] ;
        T.adjacents[1] = Aux.adjacents[2] ;

        //qDebug() << "triangle.swap: triangle swapes" ;
        //this->afficher() ;
        //T.afficher();
        voisins.clear();
        //T4 est maintenant voisin de T2 , eliminer T1 de la liste des voisins
        voisins.push_back(QPoint(T.id , T.adjacents[1]));
        //T6 est maintenant voisin de T1 , eliminer T2 de la liste des voisins
        voisins.push_back(QPoint(this->id, this->adjacents[1]));

        //*
        //liste de swaps prochains
        if (this->adjacents[1]>=0) swapsFutures.push_back( QPoint(this->id , this->adjacents[1]));
        if (this->adjacents[2]>=0) swapsFutures.push_back( QPoint(this->id , this->adjacents[2]));
        if (T.adjacents[1] >= 0) swapsFutures.push_back( QPoint(T.id , T.adjacents[1]));
        if (T.adjacents[2] >= 0) swapsFutures.push_back( QPoint(T.id , T.adjacents[2]));
        //*/
        //qDebug() << "from triangle.swap nouveaux voisins" << voisins;

    }



}

void Triangle::remplacerAdjacent(int adjInitial, int adjFinal)
{

    int id = this->trouverAdjacent(adjInitial) ;
    if (id >= 0) {
        this->adjacents[id] = adjFinal ;
    }

}

bool Triangle::estExtremal()
{

    bool b = false ;
    for( int i =0 ; i < 3 ; i++ ){
        if ((this->sommets[i] == 0 )||(this->sommets[i] == 1 )||(this->sommets[i] == 2)){
            b = true ;
            break ;
        }
    }
    return b ;



}
