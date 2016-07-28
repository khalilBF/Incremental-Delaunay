#include "restriangles.h"
#include <QDebug>
#include <math.h>

ResTriangles::ResTriangles()
{
    this->triangles.clear();
    this->points.clear();
    this->pileSwap.clear();
    pointsCoincidants = 0 ;
}

int ResTriangles::pointDansTriangle(QPointF point, int idTriangle)
{
    int a = -3 ; //code de non traitement effectué

    QPointF A, B , C ;
    Triangle t(0) ;
    if (idTriangle >= 0 ){
        this->triangles[idTriangle].copierVers(t);

        A = this->points[t.sommets[0]] ;
        B = this->points[t.sommets[1]] ;
        C = this->points[t.sommets[2]] ;

        (this->aire(point, A, B) < 0 ) ? (a = t.adjacents[2])
                                       : ((this->aire(point , B , C )< 0 ) ? (a = t.adjacents[0])
                                                                           : ((this->aire(point, C, A) < 0 ) ? (a = t.adjacents[1])
                                                                                                             : a = -2 )) ; // -2 code du points intérieur au triangle
        /*
        if((this->aire(point, A, B)==0)||(this->aire(point , B , C )== 0 )||(this->aire(point, C, A) == 0 )){
            a = -4 ;
            //qDebug() << "coincident";
            this->pointsCoincidants +=1 ;
        }*/

    }
    //qDebug() << "from pointDansTriangle , triangle pos = " << a ;
    //qDebug() << this->aire(point, A, B) << this->aire(point, B, C ) << this->aire(point, C, A);
    return a ;
}

bool ResTriangles::dansFrame(QPointF point)
{
    bool b =false ;
    if (this->points.size()>=3 ){
        QPointF A = this->points[0] ;
        QPointF B = this->points[1] ;
        QPointF C = this->points[2] ;
        ((this->aire(point, A, B) >= 0 )
                &&(this->aire(point , B , C )>= 0 )
                &&(this->aire(point, C, A) >= 0 )) ?
                    (b = true) : (b = false);

    }
    return b ;

}

void ResTriangles::insert(QPointF &p)
{

    int pos = this->walk(p) ;
    //qDebug() << pos << "position ";

    if(pos >=0 ){
        this->pileSwap.clear();
        //-insert
        int N_points = this->points.size() ;
        int N_triang = this->triangles.size() ;

        //------------insersion du triangle N+1
        this->points.push_back(p);
        Triangle T(N_points) ;
        T.definirTopologie(N_triang , N_points ,
                           this->triangles[pos].sommets[2] ,
                           this->triangles[pos].sommets[0] ,
                           this->triangles[pos].adjacents[1] ,
                           N_triang+1 , pos );
        this->triangles.push_back(T);
        //------------insersion du triangle N+2
        T.definirTopologie(N_triang+1 ,
                           N_points ,
                           this->triangles[pos].sommets[0] ,
                           this->triangles[pos].sommets[1] ,
                           this->triangles[pos].adjacents[2],
                           pos ,  N_triang );
        this->triangles.push_back(T);

        //-------mise à jour du triangle de base
        this->triangles[pos].sommets[0] = N_points ;
        this->triangles[pos].adjacents[1] = N_triang ;
        this->triangles[pos].adjacents[2] = N_triang+1 ;

        //-------mise à jour des anciens voisins
        if (this->triangles[pos].adjacents[0] >= 0){
            this->pileSwap.push_back(QPoint(pos, this->triangles[pos].adjacents[0]));
        }

        int ancienVoisin = this->triangles[N_triang].adjacents[0] ;
        if (ancienVoisin >= 0 ){
            this->triangles[ancienVoisin].remplacerAdjacent(pos , N_triang);
            this->pileSwap.push_back(QPoint(N_triang , ancienVoisin));
        }
        ancienVoisin = this->triangles[N_triang+1].adjacents[0] ;
        if (ancienVoisin >= 0 ){
            this->triangles[ancienVoisin].remplacerAdjacent(pos, N_triang+1);
            this->pileSwap.push_back(QPoint(N_triang+1 , ancienVoisin));
        }
        //*
        //-------mise à jour des centres circonscrits
        this->cercleCirconscrit(pos);
        this->cercleCirconscrit(N_triang);
        this->cercleCirconscrit(N_triang+1);
        //*/


    }
    //qDebug() << pos;



}

