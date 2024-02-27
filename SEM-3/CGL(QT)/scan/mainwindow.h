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

private slots:
    void on_pushButton_clicked();
    void on_fill_clicked();
    void drawDDA(int, int, int, int, QRgb);
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::MainWindow *ui;
    bool start;
    int count, ver=0, temp, i, j, k=0, m, n;
    int a[100], b[100], xi[20];
    float dx, dy, slope[20];

};
#endif // MAINWINDOW_H
