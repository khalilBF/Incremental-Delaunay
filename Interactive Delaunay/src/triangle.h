#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPointF>
#include <QVector>
//#include <reseautriangles.h>
//#include <fonctions.h>

#include <QPolygonF>

class Triangle
{
public:
    Triangle();

    int id ;
    int sommets[3] ;
    int adjacents[3] ;
    float centre[2] ;
    float R ;
    QPointF centroide ;

    // Vérifier si un point d'indice idPt se trouve dans le triangle "this"
    // sinon , remplace le contenu de la variable prochain par l'indice du porchain triangle à examiner
    bool inTriangle(QPointF& p , QVector<QPointF>& points , int& prochain ) ;
    bool inTriangle(QPointF &p, QVector<QPointF> &points) ;

    //vérifier si le point p se trouve dans le cercle circonscrit au triangle "this"
    bool inCircle(int& testPointID , QVector<QPointF>& points) ;

    // retourne la topologie de l'adjacent numéro i
    // si i est négatif (cas du voisin du triangle universel, la fonction ne retournera un triangle bidon)
    Triangle *adj(QVector<Triangle>& triangles, int i);

    // Retourner l'indice du point du triangle "this" , non présent dans les sommets de tcd[id_autre]
    int nonCommun(int &id_autre) ;

    // Décider si le triangle "this" est adjacent à T
    bool estAdjacent(QVector<Triangle> &triangles, int &id_autre);

    // calcule l'aire algébrique du triangle ABC
    float determinant(QPointF& A, QPointF& B , QPointF& C) ;

    // Décider si le triangle "this" doit swapper avec le triangle d'indice id_autre
    bool doitSwapper(QVector<QPointF> &points, QVector<Triangle> &triangles, int &id_autre) ;

    // caclculer le centre circonscrit du triangle "this"
    void caclulerCentreCirconscrit(QVector<QPointF>& points ) ;

    // Chercher dans les adjacent de "this" l'indice ancienAdjacent et le remplacer par nouveauAdjacent
    void remplaceAdjacent(int ancienAdjacent , int nouveauAdjacent) ;

    // copier vers un autre triangle
    void copierVers(Triangle& triangle) ;

    // calculer le centroid. Le centroide servira pour afficher les indices des triangles au niveau de l'interface graphique
    void calculerCentroide(QVector<QPointF>& points);

    // convertir en polygone dessinable
    void transformerEnPolygone(QPolygonF& polygone, QVector<QPointF> &points);

    int trouverVoisinSachantId( int id ) ;
    int trouverSommetSachantValeur(int id ) ;
};

#endif // TRIANGLE_H
