/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterBox
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_login;
    QLabel *label_5;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_username_email;
    QLabel *label_2;
    QPushButton *pushButton_register1;
    QLabel *label_3;
    QWidget *page_2;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit_password_repeat;
    QLabel *label_8;
    QPushButton *pushButton_register2;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_password;
    QWidget *page_3;
    QGroupBox *groupBox_4;
    QLineEdit *lineEdit_name;
    QLabel *label_11;
    QPushButton *pushButton_register3;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_username;
    QLabel *label_4;
    QLabel *label;

    void setupUi(QDialog *RegisterBox)
    {
        if (RegisterBox->objectName().isEmpty())
            RegisterBox->setObjectName(QString::fromUtf8("RegisterBox"));
        RegisterBox->resize(470, 512);
        RegisterBox->setMinimumSize(QSize(470, 512));
        RegisterBox->setMaximumSize(QSize(470, 512));
        stackedWidget = new QStackedWidget(RegisterBox);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 161, 470, 351));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        groupBox_2 = new QGroupBox(page_1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(55, 270, 361, 51));
        pushButton_login = new QPushButton(groupBox_2);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(35, 10, 141, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("B Nazanin"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton_login->setFont(font);
        pushButton_login->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_login->setLayoutDirection(Qt::RightToLeft);
        pushButton_login->setStyleSheet(QString::fromUtf8("color: #37A7D9;"));
        pushButton_login->setFlat(true);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(185, 10, 141, 31));
        label_5->setFont(font);
        groupBox = new QGroupBox(page_1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(55, 10, 361, 251));
        lineEdit_username_email = new QLineEdit(groupBox);
        lineEdit_username_email->setObjectName(QString::fromUtf8("lineEdit_username_email"));
        lineEdit_username_email->setGeometry(QRect(20, 130, 321, 41));
        lineEdit_username_email->setFont(font);
        lineEdit_username_email->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 95, 312, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("B Nazanin"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        pushButton_register1 = new QPushButton(groupBox);
        pushButton_register1->setObjectName(QString::fromUtf8("pushButton_register1"));
        pushButton_register1->setGeometry(QRect(20, 190, 321, 41));
        pushButton_register1->setFont(font1);
        pushButton_register1->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_register1->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(11, 9, 341, 61));
        label_3->setFont(font1);
        label_3->setWordWrap(true);
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(55, 20, 361, 311));
        lineEdit_password_repeat = new QLineEdit(groupBox_3);
        lineEdit_password_repeat->setObjectName(QString::fromUtf8("lineEdit_password_repeat"));
        lineEdit_password_repeat->setGeometry(QRect(20, 190, 321, 41));
        lineEdit_password_repeat->setFont(font);
        lineEdit_password_repeat->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        lineEdit_password_repeat->setEchoMode(QLineEdit::Password);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(25, 160, 312, 25));
        label_8->setFont(font1);
        pushButton_register2 = new QPushButton(groupBox_3);
        pushButton_register2->setObjectName(QString::fromUtf8("pushButton_register2"));
        pushButton_register2->setGeometry(QRect(20, 250, 321, 41));
        pushButton_register2->setFont(font1);
        pushButton_register2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_register2->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(11, 9, 341, 61));
        label_9->setFont(font1);
        label_9->setWordWrap(true);
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(25, 80, 312, 25));
        label_10->setFont(font1);
        lineEdit_password = new QLineEdit(groupBox_3);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 110, 321, 41));
        lineEdit_password->setFont(font);
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        groupBox_4 = new QGroupBox(page_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(55, 20, 361, 311));
        lineEdit_name = new QLineEdit(groupBox_4);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(20, 190, 321, 41));
        lineEdit_name->setFont(font);
        lineEdit_name->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(25, 160, 312, 25));
        label_11->setFont(font1);
        pushButton_register3 = new QPushButton(groupBox_4);
        pushButton_register3->setObjectName(QString::fromUtf8("pushButton_register3"));
        pushButton_register3->setGeometry(QRect(20, 250, 321, 41));
        pushButton_register3->setFont(font1);
        pushButton_register3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_register3->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(11, 9, 341, 61));
        label_12->setFont(font1);
        label_12->setWordWrap(true);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(25, 80, 312, 25));
        label_13->setFont(font1);
        lineEdit_username = new QLineEdit(groupBox_4);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(20, 110, 321, 41));
        lineEdit_username->setFont(font);
        lineEdit_username->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        stackedWidget->addWidget(page_3);
        label_4 = new QLabel(RegisterBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 130, 291, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("B Nazanin"));
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        label = new QLabel(RegisterBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(185, 15, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icon.png")));
        label->setScaledContents(true);

        retranslateUi(RegisterBox);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterBox);
    } // setupUi

    void retranslateUi(QDialog *RegisterBox)
    {
        RegisterBox->setWindowTitle(QCoreApplication::translate("RegisterBox", "\330\253\330\250\330\252 \331\206\330\247\331\205 \330\257\330\261 \330\263\333\214\330\263\330\252\331\205", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_login->setText(QCoreApplication::translate("RegisterBox", "\331\210\330\261\331\210\330\257 \330\250\330\247 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterBox", "\331\202\330\250\331\204\330\247 \330\255\330\263\330\247\330\250 \330\263\330\247\330\256\330\252\331\207 \330\247\333\214\330\257\330\237", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("RegisterBox", "\330\242\330\257\330\261\330\263 \330\247\333\214\331\205\333\214\331\204", nullptr));
        pushButton_register1->setText(QCoreApplication::translate("RegisterBox", "\330\247\330\257\330\247\331\205\331\207", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterBox", "\331\204\330\267\331\201\330\247 \330\250\330\261\330\247\333\214 \330\247\333\214\330\254\330\247\330\257 \333\214\332\251 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214 \330\254\330\257\333\214\330\257\330\214 \330\247\330\250\330\252\330\257\330\247 \330\242\330\257\330\261\330\263 \330\247\333\214\331\205\333\214\331\204 \330\256\331\210\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257.", nullptr));
        groupBox_3->setTitle(QString());
        label_8->setText(QCoreApplication::translate("RegisterBox", "\330\252\332\251\330\261\330\247\330\261 \330\261\331\205\330\262 \331\210\330\261\331\210\330\257", nullptr));
        pushButton_register2->setText(QCoreApplication::translate("RegisterBox", "\330\247\330\257\330\247\331\205\331\207", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterBox", "\330\257\330\261 \330\247\333\214\331\206 \331\205\330\261\330\255\331\204\331\207 \333\214\332\251 \330\261\331\205\330\262 \330\250\330\261\330\247\333\214 \330\256\331\210\330\257 \330\247\333\214\330\254\330\247\330\257 \331\206\331\205\330\247\333\214\333\214\330\257. (\330\255\330\257\330\247\331\202\331\204 \333\270 \330\255\330\261\331\201 \330\264\330\247\331\205\331\204 \330\247\330\271\330\257\330\247\330\257 \331\210 \330\255\330\261\331\210\331\201 \330\247\331\206\332\257\331\204\333\214\330\263\333\214)", nullptr));
        label_10->setText(QCoreApplication::translate("RegisterBox", "\330\261\331\205\330\262 \331\210\330\261\331\210\330\257", nullptr));
        groupBox_4->setTitle(QString());
        label_11->setText(QCoreApplication::translate("RegisterBox", "\331\206\330\247\331\205 \332\251\330\247\331\205\331\204 (\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214)", nullptr));
        pushButton_register3->setText(QCoreApplication::translate("RegisterBox", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_12->setText(QCoreApplication::translate("RegisterBox", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 \331\210 \331\206\330\247\331\205 \332\251\330\247\331\205\331\204 \330\256\331\210\330\257 \330\261\330\247 \331\210\330\247\330\261\330\257 \332\251\331\206\333\214\330\257. (\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 \330\250\330\247\333\214\330\257 \333\214\332\251\330\252\330\247 \330\250\330\247\330\264\330\257)", nullptr));
        label_13->setText(QCoreApplication::translate("RegisterBox", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterBox", "\330\247\333\214\330\254\330\247\330\257 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214 \330\254\330\257\333\214\330\257", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterBox: public Ui_RegisterBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
