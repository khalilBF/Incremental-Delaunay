#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <QPointF>
#include <QPolygonF>

#include <QVector>

#include <QGraphicsScene>
#include <triangle.h>
namespace fonctionsCommunes {

    // initialiser le triangle universel + traçage dans la scene
    void Frame(QGraphicsScene* scene , QVector<Triangle>& triangles , QVector<QPointF>& points ) ;

    // Fonction Walk , chercher itérativement l'indice du triangle contenant le point P
    int Walk(QPointF& p , QVector<QPointF>& points , QVector<Triangle>& triangles , QVector<int>& trace) ;
    int Walk(QPointF &p, QVector<QPointF> &points, QVector<Triangle> &triangles) ;
    // Insérer un triangle dans l'ensemble des triangles
    void Insert(QPointF& p , QVector<QPointF>& points , QVector<Triangle>& triangles,  QVector<QPoint>& pile) ;

    // Swap entre diagonales
    void Swap(int idA , int idB , QVector<QPointF>& points , QVector<Triangle> &triangles, QVector<QPoint>& pile ) ;

    // Fonction Optim
    // doit etre appelée avec une pile non vide et après insert
    void Optim(QVector<Triangle>& triangles , QVector<QPointF>& points , QVector<QPoint>& pile ) ;

    //Calcul du diagramme de voronoi
    void Voronoi(QVector<QLineF>& V  , QVector<Triangle>& triangles ) ;


    // Calcul du plus proche voisin
    void PlusProcheVoisin(QPointF& p , QVector<Triangle>& triangles , QVector<QPointF>& points , QPointF& procheVoisin);

    void VoisinsConnectes(int id , QVector<QPointF>& points , QVector<Triangle>& triangle , QVector<int> conectes ) ;

}


#endif // FONCTIONS_H
