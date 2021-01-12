#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QWheelEvent>
#include <opencv2/opencv.hpp>

using namespace cv;

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    this->setFixedSize(820,620);

    ui->setupUi(this);
    ui->lb_img->setGeometry(0,0,800,600);
    ui->lb_img->setMaximumSize(800,600);
    ui->lb_img->setStyleSheet("background-color:black;");

    ui->lb_img->setMouseTracking(true);

}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"打开图像文件","C:\\Users\\lizhifun\\Desktop\\ModelTest\\","Image File(*.bmp;*.png;*.jpg)");
    if(filename == "")
    {
        QMessageBox::information(this,"提示","文件打开失败!");
        return;
    }
    img_input = cv::imread(cv::String(filename.toLocal8Bit().toStdString()));
    if(img_input.empty())
    {
        QMessageBox::information(this,"提示","文件打开失败!");
        return;
    }
    Mat temp;
    QImage qImg;
    cv::cvtColor(img_input,temp,COLOR_BGR2RGB);
    qImg = QImage((const unsigned char*)(temp.data), temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

    ui->lb_img->setPixmap(QPixmap::fromImage(qImg));
    ui->lb_img->setScaledContents(true);
}



QImage MyWidget::MatToQImg(cv::Mat mat, bool isGray)
{
    Mat temp;
    QImage qImg;
    if(isGray)
    {
        cv::cvtColor(mat,temp,COLOR_GRAY2RGB);
    }
    else
    {
        cv::cvtColor(mat,temp,COLOR_BGR2RGB);
    }

    return qImg;
}






