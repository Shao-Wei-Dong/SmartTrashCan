#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QGraphicsView>
#include <QUdpSocket>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <iostream>
using namespace std;
using namespace cv;
namespace Ui {
class camera;
}

class camera : public QMainWindow
{
    Q_OBJECT

public:
    explicit camera(QWidget *parent = 0);
    ~camera();
    Ui::camera *ui_cam;
    QMainWindow *camerainterface;
    QLabel *userlbl;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QPushButton *open;
    QPushButton *logout;
    QPushButton *motor;
    QLineEdit *qrcode;
    QLineEdit *username;
    QTimer *timer;
    CvCapture *cam;
    IplImage *pFrame;
    int port;
    QTimer *timer2;
    QUdpSocket *udpSocket;
    QTimer *ldatetimer;
    QLabel *camNTUST;
    QLabel *tree;


private slots:
//    void on_open_clicked();

//    void on_close_clicked();

    void cameraopen();

    void receiveData(QString data);

    void on_motor_clicked();

    void on_logout_clicked();



private:

};

#endif // CAMERA_H
