/********************************************************************************
** Form generated from reading UI file 'errorbox.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORBOX_H
#define UI_ERRORBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ErrorBox
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_2;

    void setupUi(QDialog *ErrorBox)
    {
        if (ErrorBox->objectName().isEmpty())
            ErrorBox->setObjectName(QString::fromUtf8("ErrorBox"));
        ErrorBox->resize(500, 337);
        label = new QLabel(ErrorBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 20, 100, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icon.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(ErrorBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 270, 101, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("B Nazanin"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        groupBox = new QGroupBox(ErrorBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 140, 441, 111));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 421, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("B Nazanin"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        retranslateUi(ErrorBox);

        QMetaObject::connectSlotsByName(ErrorBox);
    } // setupUi

    void retranslateUi(QDialog *ErrorBox)
    {
        ErrorBox->setWindowTitle(QCoreApplication::translate("ErrorBox", "\330\256\330\267\330\247", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("ErrorBox", "\330\252\330\247\333\214\333\214\330\257", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ErrorBox: public Ui_ErrorBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORBOX_H
