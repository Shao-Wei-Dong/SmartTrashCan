#include "login.h"
#include "camera.h"
#include "ui_login.h"
#include "QZXing.h"
#include <QTime>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLCDNumber>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{

    ui->setupUi(this);

    NTUST = new QLabel(); //初始化
    QImage *imglogo=new QImage; //新建一個image物件
    imglogo->load("/home/ivam/Desktop/wwwwwasd/ntust.png"); //將影象資源載入物件img，注意路徑，可點進圖片右鍵複製路徑
    ui->NTUST->setPixmap(QPixmap::fromImage(*imglogo)); //將圖片放入label，使用setPixmap,注意指標*img

    trashlb = new QLabel(); //初始化
    QImage *img=new QImage; //新建一個image物件
    imglogo->load("/home/ivam/Desktop/wwwwwasd/t.png"); //將影象資源載入物件img，注意路徑，可點進圖片右鍵複製路徑
    ui->trashlb->setPixmap(QPixmap::fromImage(*imglogo)); //將圖片放入label，使用setPixmap,注意指標*img


    QLabel status;
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    ui->status->setText(localTime);
    timer = new QTimer(this);
    //初始化timer
    cam = NULL;
    // 初始化cam
    connect(timer, SIGNAL(timeout()), this, SLOT(cameraopen()));

    datetimer=new QTimer(this);
    datetimer->start(1000);
    connect(datetimer,SIGNAL(timeout()),this,SLOT(show_cam()));


//    cam = cvCreateCameraCapture(-1);
//    timer->start(33);
//    cameraopen();
//    show_cam();
}
Login::~Login()
{
    delete ui;
    cvReleaseCapture(&cam);

}
int Login::on_loginbtn_clicked()
{
    QString user = ui->userline->text();
    camera *cam_interface = new camera;
    connect(this,SIGNAL(sendData(QString)),cam_interface,SLOT(receiveData(QString)));
    emit sendData(ui->userline->text());
    if(user.trimmed() == tr("M10907K08AA001"))
    {
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();

        return 1;
    }
    if(user.trimmed() == tr("M10907K04BA006"))
    {
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();
        return 2;
    }
    if(user.trimmed() == tr("M10907K04CB007"))
    {
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();
        return 3;
    }
    if(user.trimmed() == tr("M10907K02DA007"))
    {
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();
        return 4;
    }
    if(user.trimmed() == tr("M10907311EB012"))
    {
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();
        return 5;
    }
    if(user.trimmed() == tr("a"))
    {
//        M10907K02FA007
        QMessageBox::information(this,"Loading..","Success",QMessageBox::Ok);
//        dialog_show();
        Login::close();
        timer->stop();
        cvReleaseCapture(&cam);
        cam_interface->show();
        return 6;
    }
    else
    {
        ui->error->setText("This QR code is wrong ! ");
        ui->error->setStyleSheet("QLabel {color : red; }");
        ui->userline->clear();
        ui->userline->setFocus();
    }
}
bool Login::on_userline_editingFinished()
{
   return true;
}
void Login::show_cam()
{
    QLabel status;
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyyy-MM-dd:hh:mm:ss");
    ui->status->setText(localTime);
}
void Login::cameraopen()
{
    pFrame = cvQueryFrame(cam);
    QImage image((const uchar*)pFrame->imageData, pFrame->width, pFrame->height,QImage::Format_RGB888);
    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    QZXing *pDecoder = new QZXing(QZXing::DecoderFormat_MAXICODE);
    //Qzxing对象
    QString qrmsg=pDecoder->decodeImage(image);
    //decodeImage是Qzxing解码函数，解码出来的是QString字符体
    if (!qrmsg.isEmpty())
    {
        ui->userline->setText(qrmsg);
        //将解码出的文本显示在lineEdit上
        QGraphicsScene *scene = new QGraphicsScene;
        //创建图片显示方式的容器
        scene->addPixmap(QPixmap::fromImage(image));
        //装载图片
        ui->graphicsView->setScene(scene);
        //显示图片，自动添加滚动条
        ui->graphicsView->show();
        //显示图片
        timer->stop();
        // 停止读取数据。
        cvReleaseCapture(&cam);
        //释放内存；
    }
    else
    {
        ui->userline->setText("條碼尚未檢測到");
        //显示解码失败
        QGraphicsScene *scene = new QGraphicsScene;
        //创建图片显示方式的容器
        scene->addPixmap(QPixmap::fromImage(image));
        //装载图片
        ui->graphicsView->setScene(scene);
        //显示图片，自动添加滚动条
        ui->graphicsView->show();
        //显示图片
    }
}
void Login::on_open_clicked()
{
    cam = cvCreateCameraCapture(0);
    timer->start(33);
}
