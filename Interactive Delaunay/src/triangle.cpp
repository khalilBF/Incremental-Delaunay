#include "triangle.h"
#include <math.h>
#include <QDebug>
Triangle::Triangle()
{
    // initialisation bidon
    this->id = -1 ;
    for (int i= 0 ; i<3 ; i++ ){
        this->sommets[i%3] = -1 ;
        this->adjacents[i%3] = -1 ;
        this->centre[i%2] = -1 ;
    }
    this->centroide = QPointF(-1 , -1 ) ;
}

//évaluer si un point p existe dans le triangle "this" , sinon retourner l'indice du prochain triangle
//susceptible de le contenir
bool Triangle::inTriangle(QPointF &p, QVector<QPointF> &points , int& prochain )
{

    float det ;
    for (int i=0 ; i<3 ; i++ ){

        det = determinant(p , points[this->sommets[i]] , points[this->sommets[ (i+1)%3 ]]) ;
        if (det < 0 ){
            prochain = this->adjacents[(i+2)%3] ;
            return  false;
        }
    }

    // si l'execution arrive à cette ligne, le point doit etre dans le triangle
    prochain = this->id ;
    return true ;


}

bool Triangle::inTriangle(QPointF &p, QVector<QPointF> &points)
{
    float det ;
    for (int i=0 ; i<3 ; i++ ){

        det = determinant(p , points[this->sommets[i]] , points[this->sommets[ (i+1)%3 ]]) ;
        if (det < 0 ){
            return  false;
        }
    }

    // si l'execution arrive à cette ligne, le point doit etre dans le triangle

    return true ;


}

bool Triangle::inCircle(int &testPointID, QVector<QPointF> &points)
{

    float a, b, c, det ;

    QPointF A = points[this->sommets[0]] ;
    QPointF B = points[this->sommets[1]] ;
    QPointF C = points[this->sommets[2]] ;
    QPointF test = points[testPointID]   ;

    QPointF AD = test - A ;
    QPointF BE = test - B ;
    QPointF CF = test - C ;

    a = test.x()*test.x() + test.y()*test.y() - A.x()*A.x() - A.y()*A.y() ; // ancien g
    b = test.x()*test.x() + test.y()*test.y() - B.x()*B.x() - B.y()*B.y() ; // ancien h
    c = test.x()*test.x() + test.y()*test.y() - C.x()*C.x() - C.y()*C.y() ; // ancien i

    det = AD.x() * ( BE.y() * c - CF.y() * b ) +
            BE.x() * ( CF.y() * a - AD.y() * c ) +
            CF.x() * ( AD.y() * b - BE.y() * a ) ;
    if(det < 0 ){
        return true ;
    }else{
        return false ;
    }
}

Triangle* Triangle::adj(QVector<Triangle> &triangles, int i)
{
    //Avertissement : tester i < 0 avant de lancer adj :)
    Triangle* T = new Triangle() ;
    if ((i>=0)&&(this->adjacents[i]>=0)){
        triangles[this->adjacents[i]].copierVers(*T);
        return T ;
    }else{
        return T ;
    }


}

int Triangle::nonCommun(int& id_autre)
{

    int a = -2  ; // absence de points communs
    if (id_autre < 0 ){
        return -3 ; // -3 code d'un id_autre = -1 (chercher le voisin d'un triangle extérieur au frame)
    }

    // parcourir les adjacents de "this" et essayer de trouver id_autre
    for(int i = 0 ; i<3 ; i++ ){
        if(this->adjacents[i]==id_autre){
            a = this->sommets[i] ;
        }

    }
    return a ;


}

bool Triangle::estAdjacent(QVector<Triangle>& triangles, int& id_autre)
{

    int a = this->nonCommun(id_autre) ; // trouver un point non commun en se basant sur les adjacents de autre
    if (a < 0){
        // this ne contient aucun point opposé au triangle d'indice id_autre
        return false ;
    }else{
        int b = triangles[id_autre].nonCommun(this->id) ;
        if (b < 0){
            return false ;
        }else{
            // a>0 et b>0
            return true;
        }
    }
}

