#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void delay(int millisecondsToWait);

private slots:
    void DDA(int x1, int y1, int x2, int y2);

    void mousePressEvent(QMouseEvent* ev);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    bool start;
    float a[100], b[100];
    double slope[100], dx, dy, xi[20], temp;
    int ver, j, k;
};
#endif // MAINWINDOW_H
