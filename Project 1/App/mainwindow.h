#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
#include "itemwidget.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;
extern bool SIGNED_IN;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Ads_clicked();

    void on_pushButton_Categories_clicked();

    void on_pushButton_Add_Ad_clicked();

    void on_pushButton_Chat_clicked();

    void on_pushButton_My_Account_clicked();

    void on_pushButton_goto_signin_clicked();

    void on_pushButton_goto_signup_clicked();

    void on_pushButton_signin_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_goto_edit_my_account_clicked();

    void on_pushButton_edit_my_account_clicked();

    void on_treeWidget_itemSelectionChanged();

    void on_comboBox_category_currentIndexChanged(int index);

    void on_pushButton_goto_continue_add_ad_clicked();

    void on_pushButton_goto_continue_add_ad_2_clicked();

    void on_pushButton_apartment_register_clicked();

    void on_pushButton_hv_register_clicked();

    void on_pushButton_oac_register_clicked();

    void on_pushButton_sbiac_register_clicked();

    void onItemClicked(QListWidgetItem *item);

    void on_lineEdit_search_textChanged(const QString &arg1);

    void on_pushButton_my_ads_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_add_image_clicked();

    void on_pushButton_detail_apartment_delete_clicked();

    void on_pushButton_detail_hv_delete_clicked();

    void on_pushButton_detail_lop_delete_clicked();

    void on_pushButton_detail_oac_delete_clicked();

    void on_pushButton_detail_sbiac_delete_clicked();

private:
    Ui::MainWindow *ui;
    void change_button_colors(const string &except);
    void addItem(const int id, const QString &imagePath, const QString &price, const QString &name, const QString &location);
    void empty_list_widget();
    void change_page(const string active_button, int page_index);
    void change_label_text(QLabel *label, string text, string stylesheet = "");
    void change_line_edit_text(QLineEdit *line_edit, string &text);
    void change_line_edit_text(QLineEdit *line_edit, QString text);
};
#endif // MAINWINDOW_H
