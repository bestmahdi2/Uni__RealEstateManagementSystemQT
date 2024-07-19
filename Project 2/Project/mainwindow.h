#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRadioButton>
#include <user.h>
#include <QListWidget>
#include "login.h"
#include "register.h"

// Forward declarations for LoginBox and RegisterBox classes
class LoginBox;
class RegisterBox;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Definition of the MainWindow class inheriting from QMainWindow
class MainWindow : public QMainWindow {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Static members for the current user and application state
    static User THIS_USER;
    static string state;

    // Constructor with an optional parent widget parameter
    MainWindow(QWidget *parent = nullptr);

    // Destructor
    ~MainWindow();

private slots:
    // Slot to handle the "Create Ad" page button click
    void on_pushButton_page_create_ad_clicked();

    // Slot to handle the "Show My Ads" page button click
    void on_pushButton_page_show_my_ads_clicked();

    // Slot to handle the "Show All Ads" page button click
    void on_pushButton_page_show_all_ads_clicked();

    // Slot to handle the "Search Ads" page button click
    void on_pushButton_page_search_ads_clicked();

    // Slot to handle the "See My Ad" button click
    void on_pushButton_see_my_ad_clicked();

    // Slot to handle the "Edit My Ad" button click
    void on_pushButton_edit_my_ad_clicked();

    // Slot to handle the "Residential" button click
    void on_pushButton_residential_clicked();

    // Slot to handle the "Office" button click
    void on_pushButton_office_clicked();

    // Slot to handle the "Commercial" button click
    void on_pushButton_commercial_clicked();

    // Slot to handle the "Non-Residential" category radio button click
    void on_radioButton_category_non_residential_clicked();

    // Slot to handle the "Residential" category radio button click
    void on_radioButton_category_residential_clicked();

    // Slot to handle the "Office" category radio button click
    void on_radioButton_category_office_clicked();

    // Slot to handle the "Commercial" category radio button click
    void on_radioButton_category_commercial_clicked();

    // Slot to handle the "Sell" type radio button click
    void on_radioButton_type_sell_clicked();

    // Slot to handle the "Exchange" type radio button click
    void on_radioButton_type_exchange_clicked();

    // Slot to handle the "Rent" type radio button click
    void on_radioButton_type_rent_clicked();

    // Slot to handle the "Kolangi" type radio button click
    void on_radioButton_type_kolangi_clicked();

    // Slot to handle the "Land" type radio button click
    void on_radioButton_type_land_clicked();

    // Slot to handle the "Garden" type radio button click
    void on_radioButton_type_garden_clicked();

    // Slot to handle the "Apartment" type radio button click
    void on_radioButton_type_apartment_clicked();

    // Slot to handle the "Villa" type radio button click
    void on_radioButton_type_villa_clicked();

    // Slot to handle the "Office" type radio button click
    void on_radioButton_type_office_clicked();

    // Slot to handle the "Clinic" type radio button click
    void on_radioButton_type_clinic_clicked();

    // Slot to handle the "Shop" type radio button click
    void on_radioButton_type_shop_clicked();

    // Slot to handle the "Storage" type radio button click
    void on_radioButton_type_storage_clicked();

    // Slot to handle the "Workshop" type radio button click
    void on_radioButton_type_workshop_clicked();

    // Slot to handle the state change of the renew checkbox
    void on_checkBox_renew_stateChanged(int arg1);

    // Slot to handle the picture button click
    void on_pushButton_pic_clicked();

    // Slot to handle the create ad button click
    void on_pushButton_create_ad_clicked();

    // Slot to handle the non-residential button click
    void on_pushButton_non_residential_clicked();

    // Slot to handle the delete my ad button click
    void on_pushButton_delete_my_ad_clicked();

    // Slot to handle the edit ad button click
    void on_pushButton_edit_ad_clicked();

    // Slot to handle the search button click
    void on_pushButton_search_clicked();

    // Slot to handle the edit account page button click
    void on_pushButton_page_edit_account_clicked();

    // Slot to handle the logout button click
    void on_pushButton_logout_clicked();

    // Slot to show the register window
    void showRegisterWindow();

    // Slot to show the login window
    void showLoginWindow();

    // Slot to handle successful login
    void handleLoginSuccessful();

    // Slot to handle login window close
    void handleLoginClose(bool success);

    // Slot to handle register window close
    void handleRegisterClose(bool allowClose);

private:
    Ui::MainWindow *ui; // Pointer to the UI elements of the MainWindow
    LoginBox *loginWindow; // Pointer to the LoginBox window
    RegisterBox *registerWindow; // Pointer to the RegisterBox window

    // Helper function to switch radio buttons
    void switch_radio_button(QRadioButton *radio_button, bool enable, bool state = false);

    // Helper function to reset other details
    void reset_other_details();

    // Helper function to update the table
    void update_table();

    // Helper function to show the detail page of an ad
    void show_page_detail_ad(int ad_index);

    // Helper function to create an item in the list
    void create_item(const int id, const QString &name, const QString &address, const QString &price, const QString &image, QListWidget *list);

    // Helper function to update the item list based on category
    void update_item_list(string category);

    // Helper function to show an error box with the given text
    void show_error_box(string text);

    // Helper function to show a success box with the given text
    void show_success_box(string text);

    // Helper function to handle item click in all ads list
    void item_click_all(QListWidgetItem *item);

    // Helper function to handle item click in search results
    void item_click_search(QListWidgetItem *item);

    // Helper function to show the edit section
    void show_edit_section();

    // Helper function to clear the create ad page
    void clear_create_page();
};

#endif // MAINWINDOW_H
