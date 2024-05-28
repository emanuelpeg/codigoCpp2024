#include "principal.h"
#include "ui_principal.h"
#include "dialog.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_spinBox_valueChanged(int arg1)
{
    this->ui->horizontalSlider->setValue(arg1);
}


void Principal::on_horizontalSlider_valueChanged(int value)
{
    this->ui->spinBox->setValue(value);
    setWindowTitle(QString::number(value));
    this->ui->lcdNumber->display(value);
}


void Principal::on_actionSalir_triggered()
{
    //this->close();
    Dialog* dialog = new Dialog(this);
    dialog->show();
}

