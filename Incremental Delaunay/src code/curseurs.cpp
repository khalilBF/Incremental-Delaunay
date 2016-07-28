//-------------Classe modèle pour les manipulations perspectives


#include "curseurs.h"
#include "ui_curseurs.h"

Curseurs::Curseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Curseurs)
{
    ui->setupUi(this);
}

Curseurs::~Curseurs()
{
    delete ui;
}

void Curseurs::Setlabels(QString L1, QString L2, QString L3)
{

    ui->xLabel->setText(L1);
    ui->yLabel->setText(L2);
    ui->zLabel->setText(L3);


}

void Curseurs::SetTitle(QString title)
{
    this->setWindowTitle( title );

}

void Curseurs::SetMinMaxSlider1(int Min, int Max)
{
    ui->parametreXSlider->setMinimum(Min);
    ui->parametreXSlider->setMaximum(Max);

}

void Curseurs::SetMinMaxSlider2(int min, int Max)
{

    ui->parametreYSlider->setMinimum(min);
    ui->parametreYSlider->setMaximum(Max);

}

void Curseurs::SetMinMaxSlider3(int Min, int Max)
{
    ui->parametreZSlider->setMinimum(Min);
    ui->parametreZSlider->setMaximum(Max);
}

void Curseurs::SetValue1(int value)
{
    ui->parametreXSlider->setValue(value);

}

void Curseurs::SetValue2(int value)
{
    ui->parametreYSlider->setValue(value);
}

void Curseurs::SetValue3(int value)
{
    ui->parametreZSlider->setValue(value);
}

void Curseurs::SetMultiplicateur(float mul)
{
    this->multiplicateur = mul ;
}

void Curseurs::on_parametreXSlider_valueChanged(int value)
{
    ui->xLcd->display((float)value * multiplicateur);
    emit xValueChanged((float)value * multiplicateur ) ;

}

void Curseurs::on_parametreYSlider_valueChanged(int value)
{
    ui->yLcd->display((float)value * multiplicateur);
    emit yValueChanged((float)value * multiplicateur ) ;
}



void Curseurs::on_parametreZSlider_valueChanged(int value)
{
    ui->zLcd->display((float)value * multiplicateur);
    emit zValueChanged((float)value * multiplicateur ) ;
}
