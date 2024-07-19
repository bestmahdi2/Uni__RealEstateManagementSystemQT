#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QCloseEvent>
#include "user.h"

// Forward declaration of the Ui namespace and LoginBox class
namespace Ui {
    class LoginBox;
}

// Definition of the LoginBox class inheriting from QDialog
class LoginBox : public QDialog {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Constructor with an optional parent widget parameter
    explicit LoginBox(QWidget *parent = nullptr);

    // Destructor
    ~LoginBox();

protected:
    // Override the close event to handle additional logic when the dialog is closed
    void closeEvent(QCloseEvent *event) override;

private slots:
    // Slot to handle login button click
    void on_pushButton_login_clicked();

    // Slot to handle new register button click
    void on_pushButton_new_register_clicked();

signals:
    // Signal emitted when login is successful
    void loginSuccessful();

    // Signal emitted to show the registration form
    void showRegister();

    // Signal emitted when login dialog is closed, with a parameter indicating if login was successful
    void loginClosed(bool success);

private:
    Ui::LoginBox *ui; // Pointer to the UI elements of the LoginBox
    bool loginSuccess; // Track the login success state

    // Private method to show an error box with the given text
    void show_error_box(string text);
};

#endif // LOGIN_H
