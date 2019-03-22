#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QTimer>
#include "UI/setting.h"
#include "UI/ch.h"
#include "UI/savesetwindow.h"
#include "UI/edityxt.h"
#include <QCloseEvent>
namespace Ui {
class main_window;
}

class main_window : public QStackedWidget
{
    Q_OBJECT

public:
    explicit main_window(QWidget *parent = 0);
    ~main_window();
    setting set;

    QVBoxLayout vBoxSet;

    ch *lych[200];
    QVBoxLayout vBoxlych;

    QTimer timer100ms;
    int countTimeOut100ms=0;

    saveSetWindow *saveSet;
    QVBoxLayout vBoxSaveSet;


    EditYxt *editYxt;
    QVBoxLayout vBoxEditYxt;

    int timer500ms=0;
public slots:
    void setAPM();
    void setFileName();
    void onTimeOut100ms();
    void changePlayBtnState(int ch);
private slots:
    void on_control_currentRowChanged(int currentRow);
    void closeEvent(QCloseEvent *event);
private:
    Ui::main_window *ui;
};

#endif // MAIN_WINDOW_H
