#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "errorbox.h"
#include "successbox.h"

RegisterBox::RegisterBox(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterBox), allowClose(true) {
    ui->setupUi(this);

    // Set window icon
    setWindowIcon(QIcon(":/user.png"));
}

RegisterBox::~RegisterBox() {
    delete ui;
}

// Overriding the close event to handle custom behavior
void RegisterBox::closeEvent(QCloseEvent *event) {
    emit registerClosed(allowClose); // Emit signal indicating whether to allow close
    if (allowClose) {
        QDialog::closeEvent(event); // Close the dialog if allowClose is true
    } else {
        event->ignore(); // Ignore the close event if allowClose is false
    }
}

// Slot to handle the login button click, emits signal to show the login window
void RegisterBox::on_pushButton_login_clicked() {
    emit showLogin(); // Signal the main window to show the login window
    this->close();    // Close the current dialog
}

// Helper function to show an error message dialog
void RegisterBox::show_error_box(string text) {
    ErrorBox error;
    error.change_label(text);
    error.setModal(true);
    error.exec();
}

// Helper function to show a success message dialog
void RegisterBox::show_success_box(string text) {
    SuccessBox success;
    success.change_label(text);
    success.setModal(true);
    success.exec();
}

// Slot to handle the first register button click
void RegisterBox::on_pushButton_register1_clicked() {
    string email = ui->lineEdit_username_email->text().toStdString();
    if (email == "") {
        show_error_box("لطفا ایمیل خود را وارد کنید.");
        return;
    }

    // Check if the email already exists
    bool already_exist = false;
    for (auto &user : User::users) {
        if (user.getEmail() == email) {
            already_exist = true;
            break;
        }
    }

    if (already_exist) {
        show_error_box("این ایمیل از قبل استفاده شده است.");
        return;
    }

    // Proceed to the next registration step
    ui->stackedWidget->setCurrentIndex(1);
    this->email = email;
}

// Slot to handle the second register button click
void RegisterBox::on_pushButton_register2_clicked() {
    string password = ui->lineEdit_password->text().toStdString();
    string password_repeat =  ui->lineEdit_password_repeat->text().toStdString();

    if (password == "" || password_repeat == "") {
        show_error_box("لطفا رمز عبور و تکرار آن را وارد کنید.");
        return;
    }

    // Check if the passwords match
    if (password == password_repeat) {
        ui->stackedWidget->setCurrentIndex(2);
        this->password = password;
    } else {
        show_error_box("رمز عبور و تکرار آن مغایرت دارند.");
    }
}

// Slot to handle the third register button click
void RegisterBox::on_pushButton_register3_clicked() {
    string username = ui->lineEdit_username->text().toStdString();
    string name =  ui->lineEdit_name->text().toStdString();

    if (username == "" || name == "") {
        show_error_box("لطفا همه موارد خواسته شده را تکمیل کنید.");
        return;
    }

    // Check if the username already exists
    bool already_exist = false;
    for (auto &user : User::users) {
        if (user.getUsername() == username) {
            already_exist = true;
            break;
        }
    }

    if (already_exist) {
        show_error_box("این نام کاربری از قبل موجود است.");
        return;
    }

    // Create a new User object and add it to the users vector
    User user = User(name, username, this->password, this->email);
    User::users.push_back(user);

    // Show success message and reset fields
    show_success_box("ثبت نام موفقیت آمیز بود.");
    ui->stackedWidget->setCurrentIndex(0);
    ui->lineEdit_username_email->setText("");
    ui->lineEdit_password->setText("");
    ui->lineEdit_password_repeat->setText("");
    ui->lineEdit_username->setText("");
    ui->lineEdit_name->setText("");

    on_pushButton_login_clicked(); // Automatically switch to login after successful registration
}
