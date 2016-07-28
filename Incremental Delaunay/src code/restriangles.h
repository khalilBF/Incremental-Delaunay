#ifndef RESTRIANGLES_H
#define RESTRIANGLES_H
//--------Classe responsable de la triangulation de delaunay
//----------------------------------------------------------
//---------------Le code est celui du lab 2 avec quelques am�liorations
//----------------------------------------------------------
//--------Code r�alis� par Khalil Ben Fadhel
//--------D�partement des sciences g�omatiques, Iniversit� Laval
//--------10-04-2015
#include <triangle.h>
#include <QVector>

#include <QPointF>
#include <QPoint>

class ResTriangles
{
public:

    ResTriangles();
    int pointsCoincidants ;
    QVector<Triangle> triangles ;
    QVector<QPointF> points ;
    QVector<QPoint> pileSwap ;
    //-------------retourne -2 si le point est dans le triangle , et l'indice du prochain triangle �  examiner sinon
    int pointDansTriangle(QPointF point , int idTriangle) ;
    bool dansFrame(QPointF point);

    void insert(QPointF& p) ;
    int walk(QPointF& p);
    void swap(QPoint couple) ;

    void optim() ;


    bool doiventSwaper(int idTr1 , int idTr2) ;
    bool pointDansCercle(int idPoint, int idTriangle) ;
    void cercleCirconscrit();


private:
    float aire(QPointF& A , QPointF& B , QPointF& C) ; // Aire algébrique du triangle ABC orienté directe
    void cercleCirconscrit(int idTriangle) ;
    Triangle extraireTriangle(int idTriangle) ;

};

#endif // RESTRIANGLES_H