float Triangle::determinant(QPointF &A, QPointF &B, QPointF &C)
{
    QPointF a = B - A ;
    QPointF b = C - A ;
    return a.x()*b.y() - a.y()*b.x() ;
}

bool Triangle::doitSwapper(QVector<QPointF>& points , QVector<Triangle>& triangles, int& id_autre)
{

    // verifier si les triangles sont adjacents

    //----------------- vérifier si id_this figure dans la liste des adjacents de id_autre
    if(!this->estAdjacent(triangles ,  id_autre )) {
        return false;
    }else{
        if(!triangles[id_autre].estAdjacent(triangles , this->id )){
            return false;
        }else{
            // on est sûr que les triangles sont adjacents
            // il y a donc une chance de faire un swap

            // 1 - chercher le point non commun dans le triangle autre et présent dans "this"
            int a = triangles[id_autre].nonCommun(this->id) ;
            return inCircle( a , points ) ;

        }
    }
}

void Triangle::caclulerCentreCirconscrit(QVector<QPointF> &points)
{
    QPointF A = points[this->sommets[0]] ;
    QPointF B = points[this->sommets[1]] ;
    QPointF C = points[this->sommets[2]] ;

    float a , b , c , P, Q, R ;

    a = A.x()*A.x() + A.y()*A.y() ;
    b = B.x()*B.x() + B.y()*B.y() ;
    c = C.x()*C.x() + C.y()*C.y() ;

    QPointF A1 = QPointF( A.x() , a) ;
    QPointF B1 = QPointF( B.x() , b) ;
    QPointF C1 = QPointF( C.x() , c) ;
    QPointF A2 = QPointF( A.y() , a) ;
    QPointF B2 = QPointF( B.y() , b) ;
    QPointF C2 = QPointF( C.y() , c) ;

    P = determinant(A2 , B2 , C2 ) ;
    Q = -determinant(A1, B1, C1) ;
    R = determinant(A,B,C) ;

    float x  = - 0.5f * P / R ;
    float y = - 0.5f * Q / R ;

    this->centre[0] = x  ;
    this->centre[1] = y ;
    this->R = sqrt( (x-A.x())*(x-A.x()) + (y-A.y())*(y-A.y())) ;

}

void Triangle::remplaceAdjacent( int ancienAdjacent, int nouveauAdjacent)
{
    // chercher l'indice de l'adjacent pointant vers ancienAdjacent
    int a  = trouverVoisinSachantId(ancienAdjacent) ;
    this->adjacents[a] = nouveauAdjacent ;

}

void Triangle::copierVers(Triangle &triangle)
{

    triangle.id = this->id ;
    for(int i = 0 ; i< 3 ; i++ ){
        triangle.sommets[i] = this->sommets[i] ;
        triangle.adjacents[i] = this->adjacents[i] ;
        triangle.centre[i%2] = this->centre[i%2] ;
    }
    triangle.R = this->R ;

}

void Triangle::calculerCentroide(QVector<QPointF> &points)
{

    QPointF p = QPointF(0,0) ;
    for(int i = 0 ; i < 3 ; i++ ){
        p += points[this->sommets[i]] ;
    }

    p = p /  3 ;
    this->centroide = p ;
}

void Triangle::transformerEnPolygone(QPolygonF &polygone , QVector<QPointF>& points)
{
    polygone.clear();
    polygone.push_back(points[this->sommets[0]]);
    polygone.push_back(points[this->sommets[1]]);
    polygone.push_back(points[this->sommets[2]]);

}

int Triangle::trouverVoisinSachantId(int id)
{

    int a = -2 ; // pas de voisins
    for (int i=0 ; i< 3 ; i++ ){
        if (  this->adjacents[i] == id ){
            a = i ;
        }
    }
    return a ;



}

int Triangle::trouverSommetSachantValeur(int id)
{
    int a = -2 ; // pas de voisins
    for (int i=0 ; i< 3 ; i++ ){
        if (  this->sommets[i] == id ){
            a = i ;
        }
    }
    return a ;

}
