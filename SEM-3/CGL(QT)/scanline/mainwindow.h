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
    void on_chooseColor_clicked();
    void on_fill_clicked();
    void drawDDA(int, int, int, int);
    void plotPixel(int, int);
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    int count;
    bool start;
    int a[100], b[100], ver, i, xi[20], j, temp, k, m, n;
    float slope[20], dx, dy;

};
#endif // MAINWINDOW_H
