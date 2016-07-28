#include "point3d.h"

Point3D::Point3D()
{

}

void Point3D::setCoordinates(float x, float y, float z, float t)
{
    this->setX(x);
    this->setY(y);
    this->setZ(z);
    this->setT(t);
}

void Point3D::setZ(float z)
{
    this->z = z ;
}

void Point3D::setT(float t)
{
    this->t = t ;
}

float Point3D::T() const
{
    return this->t ;
}

QPointF Point3D::extraireXY()
{
    QPointF p ;
    p.setX(this->x());
    p.setY(this->y());
    return p ;
}

float Point3D::Z() const
{
    return this->z ;
}

void Point3D::afficher()
{
    qDebug() << QString("%1").arg(this->x(), 0, 'g', 20)  << QString("%1").arg(this->x(), 0, 'g', 20)
             << QString("%1").arg(this->Z(), 0, 'g', 20) <<  QString("%1").arg(this->T(), 0, 'g', 20)  ;
}

Point3D& Point3D::operator=(const Point3D &point)
{
    this->setX(point.x());
    this->setY(point.y());
    this->setZ(point.Z());
    this->setT(point.T());
    return *this ;
}

Point3D Point3D::operator +(const Point3D &p2)
{
    Point3D p3 ;
    p3.setCoordinates(this->x()+p2.x() , this->y()+p2.y() , this->Z()+p2.Z() , this->T() + p2.T() ) ;
    return p3 ;
}

Point3D &Point3D::operator +=(const Point3D &point)
{
    this->setX(point.x()+this->x());
    this->setY(point.y()+this->y());
    this->setZ(point.Z()+this->Z());
    this->setT(point.T()+this->T());
    return *this ;

}

float Point3D::operator *(const Point3D &p2)
{
     return this->x()*p2.x() + this->y()*p2.y() + this->Z()*p2.Z()  ;
}

 Point3D Point3D::operator *(const float &c)
 {

     Point3D p3 ;
     p3.setCoordinates(this->x()*c , this->y()*c , this->Z()*c , this->T()*c );
     return p3 ;

 }

 Point3D Point3D::operator /(const float &c)
 {

     Point3D p3 ;
     p3.setCoordinates(this->x()/c , this->y()/c , this->Z()/c , this->T()/c );
     return p3 ;

 }

 Point3D Point3D::operator -()
 {
     Point3D p ;
     p.setCoordinates(-this->x() , -this->y() , -this->Z() , this->T());
     return p ;
 }

 Point3D &Point3D::operator -=(const Point3D &point)
 {
     this->setX(this->x() - point.x());
     this->setY(this->y() - point.y());
     this->setZ(this->Z() - point.Z());
     this->setT(this->T() - point.T());
     return *this ;

 }

 Point3D Point3D::operator -(const Point3D &point)
 {

     Point3D p , R ;
     p.setCoordinates(this->x() , this->y() , this->Z() , this->T() );
     R.setCoordinates(p.x()-point.x() , p.y() - point.y() , p.Z()-point.Z() , p.T()-point.T());
     return R ;


 }

