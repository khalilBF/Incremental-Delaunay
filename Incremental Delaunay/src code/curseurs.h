#ifndef CURSEURS_H
#define CURSEURS_H
//-------------Classe modèle pour les manipulations perspectives
//--------Code réalisé par Khalil Ben Fadhel
//--------Département des sciences géomatiques, Iniversité Laval
//--------10-04-2015
#include <QDialog>
#include <QString>

namespace Ui {
class Curseurs;
}


class Curseurs : public QDialog
{
    Q_OBJECT

public:

    explicit Curseurs(QWidget *parent = 0);
    ~Curseurs();

    void Setlabels(QString L1 , QString L2 , QString L3) ;

    void SetTitle(QString title) ;

    void SetMinMaxSlider1(int Min , int Max) ;
    void SetMinMaxSlider2(int min , int Max) ;
    void SetMinMaxSlider3(int Min, int Max) ;

    void SetValue1(int value) ;
    void SetValue2(int value) ;
    void SetValue3(int value) ;

    void SetMultiplicateur(float mul) ;

private slots:
    void on_parametreXSlider_valueChanged(int value);

    void on_parametreYSlider_valueChanged(int value);

    void on_parametreZSlider_valueChanged(int value);

private:
    Ui::Curseurs *ui;
    float multiplicateur ;
signals:

    void xValueChanged(float value) ;
    void yValueChanged(float value) ;
    void zValueChanged(float value) ;
};

#endif // CURSEURS_H
