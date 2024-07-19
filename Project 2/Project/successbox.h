#ifndef SUCCESSBOX_H
#define SUCCESSBOX_H

#include <QDialog>

using namespace std;

namespace Ui {
    class SuccessBox; // Forward declaration of the Ui::SuccessBox class
}

// Definition of the SuccessBox class inheriting from QDialog
class SuccessBox : public QDialog {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Constructor with an optional parent widget parameter
    explicit SuccessBox(QWidget *parent = nullptr);

    // Function to change the label text dynamically
    void change_label(string text);

    // Destructor
    ~SuccessBox();

private:
    Ui::SuccessBox *ui; // Pointer to the UI elements of the SuccessBox
};

#endif // SUCCESSBOX_H
