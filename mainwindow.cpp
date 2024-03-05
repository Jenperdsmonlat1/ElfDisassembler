#include "mainwindow.h"
#include "parser.h"
#include "./ui_mainwindow.h"
#include <cstdint>
#include <cstdio>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>


#ifdef __linux__
    #include <sys/stat.h>
#elif WIN32
    #include <windows.h>
#endif


MainWindow::MainWindow(QWidget *parent, const char *filename)
    : QMainWindow(parent),
    ui(new Ui::MainWindow) {

    Parser *parser = new Parser(filename);
    uint8_t *bytes = parser->readFile();
    uint32_t k = 0;

    struct stat st = parser->getFileInfo();

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    ui->setupUi(this);

    MainWindow::connect(ui->exitButton, &QPushButton::released, this, &MainWindow::ExitWindows);
    MainWindow::connect(ui->maximizeButton, &QPushButton::released, this, &MainWindow::MaximizeWindows);
    MainWindow::connect(ui->minimizButton, &QPushButton::released, this, &MainWindow::ReduceWindows);

    ui->tableWidget->setRowCount(st.st_size / 32);
    ui->tableWidget->setColumnCount(32);

    for (int i = 0; i < 32; i++) {

        for (int j = 0; j < st.st_size; j++) {

            ui->tableWidget->setColumnWidth(i, 5);

            if (bytes[k] < 10)
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString("0") + QString::number(bytes[k], 16)));
            else
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::number(bytes[k], 16)));

            k++;
        }
    }

    //ui->scrollArea->setWidget(ui->tableWidget);
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
