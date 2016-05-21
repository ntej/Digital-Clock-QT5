#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setObjectName(QString("Qt5 Blueprints"));
    a.setApplicationName(QString("Digital Clock"));

    QWidget wid;
    MainWindow w(&wid);  //Mainwindow is child of QWidget


    w.show();
    

    w.setWindowTitle("Digital clock");



    return a.exec();
}
