#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "juego.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_pushButton_clicked();
    void timeout();

private:
    void refresh();
    Ui::Principal *ui;
    Juego* juego;
    QTimer * time;


};
#endif // PRINCIPAL_H
