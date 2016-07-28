#ifndef VISUALISEUR_H
#define VISUALISEUR_H

#include <QWidget>
#include <QGraphicsView>

#include <triangle.h>


#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsPolygonItem>
#include <fonctions.h>

#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

namespace Ui {
class Visualiseur;
}

class Visualiseur : public QGraphicsView
{
    Q_OBJECT

public:
    explicit Visualiseur(QWidget *parent = 0);
    ~Visualiseur();

private slots:
    void on_checkBoxPPVoisin_clicked(bool checked);

    void on_checkBoxImmediats_clicked(bool checked);

    void on_checkBoxTriangles_clicked(bool checked);

    void on_checkBoxVoronoi_clicked(bool checked);

    void on_checkBoxSwap_clicked(bool checked);

    void on_checkBoxCentres_clicked(bool checked);

    void on_checkBoxSommets_clicked(bool checked);

private:

    bool afficherTriangulation , afficherVoronoi, afficherCercle , afficherWalk ;
    bool afficherVoisinsConnectes , afficherPlusProcheVoisin ;
    bool afficherCentres , afficherSommets ;

    Ui::Visualiseur *ui;


    Triangle triangleUniversel ;
    QGraphicsScene* scene ;

    QVector<Triangle> triangles ;
    QVector<QPointF> points ;

    //---structures pour les options graphiques
    QPointF curseur ;
    QVector<QPoint> pile ;
    QVector<int> trajectoireWalk ;



    void mouseMoveEvent(QMouseEvent *event) ;
    void mouseReleaseEvent(QMouseEvent *event) ;

    void miseAJourGraphique() ;

    void afficherTopologie() ;

    QVector<QLineF> Voronoi ;
    QPointF procheVoisin ;


};

#endif // VISUALISEUR_H
