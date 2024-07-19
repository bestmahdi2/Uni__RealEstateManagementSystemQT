#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "errorbox.h"
#include <iostream>

using namespace std;

// Constructor for LoginBox
LoginBox::LoginBox(QWidget *parent) : QDialog(parent), ui(new Ui::LoginBox), loginSuccess(false) {
    ui->setupUi(this); // Set up the user interface

    // Set the window icon
    setWindowIcon(QIcon(":/user.png"));
}

// Destructor for LoginBox
LoginBox::~LoginBox() {
    delete ui; // Delete the user interface
}

// Override the close event to handle additional logic when the dialog is closed
void LoginBox::closeEvent(QCloseEvent *event) {
    emit loginClosed(loginSuccess); // Emit signal indicating if login was successful
    QDialog::closeEvent(event); // Call the base class implementation
}

// Slot to handle login button click
void LoginBox::on_pushButton_login_clicked() {
    // Get the username/email and password from the input fields
    std::string username_email = ui->lineEdit_username_email->text().toStdString();
    std::string password = ui->lineEdit_password->text().toStdString();

    // Iterate through the list of users
    for (auto &user : User::users) {
        // Check if the password matches and the username/email matches
        if (user.getPassword() == password && (user.getEmail() == username_email || user.getUsername() == username_email)) {
            User::logged_in = true; // Set the logged in status to true
            User::logged = user; // Set the logged user
            loginSuccess = true; // Indicate that login was successful
            MainWindow::THIS_USER = user;
            emit loginSuccessful(); // Emit signal indicating login was successful
            this->close(); // Close the dialog
            return;
        }
    }
    // Show an error box if login fails
    show_error_box("ایمیل/نام کاربری یا رمز عبور اشتباه است.");
}

// Method to show an error box with the given text
void LoginBox::show_error_box(string text) {
    ErrorBox error; // Create an ErrorBox object
    error.change_label(text); // Set the error message
    error.setModal(true); // Set the error box to modal
    error.exec(); // Execute the error box
}

// Slot to handle new register button click
void LoginBox::on_pushButton_new_register_clicked() {
    emit showRegister(); // Signal the main window to show the register window
    this->close(); // Close the current dialog
}
