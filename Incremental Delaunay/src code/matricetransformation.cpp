#include "matricetransformation.h"
#include <math.h>
const float pi = 3.14159265359f ;
MatriceTransformation::MatriceTransformation()
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = 0 ;
        }
    }
}

void MatriceTransformation::Rotation(float angle, int axe)
{
    float a = (angle/180)*pi ;

    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = 0 ;
        }
    }

    for (int i=0 ; i < 4 ; i++){
        this->coefs[i][i] = 1 ;
    }

    switch (axe) {
    case 0: // axe des X
        this->coefs[1][2] = -sin(a) ;
        this->coefs[2][2] = this->coefs[1][1] = cos(a) ;
        this->coefs[2][1] = sin(a) ;
        break;
    case 1: //axe des y
        this->coefs[0][2] = sin(a) ;
        this->coefs[0][0] = this->coefs[2][2] = cos(a) ;
        this->coefs[2][0] = -sin(a) ;
        break;
    case 2: //axe des Z
        this->coefs[1][0] = sin(a) ;
        this->coefs[1][1] = this->coefs[0][0] = cos(a) ;
        this->coefs[0][1] = -sin(a) ;
        break ;
    default:
        break;
    }
}

void MatriceTransformation::Translation(Point3D T)
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = 0 ;
        }
    }

    for (int i=0 ; i < 4 ; i++){
        this->coefs[i][i] = 1 ;
    }
    this->coefs[0][3] = T.x() / T.T() ;
    this->coefs[1][3] = T.y() / T.T() ;
    this->coefs[2][3] = T.Z() / T.T() ;
}

void MatriceTransformation::Perspective(float d)
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = 0 ;
        }
    }
    this->coefs[0][0] = 1 ;
    this->coefs[1][2] = 1 ;
    this->coefs[2][1] = 1 ;
    this->coefs[3][1] = (float)(1/d);
}

void MatriceTransformation::Echelle(float sx, float sy, float sz)
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = 0 ;
        }
    }
    this->coefs[0][0] = sx ;
    this->coefs[1][1] = sy ;
    this->coefs[2][2] = sz ;
    this->coefs[3][3] = 1 ;
}

void MatriceTransformation::Identite()
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j <4 ; j++){
            (i==j)?this->coefs[i][j] = 1 : this->coefs[i][j] = 0 ;
        }
    }
}

void MatriceTransformation::afficher()
{
    qDebug() << "from afficher matrice ";
    for (int i=0 ; i<4 ; i++){
        qDebug()<< this->coefs[i][0] << "\t\t" << this->coefs[i][1] << "\t\t" << this->coefs[i][2]<< "\t\t" << this->coefs[i][3];
    }


}

void MatriceTransformation::copyFrom(MatriceTransformation M)
{
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j <4 ; j++){
            this->coefs[i][j] = M.coefs[i][j] ;
        }
    }

}

MatriceTransformation MatriceTransformation::operator +(const MatriceTransformation &M)
{
    MatriceTransformation N ;
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++){
            N.coefs[i][j] = M.coefs[i][j] + this->coefs[i][j] ;
        }
    }
    return N ;
}

MatriceTransformation &MatriceTransformation::operator +=(const MatriceTransformation &M)
{
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++){
            this->coefs[i][j] = M.coefs[i][j] + this->coefs[i][j] ;
        }
    }
    return *this ;
}

MatriceTransformation MatriceTransformation::operator -()
{
    MatriceTransformation M ;
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++){
            M.coefs[i][j] = -this->coefs[i][j] ;
        }
    }
    return M ;
}

MatriceTransformation MatriceTransformation::operator -(const MatriceTransformation &M)
{
    MatriceTransformation N ;
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++){
            N.coefs[i][j] =  this->coefs[i][j] - M.coefs[i][j] ;
        }
    }
    return N ;
}

MatriceTransformation &MatriceTransformation::operator -=(const MatriceTransformation &M)
{
    for (int i=0 ; i<4 ; i++ ){
        for (int j=0 ; j<4 ; j++){
            this->coefs[i][j] = this->coefs[i][j]-M.coefs[i][j] ;
        }
    }
    return *this ;
}

MatriceTransformation MatriceTransformation::operator *(const MatriceTransformation &M)
{

    MatriceTransformation N ;
    float s = 0 ;
    for (int i=0 ; i<4 ; i++){
        for(int j=0 ; j<4 ; j++){
            s = 0 ;
            for (int k=0 ; k<4 ; k++){
                s += this->coefs[i][k] * M.coefs[k][j] ;
            }
            N.coefs[i][j] = s ;
            //qDebug() << s << "(" << i << ";" << j << ")" ;
        }
    }
    //N.afficher();
    return N ;
}

Point3D MatriceTransformation::operator *(const Point3D &M)
{
    Point3D P ;
    QVector<float> v ;
    v.clear();
    float s = 0 ;
    for (int i=0 ; i<4 ; i++){
        s = this->coefs[i][0]*M.x() + this->coefs[i][1]*M.y() + this->coefs[i][2]*M.Z() + this->coefs[i][3]*M.T() ;
        v.push_back(s);
    }
    P.setX(v[0]) ;
    P.setY(v[1]) ;
    P.setZ(v[2]) ;
    P.setT(v[3]) ;
    return P ;
}

QVector<Point3D> MatriceTransformation::operator *(const QVector<Point3D> &points)
{

    QVector<Point3D> output ;
    output.clear();
    Point3D p ;

    for (int i=0 ; i<points.size() ; i++) {

        p = (*this)*(points[i]) ;
        output.push_back(p);

    }
    return output ;
}
