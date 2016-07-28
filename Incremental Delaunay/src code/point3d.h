#ifndef POINT3D_H
#define POINT3D_H
//--------Classe définition le type Point3D avec les manipulations vectorielles possibles.
//--------Code réalisé par Khalil Ben Fadhel
//--------Département des sciences géomatiques, Iniversité Laval
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


    // pour dÃ©bogage
    void afficher() ;

    Point3D &operator= ( const Point3D& point) ;

    Point3D operator +(const Point3D &p2);
    Point3D &operator += (const Point3D& point) ;

    float operator *(const Point3D& p2 ); // produit scalaire ne tenant pas compte de la 4Ã¨me coordonnÃ©e
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
