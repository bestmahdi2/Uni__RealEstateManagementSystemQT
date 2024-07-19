/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QToolBox *toolBox;
    QWidget *page_1;
    QPushButton *pushButton_page_show_my_ads;
    QPushButton *pushButton_page_create_ad;
    QPushButton *pushButton_page_show_all_ads;
    QPushButton *pushButton_page_search_ads;
    QWidget *page_2;
    QPushButton *pushButton_office;
    QPushButton *pushButton_non_residential;
    QPushButton *pushButton_commercial;
    QPushButton *pushButton_residential;
    QWidget *page_3;
    QPushButton *pushButton_page_edit_account;
    QPushButton *pushButton_logout;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *page_create_ad;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_type_sell;
    QRadioButton *radioButton_type_exchange;
    QRadioButton *radioButton_type_rent;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton_category_residential;
    QRadioButton *radioButton_category_non_residential;
    QRadioButton *radioButton_category_office;
    QRadioButton *radioButton_category_commercial;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton_type_land;
    QRadioButton *radioButton_type_kolangi;
    QRadioButton *radioButton_type_garden;
    QRadioButton *radioButton_type_apartment;
    QRadioButton *radioButton_type_office;
    QRadioButton *radioButton_type_clinic;
    QRadioButton *radioButton_type_shop;
    QRadioButton *radioButton_type_storage;
    QRadioButton *radioButton_type_workshop;
    QRadioButton *radioButton_type_villa;
    QLabel *label_5;
    QGroupBox *groupBox_5;
    QLineEdit *lineEdit_address;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_land;
    QLabel *label_8;
    QLineEdit *lineEdit_building;
    QLineEdit *lineEdit_rent;
    QLineEdit *lineEdit_deposit;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_price;
    QLabel *label_pic;
    QPushButton *pushButton_pic;
    QLabel *label_13;
    QLineEdit *lineEdit_description;
    QGroupBox *groupBox_6;
    QLineEdit *lineEdit_ad_name;
    QGroupBox *groupBox_7;
    QCheckBox *checkBox_deed;
    QCheckBox *checkBox_elevator;
    QCheckBox *checkBox_parking;
    QCheckBox *checkBox_balcony;
    QCheckBox *checkBox_storage;
    QCheckBox *checkBox_renew;
    QCheckBox *checkBox_wallpaper;
    QCheckBox *checkBox_furnished;
    QComboBox *comboBox_room;
    QComboBox *comboBox_build;
    QComboBox *comboBox_floor;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *pushButton_create_ad;
    QLabel *label_pic_path;
    QLabel *label_ad_id_hidden;
    QPushButton *pushButton_edit_ad;
    QWidget *page_my_ads;
    QLabel *label_25;
    QTableWidget *tableWidget;
    QLabel *label_26;
    QGroupBox *groupBox;
    QPushButton *pushButton_see_my_ad;
    QPushButton *pushButton_delete_my_ad;
    QPushButton *pushButton_edit_my_ad;
    QWidget *page_see_all_ads;
    QLabel *label_28;
    QListWidget *listWidget_all;
    QWidget *page_detail_ad;
    QLabel *label_41;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_53;
    QLabel *label_ad_type;
    QLabel *label_ad_category;
    QLabel *label_ad_property_type;
    QLabel *label_ad_address;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_61;
    QLabel *label_ad_price;
    QLabel *label_ad_meter;
    QLabel *label_ad_pic;
    QLabel *label_60;
    QLabel *label_ad_detail;
    QLabel *label_46;
    QLabel *label_ad_build;
    QLabel *label_ad_room;
    QLabel *label_ad_floor;
    QLabel *label_48;
    QLabel *label_47;
    QLabel *label_mine;
    QLabel *label_ad_name;
    QLabel *label_ad_id;
    QLabel *label_49;
    QLabel *label_70;
    QLabel *label_ad_owner;
    QLabel *label_62;
    QLabel *label_ad_price_per_meter;
    QWidget *page_search_ads;
    QLabel *label_29;
    QGroupBox *groupBox_8;
    QLineEdit *lineEdit_search;
    QGroupBox *groupBox_9;
    QRadioButton *radioButton_search_name;
    QRadioButton *radioButton_search_address;
    QPushButton *pushButton_search;
    QLabel *label_27;
    QGroupBox *groupBox_10;
    QListWidget *listWidget_search;
    QWidget *page_detail;
    QLabel *label_user_username;
    QLabel *label_71;
    QLabel *label_user_name;
    QLabel *label_42;
    QLabel *label_30;
    QLabel *label_user_email;
    QLabel *label_50;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 800);
        MainWindow->setMinimumSize(QSize(900, 800));
        MainWindow->setMaximumSize(QSize(900, 800));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #FFFFFF;\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        toolBox = new QToolBox(centralwidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(740, 111, 161, 691));
        QFont font;
        font.setFamily(QString::fromUtf8("B Nazanin"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        toolBox->setFont(font);
        toolBox->setLayoutDirection(Qt::RightToLeft);
        toolBox->setStyleSheet(QString::fromUtf8("background-color: #6AB1ED;\n"
"color: white;\n"
"border-radius: 6px;\n"
"text-align: right;\n"
""));
        toolBox->setFrameShape(QFrame::NoFrame);
        toolBox->setFrameShadow(QFrame::Plain);
        toolBox->setLineWidth(1);
        toolBox->setMidLineWidth(0);
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 0, 161, 499));
        pushButton_page_show_my_ads = new QPushButton(page_1);
        pushButton_page_show_my_ads->setObjectName(QString::fromUtf8("pushButton_page_show_my_ads"));
        pushButton_page_show_my_ads->setGeometry(QRect(0, 40, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("B Nazanin"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_page_show_my_ads->setFont(font1);
        pushButton_page_show_my_ads->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_page_show_my_ads->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_page_create_ad = new QPushButton(page_1);
        pushButton_page_create_ad->setObjectName(QString::fromUtf8("pushButton_page_create_ad"));
        pushButton_page_create_ad->setGeometry(QRect(0, 0, 161, 41));
        pushButton_page_create_ad->setFont(font1);
        pushButton_page_create_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_page_create_ad->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_page_show_all_ads = new QPushButton(page_1);
        pushButton_page_show_all_ads->setObjectName(QString::fromUtf8("pushButton_page_show_all_ads"));
        pushButton_page_show_all_ads->setGeometry(QRect(0, 80, 161, 41));
        pushButton_page_show_all_ads->setFont(font1);
        pushButton_page_show_all_ads->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_page_show_all_ads->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_page_search_ads = new QPushButton(page_1);
        pushButton_page_search_ads->setObjectName(QString::fromUtf8("pushButton_page_search_ads"));
        pushButton_page_search_ads->setGeometry(QRect(0, 120, 161, 41));
        pushButton_page_search_ads->setFont(font1);
        pushButton_page_search_ads->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_page_search_ads->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        toolBox->addItem(page_1, QString::fromUtf8("                 \330\242\332\257\331\207\333\214 \331\207\330\247"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 161, 499));
        pushButton_office = new QPushButton(page_2);
        pushButton_office->setObjectName(QString::fromUtf8("pushButton_office"));
        pushButton_office->setGeometry(QRect(0, 80, 161, 41));
        pushButton_office->setFont(font1);
        pushButton_office->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_office->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_non_residential = new QPushButton(page_2);
        pushButton_non_residential->setObjectName(QString::fromUtf8("pushButton_non_residential"));
        pushButton_non_residential->setGeometry(QRect(0, 0, 161, 41));
        pushButton_non_residential->setFont(font1);
        pushButton_non_residential->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_non_residential->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_commercial = new QPushButton(page_2);
        pushButton_commercial->setObjectName(QString::fromUtf8("pushButton_commercial"));
        pushButton_commercial->setGeometry(QRect(0, 120, 161, 41));
        pushButton_commercial->setFont(font1);
        pushButton_commercial->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_commercial->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_residential = new QPushButton(page_2);
        pushButton_residential->setObjectName(QString::fromUtf8("pushButton_residential"));
        pushButton_residential->setGeometry(QRect(0, 40, 161, 41));
        pushButton_residential->setFont(font1);
        pushButton_residential->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_residential->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        toolBox->addItem(page_2, QString::fromUtf8("             \330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 161, 499));
        pushButton_page_edit_account = new QPushButton(page_3);
        pushButton_page_edit_account->setObjectName(QString::fromUtf8("pushButton_page_edit_account"));
        pushButton_page_edit_account->setGeometry(QRect(0, 0, 161, 41));
        pushButton_page_edit_account->setFont(font1);
        pushButton_page_edit_account->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_page_edit_account->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        pushButton_logout = new QPushButton(page_3);
        pushButton_logout->setObjectName(QString::fromUtf8("pushButton_logout"));
        pushButton_logout->setGeometry(QRect(0, 40, 161, 41));
        pushButton_logout->setFont(font1);
        pushButton_logout->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_logout->setStyleSheet(QString::fromUtf8("background-color: #EBF5FD;\n"
"border-radius: 5px;\n"
"border: 1px solid #1C6B2B;\n"
"color: #020308;\n"
"text-align: right;\n"
"padding-left: 5px;"));
        toolBox->addItem(page_3, QString::fromUtf8("        \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 161, 499));
        toolBox->addItem(page, QString::fromUtf8(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(790, 5, 100, 100));
        label->setStyleSheet(QString::fromUtf8("background-color: #020308;"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/icon.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 901, 111));
        label_2->setStyleSheet(QString::fromUtf8("background-color: #020308;"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 0, 761, 101));
        QFont font2;
        font2.setFamily(QString::fromUtf8("B Titr"));
        font2.setPointSize(28);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("background-color: #020308; color: white;"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 110, 741, 691));
        page_create_ad = new QWidget();
        page_create_ad->setObjectName(QString::fromUtf8("page_create_ad"));
        label_4 = new QLabel(page_create_ad);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 741, 61));
        QFont font3;
        font3.setFamily(QString::fromUtf8("B Titr"));
        font3.setPointSize(18);
        font3.setBold(true);
        font3.setWeight(75);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0; color: white;"));
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(page_create_ad);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 220, 381, 81));
        QFont font4;
        font4.setFamily(QString::fromUtf8("B Titr"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox_2->setFont(font4);
        groupBox_2->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_sell = new QRadioButton(groupBox_2);
        radioButton_type_sell->setObjectName(QString::fromUtf8("radioButton_type_sell"));
        radioButton_type_sell->setGeometry(QRect(280, 40, 71, 31));
        radioButton_type_sell->setFont(font);
        radioButton_type_sell->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_sell->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_exchange = new QRadioButton(groupBox_2);
        radioButton_type_exchange->setObjectName(QString::fromUtf8("radioButton_type_exchange"));
        radioButton_type_exchange->setGeometry(QRect(150, 40, 81, 31));
        radioButton_type_exchange->setFont(font);
        radioButton_type_exchange->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_exchange->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_rent = new QRadioButton(groupBox_2);
        radioButton_type_rent->setObjectName(QString::fromUtf8("radioButton_type_rent"));
        radioButton_type_rent->setGeometry(QRect(40, 40, 61, 31));
        radioButton_type_rent->setFont(font);
        radioButton_type_rent->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_rent->setLayoutDirection(Qt::RightToLeft);
        groupBox_3 = new QGroupBox(page_create_ad);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(350, 310, 381, 91));
        groupBox_3->setFont(font4);
        groupBox_3->setLayoutDirection(Qt::RightToLeft);
        radioButton_category_residential = new QRadioButton(groupBox_3);
        radioButton_category_residential->setObjectName(QString::fromUtf8("radioButton_category_residential"));
        radioButton_category_residential->setGeometry(QRect(165, 45, 81, 31));
        radioButton_category_residential->setFont(font);
        radioButton_category_residential->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_category_residential->setLayoutDirection(Qt::RightToLeft);
        radioButton_category_non_residential = new QRadioButton(groupBox_3);
        radioButton_category_non_residential->setObjectName(QString::fromUtf8("radioButton_category_non_residential"));
        radioButton_category_non_residential->setGeometry(QRect(255, 45, 111, 31));
        radioButton_category_non_residential->setFont(font);
        radioButton_category_non_residential->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_category_non_residential->setLayoutDirection(Qt::RightToLeft);
        radioButton_category_office = new QRadioButton(groupBox_3);
        radioButton_category_office->setObjectName(QString::fromUtf8("radioButton_category_office"));
        radioButton_category_office->setGeometry(QRect(90, 45, 61, 31));
        radioButton_category_office->setFont(font);
        radioButton_category_office->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_category_office->setLayoutDirection(Qt::RightToLeft);
        radioButton_category_commercial = new QRadioButton(groupBox_3);
        radioButton_category_commercial->setObjectName(QString::fromUtf8("radioButton_category_commercial"));
        radioButton_category_commercial->setGeometry(QRect(10, 45, 71, 31));
        radioButton_category_commercial->setFont(font);
        radioButton_category_commercial->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_category_commercial->setLayoutDirection(Qt::RightToLeft);
        groupBox_4 = new QGroupBox(page_create_ad);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(350, 410, 381, 125));
        groupBox_4->setFont(font4);
        groupBox_4->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_land = new QRadioButton(groupBox_4);
        radioButton_type_land->setObjectName(QString::fromUtf8("radioButton_type_land"));
        radioButton_type_land->setEnabled(false);
        radioButton_type_land->setGeometry(QRect(310, 45, 61, 31));
        radioButton_type_land->setFont(font);
        radioButton_type_land->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_land->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_kolangi = new QRadioButton(groupBox_4);
        radioButton_type_kolangi->setObjectName(QString::fromUtf8("radioButton_type_kolangi"));
        radioButton_type_kolangi->setEnabled(false);
        radioButton_type_kolangi->setGeometry(QRect(230, 45, 71, 31));
        radioButton_type_kolangi->setFont(font);
        radioButton_type_kolangi->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_kolangi->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_garden = new QRadioButton(groupBox_4);
        radioButton_type_garden->setObjectName(QString::fromUtf8("radioButton_type_garden"));
        radioButton_type_garden->setEnabled(false);
        radioButton_type_garden->setGeometry(QRect(180, 45, 41, 31));
        radioButton_type_garden->setFont(font);
        radioButton_type_garden->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_garden->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_apartment = new QRadioButton(groupBox_4);
        radioButton_type_apartment->setObjectName(QString::fromUtf8("radioButton_type_apartment"));
        radioButton_type_apartment->setEnabled(false);
        radioButton_type_apartment->setGeometry(QRect(90, 45, 81, 31));
        radioButton_type_apartment->setFont(font);
        radioButton_type_apartment->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_apartment->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_office = new QRadioButton(groupBox_4);
        radioButton_type_office->setObjectName(QString::fromUtf8("radioButton_type_office"));
        radioButton_type_office->setEnabled(false);
        radioButton_type_office->setGeometry(QRect(295, 85, 75, 31));
        radioButton_type_office->setFont(font);
        radioButton_type_office->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_office->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_clinic = new QRadioButton(groupBox_4);
        radioButton_type_clinic->setObjectName(QString::fromUtf8("radioButton_type_clinic"));
        radioButton_type_clinic->setEnabled(false);
        radioButton_type_clinic->setGeometry(QRect(230, 85, 61, 31));
        radioButton_type_clinic->setFont(font);
        radioButton_type_clinic->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_clinic->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_shop = new QRadioButton(groupBox_4);
        radioButton_type_shop->setObjectName(QString::fromUtf8("radioButton_type_shop"));
        radioButton_type_shop->setEnabled(false);
        radioButton_type_shop->setGeometry(QRect(160, 85, 61, 31));
        radioButton_type_shop->setFont(font);
        radioButton_type_shop->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_shop->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_storage = new QRadioButton(groupBox_4);
        radioButton_type_storage->setObjectName(QString::fromUtf8("radioButton_type_storage"));
        radioButton_type_storage->setEnabled(false);
        radioButton_type_storage->setGeometry(QRect(90, 85, 61, 31));
        radioButton_type_storage->setFont(font);
        radioButton_type_storage->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_storage->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_workshop = new QRadioButton(groupBox_4);
        radioButton_type_workshop->setObjectName(QString::fromUtf8("radioButton_type_workshop"));
        radioButton_type_workshop->setEnabled(false);
        radioButton_type_workshop->setGeometry(QRect(20, 85, 61, 31));
        radioButton_type_workshop->setFont(font);
        radioButton_type_workshop->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_workshop->setLayoutDirection(Qt::RightToLeft);
        radioButton_type_villa = new QRadioButton(groupBox_4);
        radioButton_type_villa->setObjectName(QString::fromUtf8("radioButton_type_villa"));
        radioButton_type_villa->setEnabled(false);
        radioButton_type_villa->setGeometry(QRect(10, 45, 71, 31));
        radioButton_type_villa->setFont(font);
        radioButton_type_villa->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_type_villa->setLayoutDirection(Qt::RightToLeft);
        label_5 = new QLabel(page_create_ad);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 61, 391, 61));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_5 = new QGroupBox(page_create_ad);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 120, 331, 415));
        groupBox_5->setFont(font4);
        groupBox_5->setLayoutDirection(Qt::RightToLeft);
        lineEdit_address = new QLineEdit(groupBox_5);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));
        lineEdit_address->setGeometry(QRect(15, 70, 301, 31));
        lineEdit_address->setFont(font1);
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 40, 291, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("B Nazanin"));
        font5.setPointSize(11);
        font5.setBold(true);
        font5.setWeight(75);
        label_6->setFont(font5);
        label_6->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(175, 110, 141, 31));
        label_7->setFont(font5);
        label_7->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_land = new QLineEdit(groupBox_5);
        lineEdit_land->setObjectName(QString::fromUtf8("lineEdit_land"));
        lineEdit_land->setGeometry(QRect(175, 140, 141, 31));
        lineEdit_land->setFont(font1);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(15, 110, 141, 31));
        label_8->setFont(font5);
        label_8->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_building = new QLineEdit(groupBox_5);
        lineEdit_building->setObjectName(QString::fromUtf8("lineEdit_building"));
        lineEdit_building->setGeometry(QRect(15, 140, 141, 31));
        lineEdit_building->setFont(font1);
        lineEdit_rent = new QLineEdit(groupBox_5);
        lineEdit_rent->setObjectName(QString::fromUtf8("lineEdit_rent"));
        lineEdit_rent->setEnabled(false);
        lineEdit_rent->setGeometry(QRect(15, 210, 141, 31));
        lineEdit_rent->setFont(font1);
        lineEdit_deposit = new QLineEdit(groupBox_5);
        lineEdit_deposit->setObjectName(QString::fromUtf8("lineEdit_deposit"));
        lineEdit_deposit->setEnabled(false);
        lineEdit_deposit->setGeometry(QRect(175, 210, 141, 31));
        lineEdit_deposit->setFont(font1);
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(175, 180, 141, 31));
        label_9->setFont(font5);
        label_9->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(15, 180, 141, 31));
        label_10->setFont(font5);
        label_10->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_10->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(175, 250, 141, 31));
        label_11->setFont(font5);
        label_11->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_11->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_price = new QLineEdit(groupBox_5);
        lineEdit_price->setObjectName(QString::fromUtf8("lineEdit_price"));
        lineEdit_price->setEnabled(false);
        lineEdit_price->setGeometry(QRect(175, 280, 141, 31));
        lineEdit_price->setFont(font1);
        label_pic = new QLabel(groupBox_5);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setGeometry(QRect(15, 260, 141, 141));
        label_pic->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0;"));
        label_pic->setScaledContents(true);
        label_pic->setAlignment(Qt::AlignCenter);
        pushButton_pic = new QPushButton(groupBox_5);
        pushButton_pic->setObjectName(QString::fromUtf8("pushButton_pic"));
        pushButton_pic->setGeometry(QRect(15, 260, 141, 141));
        QFont font6;
        font6.setFamily(QString::fromUtf8("B Nazanin"));
        font6.setPointSize(15);
        font6.setBold(true);
        font6.setWeight(75);
        pushButton_pic->setFont(font6);
        pushButton_pic->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_pic->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButton_pic->setFlat(true);
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(175, 330, 141, 31));
        label_13->setFont(font5);
        label_13->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineEdit_description = new QLineEdit(groupBox_5);
        lineEdit_description->setObjectName(QString::fromUtf8("lineEdit_description"));
        lineEdit_description->setGeometry(QRect(175, 360, 141, 31));
        lineEdit_description->setFont(font1);
        groupBox_6 = new QGroupBox(page_create_ad);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(350, 120, 381, 91));
        groupBox_6->setFont(font4);
        groupBox_6->setLayoutDirection(Qt::RightToLeft);
        lineEdit_ad_name = new QLineEdit(groupBox_6);
        lineEdit_ad_name->setObjectName(QString::fromUtf8("lineEdit_ad_name"));
        lineEdit_ad_name->setGeometry(QRect(15, 45, 351, 31));
        lineEdit_ad_name->setFont(font1);
        groupBox_7 = new QGroupBox(page_create_ad);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 540, 721, 141));
        groupBox_7->setFont(font4);
        groupBox_7->setLayoutDirection(Qt::RightToLeft);
        checkBox_deed = new QCheckBox(groupBox_7);
        checkBox_deed->setObjectName(QString::fromUtf8("checkBox_deed"));
        checkBox_deed->setEnabled(false);
        checkBox_deed->setGeometry(QRect(619, 45, 91, 25));
        checkBox_deed->setFont(font);
        checkBox_deed->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_deed->setTristate(false);
        checkBox_elevator = new QCheckBox(groupBox_7);
        checkBox_elevator->setObjectName(QString::fromUtf8("checkBox_elevator"));
        checkBox_elevator->setEnabled(false);
        checkBox_elevator->setGeometry(QRect(499, 75, 101, 25));
        checkBox_elevator->setFont(font);
        checkBox_elevator->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_elevator->setTristate(false);
        checkBox_parking = new QCheckBox(groupBox_7);
        checkBox_parking->setObjectName(QString::fromUtf8("checkBox_parking"));
        checkBox_parking->setEnabled(false);
        checkBox_parking->setGeometry(QRect(499, 45, 101, 25));
        checkBox_parking->setFont(font);
        checkBox_parking->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_parking->setTristate(false);
        checkBox_balcony = new QCheckBox(groupBox_7);
        checkBox_balcony->setObjectName(QString::fromUtf8("checkBox_balcony"));
        checkBox_balcony->setEnabled(false);
        checkBox_balcony->setGeometry(QRect(370, 45, 110, 25));
        checkBox_balcony->setFont(font);
        checkBox_balcony->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_balcony->setTristate(false);
        checkBox_storage = new QCheckBox(groupBox_7);
        checkBox_storage->setObjectName(QString::fromUtf8("checkBox_storage"));
        checkBox_storage->setEnabled(false);
        checkBox_storage->setGeometry(QRect(499, 105, 101, 25));
        checkBox_storage->setFont(font);
        checkBox_storage->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_storage->setTristate(false);
        checkBox_renew = new QCheckBox(groupBox_7);
        checkBox_renew->setObjectName(QString::fromUtf8("checkBox_renew"));
        checkBox_renew->setEnabled(false);
        checkBox_renew->setGeometry(QRect(619, 105, 91, 25));
        checkBox_renew->setFont(font);
        checkBox_renew->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_renew->setTristate(false);
        checkBox_wallpaper = new QCheckBox(groupBox_7);
        checkBox_wallpaper->setObjectName(QString::fromUtf8("checkBox_wallpaper"));
        checkBox_wallpaper->setEnabled(false);
        checkBox_wallpaper->setGeometry(QRect(370, 75, 110, 25));
        checkBox_wallpaper->setFont(font);
        checkBox_wallpaper->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_wallpaper->setTristate(false);
        checkBox_furnished = new QCheckBox(groupBox_7);
        checkBox_furnished->setObjectName(QString::fromUtf8("checkBox_furnished"));
        checkBox_furnished->setEnabled(false);
        checkBox_furnished->setGeometry(QRect(619, 75, 91, 25));
        checkBox_furnished->setFont(font);
        checkBox_furnished->setCursor(QCursor(Qt::PointingHandCursor));
        checkBox_furnished->setTristate(false);
        comboBox_room = new QComboBox(groupBox_7);
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->addItem(QString());
        comboBox_room->setObjectName(QString::fromUtf8("comboBox_room"));
        comboBox_room->setEnabled(false);
        comboBox_room->setGeometry(QRect(20, 45, 91, 30));
        comboBox_room->setFont(font);
        comboBox_room->setFrame(true);
        comboBox_build = new QComboBox(groupBox_7);
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->addItem(QString());
        comboBox_build->setObjectName(QString::fromUtf8("comboBox_build"));
        comboBox_build->setEnabled(false);
        comboBox_build->setGeometry(QRect(180, 45, 91, 30));
        comboBox_build->setFont(font);
        comboBox_build->setFrame(true);
        comboBox_floor = new QComboBox(groupBox_7);
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->addItem(QString());
        comboBox_floor->setObjectName(QString::fromUtf8("comboBox_floor"));
        comboBox_floor->setEnabled(false);
        comboBox_floor->setGeometry(QRect(180, 90, 91, 30));
        comboBox_floor->setFont(font);
        comboBox_floor->setToolTipDuration(-1);
        comboBox_floor->setFrame(true);
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(280, 45, 61, 31));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_22->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(280, 90, 61, 31));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_23->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_24 = new QLabel(groupBox_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(120, 45, 41, 31));
        label_24->setFont(font);
        label_24->setStyleSheet(QString::fromUtf8("background-color: none;"));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_create_ad = new QPushButton(page_create_ad);
        pushButton_create_ad->setObjectName(QString::fromUtf8("pushButton_create_ad"));
        pushButton_create_ad->setGeometry(QRect(10, 70, 331, 41));
        pushButton_create_ad->setFont(font);
        pushButton_create_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_create_ad->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_pic_path = new QLabel(page_create_ad);
        label_pic_path->setObjectName(QString::fromUtf8("label_pic_path"));
        label_pic_path->setGeometry(QRect(0, 0, 391, 31));
        label_pic_path->setFont(font);
        label_pic_path->setStyleSheet(QString::fromUtf8(""));
        label_pic_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_id_hidden = new QLabel(page_create_ad);
        label_ad_id_hidden->setObjectName(QString::fromUtf8("label_ad_id_hidden"));
        label_ad_id_hidden->setGeometry(QRect(320, 10, 391, 31));
        label_ad_id_hidden->setFont(font);
        label_ad_id_hidden->setStyleSheet(QString::fromUtf8(""));
        label_ad_id_hidden->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        pushButton_edit_ad = new QPushButton(page_create_ad);
        pushButton_edit_ad->setObjectName(QString::fromUtf8("pushButton_edit_ad"));
        pushButton_edit_ad->setGeometry(QRect(10, 70, 331, 41));
        pushButton_edit_ad->setFont(font);
        pushButton_edit_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_edit_ad->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        stackedWidget->addWidget(page_create_ad);
        label_ad_id_hidden->raise();
        label_pic_path->raise();
        label_4->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        label_5->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_7->raise();
        pushButton_edit_ad->raise();
        pushButton_create_ad->raise();
        page_my_ads = new QWidget();
        page_my_ads->setObjectName(QString::fromUtf8("page_my_ads"));
        label_25 = new QLabel(page_my_ads);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, -1, 741, 61));
        label_25->setFont(font3);
        label_25->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0; color: white;"));
        label_25->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(page_my_ads);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 140, 721, 541));
        tableWidget->setFont(font1);
        tableWidget->setLayoutDirection(Qt::RightToLeft);
        tableWidget->setStyleSheet(QString::fromUtf8("QHeaderView {  \n"
"	font-family: \"B Titr\";\n"
"	font-size: 14pt;\n"
"}"));
        tableWidget->setFrameShape(QFrame::Panel);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideRight);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setWordWrap(true);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(150);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setMinimumSectionSize(50);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setHighlightSections(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);
        label_26 = new QLabel(page_my_ads);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(180, 60, 551, 71));
        label_26->setFont(font);
        label_26->setStyleSheet(QString::fromUtf8(""));
        label_26->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_26->setWordWrap(true);
        groupBox = new QGroupBox(page_my_ads);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 161, 61));
        groupBox->setFont(font);
        groupBox->setLayoutDirection(Qt::RightToLeft);
        pushButton_see_my_ad = new QPushButton(groupBox);
        pushButton_see_my_ad->setObjectName(QString::fromUtf8("pushButton_see_my_ad"));
        pushButton_see_my_ad->setGeometry(QRect(110, 10, 40, 40));
        QFont font7;
        font7.setPointSize(12);
        pushButton_see_my_ad->setFont(font7);
        pushButton_see_my_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_see_my_ad->setStyleSheet(QString::fromUtf8("border: 1px solid #6AB1ED;\n"
"border-radius: 20px;\n"
"color: #020308; \n"
"padding-bottom: 4px;\n"
"padding-left: 4px;"));
        pushButton_see_my_ad->setFlat(true);
        pushButton_delete_my_ad = new QPushButton(groupBox);
        pushButton_delete_my_ad->setObjectName(QString::fromUtf8("pushButton_delete_my_ad"));
        pushButton_delete_my_ad->setGeometry(QRect(10, 10, 40, 40));
        pushButton_delete_my_ad->setFont(font7);
        pushButton_delete_my_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_delete_my_ad->setStyleSheet(QString::fromUtf8("border: 1px solid #6AB1ED;\n"
"border-radius: 20px;\n"
"color: #020308; \n"
"padding-bottom: 4px;\n"
"padding-left: 4px;"));
        pushButton_delete_my_ad->setFlat(true);
        pushButton_edit_my_ad = new QPushButton(groupBox);
        pushButton_edit_my_ad->setObjectName(QString::fromUtf8("pushButton_edit_my_ad"));
        pushButton_edit_my_ad->setGeometry(QRect(60, 10, 40, 40));
        pushButton_edit_my_ad->setFont(font7);
        pushButton_edit_my_ad->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_edit_my_ad->setStyleSheet(QString::fromUtf8("border: 1px solid #6AB1ED;\n"
"border-radius: 20px;\n"
"color: #020308; \n"
"padding-bottom: 4px;\n"
"padding-left: 4px;"));
        pushButton_edit_my_ad->setFlat(true);
        stackedWidget->addWidget(page_my_ads);
        page_see_all_ads = new QWidget();
        page_see_all_ads->setObjectName(QString::fromUtf8("page_see_all_ads"));
        label_28 = new QLabel(page_see_all_ads);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(0, 0, 741, 61));
        label_28->setFont(font3);
        label_28->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0; color: white;"));
        label_28->setAlignment(Qt::AlignCenter);
        listWidget_all = new QListWidget(page_see_all_ads);
        listWidget_all->setObjectName(QString::fromUtf8("listWidget_all"));
        listWidget_all->setGeometry(QRect(0, 70, 731, 611));
        listWidget_all->setFont(font);
        listWidget_all->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget_all->setLayoutDirection(Qt::LeftToRight);
        listWidget_all->setFrameShadow(QFrame::Raised);
        listWidget_all->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_all->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget_all->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget_all->setViewMode(QListView::ListMode);
        listWidget_all->setWordWrap(true);
        listWidget_all->setItemAlignment(Qt::AlignCenter);
        listWidget_all->setSortingEnabled(false);
        stackedWidget->addWidget(page_see_all_ads);
        page_detail_ad = new QWidget();
        page_detail_ad->setObjectName(QString::fromUtf8("page_detail_ad"));
        label_41 = new QLabel(page_detail_ad);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(650, 10, 81, 50));
        label_41->setFont(font);
        label_41->setLayoutDirection(Qt::RightToLeft);
        label_41->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_41->setAlignment(Qt::AlignCenter);
        label_43 = new QLabel(page_detail_ad);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(400, 160, 81, 50));
        label_43->setFont(font);
        label_43->setLayoutDirection(Qt::RightToLeft);
        label_43->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_43->setAlignment(Qt::AlignCenter);
        label_44 = new QLabel(page_detail_ad);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(150, 160, 91, 50));
        label_44->setFont(font);
        label_44->setLayoutDirection(Qt::RightToLeft);
        label_44->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_44->setAlignment(Qt::AlignCenter);
        label_45 = new QLabel(page_detail_ad);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(650, 220, 81, 50));
        label_45->setFont(font);
        label_45->setLayoutDirection(Qt::RightToLeft);
        label_45->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_45->setAlignment(Qt::AlignCenter);
        label_53 = new QLabel(page_detail_ad);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 10, 51, 50));
        label_53->setFont(font);
        label_53->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_53->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_type = new QLabel(page_detail_ad);
        label_ad_type->setObjectName(QString::fromUtf8("label_ad_type"));
        label_ad_type->setGeometry(QRect(250, 160, 141, 50));
        label_ad_type->setFont(font);
        label_ad_type->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_type->setAlignment(Qt::AlignCenter);
        label_ad_category = new QLabel(page_detail_ad);
        label_ad_category->setObjectName(QString::fromUtf8("label_ad_category"));
        label_ad_category->setGeometry(QRect(10, 160, 131, 50));
        label_ad_category->setFont(font);
        label_ad_category->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_category->setAlignment(Qt::AlignCenter);
        label_ad_property_type = new QLabel(page_detail_ad);
        label_ad_property_type->setObjectName(QString::fromUtf8("label_ad_property_type"));
        label_ad_property_type->setGeometry(QRect(490, 220, 151, 50));
        label_ad_property_type->setFont(font);
        label_ad_property_type->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_property_type->setAlignment(Qt::AlignCenter);
        label_ad_address = new QLabel(page_detail_ad);
        label_ad_address->setObjectName(QString::fromUtf8("label_ad_address"));
        label_ad_address->setGeometry(QRect(10, 220, 381, 50));
        label_ad_address->setFont(font);
        label_ad_address->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_address->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_58 = new QLabel(page_detail_ad);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(400, 220, 81, 50));
        label_58->setFont(font);
        label_58->setLayoutDirection(Qt::RightToLeft);
        label_58->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_58->setAlignment(Qt::AlignCenter);
        label_59 = new QLabel(page_detail_ad);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(650, 340, 81, 81));
        label_59->setFont(font);
        label_59->setLayoutDirection(Qt::RightToLeft);
        label_59->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_59->setAlignment(Qt::AlignCenter);
        label_61 = new QLabel(page_detail_ad);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(650, 430, 81, 81));
        label_61->setFont(font);
        label_61->setLayoutDirection(Qt::RightToLeft);
        label_61->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_61->setAlignment(Qt::AlignCenter);
        label_ad_price = new QLabel(page_detail_ad);
        label_ad_price->setObjectName(QString::fromUtf8("label_ad_price"));
        label_ad_price->setGeometry(QRect(360, 430, 281, 81));
        label_ad_price->setFont(font);
        label_ad_price->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_price->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_price->setWordWrap(true);
        label_ad_meter = new QLabel(page_detail_ad);
        label_ad_meter->setObjectName(QString::fromUtf8("label_ad_meter"));
        label_ad_meter->setGeometry(QRect(360, 340, 281, 81));
        label_ad_meter->setFont(font);
        label_ad_meter->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_meter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_meter->setWordWrap(true);
        label_ad_pic = new QLabel(page_detail_ad);
        label_ad_pic->setObjectName(QString::fromUtf8("label_ad_pic"));
        label_ad_pic->setGeometry(QRect(10, 340, 340, 340));
        label_ad_pic->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0;"));
        label_ad_pic->setScaledContents(true);
        label_ad_pic->setAlignment(Qt::AlignCenter);
        label_60 = new QLabel(page_detail_ad);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(650, 570, 81, 111));
        label_60->setFont(font);
        label_60->setLayoutDirection(Qt::RightToLeft);
        label_60->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_60->setAlignment(Qt::AlignCenter);
        label_60->setWordWrap(true);
        label_ad_detail = new QLabel(page_detail_ad);
        label_ad_detail->setObjectName(QString::fromUtf8("label_ad_detail"));
        label_ad_detail->setGeometry(QRect(360, 570, 281, 111));
        label_ad_detail->setFont(font);
        label_ad_detail->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_detail->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_detail->setWordWrap(true);
        label_46 = new QLabel(page_detail_ad);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(650, 280, 81, 50));
        label_46->setFont(font);
        label_46->setLayoutDirection(Qt::RightToLeft);
        label_46->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_46->setAlignment(Qt::AlignCenter);
        label_ad_build = new QLabel(page_detail_ad);
        label_ad_build->setObjectName(QString::fromUtf8("label_ad_build"));
        label_ad_build->setGeometry(QRect(490, 280, 151, 50));
        label_ad_build->setFont(font);
        label_ad_build->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_build->setAlignment(Qt::AlignCenter);
        label_ad_room = new QLabel(page_detail_ad);
        label_ad_room->setObjectName(QString::fromUtf8("label_ad_room"));
        label_ad_room->setGeometry(QRect(10, 280, 141, 50));
        label_ad_room->setFont(font);
        label_ad_room->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_room->setAlignment(Qt::AlignCenter);
        label_ad_floor = new QLabel(page_detail_ad);
        label_ad_floor->setObjectName(QString::fromUtf8("label_ad_floor"));
        label_ad_floor->setGeometry(QRect(250, 280, 141, 50));
        label_ad_floor->setFont(font);
        label_ad_floor->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_floor->setAlignment(Qt::AlignCenter);
        label_48 = new QLabel(page_detail_ad);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(160, 280, 81, 50));
        label_48->setFont(font);
        label_48->setLayoutDirection(Qt::RightToLeft);
        label_48->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_48->setAlignment(Qt::AlignCenter);
        label_47 = new QLabel(page_detail_ad);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(400, 280, 81, 50));
        label_47->setFont(font);
        label_47->setLayoutDirection(Qt::RightToLeft);
        label_47->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_47->setAlignment(Qt::AlignCenter);
        label_mine = new QLabel(page_detail_ad);
        label_mine->setObjectName(QString::fromUtf8("label_mine"));
        label_mine->setGeometry(QRect(11, 11, 49, 48));
        label_mine->setFont(font);
        label_mine->setCursor(QCursor(Qt::OpenHandCursor));
        label_mine->setLayoutDirection(Qt::RightToLeft);
        label_mine->setStyleSheet(QString::fromUtf8("padding-bottom: 2px;\n"
"padding-left: 2px;"));
        label_mine->setAlignment(Qt::AlignCenter);
        label_ad_name = new QLabel(page_detail_ad);
        label_ad_name->setObjectName(QString::fromUtf8("label_ad_name"));
        label_ad_name->setGeometry(QRect(60, 10, 581, 50));
        label_ad_name->setFont(font);
        label_ad_name->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_id = new QLabel(page_detail_ad);
        label_ad_id->setObjectName(QString::fromUtf8("label_ad_id"));
        label_ad_id->setGeometry(QRect(490, 160, 151, 50));
        label_ad_id->setFont(font);
        label_ad_id->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_id->setAlignment(Qt::AlignCenter);
        label_49 = new QLabel(page_detail_ad);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(650, 160, 81, 50));
        QFont font8;
        font8.setFamily(QString::fromUtf8("B Nazanin"));
        font8.setPointSize(10);
        font8.setBold(true);
        font8.setWeight(75);
        label_49->setFont(font8);
        label_49->setLayoutDirection(Qt::RightToLeft);
        label_49->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_49->setAlignment(Qt::AlignCenter);
        label_70 = new QLabel(page_detail_ad);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(650, 70, 81, 81));
        label_70->setFont(font);
        label_70->setLayoutDirection(Qt::RightToLeft);
        label_70->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_70->setAlignment(Qt::AlignCenter);
        label_70->setWordWrap(true);
        label_ad_owner = new QLabel(page_detail_ad);
        label_ad_owner->setObjectName(QString::fromUtf8("label_ad_owner"));
        label_ad_owner->setGeometry(QRect(10, 70, 631, 81));
        label_ad_owner->setFont(font);
        label_ad_owner->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_owner->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_owner->setWordWrap(true);
        label_62 = new QLabel(page_detail_ad);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        label_62->setGeometry(QRect(650, 520, 81, 41));
        label_62->setFont(font8);
        label_62->setLayoutDirection(Qt::RightToLeft);
        label_62->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_62->setAlignment(Qt::AlignCenter);
        label_ad_price_per_meter = new QLabel(page_detail_ad);
        label_ad_price_per_meter->setObjectName(QString::fromUtf8("label_ad_price_per_meter"));
        label_ad_price_per_meter->setGeometry(QRect(360, 520, 281, 41));
        label_ad_price_per_meter->setFont(font);
        label_ad_price_per_meter->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_ad_price_per_meter->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_ad_price_per_meter->setWordWrap(true);
        stackedWidget->addWidget(page_detail_ad);
        label_41->raise();
        label_43->raise();
        label_44->raise();
        label_45->raise();
        label_53->raise();
        label_ad_type->raise();
        label_ad_category->raise();
        label_ad_property_type->raise();
        label_ad_address->raise();
        label_58->raise();
        label_59->raise();
        label_61->raise();
        label_ad_price->raise();
        label_ad_meter->raise();
        label_ad_pic->raise();
        label_60->raise();
        label_ad_detail->raise();
        label_46->raise();
        label_ad_build->raise();
        label_ad_room->raise();
        label_ad_floor->raise();
        label_48->raise();
        label_47->raise();
        label_ad_name->raise();
        label_mine->raise();
        label_ad_id->raise();
        label_49->raise();
        label_70->raise();
        label_ad_owner->raise();
        label_62->raise();
        label_ad_price_per_meter->raise();
        page_search_ads = new QWidget();
        page_search_ads->setObjectName(QString::fromUtf8("page_search_ads"));
        label_29 = new QLabel(page_search_ads);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(0, 0, 741, 61));
        label_29->setFont(font3);
        label_29->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0; color: white;"));
        label_29->setAlignment(Qt::AlignCenter);
        groupBox_8 = new QGroupBox(page_search_ads);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(250, 120, 481, 95));
        groupBox_8->setFont(font4);
        groupBox_8->setLayoutDirection(Qt::RightToLeft);
        lineEdit_search = new QLineEdit(groupBox_8);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(10, 45, 461, 31));
        lineEdit_search->setFont(font1);
        groupBox_9 = new QGroupBox(page_search_ads);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 120, 231, 95));
        groupBox_9->setFont(font4);
        groupBox_9->setLayoutDirection(Qt::RightToLeft);
        radioButton_search_name = new QRadioButton(groupBox_9);
        radioButton_search_name->setObjectName(QString::fromUtf8("radioButton_search_name"));
        radioButton_search_name->setGeometry(QRect(130, 45, 91, 31));
        radioButton_search_name->setFont(font);
        radioButton_search_name->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_search_name->setLayoutDirection(Qt::RightToLeft);
        radioButton_search_name->setChecked(true);
        radioButton_search_address = new QRadioButton(groupBox_9);
        radioButton_search_address->setObjectName(QString::fromUtf8("radioButton_search_address"));
        radioButton_search_address->setGeometry(QRect(10, 45, 111, 31));
        radioButton_search_address->setFont(font);
        radioButton_search_address->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_search_address->setLayoutDirection(Qt::RightToLeft);
        pushButton_search = new QPushButton(page_search_ads);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));
        pushButton_search->setGeometry(QRect(10, 70, 331, 41));
        pushButton_search->setFont(font);
        pushButton_search->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_search->setStyleSheet(QString::fromUtf8("border-radius: 6px;\n"
"color: white;\n"
"border: 1px solid #1C6B2B;\n"
"background-color: #1C6B2B;"));
        label_27 = new QLabel(page_search_ads);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(340, 60, 391, 61));
        label_27->setFont(font);
        label_27->setStyleSheet(QString::fromUtf8(""));
        label_27->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_10 = new QGroupBox(page_search_ads);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 230, 721, 451));
        groupBox_10->setFont(font4);
        groupBox_10->setLayoutDirection(Qt::RightToLeft);
        listWidget_search = new QListWidget(groupBox_10);
        listWidget_search->setObjectName(QString::fromUtf8("listWidget_search"));
        listWidget_search->setGeometry(QRect(10, 40, 701, 401));
        listWidget_search->setFont(font);
        listWidget_search->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        listWidget_search->setLayoutDirection(Qt::LeftToRight);
        listWidget_search->setFrameShadow(QFrame::Raised);
        listWidget_search->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget_search->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget_search->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget_search->setViewMode(QListView::ListMode);
        listWidget_search->setWordWrap(true);
        listWidget_search->setItemAlignment(Qt::AlignCenter);
        listWidget_search->setSortingEnabled(false);
        stackedWidget->addWidget(page_search_ads);
        groupBox_8->raise();
        groupBox_9->raise();
        pushButton_search->raise();
        label_27->raise();
        groupBox_10->raise();
        label_29->raise();
        page_detail = new QWidget();
        page_detail->setObjectName(QString::fromUtf8("page_detail"));
        label_user_username = new QLabel(page_detail);
        label_user_username->setObjectName(QString::fromUtf8("label_user_username"));
        label_user_username->setGeometry(QRect(10, 150, 631, 50));
        label_user_username->setFont(font);
        label_user_username->setStyleSheet(QString::fromUtf8("background-color: #FDFFE6; \n"
"border: 1px solid #1C6B2B;"));
        label_user_username->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_user_username->setWordWrap(true);
        label_71 = new QLabel(page_detail);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        label_71->setGeometry(QRect(650, 150, 81, 50));
        label_71->setFont(font);
        label_71->setLayoutDirection(Qt::RightToLeft);
        label_71->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_71->setAlignment(Qt::AlignCenter);
        label_71->setWordWrap(true);
        label_user_name = new QLabel(page_detail);
        label_user_name->setObjectName(QString::fromUtf8("label_user_name"));
        label_user_name->setGeometry(QRect(10, 80, 631, 50));
        label_user_name->setFont(font);
        label_user_name->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_user_name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_42 = new QLabel(page_detail);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(650, 80, 81, 50));
        label_42->setFont(font);
        label_42->setLayoutDirection(Qt::RightToLeft);
        label_42->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_42->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(page_detail);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(0, 0, 741, 61));
        label_30->setFont(font3);
        label_30->setStyleSheet(QString::fromUtf8("background-color: #A0A0A0; color: white;"));
        label_30->setAlignment(Qt::AlignCenter);
        label_user_email = new QLabel(page_detail);
        label_user_email->setObjectName(QString::fromUtf8("label_user_email"));
        label_user_email->setGeometry(QRect(10, 220, 631, 50));
        label_user_email->setFont(font);
        label_user_email->setStyleSheet(QString::fromUtf8("background-color: #DEF1E6; \n"
"border: 1px solid #1C6B2B;"));
        label_user_email->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_50 = new QLabel(page_detail);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(650, 220, 81, 50));
        label_50->setFont(font);
        label_50->setLayoutDirection(Qt::RightToLeft);
        label_50->setStyleSheet(QString::fromUtf8("background-color: #FDF5E6; \n"
"border: 1px solid #1C6B2B;"));
        label_50->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page_detail);
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        toolBox->raise();
        label_3->raise();
        label->raise();
        stackedWidget->raise();

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);
        comboBox_build->setCurrentIndex(53);
        comboBox_floor->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\330\263\330\247\331\205\330\247\331\206\331\207 \331\205\330\257\333\214\330\261\333\214\330\252 \330\247\331\205\331\204\330\247\332\251 \331\210 \331\205\330\263\330\252\330\272\331\204\330\247\330\252", nullptr));
        pushButton_page_show_my_ads->setText(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\247\331\207\330\257\331\207 \330\242\332\257\331\207\333\214 \331\205\331\206", nullptr));
        pushButton_page_create_ad->setText(QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \330\242\332\257\331\207\333\214 \330\254\330\257\333\214\330\257", nullptr));
        pushButton_page_show_all_ads->setText(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\247\331\207\330\257\331\207 \331\207\331\205\331\207 \330\242\332\257\331\207\333\214 \331\207\330\247", nullptr));
        pushButton_page_search_ads->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252\330\254\331\210 \330\257\330\261 \330\242\332\257\331\207\333\214 \331\207\330\247", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_1), QCoreApplication::translate("MainWindow", "                 \330\242\332\257\331\207\333\214 \331\207\330\247", nullptr));
        pushButton_office->setText(QCoreApplication::translate("MainWindow", "\330\247\330\257\330\247\330\261\333\214", nullptr));
        pushButton_non_residential->setText(QCoreApplication::translate("MainWindow", "\330\272\333\214\330\261\331\205\330\263\332\251\331\210\331\206\333\214", nullptr));
        pushButton_commercial->setText(QCoreApplication::translate("MainWindow", "\330\252\330\254\330\247\330\261\333\214", nullptr));
        pushButton_residential->setText(QCoreApplication::translate("MainWindow", "\331\205\330\263\332\251\331\210\331\206\333\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "             \330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214", nullptr));
        pushButton_page_edit_account->setText(QCoreApplication::translate("MainWindow", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        pushButton_logout->setText(QCoreApplication::translate("MainWindow", "\330\256\330\261\331\210\330\254", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QCoreApplication::translate("MainWindow", "        \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "\330\263\330\247\331\205\330\247\331\206\331\207 \331\205\330\257\333\214\330\261\333\214\330\252 \330\247\331\205\331\204\330\247\332\251 \331\210 \331\205\330\263\330\252\330\272\331\204\330\247\330\252", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \330\242\332\257\331\207\333\214 \330\254\330\257\333\214\330\257", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "* \331\206\331\210\330\271 \330\242\332\257\331\207\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_sell->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\242\332\257\331\207\333\214 \331\201\330\261\331\210\330\264</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        radioButton_type_sell->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        radioButton_type_sell->setText(QCoreApplication::translate("MainWindow", "\331\201\330\261\331\210\330\264", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_exchange->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\242\332\257\331\207\333\214 \331\205\330\271\330\247\331\210\330\266\331\207</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        radioButton_type_exchange->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        radioButton_type_exchange->setText(QCoreApplication::translate("MainWindow", "\331\205\330\271\330\247\331\210\330\266\331\207", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_rent->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\242\332\257\331\207\333\214 \330\247\330\254\330\247\330\261\331\207</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        radioButton_type_rent->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        radioButton_type_rent->setText(QCoreApplication::translate("MainWindow", "\330\247\330\254\330\247\330\261\331\207", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "* \330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_category_residential->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\331\204\332\251\333\214 \332\251\331\207 \331\202\330\247\330\250\331\204 \330\263\332\251\331\210\331\206\330\252 \330\250\330\247\330\264\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_category_residential->setText(QCoreApplication::translate("MainWindow", "\331\205\330\263\332\251\331\210\331\206\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_category_non_residential->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\331\204\332\251\333\214 \332\251\331\207 \331\202\330\247\330\250\331\204 \330\263\332\251\331\210\331\206\330\252 \331\206\330\250\330\247\330\264\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        radioButton_category_non_residential->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        radioButton_category_non_residential->setText(QCoreApplication::translate("MainWindow", "\330\272\333\214\330\261\331\205\330\263\332\251\331\210\331\206\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_category_office->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\210\330\247\330\255\330\257\333\214 \332\251\331\207 \330\247\330\272\331\204\330\250 \330\250\330\265\331\210\330\261\330\252 \330\242\331\276\330\247\330\261\330\252\331\205\330\247\331\206\333\214 \330\250\330\247\330\264\330\257 \331\210 \331\205\330\254\331\210\330\262 \331\204\330\247\330\262\331\205 \330\247\330\257\330\247\330\261\333\214 \330\261\330\247 \330\247\330\262 \330\264\331\207\330\261\330\257\330\247\330\261\333\214 \331\205\331\206\330\267\331\202\331\207 \330\247\330\256\330\260 \332\251\330\261\330\257\331\207 \330\250\330\247\330\264\330\257 \332\251\331\207 \330\250\330\265\331\210\330\261\330\252 \330\247\330\257\330\247\330\261\333\214 \330\247\330\263\330\252\331\201\330\247\330\257\331\207 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_category_office->setText(QCoreApplication::translate("MainWindow", "\330\247\330\257\330\247\330\261\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_category_commercial->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\205\330\255\331\204\333\214 \332\251\331\207 \330\257\330\261 \333\214\332\251 \331\205\331\204\332\251 \331\205\330\264\330\261\331\201 \330\250\331\207 \330\256\333\214\330\247\330\250\330\247\331\206 \330\247\330\263\330\252 \331\210 \330\257\330\261 \330\242\331\206 \330\247\331\202\330\257\330\247\331\205 \330\250\331\207 \332\251\330\247\330\261 \331\207\330\247\333\214 \330\252\330\254\330\247\330\261\333\214 \331\205\333\214 \332\251\331\206\331\206\330\257 \331\210 \330\257\330\247\330\261\330\247\333\214 \331\205\330\254\331\210\330\262 \330\252\330\254\330\247\330\261\333\214 \330\247\330\262 \330\264\331\207\330\261\330\257\330\247\330\261\333\214 \331\205\330\261\330\250\331\210\330\267\331\207 \331\205\333\214 \330\250\330\247\330\264\331\206\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_category_commercial->setText(QCoreApplication::translate("MainWindow", "\330\252\330\254\330\247\330\261\333\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "* \331\206\331\210\330\271 \331\205\331\204\332\251", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_land->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600; vertical-align:super;\">\330\250\331\207 \331\205\330\255\331\204\333\214 \332\251\331\207 \330\257\330\261\331\210\331\206 \330\242\331\206 \331\207\333\214\332\206 \332\257\331\210\331\206\331\207 \330\250\331\206\330\247\333\214\333\214 \330\247\330\255\330\257\330\247\330\253 \331\206\330\264\330\257\331\207 \330\250\330\247\330\264\330\257 \330\262\331\205\333\214\331\206 \332\257\331\201\330\252\331\207 \331\205\333\214 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_land->setText(QCoreApplication::translate("MainWindow", "\330\262\331\205\333\214\331\206", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_kolangi->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\205\331\204\332\251\333\214 \330\247\330\267\331\204\330\247\331\202 \331\205\333\214\330\264\331\210\330\257 \332\251\331\207 \330\272\333\214\330\261 \331\202\330\247\330\250\331\204 \330\247\330\263\330\252\331\201\330\247\330\257\331\207 \330\250\331\210\330\257\331\207 \331\210 \331\205\333\214 \330\250\330\247\333\214\330\263\330\252 \331\205\330\254\330\257\330\257\330\247 \330\252\330\256\330\261\333\214\330\250 \331\210 \331\206\331\210\330\263\330\247\330\262\333\214 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_kolangi->setText(QCoreApplication::translate("MainWindow", "\332\251\331\204\331\206\332\257\333\214", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_garden->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\205\330\255\331\204\333\214 \332\251\331\207 \330\250\331\206\330\247\333\214\333\214 \332\251\331\210\332\206\332\251 \330\257\330\261 \330\242\331\206 \331\210\330\254\331\210\330\257 \330\257\330\247\330\264\330\252\331\207 \331\210 \330\250\330\247\331\202\333\214 \331\205\331\204\332\251 \330\257\330\247\330\261\330\247\333\214 \330\257\330\261\330\256\330\252 \331\207\330\247\333\214 \331\201\330\261\330\247\331\210\330\247\331\206 \330\250\330\247\330\264\330\257 \330\250\330\247\330\272 \332\257\331\201\330\252\331\207 \331\205\333\214 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_garden->setText(QCoreApplication::translate("MainWindow", "\330\250\330\247\330\272", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_apartment->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\205\330\254\331\205\331\210\330\271 \331\210\330\247\330\255\330\257\331\207\330\247\333\214\333\214 \332\251\331\207 \330\257\330\261 \333\214\332\251 \333\214\330\247 \332\206\331\206\330\257 \330\263\330\247\330\256\330\252\331\205\330\247\331\206 \331\210\330\247\331\202\330\271 \330\264\330\257\331\207 \331\210 \330\247\330\262 \331\206\330\270\330\261 \330\261\330\247\331\207 \331\276\331\204\331\207\330\214 \331\210\330\261\331\210\330\257\333\214 \330\247\330\265\331\204\333\214 \331\210 \332\257\330\247\331\207\333\214 \331\276\330\247\330\261\332\251\333\214\331\206\332\257 \331\210 \330\255\333\214\330\247\330\267 \330\250\330\247 \333\214\332\251\330\257\333\214\332\257\330\261 \331\205\330\264\330\252\330\261\332\251 \331\207\330\263\330\252\331\206\330\257 \330\250\331\206\330\247\333\214 \330\242\331\276\330\247\330\261\330\252\331\205\330\247\331\206\333\214 \332\257\331\201\330\252\331"
                        "\207 \331\205\333\214 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_apartment->setText(QCoreApplication::translate("MainWindow", "\330\242\331\276\330\247\330\261\330\252\331\205\330\247\331\206", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_office->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\331\204\332\251\333\214 \332\251\331\207 \331\205\330\254\331\210\330\262 \330\247\330\257\330\247\330\261\333\214 \330\257\330\247\330\264\330\252\331\207 \330\250\330\247\330\264\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_office->setText(QCoreApplication::translate("MainWindow", "\330\257\331\201\330\252\330\261\332\251\330\247\330\261", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_clinic->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\331\204\332\251\333\214 \332\251\331\207 \331\205\330\254\331\210\330\262 \330\247\330\257\330\247\330\261\333\214 \330\257\330\247\330\264\330\252\331\207 \330\250\330\247\330\264\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_clinic->setText(QCoreApplication::translate("MainWindow", "\331\205\330\267\330\250", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_shop->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\330\272\330\247\330\262\331\207\330\247 \331\207\331\205\330\247\331\206 \331\205\330\264\330\256\330\265\330\247\330\252 \331\205\331\204\332\251 \331\207\330\247\333\214 \330\252\330\254\330\247\330\261\333\214 \330\261\330\247 \330\257\330\247\330\261\330\257 \330\250\330\247 \330\247\333\214\331\206 \331\201\330\261\331\202 \332\251\331\207 \333\214\332\251 \331\205\330\272\330\247\330\262\331\207 \331\205\333\214 \330\250\330\247\333\214\330\263\330\252 \330\255\330\252\331\205\330\247 \330\250\331\207 \330\250\333\214\330\261\331\210\331\206 \330\257\330\263\330\252\330\261\330\263\333\214 \331\205\330\263\330\252\330\272\331\204 \330\257\330\247\330\264\330\252\331\207 \330\250\330\247\330\264\330\257 \331\210 \330\257\330\247\330\256\331\204 \330\242\331\206 \332\251\330\247\331\205\331\204\330\247 \330\257\333\214\330\257\331\207 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_shop->setText(QCoreApplication::translate("MainWindow", "\331\205\330\272\330\247\330\262\331\207", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_storage->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\330\255\331\204\333\214 \332\251\331\207 \330\254\331\207\330\252 \330\257\331\276\331\210 \332\251\330\261\330\257\331\206 \330\247\330\254\331\206\330\247\330\263 \330\250\331\207 \331\205\331\206\330\270\331\210\330\261\331\207\330\247\333\214 \331\205\330\256\330\252\331\204\331\201 \330\247\330\263\330\252\331\201\330\247\330\257\331\207 \331\205\333\214 \330\264\331\210\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_storage->setText(QCoreApplication::translate("MainWindow", "\330\247\331\206\330\250\330\247\330\261", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_workshop->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\331\205\330\255\331\204\333\214 \332\251\331\207 \330\257\330\261 \330\242\331\206 \332\251\330\247\330\261\332\257\330\261 \332\251\330\247\330\261 \331\205\333\214\332\251\331\206\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_workshop->setText(QCoreApplication::translate("MainWindow", "\332\251\330\247\330\261\332\257\330\247\331\207", nullptr));
#if QT_CONFIG(tooltip)
        radioButton_type_villa->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:12pt; font-weight:600;\">\330\250\331\207 \331\205\331\204\332\251 \331\207\330\247\333\214\333\214 \332\257\331\201\330\252\331\207 \331\205\333\214\330\264\331\210\330\257 \332\251\331\207 \330\271\331\205\330\257\330\252\330\247 \331\205\330\255\331\204 \330\262\331\206\330\257\332\257\333\214 \333\214\332\251 \333\214\330\247 \331\206\331\207\330\247\333\214\330\252\330\247 \333\262 \330\256\330\247\331\206\331\210\330\247\330\261 \330\250\330\247\330\264\330\257 \331\210 \330\257\330\247\330\261\330\247\333\214 \330\255\333\214\330\247\330\267 \330\250\330\247\330\264\330\257</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_type_villa->setText(QCoreApplication::translate("MainWindow", "\331\210\333\214\331\204\330\247\333\214\333\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\331\204\330\267\331\201\330\247 \331\205\331\210\330\247\330\261\330\257 \330\256\331\210\330\247\330\263\330\252\331\207 \330\264\330\257\331\207 \330\261\330\247 \330\252\332\251\331\205\333\214\331\204 \332\251\331\206\333\214\330\257.", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\256\330\265\330\247\330\252 \331\205\331\204\332\251", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\330\242\330\257\330\261\330\263*:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\331\205\330\252\330\261\330\247\332\230 \330\262\331\205\333\214\331\206*:", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\331\205\330\252\330\261\330\247\332\230 \330\263\330\247\330\256\330\252\331\205\330\247\331\206*:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\331\205\330\250\331\204\330\272 \331\210\330\257\333\214\330\271\331\207*:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\331\205\330\250\331\204\330\272 \330\247\330\254\330\247\330\261\331\207*:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\331\205\330\250\331\204\330\272 \332\251\331\204*:", nullptr));
        label_pic->setText(QString());
        pushButton_pic->setText(QCoreApplication::translate("MainWindow", "\330\247\331\206\330\252\330\256\330\247\330\250 \330\252\330\265\331\210\333\214\330\261", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252:", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "* \331\206\330\247\331\205 \330\242\332\257\331\207\333\214", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\331\205\331\210\330\247\330\261\330\257 \330\257\333\214\332\257\330\261", nullptr));
        checkBox_deed->setText(QCoreApplication::translate("MainWindow", "\330\263\331\206\330\257", nullptr));
        checkBox_elevator->setText(QCoreApplication::translate("MainWindow", "\330\242\330\263\330\247\331\206\330\263\331\210\330\261", nullptr));
        checkBox_parking->setText(QCoreApplication::translate("MainWindow", "\331\276\330\247\330\261\332\251\333\214\331\206\332\257", nullptr));
        checkBox_balcony->setText(QCoreApplication::translate("MainWindow", "\330\250\330\247\331\204\332\251\331\206/\330\252\330\261\330\247\330\263", nullptr));
        checkBox_storage->setText(QCoreApplication::translate("MainWindow", "\330\247\331\206\330\250\330\247\330\261\333\214", nullptr));
        checkBox_renew->setText(QCoreApplication::translate("MainWindow", "\331\206\331\210\330\263\330\247\330\262", nullptr));
        checkBox_wallpaper->setText(QCoreApplication::translate("MainWindow", "\332\251\330\247\330\272\330\260 \330\257\333\214\331\210\330\247\330\261\333\214", nullptr));
        checkBox_furnished->setText(QCoreApplication::translate("MainWindow", "\331\205\330\250\331\204\331\207", nullptr));
        comboBox_room->setItemText(0, QCoreApplication::translate("MainWindow", "\331\206\330\257\330\247\330\261\330\257", nullptr));
        comboBox_room->setItemText(1, QCoreApplication::translate("MainWindow", "\333\214\332\251", nullptr));
        comboBox_room->setItemText(2, QCoreApplication::translate("MainWindow", "\330\257\331\210", nullptr));
        comboBox_room->setItemText(3, QCoreApplication::translate("MainWindow", "\330\263\331\207", nullptr));
        comboBox_room->setItemText(4, QCoreApplication::translate("MainWindow", "\332\206\331\207\330\247\330\261", nullptr));
        comboBox_room->setItemText(5, QCoreApplication::translate("MainWindow", "\331\276\331\206\330\254", nullptr));
        comboBox_room->setItemText(6, QCoreApplication::translate("MainWindow", "\330\264\330\264", nullptr));
        comboBox_room->setItemText(7, QCoreApplication::translate("MainWindow", "\331\207\331\201\330\252", nullptr));
        comboBox_room->setItemText(8, QCoreApplication::translate("MainWindow", "\331\207\330\264\330\252", nullptr));
        comboBox_room->setItemText(9, QCoreApplication::translate("MainWindow", "\331\206\331\207", nullptr));
        comboBox_room->setItemText(10, QCoreApplication::translate("MainWindow", "\330\257\331\207", nullptr));

        comboBox_build->setItemText(0, QCoreApplication::translate("MainWindow", "1350", nullptr));
        comboBox_build->setItemText(1, QCoreApplication::translate("MainWindow", "1351", nullptr));
        comboBox_build->setItemText(2, QCoreApplication::translate("MainWindow", "1352", nullptr));
        comboBox_build->setItemText(3, QCoreApplication::translate("MainWindow", "1353", nullptr));
        comboBox_build->setItemText(4, QCoreApplication::translate("MainWindow", "1354", nullptr));
        comboBox_build->setItemText(5, QCoreApplication::translate("MainWindow", "1355", nullptr));
        comboBox_build->setItemText(6, QCoreApplication::translate("MainWindow", "1356", nullptr));
        comboBox_build->setItemText(7, QCoreApplication::translate("MainWindow", "1357", nullptr));
        comboBox_build->setItemText(8, QCoreApplication::translate("MainWindow", "1358", nullptr));
        comboBox_build->setItemText(9, QCoreApplication::translate("MainWindow", "1359", nullptr));
        comboBox_build->setItemText(10, QCoreApplication::translate("MainWindow", "1360", nullptr));
        comboBox_build->setItemText(11, QCoreApplication::translate("MainWindow", "1361", nullptr));
        comboBox_build->setItemText(12, QCoreApplication::translate("MainWindow", "1362", nullptr));
        comboBox_build->setItemText(13, QCoreApplication::translate("MainWindow", "1363", nullptr));
        comboBox_build->setItemText(14, QCoreApplication::translate("MainWindow", "1364", nullptr));
        comboBox_build->setItemText(15, QCoreApplication::translate("MainWindow", "1365", nullptr));
        comboBox_build->setItemText(16, QCoreApplication::translate("MainWindow", "1366", nullptr));
        comboBox_build->setItemText(17, QCoreApplication::translate("MainWindow", "1367", nullptr));
        comboBox_build->setItemText(18, QCoreApplication::translate("MainWindow", "1368", nullptr));
        comboBox_build->setItemText(19, QCoreApplication::translate("MainWindow", "1369", nullptr));
        comboBox_build->setItemText(20, QCoreApplication::translate("MainWindow", "1370", nullptr));
        comboBox_build->setItemText(21, QCoreApplication::translate("MainWindow", "1371", nullptr));
        comboBox_build->setItemText(22, QCoreApplication::translate("MainWindow", "1372", nullptr));
        comboBox_build->setItemText(23, QCoreApplication::translate("MainWindow", "1373", nullptr));
        comboBox_build->setItemText(24, QCoreApplication::translate("MainWindow", "1374", nullptr));
        comboBox_build->setItemText(25, QCoreApplication::translate("MainWindow", "1375", nullptr));
        comboBox_build->setItemText(26, QCoreApplication::translate("MainWindow", "1376", nullptr));
        comboBox_build->setItemText(27, QCoreApplication::translate("MainWindow", "1377", nullptr));
        comboBox_build->setItemText(28, QCoreApplication::translate("MainWindow", "1378", nullptr));
        comboBox_build->setItemText(29, QCoreApplication::translate("MainWindow", "1379", nullptr));
        comboBox_build->setItemText(30, QCoreApplication::translate("MainWindow", "1380", nullptr));
        comboBox_build->setItemText(31, QCoreApplication::translate("MainWindow", "1381", nullptr));
        comboBox_build->setItemText(32, QCoreApplication::translate("MainWindow", "1382", nullptr));
        comboBox_build->setItemText(33, QCoreApplication::translate("MainWindow", "1383", nullptr));
        comboBox_build->setItemText(34, QCoreApplication::translate("MainWindow", "1384", nullptr));
        comboBox_build->setItemText(35, QCoreApplication::translate("MainWindow", "1385", nullptr));
        comboBox_build->setItemText(36, QCoreApplication::translate("MainWindow", "1386", nullptr));
        comboBox_build->setItemText(37, QCoreApplication::translate("MainWindow", "1387", nullptr));
        comboBox_build->setItemText(38, QCoreApplication::translate("MainWindow", "1388", nullptr));
        comboBox_build->setItemText(39, QCoreApplication::translate("MainWindow", "1389", nullptr));
        comboBox_build->setItemText(40, QCoreApplication::translate("MainWindow", "1390", nullptr));
        comboBox_build->setItemText(41, QCoreApplication::translate("MainWindow", "1391", nullptr));
        comboBox_build->setItemText(42, QCoreApplication::translate("MainWindow", "1392", nullptr));
        comboBox_build->setItemText(43, QCoreApplication::translate("MainWindow", "1393", nullptr));
        comboBox_build->setItemText(44, QCoreApplication::translate("MainWindow", "1394", nullptr));
        comboBox_build->setItemText(45, QCoreApplication::translate("MainWindow", "1395", nullptr));
        comboBox_build->setItemText(46, QCoreApplication::translate("MainWindow", "1396", nullptr));
        comboBox_build->setItemText(47, QCoreApplication::translate("MainWindow", "1397", nullptr));
        comboBox_build->setItemText(48, QCoreApplication::translate("MainWindow", "1398", nullptr));
        comboBox_build->setItemText(49, QCoreApplication::translate("MainWindow", "1399", nullptr));
        comboBox_build->setItemText(50, QCoreApplication::translate("MainWindow", "1400", nullptr));
        comboBox_build->setItemText(51, QCoreApplication::translate("MainWindow", "1401", nullptr));
        comboBox_build->setItemText(52, QCoreApplication::translate("MainWindow", "1402", nullptr));
        comboBox_build->setItemText(53, QCoreApplication::translate("MainWindow", "1403", nullptr));

        comboBox_floor->setItemText(0, QCoreApplication::translate("MainWindow", "\330\262\333\214\330\261\330\262\331\205\333\214\331\206", nullptr));
        comboBox_floor->setItemText(1, QCoreApplication::translate("MainWindow", "\331\207\331\205\332\251\331\201", nullptr));
        comboBox_floor->setItemText(2, QCoreApplication::translate("MainWindow", "\330\247\331\210\331\204", nullptr));
        comboBox_floor->setItemText(3, QCoreApplication::translate("MainWindow", "\330\257\331\210\331\205", nullptr));
        comboBox_floor->setItemText(4, QCoreApplication::translate("MainWindow", "\330\263\331\210\331\205", nullptr));
        comboBox_floor->setItemText(5, QCoreApplication::translate("MainWindow", "\332\206\331\207\330\247\330\261\331\205", nullptr));
        comboBox_floor->setItemText(6, QCoreApplication::translate("MainWindow", "\331\276\331\206\330\254\331\205", nullptr));
        comboBox_floor->setItemText(7, QCoreApplication::translate("MainWindow", "\330\264\330\264\331\205", nullptr));
        comboBox_floor->setItemText(8, QCoreApplication::translate("MainWindow", "\331\207\331\201\330\252\331\205", nullptr));
        comboBox_floor->setItemText(9, QCoreApplication::translate("MainWindow", "\331\207\330\264\330\252\331\205", nullptr));
        comboBox_floor->setItemText(10, QCoreApplication::translate("MainWindow", "\331\206\331\207\331\205", nullptr));
        comboBox_floor->setItemText(11, QCoreApplication::translate("MainWindow", "\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(12, QCoreApplication::translate("MainWindow", "\333\214\330\247\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(13, QCoreApplication::translate("MainWindow", "\330\257\331\210\330\247\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(14, QCoreApplication::translate("MainWindow", "\330\263\333\214\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(15, QCoreApplication::translate("MainWindow", "\332\206\331\207\330\247\330\261\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(16, QCoreApplication::translate("MainWindow", "\331\276\330\247\331\206\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(17, QCoreApplication::translate("MainWindow", "\330\264\330\247\331\206\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(18, QCoreApplication::translate("MainWindow", "\331\207\331\201\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(19, QCoreApplication::translate("MainWindow", "\331\207\330\254\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(20, QCoreApplication::translate("MainWindow", "\331\206\331\210\330\262\330\257\331\207\331\205", nullptr));
        comboBox_floor->setItemText(21, QCoreApplication::translate("MainWindow", "\330\250\333\214\330\263\330\252\331\205", nullptr));

        label_22->setText(QCoreApplication::translate("MainWindow", "\330\263\330\247\330\256\330\252:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\330\267\330\250\331\202\331\207:", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "\330\247\330\252\330\247\331\202:", nullptr));
        pushButton_create_ad->setText(QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \330\242\332\257\331\207\333\214", nullptr));
        label_pic_path->setText(QString());
        label_ad_id_hidden->setText(QString());
        pushButton_edit_ad->setText(QCoreApplication::translate("MainWindow", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\242\332\257\331\207\333\214", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\330\242\332\257\331\207\333\214 \331\207\330\247\333\214 \331\205\331\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\330\264\331\206\330\247\330\263\331\207", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205 \331\206\331\205\330\247\333\214\330\264\333\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\331\206\331\210\330\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\331\206\331\210\330\271 \331\205\331\204\332\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\330\242\330\257\330\261\330\263", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\331\202\333\214\331\205\330\252", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\330\250\330\261\330\247\333\214 \331\205\330\264\330\247\331\207\330\257\331\207\330\214 \331\210\333\214\330\261\330\247\333\214\330\264 \333\214\330\247 \330\255\330\260\331\201 \331\207\330\261 \332\251\330\257\330\247\331\205\330\214 \330\247\330\250\330\252\330\257\330\247 \330\242\332\257\331\207\333\214 \330\261\330\247 \330\247\331\206\330\252\330\256\330\247\330\250 \332\251\330\261\330\257\331\207 \331\210 \330\261\331\210\333\214 \330\271\331\205\331\204\333\214\330\247\330\252 \331\205\331\210\330\261\330\257 \331\206\330\270\330\261 \332\251\331\204\333\214\332\251 \332\251\331\206\333\214\330\257.", nullptr));
        groupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        pushButton_see_my_ad->setToolTip(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\247\331\207\330\257\331\207 \330\242\332\257\331\207\333\214", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_see_my_ad->setText(QCoreApplication::translate("MainWindow", "\360\237\221\201", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_delete_my_ad->setToolTip(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201 \330\242\332\257\331\207\333\214", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_delete_my_ad->setText(QCoreApplication::translate("MainWindow", "\342\235\214", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_edit_my_ad->setToolTip(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\247\331\207\330\257\331\207 \330\242\332\257\331\207\333\214", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_edit_my_ad->setText(QCoreApplication::translate("MainWindow", "\360\237\223\235", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\247\331\207\330\257\331\207 \330\242\332\257\331\207\333\214 \331\207\330\247", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205 \330\242\332\257\331\207\333\214", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "\331\206\331\210\330\271 \330\242\332\257\331\207\333\214", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "\330\257\330\263\330\252\331\207 \330\250\331\206\330\257\333\214", nullptr));
        label_45->setText(QCoreApplication::translate("MainWindow", "\331\206\331\210\330\271 \331\205\331\204\332\251", nullptr));
        label_53->setText(QString());
        label_ad_type->setText(QString());
        label_ad_category->setText(QString());
        label_ad_property_type->setText(QString());
        label_ad_address->setText(QString());
        label_58->setText(QCoreApplication::translate("MainWindow", "\330\242\330\257\330\261\330\263", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "\331\205\330\252\330\261\330\247\332\230", nullptr));
        label_61->setText(QCoreApplication::translate("MainWindow", "\331\202\333\214\331\205\330\252", nullptr));
        label_ad_price->setText(QString());
        label_ad_meter->setText(QString());
        label_ad_pic->setText(QString());
        label_60->setText(QCoreApplication::translate("MainWindow", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\242\332\257\331\207\333\214", nullptr));
        label_ad_detail->setText(QString());
        label_46->setText(QCoreApplication::translate("MainWindow", "\330\263\330\247\330\256\330\252", nullptr));
        label_ad_build->setText(QString());
        label_ad_room->setText(QString());
        label_ad_floor->setText(QString());
        label_48->setText(QCoreApplication::translate("MainWindow", "\330\247\330\252\330\247\331\202", nullptr));
        label_47->setText(QCoreApplication::translate("MainWindow", "\330\267\330\250\331\202\331\207", nullptr));
#if QT_CONFIG(statustip)
        label_mine->setStatusTip(QCoreApplication::translate("MainWindow", "\331\205\330\247\331\204\332\251 \330\242\332\257\331\207\333\214 \330\256\331\210\330\257\330\252\330\247\331\206 \331\207\330\263\330\252\333\214\330\257.", nullptr));
#endif // QT_CONFIG(statustip)
        label_mine->setText(QCoreApplication::translate("MainWindow", "\342\255\220\357\270\217", nullptr));
        label_ad_name->setText(QString());
        label_ad_id->setText(QString());
        label_49->setText(QCoreApplication::translate("MainWindow", "\330\264\331\206\330\247\330\263\331\207 \330\242\332\257\331\207\333\214", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \331\201\330\261\331\210\330\264\331\206\330\257\331\207", nullptr));
        label_ad_owner->setText(QString());
        label_62->setText(QCoreApplication::translate("MainWindow", "\331\202\333\214\331\205\330\252 \331\207\330\261 \331\205\330\252\330\261", nullptr));
        label_ad_price_per_meter->setText(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252\330\254\331\210 \330\257\330\261 \330\242\332\257\331\207\333\214 \331\207\330\247", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "* \330\271\330\250\330\247\330\261\330\252", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "* \330\254\330\263\330\252\330\254\331\210 \330\257\330\261", nullptr));
        radioButton_search_name->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205 \330\242\332\257\331\207\333\214", nullptr));
        radioButton_search_address->setText(QCoreApplication::translate("MainWindow", "\330\242\330\257\330\261\330\263 \330\242\332\257\331\207\333\214", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\331\204\330\267\331\201\330\247 \331\205\331\210\330\247\330\261\330\257 \330\256\331\210\330\247\330\263\330\252\331\207 \330\264\330\257\331\207 \330\261\330\247 \330\252\332\251\331\205\333\214\331\204 \332\251\331\206\333\214\330\257.", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\331\206\330\252\330\247\333\214\330\254", nullptr));
        label_user_username->setText(QString());
        label_71->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_user_name->setText(QString());
        label_42->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\255\330\263\330\247\330\250 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_user_email->setText(QString());
        label_50->setText(QCoreApplication::translate("MainWindow", "\330\247\333\214\331\205\333\214\331\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
