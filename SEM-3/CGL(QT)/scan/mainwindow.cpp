#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QMouseEvent>
#include <iostream>
#include <QTime>

using namespace std;

QImage img(501, 501, QImage::Format_RGB888);
QColor color = qRgb(255, 255, 255);
QRgb val = qRgb(0,0,0);
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
    while(QTime::currentTime() < waitTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::drawDDA(int x1, int y1, int x2, int y2, QRgb val){
    float dx = x2-x1;
    float dy = y2-y2;

    float length = (abs(dx)>abs(dy)) ? abs(dx) : abs(dy);

    float xinc = dx/length;
    float yinc = dy/length;

    int sign=0;
    if(dx>0){
        sign+=1;
    }
    else if(dx==0){
        sign = 0;
    }
    else{
        sign = -1;
    }

    float x = x1+0.5*(sign);
    float y = y1+0.5*(sign);

    int i=0;
    while(i<length){

        img.pixel(int(x), int(y));
        img.setPixel(int(x), int(y), color.rgb());
        x += xinc;
        y += yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    int p=event->pos().x(); // Taking the x position of mouse
    int q=event->pos().y(); // Taking the y position of mouse

    a[count]=p;
    b[count]=q+44; // Adding 44 to match with the tip of the cursor
    if(start){

        if(event->button()==Qt::RightButton)
        {

            // Right click ends the coordinate plotting

            drawDDA(a[count],b[count],a[0],b[0], val);
            start=false;
        }
        else
        {
            if(count>0)
            {

                drawDDA(a[count],b[count],a[count-1],b[count-1], val); // Drawing line between successive points

            }
        }
        count++;

    }

}


void MainWindow::on_pushButton_clicked()
{
    color = QColorDialog::getColor();
}


void MainWindow::on_fill_clicked()
{
    a[count] = a[0];
    b[count] = b[0];

    for(int i=0; i<count; i++){
        dy = b[i+1] - b[i];
        dx = a[i+1] - a[i];

        if(dy == 0.0f){
            slope[i] = 1;
        }
        else if(dx == 0.0f){
            slope[i] = 0.0;
        }
        else{
            slope[i] = dx/dy;
        }
    }

    for(m = 0; m<501; m++){
        k = 0;
        for(i =0; i<count; i++){
            if(((b[i]<=m)&&(b[i+1]>m)) || ((b[i]>m)&&(b[i+1]<=m))){
                xi[k] = a[i] + (slope[i]*(m-b[i]));
                k++;
            }
        }

        for(n=0; n<k;n++){
            for(ver=0; ver<k-n-1; ver++){
                if(xi[ver+1]> xi[ver]){
                    temp = xi[ver];
                    xi[ver] = xi[ver+1];
                    xi[ver+1] = temp;
                }
            }
        }

        for(i = 0; i<k; i+=2){
            delay(20);
            drawDDA(xi[i], m, xi[i+1], m, val);
        }
    }
}

