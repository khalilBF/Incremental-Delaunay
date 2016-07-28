/********************************************************************************
** Form generated from reading UI file 'visualiseur.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALISEUR_H
#define UI_VISUALISEUR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visualiseur
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelPos;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxPPVoisin;
    QCheckBox *checkBoxImmediats;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxTriangles;
    QCheckBox *checkBoxVoronoi;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxSwap;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *checkBoxCentres;
    QCheckBox *checkBoxSommets;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditPileSwap;

    void setupUi(QWidget *Visualiseur)
    {
        if (Visualiseur->objectName().isEmpty())
            Visualiseur->setObjectName(QString::fromUtf8("Visualiseur"));
        Visualiseur->resize(965, 596);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Visualiseur->sizePolicy().hasHeightForWidth());
        Visualiseur->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Visualiseur);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Visualiseur);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        horizontalLayout->addWidget(label);

        labelPos = new QLabel(Visualiseur);
        labelPos->setObjectName(QString::fromUtf8("labelPos"));
        labelPos->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";\n"
""));

        horizontalLayout->addWidget(labelPos);


        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        checkBoxPPVoisin = new QCheckBox(Visualiseur);
        checkBoxPPVoisin->setObjectName(QString::fromUtf8("checkBoxPPVoisin"));
        checkBoxPPVoisin->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout_3->addWidget(checkBoxPPVoisin);

        checkBoxImmediats = new QCheckBox(Visualiseur);
        checkBoxImmediats->setObjectName(QString::fromUtf8("checkBoxImmediats"));
        checkBoxImmediats->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout_3->addWidget(checkBoxImmediats);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBoxTriangles = new QCheckBox(Visualiseur);
        checkBoxTriangles->setObjectName(QString::fromUtf8("checkBoxTriangles"));
        checkBoxTriangles->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout->addWidget(checkBoxTriangles);

        checkBoxVoronoi = new QCheckBox(Visualiseur);
        checkBoxVoronoi->setObjectName(QString::fromUtf8("checkBoxVoronoi"));
        checkBoxVoronoi->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout->addWidget(checkBoxVoronoi);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBoxSwap = new QCheckBox(Visualiseur);
        checkBoxSwap->setObjectName(QString::fromUtf8("checkBoxSwap"));
        checkBoxSwap->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout_2->addWidget(checkBoxSwap);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        checkBoxCentres = new QCheckBox(Visualiseur);
        checkBoxCentres->setObjectName(QString::fromUtf8("checkBoxCentres"));
        checkBoxCentres->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";\n"
""));

        verticalLayout_5->addWidget(checkBoxCentres);

        checkBoxSommets = new QCheckBox(Visualiseur);
        checkBoxSommets->setObjectName(QString::fromUtf8("checkBoxSommets"));
        checkBoxSommets->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        verticalLayout_5->addWidget(checkBoxSommets);


        horizontalLayout_2->addLayout(verticalLayout_5);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Visualiseur);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 52 8pt \"Ubuntu\";"));

        horizontalLayout_3->addWidget(label_2);

        lineEditPileSwap = new QLineEdit(Visualiseur);
        lineEditPileSwap->setObjectName(QString::fromUtf8("lineEditPileSwap"));

        horizontalLayout_3->addWidget(lineEditPileSwap);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);

        retranslateUi(Visualiseur);

        QMetaObject::connectSlotsByName(Visualiseur);
    } // setupUi

    void retranslateUi(QWidget *Visualiseur)
    {
        Visualiseur->setWindowTitle(QApplication::translate("Visualiseur", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Visualiseur", "position:", 0, QApplication::UnicodeUTF8));
        labelPos->setText(QApplication::translate("Visualiseur", "pos", 0, QApplication::UnicodeUTF8));
        checkBoxPPVoisin->setText(QApplication::translate("Visualiseur", "Plus Proche Voisin", 0, QApplication::UnicodeUTF8));
        checkBoxImmediats->setText(QApplication::translate("Visualiseur", "Voisins Immediats", 0, QApplication::UnicodeUTF8));
        checkBoxTriangles->setText(QApplication::translate("Visualiseur", "Triangulation", 0, QApplication::UnicodeUTF8));
        checkBoxVoronoi->setText(QApplication::translate("Visualiseur", "Diagramme Voronoi", 0, QApplication::UnicodeUTF8));
        checkBoxSwap->setText(QApplication::translate("Visualiseur", "Verifier Swap", 0, QApplication::UnicodeUTF8));
        checkBoxCentres->setText(QApplication::translate("Visualiseur", "Indices Triangles", 0, QApplication::UnicodeUTF8));
        checkBoxSommets->setText(QApplication::translate("Visualiseur", "Indices sommets", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Visualiseur", "Triangles modifi\303\251s par swap", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Visualiseur: public Ui_Visualiseur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALISEUR_H
