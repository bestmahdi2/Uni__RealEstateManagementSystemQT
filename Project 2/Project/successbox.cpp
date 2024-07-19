#include "successbox.h"
#include "ui_successbox.h"

using namespace std;

SuccessBox::SuccessBox(QWidget *parent) : QDialog(parent), ui(new Ui::SuccessBox) {
    ui->setupUi(this); // Initialize the UI elements defined in Ui::SuccessBox

    setWindowIcon(QIcon(":/success.png")); // Set window icon to a success icon

    // Connect the button's clicked signal to the close slot
    connect(ui->pushButton, &QPushButton::clicked, this, &QDialog::close);
    // When pushButton is clicked, close the dialog
}

SuccessBox::~SuccessBox() {
    delete ui; // Clean up the UI pointer
}

// Function to dynamically change the label text
void SuccessBox::change_label(string text) {
    ui->label_2->setText(QString::fromStdString(text)); // Set the text of label_2 with the provided text
}
