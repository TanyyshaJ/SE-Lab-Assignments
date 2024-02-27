#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMouseEvent"
#include<QColorDialog>
#include<iostream>
#include<QTime>

QImage img(501, 501, QImage::Format_RGB888);//canvas
QColor color = qRgb(255,255,255);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    start = true;
    count = 0;
}

void delay(int millisecondsToWait){
    QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while(QTime::currentTime()<dieTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    if(start){
        int p = event->pos().x();
        int q = event->pos().y();

        a[count] = p;
        b[count] = q;

        if(event->button()==Qt::RightButton){
            drawDDA(a[count-1], b[count-1], a[0], b[0]);
            drawDDA(a[count-1]+1, b[count-1]+1, a[0]+1, b[0]+1);
            start = false;
            cout<<"Final"<<endl;
        }
        else{
            if(count>0){
                drawDDA(a[count], b[count], a[count-1], b[count-1]);
                drawDDA(a[count]+1, b[count]+1, a[count-1]+1, b[count-1]+1);
            }
            count++;
        }
    }
}

void MainWindow::plotPixel(int x, int y){
    img.setPixel(x, y, qRgb(255,0,0));
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

    plotPixel(x1, y1);

    for(int i=0; i<step; i++){
        plotPixel(x, y);
        x = x+x_inc;
        y = y+y_inc;
    }
}

void MainWindow::on_chooseColor_clicked()
{
    color = QColorDialog::getColor();
}


void MainWindow::on_fill_clicked()
{
    cout<<x[i]<<x[i+1]<<endl;
    a[count] = a[0];
    b[count] = b[0];

    for(i=0;i<count;i++){
        dy = b[i+1]-b[i];
        dx = a[i+1]-a[i];
        if(dy===0.0f){
            slope[i]=1.0;
        }
        if(dx===0.0f){
            slope[i]=0.0;
        }
        if((dy!=0.0f)&&(dx!=0.0f)){
            slope[i] = dx/dy;
        }
    }
    for(int y=0; y<500; y++){
        k=0;
        for(i=0; i<count; i++){
            if(((b[i]<=y) && (b[i+1]>y) || (b[i]>y) && (b[i+1]<=y))){
                xi[k] = int(a[i] + slope[i]*(y-b[i]));
                k++;
            }
        }
        for(j=0;j<k-1;j++){
            if(xi[i+1]>xi){
                temp = xi[i];
                xi[i]=x[i+1];
                x[i+1]=temp;
            }
        }
    }
    for(i=0;i<k;i+=2){
        delay(20);
        drawDDA(x[i], y, x[i+1], y);
    }
}

