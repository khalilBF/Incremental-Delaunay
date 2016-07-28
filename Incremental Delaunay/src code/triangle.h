#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QVector>
#include <QPoint>
#include <QPointF>
//--------Classe d�finissant la structure de triangle, avec des fonctions utiles pour la triangulation Delaunay
//--------Code r�alis� par Khalil Ben Fadhel
//--------D�partement des sciences g�omatiques, Iniversit� Laval
//--------10-04-2015
class Triangle
{
public:
    Triangle(int id);
    Triangle() ;
    int sommets[3] ;
    int adjacents[3] ;
    int id ;
    float Xc , Yc , R  ;
    QPointF centroid ;


    void afficher() ;

    //---------triangulation

    void definirCommeUniversel();
    void definirTopologie(int id , int s1, int s2 , int s3 , int ta1, int ta2 , int ta3) ;

    //---------copier vers un triangle auxiliaire
    void copierVers(Triangle& T) ;
    //---------créér �  partir d'un triangle
    void copierDe(Triangle& T) ;

    //---------trouver l'indice de l'adjacent numéro adjId
    int trouverAdjacent(int adjId) ;
    //---------trouver l'indice du sommet numéro sommetID
    int trouverSommet(int sommetId) ;

    //---------Décider si le triangle est adjacent �  T
    bool estAdjacentA(Triangle& T) ;
    //---------Si le triangle est adjacent �  T, trouver le point Non commun de 'this'
    int pointNonCommun(Triangle& T) ;

    //---------Permutation circulaire sachant l'id du prochain premier sommet
    void permut(int id ) ;

    //---------Swap si adjacents
    void swap(Triangle& T, QVector<QPoint>& voisins, QVector<QPoint>& swapsFutures) ;

    //---------Changer la valeur d'un adjacent
    void remplacerAdjacent(int adjInitial , int adjFinal) ;

    //---------Est extremal
    bool estExtremal() ;
};

#endif // TRIANGLE_H
