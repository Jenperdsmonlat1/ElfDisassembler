#ifndef HOMEWINDOWS_HPP
#define HOMEWINDOWS_HPP

#include <QMainWindow>
#include <QGraphicsDropShadowEffect>


QT_BEGIN_NAMESPACE
namespace Ui { class HomeWindows; }
QT_END_NAMESPACE

class HomeWindows : public QMainWindow {

    Q_OBJECT

public:
    bool maximized;
    QGraphicsDropShadowEffect *shadow;

    HomeWindows(QWidget *parent = nullptr);

    void MaximizeWindows(void);
    void ReduceWindows(void);
    void ExitWindows(void);
    const char *SwitchWindows(void);
    ~HomeWindows();

private:
    Ui::HomeWindows *ui;
};

#endif // HOMEWINDOWS_HPP
