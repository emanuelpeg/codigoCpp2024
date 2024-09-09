#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int dni = this->ui->spinBox->value();
    int cantHs = this->ui->spinBox_2->value();
    Empleado emp(dni, cantHs);
    this->gestor.agregar(emp);
    this->ui->pushButton_2->setEnabled(true);
    this->ui->pushButton_3->setEnabled(true);
    this->ui->pushButton_4->setEnabled(true);
    this->ui->pushButton_5->setEnabled(true);
    this->ui->spinBox->setValue(0);
    this->ui->spinBox_2->setValue(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    std::vector<Empleado> emps = this->gestor.max();
    QString s;
    for(int i = 0; i < emps.size(); i++) {
        s.append(QString::number(emps[i].getDni()));
        s.append(", ");
    }
    this->ui->label_3->setText(s);
}

void MainWindow::on_pushButton_3_clicked()
{
    std::vector<Empleado> emps = this->gestor.min();
    QString s;
    for(int i = 0; i < emps.size(); i++) {
        s.append(QString::number(emps[i].getDni()));
        s.append(", ");
    }
    this->ui->label_3->setText(s);
}


void MainWindow::on_pushButton_4_clicked()
{
    /* Con vector */
    /*
    std::vector<Empleado> emps = this->gestor.ordenaFive();
    QString s = this->ui->label_4->text();

    for(int i = 0; i < emps.size(); i++) {
        s.append(QString::number(emps[i].getDni()));
        s.append(", ");
    }

    */
    /* Con map */
    std::map<int, int> acumulaHs = this->gestor.getAcumulaHs();
    // Copiar los elementos del mapa a un vector de pares
    std::vector<std::pair<int, int>> acumulados(acumulaHs.begin(), acumulaHs.end());
    // Ordenar el vector por el valor (repeticiones) de manera descendente
    std::sort(acumulados.begin(), acumulados.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.second > b.second;
            });
    QString s;// = this->ui->label_5->text();
    // Imprimir los valores en el mapa
    int cant = 0;
    for (const auto& par : acumulados) {
        if (cant++<5){
            s.append(QString::number(par.first));
            s.append(", ");
        };
    }

    this->ui->label_4->setText(s);
}


void MainWindow::on_pushButton_5_clicked()
{

    std::map<int, int> distintos = this->gestor.getDistintos();
    QString s;// = this->ui->label_5->text();
    // Imprimir los valores en el mapa
    for (const auto& par : distintos) {
        if (par.second>1){
            s.append(QString::number(par.first));
            s.append(", ");
        };
    }
    this->ui->label_5->setText(s);
}

