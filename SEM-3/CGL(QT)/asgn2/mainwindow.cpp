#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<qmath.h>
#include<cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
QImage img(501, 501, QImage::Format_RGB888);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawDDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps;

    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }
    else{
        steps = abs(dy);
    }

    float xinc = dx/steps;
    float yinc = dy/steps;

    float x = x1;
    float y = y1;

    int i = 0;

    while(i<steps){
        img.setPixel(x, y, qRgb(255, 255, 255));
        x+=xinc;
        y+=yinc;
        i++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::clearImage(){
    img.fill(qRgb(0,0,0));
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
    drawDDA(200, 0, 200, 400);
    drawDDA(400, 200, 0, 200);
}

float original_x1, original_y1, original_x2, original_y2, original_x3, original_y3;
void MainWindow::on_pushButton_2_clicked()
{

    original_x1 = ui->textEdit->toPlainText().toInt();
    original_y1= ui->textEdit_2->toPlainText().toInt();
    original_x2= ui->textEdit_3->toPlainText().toInt();
    original_y2 = ui->textEdit_4->toPlainText().toInt();
    original_x3= ui->textEdit_5->toPlainText().toInt();
    original_y3 = ui->textEdit_6->toPlainText().toInt();

    drawDDA(200+original_x1, 200+original_y1, 200+original_x2, 200+original_y2);
    drawDDA(200+original_x2, 200+original_y2, 200+original_x3, 200+original_y3);
    drawDDA(200+original_x1, 200+original_y1 , 200+original_x3, 200+original_y3);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_3_clicked()
{
    void clearImage();
    float tx, ty;

    tx = ui->textEdit_7->toPlainText().toInt();
    ty = ui->textEdit_8->toPlainText().toInt();

    drawDDA(200+original_x1+tx, 200+original_y1+ty, 200+original_x2+tx, 200+original_y2+ty);
    drawDDA(200+original_x2+tx, 200+original_y2+ty, 200+original_x3+tx, 200+original_y3+ty);
    drawDDA(200+original_x1+tx, 200+original_y1+ty, 200+original_x3+tx, 200+original_y3+ty);

    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::on_pushButton_4_clicked()
{
    void clearImage();
    float sx, sy;

    sx = ui->textEdit_9->toPlainText().toFloat();
    sy = ui->textEdit_10->toPlainText().toFloat();

    drawDDA(200+(original_x1*sx), 200+(original_y1*sy), 200+(original_x2*sx), 200+(original_y2*sy));
    drawDDA(200+(original_x2*sx), 200+(original_y2*sy), 200+(original_x3*sx), 200+(original_y3*sy));
    drawDDA(200+(original_x1*sx), 200+(original_y1*sy), 200+(original_x3*sx), 200+(original_y3*sy));

    ui->label->setPixmap(QPixmap::fromImage(img));

}


void MainWindow::on_pushButton_5_clicked()
{
    void clearImage();
    float deg;

    deg = ui->textEdit_11->toPlainText().toFloat();

    float(rad) = deg*(0.01745);

    float X1, Y1, X2, Y2, X3, Y3;
    X1 = original_x1*cos(rad) - original_y1*sin(rad);
    Y1 = original_x1*sin(rad) + original_y1*cos(rad);
    X2 = original_x2*cos(rad) - original_y2*sin(rad);
    Y2 = original_x2*sin(rad) + original_y2*cos(rad);
    X3 = original_x3*cos(rad) - original_y3*sin(rad);
    Y3 = original_x3*sin(rad) + original_y3*cos(rad);

    drawDDA(200+X1, 200+Y1, 200+X2, 200+Y2);
    drawDDA(200+X2, 200+Y2, 200+X3, 200+Y3);
    drawDDA(200+X1, 200+Y1, 200+X3, 200+Y3);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

