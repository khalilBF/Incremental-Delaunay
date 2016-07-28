#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <curseurs.h>
#include <matricetransformation.h>
#include <point3d.h>
#include <qvector.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    Point3D centroide ;

    QVector<Point3D> points ;

    Curseurs* rotationWid ;
    Curseurs* translationWid ;
    Curseurs* echelleWid ;

    float ax , ay , az , tx , ty , tz , sx , sy , sz , d ;

    MatriceTransformation M , P , T , Tplus , S , Rz , Rx , Ry , Tmoins ;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_rotB_clicked();

    void on_transB_clicked();

    void on_scaleB_clicked();

    void quitterApplication() ;

    void rotX(float angle) ;
    void rotY(float angle) ;
    void rotZ(float angle) ;

    void translX(float dx) ;
    void translY(float dy) ;
    void translZ(float dz) ;

    void scaleX(float s) ;
    void scaleY(float s) ;
    void scaleZ(float s) ;

    void setCentroide(Point3D p);
    void setPerspectiveMatrix(float d) ;

    void projeter();

private:
    Ui::MainWindow *ui;
signals:

    void dessiner() ;
};

#endif // MAINWINDOW_H
