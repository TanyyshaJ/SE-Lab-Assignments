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

QImage img(501, 501, QImage::Format_RGB888);

void MainWindow::on_pushButton_clicked()
{
    int order;
    order = ui->textEdit->toPlainText().toInt();

    paint_recursive(order, 50, 400, 350, 400);
    paint_recursive(order, 350, 400, 200, 400);
    paint_recursive(order, 200, 140, 50, 400);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx , dy, xinc, yinc, x, y;
    int len = 0;

    dx = x2-x1;
    dy = y2-y1;

    if(abs(dx)> abs(dy)){
        len = abs(dx);
    }
    else{
        len = abs(dy);
    }

    xinc = dx/len;
    yinc = dy/len;

    int i=0;
    x=x1;
    y=y1;
    while(i<len){
        img.setPixel(x,y, qRgb(255,255,255));
        x += xinc;
        y += yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::paint_recursive(int order, int x1, int y1, int x5, int y5){
    int dx, dy, x2, y2, x3, y3, x4, y4;

    if(order == 1){
        DDA(x1, y1, x5, y5);
    }
    else{
        dx = (x5-x1)/3;
        dy = (y5-y1)/3;
        x2 = x1+dx;
        y2 = y1+dy;
        x3 = int((x1+x5)/2+ sqrt(3)*(y1-y5)/6);
        y3 = int((y1+y5)/2+ sqrt(3)*(x5-x1)/6);
        x4 = x1+dx*2;
        y4 = y1+dy*2;

        paint_recursive(order-1, x1, y1, x2, y2);
        paint_recursive(order-1, x2, y2, x3, y3);
        paint_recursive(order-1, x3, y3, x4, y4);
        paint_recursive(order-1, x4, y4, x5, y5);
    }
}

