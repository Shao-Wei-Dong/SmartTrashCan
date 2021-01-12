#include "camera.h"
#include "login.h"
#include "ui_camera.h"
#include <QTimer>
#include <QMessageBox>
#include "QZXing.h"
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
camera::camera(QWidget *parent) :
    QMainWindow(parent),
    ui_cam(new Ui::camera)
{

    ui_cam->setupUi(this);

    camNTUST = new QLabel(); //初始化
    QImage *imglogo=new QImage; //新建一個image物件
    imglogo->load("/home/ivam/Desktop/wwwwwasd/ntust.png"); //將影象資源載入物件img，注意路徑，可點進圖片右鍵複製路徑
    ui_cam-> camNTUST->setPixmap(QPixmap::fromImage(*imglogo)); //將圖片放入label，使用setPixmap,注意指標*img


    tree = new QLabel(); //初始化
    QImage *imgtree=new QImage; //新建一個image物件
    imgtree->load("/home/ivam/Desktop/wwwwwasd/n.png"); //將影象資源載入物件img，注意路徑，可點進圖片右鍵複製路徑
    ui_cam-> tree->setPixmap(QPixmap::fromImage(*imgtree)); //將圖片放入label，使用setPixmap,注意指標*img






    timer = new QTimer(this);
//    cam = NULL;
//    connect(timer,SIGNAL(timeout()), this, SLOT(cameraopen()));

    ldatetimer = new QTimer(this);
    ldatetimer->start(1000);
    connect(ldatetimer,SIGNAL(timeout()),this,SLOT(cameraopen()));
//    loginuser();
//    connect(open,SIGNAL(on_open_clicked()),this,SLOT(loginuser()));
//    connect(log,SIGNAL(sendData(QString)),this,SLOT(receiveData(QString)));
//    log->show();

}
camera::~camera()
{
    delete ui_cam;
    cvReleaseCapture(&cam);
}
//void camera::on_open_clicked()
//{
//    cam = cvCreateCameraCapture(-1);
//    timer->start(33);

//    port = 5555;
//    udpSocket = new QUdpSocket(this);

//    QString msg = "open";
//    int lengh = 0;

//    if((lengh=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::LocalHost , port)) != msg.length())
//    {
//        return;
//    }
//}
void camera::on_logout_clicked()
{
//    timer->stop();
//    cvReleaseCapture(&cam);
    Login *login = new Login;

//    emit sendData(ui_cam->close->clicked());
    QMessageBox::information(this,"waiting","Log Out Success",QMessageBox::Ok);
    login->show();
    camera::close();
}
void camera::cameraopen()
{
    QLabel label_2;
    QDateTime local(QDateTime::currentDateTime());
    QString localTime1 = local.toString("yyyy-MM-dd:hh:mm:ss");
    ui_cam->label_2->setText(localTime1);

}
void ::camera::receiveData(QString data)
{
    ui_cam->username->setText(data);

}
void camera::on_motor_clicked()
{
    port = 5555;
    udpSocket = new QUdpSocket(this);

    QString msg = "open";
    int lengh = 0;


    if((lengh=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::LocalHost , port)) != msg.length())
    {
        return;
    }
}


