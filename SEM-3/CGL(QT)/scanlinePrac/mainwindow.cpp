#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMouseEvent>
#include <iostream>
#include <QTime>

using namespace std;

QColorDialog color;
QImage img(501, 501, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    count = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void delay(int delayTime){
    QTime waitTime = QTime::currentTime().addMSecs(delayTime);
    while(QTime::currentTime()<waitTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 400);
    }
}

void MainWindow::drawDDA(int x1, int y1, int x2, int y2){
    float dx = x2-x1;
    float dy = y2-y1;
    float step;

    if(abs(dx)>abs(dy)){
        step = abs(dx);
    }
    else{
        step = abs(dy);
    }

    float x_inc = dx/step;
    float y_inc = dy/step;

    float x=x1;
    float y=y1;

    img.setPixel(x,y,color.rgb());

    for(int i=0; i<step; i++){
        img.setPixel(x,y,color.rgb());
        x = x+x_inc;
        y = y+y_inc;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(start){
        a[count] = event->pos().x();
        b[count] = event->pos().y();

        if(event->button() == Qt::RightButton){
            drawDDA(a[count-1], b[count-1], a[0], b[0]);
            start = false;
            cout<<"Polygon GONE!";
        }
        else{
            if(count>0){
                drawDDA(a[count], b[count], a[count-1], b[count-1]);
            }
            count++;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    //selecting a color
    QColor newColor = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if(newColor.isValid()){
        color = newColor;
    }
}


void MainWindow::on_pushButton_2_clicked()
{

}

