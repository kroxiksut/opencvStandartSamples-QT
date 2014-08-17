#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QImage>


//#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
//using namespace cv;
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->pushButton->click(); //show image
   ui->pushButton->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_actionHelp_triggered()
{

    QMessageBox::about(this,"About","This program demonstrates finding the minimum enclosing box or circle of a set\n"
                                         "of points using functions: minAreaRect() minEnclosingCircle().\n"
                                         "Random points are generated and then enclosed.\n"
                                         "Using OpenCV version " CV_VERSION"\n\n"
                                         "QT was adding in example by Fyodor Malkov at fmalkov@istu.edu"

                             );
}

void MainWindow::on_pushButton_clicked()
{
    Mat img(ui->label->geometry().width(),ui->label->geometry().height(),CV_8UC3);

    int i, count = rng.uniform(1, 101);
    vector<Point> points;
    for( i = 0; i < count; i++ )
    {
        Point pt;
        pt.x = rng.uniform(img.cols/4, img.cols*3/4);
        pt.y = rng.uniform(img.rows/4, img.rows*3/4);
        points.push_back(pt);
    }

    RotatedRect box = minAreaRect(Mat(points));
    Point2f center, vtx[4];
    float radius = 0;
    minEnclosingCircle(Mat(points), center, radius);
    box.points(vtx);

    img = Scalar::all(0);
    for( i = 0; i < count; i++ )
                circle( img, points[i], 3, Scalar(0, 0, 255), CV_FILLED, CV_AA );

            for( i = 0; i < 4; i++ )
                line(img, vtx[i], vtx[(i+1)%4], Scalar(0, 255, 0), 1, CV_AA);

            circle(img, center, cvRound(radius), Scalar(0, 255, 255), 1, CV_AA);

            QImage toImg(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);

            ui->label->setPixmap(QPixmap::fromImage(toImg));

}

void MainWindow::on_actionGenerated_triggered()
{
    ui->pushButton->click();
}
