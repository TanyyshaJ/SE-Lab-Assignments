#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<math.h>

QImage img(501, 501, QImage::Format_RGB888);

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
    int level;
    level = ui->textEdit->toPlainText().toInt();

    int x1 = 20, x5 = 300;
    int y1 = 280, y5 = 280;

    paint_recurssive(level, 50, 400, 350, 400);
    paint_recurssive(level, 350, 400, 200, 140);
    paint_recurssive(level, 200, 140, 50, 400);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::paint_recurssive(int order, int x1, int y1, int x5, int y5){
    int dx, dy, x2, y2, x3, y3, x4, y4;

    if(order == 1){
        dda(x1, y1, x5, y5);
    }
    else{
        dx = (x5 - x1)/3;
        dy = (y5 - y1)/3;

        x2 = x1+dx;
        y2 = y1+dy;

        x3 = int((x1+x5)/2 + sqrt(3) * (y1-y5)/6);
        y3 = int((y1+y5)/2 + sqrt(3) * (x5-x1)/6);

        x4 = x1+2*dx;
        y4 = y1+2*dy;

        paint_recurssive(order-1, x1, y1, x2, y2);
        paint_recurssive(order-1, x2, y2, x3, y3);
        paint_recurssive(order-1, x3, y3, x4, y4);
        paint_recurssive(order-1, x4, y4, x5, y5);
    }
}

void MainWindow::dda(float x1, float y1, float x2, float y2){
    float dx = x2-x1;
    float dy = y2-y1;
    float steps = abs(dx)>abs(dy)?abs(dx):abs(dy);

    float xinc = dx/steps;
    float yinc = dy/steps;

    float x = x1;
    float y = y1;

    int i=0;
    while(i<steps){
        img.setPixel(x, y, qRgb(255,255,255));
        x+=xinc;
        y+=yinc;
        i++;
    }
}
