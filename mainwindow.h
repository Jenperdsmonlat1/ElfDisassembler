#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    bool maximized;

    MainWindow(QWidget *parent = nullptr, const char *filename = nullptr);
    ~MainWindow();

    void MaximizeWindows(void);
    void ReduceWindows(void);
    void ExitWindows(void);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
