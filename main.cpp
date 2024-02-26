#include "homewindows.h"
#include <QApplication>
#include <QStackedWidget>
#include <Qt>


int main(int argc, char **argv) {

    QApplication a(argc, argv);
    HomeWindows home;

    home.show();

    return a.exec();
}
