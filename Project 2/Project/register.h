#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QCloseEvent>

using namespace std;

namespace Ui {
    class RegisterBox; // Forward declaration of the Ui::RegisterBox class
}

// Definition of the RegisterBox class inheriting from QDialog
class RegisterBox : public QDialog {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Constructor with an optional parent widget parameter
    explicit RegisterBox(QWidget *parent = nullptr);

    // Destructor
    ~RegisterBox();

protected:
    // Overriding the close event to handle custom behavior when the dialog is closed
    void closeEvent(QCloseEvent *event) override;

private slots:
    // Slot to handle the login button click
    void on_pushButton_login_clicked();

    // Slot to handle the first register button click
    void on_pushButton_register1_clicked();

    // Slot to handle the second register button click
    void on_pushButton_register2_clicked();

    // Slot to handle the third register button click
    void on_pushButton_register3_clicked();

signals:
    // Signal to show the login window
    void showLogin();

    // Signal emitted when the register dialog is closed
    void registerClosed(bool allowClose);

private:
    Ui::RegisterBox *ui; // Pointer to the UI elements of the RegisterBox
    bool allowClose; // Flag to determine if the dialog can be closed

    // User information
    string username;
    string email;
    string password;
    string name;

    // Helper function to show an error box with the given text
    void show_error_box(string text);

    // Helper function to show a success box with the given text
    void show_success_box(string text);
};

#endif // REGISTER_H
