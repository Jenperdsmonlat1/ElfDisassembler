#include "homewindows.h"
#include "./ui_homewindows.h"
#include <QPushButton>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <iostream>
#include "mainwindow.h"


HomeWindows::HomeWindows(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::HomeWindows) {

    maximized = false;
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    HomeWindows::connect(ui->exitButton, &QPushButton::released, this, &HomeWindows::ExitWindows);
    HomeWindows::connect(ui->maximizeButton, &QPushButton::released, this, &HomeWindows::MaximizeWindows);
    HomeWindows::connect(ui->reduceButton, &QPushButton::released, this, &HomeWindows::ReduceWindows);
    HomeWindows::connect(ui->fileOpenerButton, &QPushButton::released, this, &HomeWindows::SwitchWindows);

    shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(50);
    shadow->setColor(QColor("#443e4c"));
    shadow->setXOffset(0);
    shadow->setYOffset(10);
    ui->fileOpenerButton->setGraphicsEffect(shadow);
}

HomeWindows::~HomeWindows() {

    delete shadow;
    delete ui;
}

void HomeWindows::MaximizeWindows(void) {

    if (maximized == false) {
        HomeWindows::showMaximized();
        maximized = true;
    } else {
        HomeWindows::showNormal();
        maximized = false;
    }
}

void HomeWindows::ReduceWindows(void) {

    HomeWindows::showMinimized();
}

void HomeWindows::ExitWindows(void) {

    HomeWindows::close();
}

void HomeWindows::SwitchWindows(void) {

    QString file = QFileDialog::getOpenFileName(this, tr("Sélectionner un fichier."), "/", tr("ELF"));
    std::cout << file.toStdString() << std::endl;

    MainWindow *mainWindows = new MainWindow(nullptr, file.toStdString().c_str());
    mainWindows->show();
    mainWindows->activateWindow();

    this->ExitWindows();
}
