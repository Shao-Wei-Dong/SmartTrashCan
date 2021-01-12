#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLCDNumber>
#include <QTime>
#include <QTimer>
#include <QGraphicsView>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <iostream>
using namespace cv;
using namespace std;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QMainWindow *loginterface;
    QGraphicsView *graphicsView;
    QLabel *location;
    QLabel *status;
    QLabel *NTUST;
    QLabel *percent;
    QLabel *user;
    QLabel *error;
    QPushButton *loginbtn;
    QPushButton *okbtn;
    QPushButton *open;
    QLineEdit *userline;
    QTimer time1;
    QTimer *timer;
    QDialog *waiting;
    CvCapture *cam;
    IplImage *pFrame;
    Ui::Login *ui;
    QTimer *datetimer;
    QLabel *trashlb;
public slots:

    bool on_userline_editingFinished();

    void show_cam();

    int on_loginbtn_clicked();

    void cameraopen();

    void on_open_clicked();

signals:
    void sendData(QString);
private slots:

private:

};

#endif // LOGIN_H
