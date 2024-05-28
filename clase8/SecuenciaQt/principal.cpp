#include "principal.h"
#include "ui_principal.h"
#include <QMessageBox>
#include <QTimer>
#include <QObject>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    this->juego = new Juego();
    this->time = new QTimer(this);
    QObject::connect(time,
                     SIGNAL(timeout()),
                     this, SLOT(timeout()));
    this->refresh();
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_pushButton_clicked()
{
    this->time->stop();
    if (this->juego->estaBien(this->ui->spinBox->value())) {
        QMessageBox::information(this, "Ganaste", "Ganaste!!");
    } else {
        QMessageBox::warning(this, "Perdiste", "Perdiste :( ");
    }
    this->refresh();
}

void Principal::refresh()
{
    this->ui->label->setText(
                QString::number(this->juego->getNro1()));
    this->ui->label_2->setText(
                QString::number(this->juego->getNro2()));
    this->ui->label_3->setText(
                QString::number(this->juego->getNro4()));
    this->ui->spinBox->setValue(0);
    this->ui->label_punto->setText(
                QString::number(this->juego->getPuntos()));
    this->ui->lcdNumber->display(10);
    time->start(1000);
}

void Principal::timeout()
{
    int valor = this->ui->lcdNumber->value();
    if (valor == 0) {
        this->on_pushButton_clicked();
    } else {
        this->ui->lcdNumber->display(valor-1);
    }
}

