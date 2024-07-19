#ifndef ERRORBOX_H
#define ERRORBOX_H

#include <QDialog>

using namespace std;

// Forward declaration of the Ui namespace and ErrorBox class
namespace Ui {
    class ErrorBox;
}

// Definition of the ErrorBox class inheriting from QDialog
class ErrorBox : public QDialog {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Constructor with an optional parent widget parameter
    explicit ErrorBox(QWidget *parent = nullptr);

    // Destructor
    ~ErrorBox();

    // Method to change the text of a label in the ErrorBox
    void change_label(string text);

private:
    Ui::ErrorBox *ui; // Pointer to the UI elements of the ErrorBox
};

#endif // ERRORBOX_H
