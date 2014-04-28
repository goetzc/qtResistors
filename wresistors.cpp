#include "wresistors.h"
#include "ui_wresistors.h"
//=========================================================================
#include <QString>
#include <math.h>
#include <QPixmap>
#include <QIcon>
//=========================================================================
wResistors::wResistors(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::wResistors)
{
    ui->setupUi(this);

// Add items in all comboboxes
    ui->comboBox_1->addItem(createIcon("#000000"),"Black");
    ui->comboBox_1->addItem(createIcon("#AA5500"),"Brown");
    ui->comboBox_1->addItem(createIcon("#FF0000"),"Red");
    ui->comboBox_1->addItem(createIcon("#FFAA00"),"Orange");
    ui->comboBox_1->addItem(createIcon("#FFFF00"),"Yellow");
    ui->comboBox_1->addItem(createIcon("#00FF00"),"Green");
    ui->comboBox_1->addItem(createIcon("#0000FF"),"Blue");
    ui->comboBox_1->addItem(createIcon("#AA55FF"),"Violet");
    ui->comboBox_1->addItem(createIcon("#808080"),"Grey");
    ui->comboBox_1->addItem(createIcon("#FFFFFF"),"White");

    ui->comboBox_2->addItem(createIcon("#000000"),"Black");
    ui->comboBox_2->addItem(createIcon("#AA5500"),"Brown");
    ui->comboBox_2->addItem(createIcon("#FF0000"),"Red");
    ui->comboBox_2->addItem(createIcon("#FFAA00"),"Orange");
    ui->comboBox_2->addItem(createIcon("#FFFF00"),"Yellow");
    ui->comboBox_2->addItem(createIcon("#00FF00"),"Green");
    ui->comboBox_2->addItem(createIcon("#0000FF"),"Blue");
    ui->comboBox_2->addItem(createIcon("#AA55FF"),"Violet");
    ui->comboBox_2->addItem(createIcon("#808080"),"Grey");
    ui->comboBox_2->addItem(createIcon("#FFFFFF"),"White");

    ui->comboBox_3->addItem(createIcon("#000000"),"Black");
    ui->comboBox_3->addItem(createIcon("#AA5500"),"Brown");
    ui->comboBox_3->addItem(createIcon("#FF0000"),"Red");
    ui->comboBox_3->addItem(createIcon("#FFAA00"),"Orange");
    ui->comboBox_3->addItem(createIcon("#FFFF00"),"Yellow");
    ui->comboBox_3->addItem(createIcon("#00FF00"),"Green");
    ui->comboBox_3->addItem(createIcon("#0000FF"),"Blue");
    ui->comboBox_3->addItem(createIcon("#AA55FF"),"Violet");
    ui->comboBox_3->addItem(createIcon("#808080"),"Grey");
    ui->comboBox_3->addItem(createIcon("#FFFFFF"),"White");
    ui->comboBox_3->addItem(createIcon("#FFFF80"),"Gold");
    ui->comboBox_3->addItem(createIcon("#DBDBDB"),"Silver");

    ui->comboBox_4->addItem(createIcon("#AA5500"),"Brown");
    ui->comboBox_4->addItem(createIcon("#FF0000"),"Red");
    ui->comboBox_4->addItem(createIcon("#00FF00"),"Green");
    ui->comboBox_4->addItem(createIcon("#0000FF"),"Blue");
    ui->comboBox_4->addItem(createIcon("#AA55FF"),"Violet");
    ui->comboBox_4->addItem(createIcon("#808080"),"Grey");
    ui->comboBox_4->addItem(createIcon("#FFFF80"),"Gold");
    ui->comboBox_4->addItem(createIcon("#DBDBDB"),"Silver");
    ui->comboBox_4->addItem("No Color");


// Connect signals and slots
    QObject::connect(ui->comboBox_1, SIGNAL(currentIndexChanged(int)),this, SLOT(preracunaj()));
    QObject::connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)),this, SLOT(preracunaj()));
    QObject::connect(ui->comboBox_3, SIGNAL(currentIndexChanged(int)),this, SLOT(preracunaj()));
    QObject::connect(ui->comboBox_4, SIGNAL(currentIndexChanged(int)),this, SLOT(preracunaj()));

}

//=========================================================================
wResistors::~wResistors()
{
    delete ui;
}

//=========================================================================
void wResistors::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

//=========================================================================
void wResistors::preracunaj()
{    
// First color represent tens and color ones, so use string to create double digit number.
    QString str1, str2;

    str1.setNum((int) ui->comboBox_1->currentIndex());
    str2.setNum((int) ui->comboBox_2->currentIndex());
    str1 +=str2;

    float rez = str1.toInt(); // rez je dvocifren broj - rez is double digit no.


    str2 = " ";
    switch ((int) ui->comboBox_3->currentIndex())
    {
    case 0:    rez *= pow(10, ui->comboBox_3->currentIndex());
        break;
    case 1:    rez *= pow(10, ui->comboBox_3->currentIndex());
        break;
    case 2:    rez *= pow(10, ui->comboBox_3->currentIndex());
        break;
    case 3:    str2 = "K";
        break;
    case 4:    rez *= pow(10, 1);str2 = "K";
        break;
    case 5:    rez *= pow(10, 2);str2 = "K";
        break;
    case 6:    str2 = "M";
        break;
    case 7:    rez *= pow(10, 1);str2 = "M";
        break;
    case 8:    rez *= pow(10, 2);str2 = "M";
        break;
    case 9:    rez *= pow(10, 3);str2 = "M";
        break;
    case 10:    rez *= pow(10, -1);
        break;
    case 11:    rez *= pow(10, -2);
        break;

    default:
        ui->label_ohm->setText("ERROR");
        break;
    }

 ui->label_ohm->setText(str1.setNum(rez) + str2 + " Ohm");

// Displays tolerance
    switch (ui->comboBox_4->currentIndex())
    {
    case 0:
        ui->label_tol->setText("+/-1% (F)");
        break;
    case 1:
        ui->label_tol->setText("+/-2% (G)");
        break;
    case 2:
        ui->label_tol->setText("+/-0.5% (D)");
        break;
    case 3:
        ui->label_tol->setText("+/-0.25% (C)");
        break;
    case 4:
        ui->label_tol->setText("+/-0.1% (B)");
        break;
    case 5:
        ui->label_tol->setText("+/-0.05% (A)");
        break;
    case 6:
        ui->label_tol->setText("+/-5% (J)");
        break;
    case 7:
        ui->label_tol->setText("+/-10% (K)");
        break;
    case 8:
        ui->label_tol->setText("+/-20% (M)");
        break;
    default:
        ui->label_tol->setText(" ");
        break;
    }

}
//=========================================================================
// Used for drawing color in ComboBoxes
QIcon wResistors::createIcon(QString colorName)
{
    QPixmap iconPixmap(32,32);
    iconPixmap.fill(QColor(colorName));
    QIcon itemIcon(iconPixmap);
    return itemIcon;
}
