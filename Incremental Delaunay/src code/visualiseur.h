#ifndef VISUALISEUR_H
#define VISUALISEUR_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <point3d.h>
#include <QVector>

#include <point3d.h>
#include <restriangles.h>

#include <matricetransformation.h>
//-------------Classe modèle pour la visualisation
//--------Code réalisé par Khalil Ben Fadhel
//--------Département des sciences géomatiques, Iniversité Laval
//--------10-04-2015
namespace Ui {
class Visualiseur;
}

class Visualiseur : public QGraphicsView
{
    Q_OBJECT

public:

    QGraphicsScene* scene ;
    explicit Visualiseur(QWidget *parent = 0);
    ~Visualiseur();

    ResTriangles reseau ;
    QVector<Point3D> pointsOriginaux ;
private:



    Ui::Visualiseur *ui;

    //---------Limites du nuage de points
    float Xmin , Xmax , Ymin , Ymax ;
    //---------Limites de la vue
    float topleftx, toplefty , height , width ;

    QVector<QPointF> points2D ;

    //------Fonction permettant d'effectuer la triangulation une fois les points chargés
    void triangulationDelaunay() ;

    //------recadred la vue pour contenir les points 2D projetés
    void preparerVue() ;

    //-----initialisation
    void initialiserVue() ;

    //-----calculer le point central du nuage de points
    void calculerCentroide() ;

//--------Slots écoutant des signaux venant de la fenetre principale ou des curseurs
private slots:

    //----------Fonction a effectuer lors du clic sur bouton ouvrir
    void chargerPoints3D() ;


    void reTracer() ;


    void calculerLimites() ;

    //--------ajouter le triangle universel
    void creerPointsTriangulation() ;

    void recadrer();

signals:

    void centre(Point3D c);

    void distancePerspective(float d) ;

    void visualisationInitiale();
};

#endif // VISUALISEUR_H
