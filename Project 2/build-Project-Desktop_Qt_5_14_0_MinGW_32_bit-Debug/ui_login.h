/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginBox
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_username_email;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_login;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_new_register;
    QLabel *label_5;

    void setupUi(QDialog *LoginBox)
    {
        if (LoginBox->objectName().isEmpty())
            LoginBox->setObjectName(QString::fromUtf8("LoginBox"));
        LoginBox->resize(470, 512);
        LoginBox->setMinimumSize(QSize(470, 512));
        LoginBox->setMaximumSize(QSize(16777215, 512));
        label = new QLabel(LoginBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(185, 15, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icon.png")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(LoginBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(55, 170, 361, 251));
        lineEdit_username_email = new QLineEdit(groupBox);
        lineEdit_username_email->setObjectName(QString::fromUtf8("lineEdit_username_email"));
        lineEdit_username_email->setGeometry(QRect(20, 40, 321, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("B Nazanin"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        lineEdit_username_email->setFont(font);
        lineEdit_username_email->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(25, 10, 312, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("B Nazanin"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(25, 100, 312, 25));
        label_3->setFont(font1);
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(20, 130, 321, 41));
        lineEdit_password->setFont(font);
        lineEdit_password->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"border: 1px solid black;"));
        lineEdit_password->setEchoMode(QLineEdit::Password);
        pushButton_login = new QPushButton(groupBox);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(20, 190, 321, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("B Nazanin"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_login->setFont(font2);
        pushButton_login->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_login->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_4 = new QLabel(LoginBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(145, 124, 181, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("B Nazanin"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(LoginBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(55, 430, 361, 51));
        pushButton_new_register = new QPushButton(groupBox_2);
        pushButton_new_register->setObjectName(QString::fromUtf8("pushButton_new_register"));
        pushButton_new_register->setGeometry(QRect(35, 10, 181, 31));
        pushButton_new_register->setFont(font);
        pushButton_new_register->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_new_register->setLayoutDirection(Qt::RightToLeft);
        pushButton_new_register->setStyleSheet(QString::fromUtf8("color: #37A7D9;"));
        pushButton_new_register->setFlat(true);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 10, 111, 31));
        label_5->setFont(font);
        groupBox_2->raise();
        label->raise();
        groupBox->raise();
        label_4->raise();

        retranslateUi(LoginBox);

        QMetaObject::connectSlotsByName(LoginBox);
    } // setupUi

    void retranslateUi(QDialog *LoginBox)
    {
        LoginBox->setWindowTitle(QCoreApplication::translate("LoginBox", "\331\210\330\261\331\210\330\257 \330\250\331\207 \330\263\333\214\330\263\330\252\331\205", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("LoginBox", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214 \333\214\330\247 \330\242\330\257\330\261\330\263 \330\247\333\214\331\205\333\214\331\204", nullptr));
        label_3->setText(QCoreApplication::translate("LoginBox", "\330\261\331\205\330\262 \330\271\330\250\331\210\330\261", nullptr));
        pushButton_login->setText(QCoreApplication::translate("LoginBox", "\331\210\330\261\331\210\330\257", nullptr));
        label_4->setText(QCoreApplication::translate("LoginBox", "\331\210\330\261\331\210\330\257 \330\250\331\207 \330\263\333\214\330\263\330\252\331\205", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_new_register->setText(QCoreApplication::translate("LoginBox", "\330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214 \330\254\330\257\333\214\330\257 \330\250\330\263\330\247\330\262\333\214\330\257", nullptr));
        label_5->setText(QCoreApplication::translate("LoginBox", "\332\251\330\247\330\261\330\250\330\261 \330\252\330\247\330\262\331\207 \331\207\330\263\330\252\333\214\330\257\330\237 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginBox: public Ui_LoginBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
