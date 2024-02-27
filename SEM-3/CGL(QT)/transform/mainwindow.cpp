#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QtDebug>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    ver = 0;
    axes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scaling_clicked()
{
    double scale = ui->scaling_box->toPlainText().toFloat();
}


void MainWindow::on_translating_clicked()
{

}


void MainWindow::on_rotating_clicked()
{

}

