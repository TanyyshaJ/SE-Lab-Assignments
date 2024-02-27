#include "mainwindow.h"
#include "./ui_mainwindow.h"

QImage img(501, 501, QImage::Format_RGB888); //canvas

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

void MainWindow::plotPixel(int x, int y){
    img.setPixel(x,y,qRgb(255,0,0));
}

void MainWindow::drawDDAline(int x1, int y1, int x2, int y2){
    float dx = x2 - x1;
    float dy = y2 -  y1;
    float step;

    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    float x_inc = dx/step;
    float y_inc = dy/step;

    float x = x1;
    float y = y1;

    plotPixel(x1,y1);

    for(int i=0; i<step; i++){
        plotPixel(x,y);
        x = x+x_inc;
        y = y+y_inc;
    }
}

void MainWindow::drawBresenhamCircle(int x_c, int y_c, int radius){
    int x=0;
    int y=radius;

    float d = 3-(2*radius);

    while(x<=y){
        plotPixel(x + x_c, y + y_c);
        plotPixel(-x + x_c, y + y_c);
        plotPixel(-x + x_c, -y + y_c);
        plotPixel(x + x_c, -y + y_c);
        plotPixel(y + y_c, x + x_c);
        plotPixel(-y + y_c, x + x_c);
        plotPixel(-y + y_c, -x + x_c);
        plotPixel(y + y_c, -x + x_c);

        if(d<0){
            d = d + (4*x) + 6;
        }

        else{
            d = d + (4*(x-y)) + 10;
            y = y-1;
        }
        x = x+1;
    }
}

void MainWindow::on_draw_clicked()
{
    //main circle
    drawBresenhamCircle(100, 100, 40);
    //smaller circle
    drawBresenhamCircle(100, 100, 20);

    // drawDDAline(xc,yc-r,xc-(0.866*r),yc+r/2);
    // drawDDAline(xc,yc-r,xc+(0.866*r),yc+r/2);
    // drawDDAline(xc+(0.866*r),yc+r/2,xc-(0.866*r),yc+r/2);

    drawDDAline(100,100-40,100-(0.866*40),100+20);
    drawDDAline(100,100-40,100+(0.866*40),100+20);
    drawDDAline(100+(0.866*40),100+20,100-(0.866*40),100+20);
    //insert on canvas
    ui -> frame -> setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_clicked()
{
    img = QImage (501, 501, QImage::Format_RGB888);
    ui -> frame -> setPixmap(QPixmap::fromImage(img));
}

