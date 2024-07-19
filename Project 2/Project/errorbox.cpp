#include "errorbox.h"
#include "ui_errorbox.h"

// Constructor for the ErrorBox class
ErrorBox::ErrorBox(QWidget *parent) : QDialog(parent), ui(new Ui::ErrorBox) {
    ui->setupUi(this); // Set up the user interface

    setWindowIcon(QIcon(":/error.png")); // Set the window icon

    // Connect the button's clicked signal to the close slot
    connect(ui->pushButton, &QPushButton::clicked, this, &QDialog::close);
}

// Destructor for the ErrorBox class
ErrorBox::~ErrorBox() {
    delete ui; // Delete the user interface
}

// Function to change the label text
void ErrorBox::change_label(string text) {
    ui->label_2->setText(QString::fromStdString(text)); // Convert std::string to QString and set the label text
}

