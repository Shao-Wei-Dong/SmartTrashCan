/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_camera
{
public:
    QWidget *centralwidget;
    QPushButton *logout;
    QLabel *userlbl;
    QLineEdit *username;
    QLabel *label_2;
    QPushButton *motor;
    QLabel *camNTUST;
    QLabel *tree;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *camera)
    {
        if (camera->objectName().isEmpty())
            camera->setObjectName(QStringLiteral("camera"));
        camera->resize(1200, 800);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        camera->setPalette(palette);
        centralwidget = new QWidget(camera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        logout = new QPushButton(centralwidget);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(440, 370, 300, 70));
        QFont font;
        font.setPointSize(20);
        logout->setFont(font);
        userlbl = new QLabel(centralwidget);
        userlbl->setObjectName(QStringLiteral("userlbl"));
        userlbl->setGeometry(QRect(270, 180, 171, 101));
        QFont font1;
        font1.setPointSize(25);
        userlbl->setFont(font1);
        username = new QLineEdit(centralwidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(410, 210, 361, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 100, 371, 51));
        label_2->setFont(font);
        motor = new QPushButton(centralwidget);
        motor->setObjectName(QStringLiteral("motor"));
        motor->setGeometry(QRect(440, 270, 300, 70));
        motor->setFont(font);
        camNTUST = new QLabel(centralwidget);
        camNTUST->setObjectName(QStringLiteral("camNTUST"));
        camNTUST->setGeometry(QRect(10, 0, 520, 100));
        tree = new QLabel(centralwidget);
        tree->setObjectName(QStringLiteral("tree"));
        tree->setGeometry(QRect(90, 520, 1091, 231));
        camera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(camera);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 19));
        camera->setMenuBar(menubar);
        statusbar = new QStatusBar(camera);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        camera->setStatusBar(statusbar);

        retranslateUi(camera);

        QMetaObject::connectSlotsByName(camera);
    } // setupUi

    void retranslateUi(QMainWindow *camera)
    {
        camera->setWindowTitle(QApplication::translate("camera", "MainWindow", Q_NULLPTR));
        logout->setText(QApplication::translate("camera", "Log Out", Q_NULLPTR));
        userlbl->setText(QApplication::translate("camera", "   User", Q_NULLPTR));
        label_2->setText(QApplication::translate("camera", "TIME :", Q_NULLPTR));
        motor->setText(QApplication::translate("camera", "Open Cap", Q_NULLPTR));
        camNTUST->setText(QApplication::translate("camera", "TextLabel", Q_NULLPTR));
        tree->setText(QApplication::translate("camera", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class camera: public Ui_camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
