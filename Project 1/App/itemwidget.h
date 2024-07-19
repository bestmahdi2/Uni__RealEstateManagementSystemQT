#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#pragma once

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ItemWidget(int id, const QString &imagePath, const QString &price, const QString &name, const QString &location, QWidget *parent = nullptr);
    int getId() const { return id; }

private:
    QLabel *imageLabel;
    QLabel *priceLabel;
    QLabel *nameLabel;
    QLabel *locationLabel;
    int id;
};

#endif // ITEMWIDGET_H
