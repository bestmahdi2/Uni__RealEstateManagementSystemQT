#include "itemwidget.h"
#include <QPixmap>
#include <iostream>

using namespace std;

// Constructor for ItemWidget
ItemWidget::ItemWidget(const int id, const QString &image, const QString &type, const QString &name, const QString &address, QWidget *parent) : QWidget(parent) {
    // Initialize labels
    imageLabel = new QLabel; // Label to display the image
    typeLabel = new QLabel(type); // Label to display the type
    nameLabel = new QLabel(name); // Label to display the name
    addressLabel = new QLabel(address); // Label to display the address

    // Set image
    if (image != "") {
        QPixmap pixmap(image); // Load the specified image
        imageLabel->setPixmap(pixmap.scaled(250, 250, Qt::KeepAspectRatio)); // Set the pixmap with scaled size
    } else {
        QPixmap pixmap(":/no_pic.jpg"); // Load a default image if none is specified
        imageLabel->setPixmap(pixmap.scaled(250, 250, Qt::KeepAspectRatio)); // Set the pixmap with scaled size
    }

    // Create vertical layout for text labels
    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(nameLabel); // Add name label to layout
    textLayout->addWidget(typeLabel); // Add type label to layout
    textLayout->addWidget(addressLabel); // Add address label to layout

    // Create horizontal layout for the main layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(imageLabel, 4); // Add image label with stretch factor 4
    mainLayout->addLayout(textLayout, 6); // Add text layout with stretch factor 6

    // Set cursor to pointing hand when hovering over the widget
    this->setCursor(Qt::PointingHandCursor);

    // Set the main layout for the widget
    setLayout(mainLayout);
}
