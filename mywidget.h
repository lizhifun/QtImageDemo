#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QPixmap>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
    cv::Mat img_input;
    cv::Mat img_scale;
    QImage MatToQImg(cv::Mat mat, bool isGray);


protected:


};
#endif // MYWIDGET_H
