#ifndef POINT3D_H
#define POINT3D_H
//--------Classe d�finition le type Point3D avec les manipulations vectorielles possibles.
//--------Code r�alis� par Khalil Ben Fadhel
//--------D�partement des sciences g�omatiques, Iniversit� Laval
//--------10-04-2015

#include <QPointF>
#include <QDebug>

class Point3D : public QPointF
{
public:
    Point3D();
    void setCoordinates(float x , float y , float z , float t) ;
    void setZ(float z) ;
    void setT(float t) ;
    float Z() const ;
    float T() const ;

    QPointF extraireXY() ;


    // pour débogage
    void afficher() ;

    Point3D &operator= ( const Point3D& point) ;

    Point3D operator +(const Point3D &p2);
    Point3D &operator += (const Point3D& point) ;

    float operator *(const Point3D& p2 ); // produit scalaire ne tenant pas compte de la 4ème coordonnée
    Point3D operator *(const float& c) ;
    Point3D operator /(const float& c) ;

    Point3D operator -();
    Point3D &operator -= (const Point3D& point) ;
    Point3D operator -(const Point3D& point) ;

private:
    float z ;
    float t ;


};


#endif // POINT3D_H
