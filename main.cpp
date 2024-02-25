#include "mainwindow.h"
#include "homewindows.h"
#include <QApplication>
#include <Qt>
#include "parser.h"


int main(int argc, char **argv) {

    QApplication a(argc, argv);
    MainWindow mainWindows;
    HomeWindows home;

    home.show();
    return a.exec();
}
