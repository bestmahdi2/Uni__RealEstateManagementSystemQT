#include "mainwindow.h"
#include "login.h"
#include "register.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    return a.exec();
}
