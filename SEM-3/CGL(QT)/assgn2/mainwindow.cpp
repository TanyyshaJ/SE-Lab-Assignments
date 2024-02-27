#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMouseEvent>
#include<QTime>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver = 0;
    start = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage img(500, 500, QImage::Format_RGB888);
QColor Color;

void MainWindow::delay(int millisecondsToWait){
    QTime waitTime = QTime::currentTime().addMSecs(millisecondsToWait);
    while(QTime::currentTime()<waitTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::DDA(int x1, int y1, int x2, int y2)
{
    float dx, dy, xinc, yinc;
    int length;

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx)> abs(dy)){
        length = abs(dx);
    }
    else{
        length = abs(dy);
    }

    xinc = dx / length;
    yinc = dy / length;

    float x = x1;
    float y = y1;
    int i=0 ;
    while(i<length){
        img.setPixel(x, y, qRgb(Color.red(), Color.green(), Color.blue()));
        x += xinc;
        y += yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if (start)
    {
        int p = ev->pos().x();
        int q = ev->pos().y();
        a[ver] = p;
        b[ver] = q;

        if (ev->button() == Qt::RightButton)
        {
            DDA(a[0], b[0], a[ver - 1], b[ver - 1]);
            start = false;
        }
        else
        {
            if (ver > 0)
            {
                DDA(a[ver], b[ver], a[ver - 1], b[ver - 1]);
            }
            ver++;
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    Color = QColorDialog::getColor();
}

void MainWindow::on_pushButton_2_clicked()
{
    int ymax = 0;
    int ymin = 10000000;
    a[ver] = a[0];
    b[ver] = b[0];

    for (int i = 0; i <= ver - 1; ++i)
    {
        if (b[i] > ymax)
        {
            ymax = b[i];
        }
        if (b[i] < ymin)
        {
            ymin = b[i];
        }
    }

    for(int i=0 ; i< ver ; i++){
        dy = b[i+1] - b[i];
        dx = a[i+1] - a[i];

        if(dy == 0.0 ){
            slope[i] =1.0;
        }
        if(dx == 0.0){
            slope[i] = 0.0;
        }
        if((dy!=0.0)&&(dx!=0.0))
        {
            slope[i]=float(dx/dy);
        }
    }

    for (int y = ymin; y < ymax; ++y)
    {
        int  k = 0;

        for (int i = 0; i < ver; i ++ )
        {
            if ((b[i] <= y && b[i + 1] > y) || (b[i] > y && b[i + 1] <= y))
            {
                xi[k] = int(a[i] + slope[i] *(y - b[i]));
                ++k;
            }
        }

        for(j=0; j<= k-1 ; j++){
            for(int i=0 ; i<k-j-1 ; i++){
                if(xi[i]> xi[i+1]){
                    temp=xi[i];
                    xi[i]=xi[i+1];
                    xi[i+1]=temp;
                }
            }


            for(int i = 0;i<k;i+=2)
            {
                delay(20);
                DDA(xi[i],y,xi[i+1],y);
            }
        }
    }
}
