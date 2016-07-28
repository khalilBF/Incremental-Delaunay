//--------Interface principale
//--------Code réalisé par Khalil Ben Fadhel
//--------Département des sciences géomatiques, Iniversité Laval
//--------10-04-2015


#include "mainwindow.h"
#include "ui_mainwindow.h"

const float pi = 3.14159265359f ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rotationWid = new Curseurs(this) ;
    translationWid = new Curseurs(this) ;
    echelleWid = new Curseurs(this) ;


    //---------------PrÃ©paration des curseurs dans l'interface graphique

    rotationWid->SetTitle("Controlleurs de rotation");
    translationWid->SetTitle("Controlleurs de translation");
    echelleWid->SetTitle("controlleurs d'echelle ");

    rotationWid->SetMultiplicateur(1);
    rotationWid->SetMinMaxSlider1(-180 , 180);
    rotationWid->SetMinMaxSlider2(-180 , 180);
    rotationWid->SetMinMaxSlider3(-180 , 180);
    rotationWid->SetValue1(0);
    rotationWid->SetValue2(0);
    rotationWid->SetValue3(0);
    rotationWid->Setlabels("Angle autour de l'axe X" , "Angle autour de l'axe Y" , "Angle autour de l'axe Z" );

    translationWid->SetMultiplicateur(1);
    translationWid->SetMinMaxSlider1(-200 , 200);
    translationWid->SetMinMaxSlider2(-180 , 200);
    translationWid->SetMinMaxSlider3(-200 , 200);
    translationWid->SetValue1(0);
    translationWid->SetValue2(0);
    translationWid->SetValue3(0);
    translationWid->Setlabels("translation selon X" , "translation selon Y" , "translation selon Z" );

    echelleWid->SetMultiplicateur(0.01f);
    echelleWid->SetMinMaxSlider1(-1000 , 1000);
    echelleWid->SetMinMaxSlider2(-1000 , 1000);
    echelleWid->SetMinMaxSlider3(-1000 , 1000);
    echelleWid->SetValue1(100);
    echelleWid->SetValue2(100);
    echelleWid->SetValue3(100);
    echelleWid->Setlabels("echelle selon X" , "echelle selon Y" , "echelle selon Z" );

    //----------Initialiser les matrices
    ax =ay =az = tx = ty = tz = 0 ;
    sx = sy =sz = 1 ;
    S.Identite();
    M = Tmoins = Tplus = T = Rx = Ry = Rz = P = S ;
    M.afficher();



    //----------Connexions
    connect(ui->openB , SIGNAL(clicked()) , ui->vue , SLOT(chargerPoints3D()) ) ;
    connect(ui->quitterB , SIGNAL(clicked()) , this , SLOT(quitterApplication()) ) ;

    connect(this->rotationWid , SIGNAL(xValueChanged(float)) , this , SLOT(rotX(float)) ) ;
    connect(this->rotationWid , SIGNAL(yValueChanged(float)) , this , SLOT(rotY(float)) ) ;
    connect(this->rotationWid , SIGNAL(zValueChanged(float)) , this , SLOT(rotZ(float)) ) ;

    connect(this->translationWid , SIGNAL(xValueChanged(float)) , this , SLOT(translX(float)) ) ;
    connect(this->translationWid , SIGNAL(yValueChanged(float)) , this , SLOT(translY(float)) ) ;
    connect(this->translationWid , SIGNAL(zValueChanged(float)) , this , SLOT(translZ(float)) ) ;

    connect(this->echelleWid , SIGNAL(xValueChanged(float)) , this , SLOT(scaleX(float)) ) ;
    connect(this->echelleWid , SIGNAL(yValueChanged(float)) , this , SLOT(scaleY(float)) ) ;
    connect(this->echelleWid , SIGNAL(zValueChanged(float)) , this , SLOT(scaleZ(float)) ) ;

    connect(this , SIGNAL(dessiner()) , ui->vue , SLOT(reTracer()) ) ;

    connect(ui->vue , SIGNAL(centre(Point3D)) ,  this , SLOT(setCentroide(Point3D)) ) ;

    connect(ui->vue , SIGNAL(distancePerspective(float)) , this , SLOT(setPerspectiveMatrix(float)) ) ;

    connect(ui->vue , SIGNAL(visualisationInitiale()) , this , SLOT(projeter()) ) ;

    connect(ui->recadrerB, SIGNAL(clicked()) , ui->vue , SLOT(recadrer()) ) ;

    QMainWindow::showMaximized() ;


    points.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rotB_clicked()
{
    rotationWid->show();
}

void MainWindow::on_transB_clicked()
{
    translationWid->show();
}

void MainWindow::on_scaleB_clicked()
{
    echelleWid->show();
}

void MainWindow::quitterApplication()
{
    QCoreApplication::exit() ;
}

void MainWindow::rotX(float angle)
{
    ax = angle ;
    Rx.Rotation(ax , 0 );
    projeter();

}

void MainWindow::rotY(float angle)
{
    ay = angle ;
    Ry.Rotation(ay , 1);
    projeter();
}

void MainWindow::rotZ(float angle)
{
    az = angle ;
    Rz.Rotation(az , 2);
    projeter();
}

void MainWindow::translX(float dx)
{
    tx = dx ;
    Point3D t ;
    t.setCoordinates(tx , ty , tz , 1);
    T.Translation(t);
    projeter();
}

void MainWindow::translY(float dy)
{
    ty = dy ;
    Point3D t ;
    t.setCoordinates(tx , ty , tz , 1);
    T.Translation(t);
    projeter();
}

void MainWindow::translZ(float dz)
{
    tz = dz ;
    Point3D t ;
    t.setCoordinates(tx , ty , tz , 1);
    T.Translation(t);
    projeter();

}

void MainWindow::scaleX(float s)
{
    sx = s ;
    S.Echelle(sx , sy , sz);
    projeter();

}

void MainWindow::scaleY(float s)
{
    sy = s ;
    S.Echelle(sx ,sy ,sz );
    projeter();

}

void MainWindow::scaleZ(float s)
{
    sz = s ;
    S.Echelle(sx, sy , sz);
    projeter();

}

void MainWindow::setCentroide(Point3D p)
{
    centroide = p ;
    Tplus.Translation(p);
    Tmoins.Translation(-p);

}

void MainWindow::setPerspectiveMatrix(float d)
{
    this->d = d ;
    P.Perspective(this->d);

}

void MainWindow::projeter()
{
    M = P * T * Tplus * Rx * Ry * Rz * S * Tmoins ;
    points.clear();
    if (ui->vue->pointsOriginaux.size()>3){

        points = M * ui->vue->pointsOriginaux ;

        ui->vue->reseau.points.clear();
        for (int i=0 ; i < points.size() ; i ++ ){

            points[i] = points[i] / points[i].T() ;

            ui->vue->reseau.points.push_back(points[i]);
        }
        emit dessiner();
    }

}