int ResTriangles::walk(QPointF &p)
{
    int pos = -1 ;
    //qDebug() << "from walk " << this->dansFrame(p ) ;
    if( this->dansFrame(p) ){

        int a =-2;

        for (int i=0 ; i < this->triangles.size() ; i++ ){

            a = this->pointDansTriangle(p , i) ;

            if(a == -2 ){
                //----- (-2) code du point contenu dans le triangle
                pos = i ;
                break ;
            }

        }
    }
    //qDebug() << "from walk pos = " << pos ;
    return pos ;
}

void ResTriangles::swap(QPoint couple)
{
    //------swap à partir d'un couple d'entiers
    int x , y ;
    x = couple.x() ;
    y = couple.y() ;
    QVector<QPoint> voisins ;
    voisins.clear();
    this->triangles[x].swap(this->triangles[y] , voisins , this->pileSwap) ;
    //qDebug() << "from reseau.swap/ voisins Swap: " << voisins.size()   << voisins  ;

    //------mise à jour des nouveaux voisins
    QPoint p ;
    QPoint q ;
    //qDebug() << "ancien voisin";
    for(int i=0 ; i<2 ; i++ ){
        p = voisins[i] ;
        q = voisins[(i+1)%2] ;
        if (p.y() >= 0){
            //this->triangles[p.y()].afficher();
            this->triangles[p.y()].remplacerAdjacent(q.x() , p.x() );
            //this->triangles[p.y()].afficher();
        }
    }

}

void ResTriangles::optim()
{
    while (this->pileSwap.size()>0) {
        QPoint coupleSwap = this->pileSwap[this->pileSwap.size()-1];
        this->pileSwap.pop_back();
        if (this->doiventSwaper(coupleSwap.x(), coupleSwap.y())){
            this->swap(coupleSwap);
            this->cercleCirconscrit();
        }
    }

    this->pileSwap.clear();

}

bool ResTriangles::doiventSwaper(int idTr1, int idTr2)
{
    Triangle T1 = this->extraireTriangle(idTr1);
    Triangle T2 = this->extraireTriangle(idTr2);
    bool b = T1.estAdjacentA(T2);
    //qDebug() << "from doivent swaper " << idTr1 << idTr2 << "adjacents ?" << b ;
    if(b){
        int idPt = T2.pointNonCommun(T1) ; //ne peut pas être -2
        //qDebug() << "from doivent swaper/ point non commun " << idPt ;
        b = this->pointDansCercle(idPt , idTr1) ;
    }
    return b ;
}

bool ResTriangles::pointDansCercle(int idPoint, int idTriangle)
{
    float a, b, c, det ;

    QPointF A = this->points[this->triangles[idTriangle].sommets[0]] ;
    QPointF B = this->points[this->triangles[idTriangle].sommets[1]] ;
    QPointF C = this->points[this->triangles[idTriangle].sommets[2]] ;
    QPointF test = this->points[idPoint] ;

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

void ResTriangles::cercleCirconscrit()
{
    for (int i=0 ; i < this->triangles.size() ; i++ ){
        this->cercleCirconscrit(i) ;
    }
}

float ResTriangles::aire(QPointF &A, QPointF &B, QPointF &C)
{
    QPointF a = B - A ;
    QPointF b = C - A ;
    return a.x()*b.y() - a.y()*b.x() ;
}

void ResTriangles::cercleCirconscrit(int idTriangle)
{
    Triangle T(idTriangle) ;
    T = this->extraireTriangle(idTriangle) ;
    QPointF A = this->points[T.sommets[0]]  ;
    QPointF B = this->points[T.sommets[1]] ;
    QPointF C = this->points[T.sommets[2]] ;

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

    P = this->aire(A2 , B2 , C2 ) ;
    Q = -this->aire(A1, B1, C1) ;
    R = this->aire(A,B,C) ;

    float x  = - 0.5f * P / R ;
    float y = - 0.5f * Q / R ;

    //------------------mise à jour du centre circonscrit et du centroide
    this->triangles[idTriangle].Xc = x ;
    this->triangles[idTriangle].Yc = y ;
    this->triangles[idTriangle].R = sqrt( (x-A.x())*(x-A.x()) + (y-A.y())*(y-A.y())) ;

    this->triangles[idTriangle].centroid = (A+B+C)/3 ;

}

Triangle ResTriangles::extraireTriangle(int idTriangle)
{

    return this->triangles[idTriangle];

}

