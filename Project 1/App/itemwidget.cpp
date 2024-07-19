#include "itemwidget.h"
#include <QPixmap>

ItemWidget::ItemWidget(const int id, const QString &imagePath, const QString &price, const QString &name, const QString &location, QWidget *parent)
    : QWidget(parent)
{
    // Initialize labels
    imageLabel = new QLabel;
    priceLabel = new QLabel(price);
    nameLabel = new QLabel(name);
    locationLabel = new QLabel(location);

    // Set image
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(150, 150, Qt::KeepAspectRatio)); // Adjust size as needed

    // Create layouts
    QVBoxLayout *textLayout = new QVBoxLayout;
    textLayout->addWidget(nameLabel);
    textLayout->addWidget(priceLabel);
    textLayout->addWidget(locationLabel);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(imageLabel, 4); // Stretch factor for image
    mainLayout->addLayout(textLayout, 6); // Stretch factor for text layout

    // Set cursor to pointing hand when hovering over the widget
    this->setCursor(Qt::PointingHandCursor);

    setLayout(mainLayout);
}
