#include "mainwindow.h"
#include "parser.h"
#include "./ui_mainwindow.h"
#include <cstdint>
#include <QLabel>
#include <iostream>


MainWindow::MainWindow(QWidget *parent, const char *filename)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {

    uint8_t *bytes;
    Parser *parser = new Parser();
    QLabel *label = new QLabel();

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    MainWindow::connect(ui->exitButton, &QPushButton::released, this, &MainWindow::ExitWindows);
    MainWindow::connect(ui->maximizeButton, &QPushButton::released, this, &MainWindow::MaximizeWindows);
    MainWindow::connect(ui->minimizButton, &QPushButton::released, this, &MainWindow::ReduceWindows);

    bytes = parser->readFile(filename);

    for (int i = 0; i < sizeof(bytes) + 1; i++) {
        printf("%x ", bytes[i]);
    }

    /*for (int i = 0; i < sizeof(bytes); i++) {
        label[i].setText(QString(bytes[i]));
        label[i].setStyleSheet("color: white;");
        label[i].setMargin(5);
    }*/

    //ui->scrollArea->setWidget(label);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MaximizeWindows(void) {

    if (maximized == false) {
        MainWindow::showMaximized();
        maximized = true;
    } else {
        MainWindow::showNormal();
        maximized = false;
    }
}

void MainWindow::ReduceWindows(void) {

    MainWindow::showMinimized();
}

void MainWindow::ExitWindows(void) {

    MainWindow::close();
}
