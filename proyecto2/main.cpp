#include "mainwindow.h"
#include <QApplication>
#include "editor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    editor w;
    w.show();

    return a.exec();
}
