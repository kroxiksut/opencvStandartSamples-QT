#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionClose_triggered();

    void on_actionHelp_triggered();

    void on_pushButton_clicked();

    void on_actionGenerated_triggered();

private:
    Ui::MainWindow *ui;
    Mat img;
    RNG& rng = theRNG();

    QImage toImg;
};

#endif // MAINWINDOW_H
