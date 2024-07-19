#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

// Definition of the ItemWidget class inheriting from QWidget
class ItemWidget : public QWidget {
    Q_OBJECT // Macro for enabling Qt's meta-object features, such as signals and slots

public:
    // Constructor with parameters for id, image, type, name, address, and an optional parent widget
    explicit ItemWidget(int id, const QString &image, const QString &type, const QString &name, const QString &address, QWidget *parent = nullptr);

    // Getter method to return the id of the ItemWidget
    int getId() const { return id; }

private:
    int id; // Identifier for the ItemWidget
    QLabel *imageLabel; // Label to display the image
    QLabel *typeLabel; // Label to display the type
    QLabel *nameLabel; // Label to display the name
    QLabel *addressLabel; // Label to display the address
};

#endif // ITEMWIDGET_H
