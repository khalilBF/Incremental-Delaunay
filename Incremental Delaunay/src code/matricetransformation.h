#ifndef MATRICETRANSFORMATION_H
#define MATRICETRANSFORMATION_H

//----------------Type de base pour la création et la manipulation des matrices de transformation
//-----------------------------------------------------------------------------------------------
//----Les multiplications par un vecteur et par une matrice supposent implicitement que la ------
//----matrice "this" est l'opérande gauche.------------------------------------------------------
//-----------------------------------------------------------------------------------------------

#include <QVector>
#include <QDebug>

#include <point3d.h>

class MatriceTransformation
{
public:
    MatriceTransformation();

    float coefs[4][4] ;

    void Rotation(float angle , int axe ) ;

    void Translation(Point3D T ) ;

    void Perspective(float d );

    void Echelle(float sx, float sy, float sz) ;

    void Identite() ;

    void afficher() ;

    void copyFrom(MatriceTransformation M );
    //-----------opérations sur les matrices

    MatriceTransformation operator +(const MatriceTransformation& M); // operation this.+M
    MatriceTransformation & operator +=(const MatriceTransformation& M) ; // operation this += M

    MatriceTransformation operator -() ; //opérateur unaire
    MatriceTransformation operator -(const MatriceTransformation& M) ;
    MatriceTransformation &operator -=(const MatriceTransformation& M) ;

    MatriceTransformation operator *(const MatriceTransformation& M) ;
    Point3D operator *(const Point3D& M) ;
    QVector<Point3D> operator *(const QVector<Point3D>& points) ;


};

#endif // MATRICETRANSFORMATION_H
