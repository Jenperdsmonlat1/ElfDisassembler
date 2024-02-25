#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    MainWindow::connect(ui->exitButton, &QPushButton::released, this, &MainWindow::ExitWindows);
    MainWindow::connect(ui->maximizeButton, &QPushButton::released, this, &MainWindow::MaximizeWindows);
    MainWindow::connect(ui->minimizButton, &QPushButton::released, this, &MainWindow::ReduceWindows);
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
