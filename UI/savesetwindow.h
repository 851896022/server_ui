#ifndef SAVESETWINDOW_H
#define SAVESETWINDOW_H

#include <QFrame>
#include <QFileDialog>
#include <global.h>
namespace Ui {
class saveSetWindow;
}

class saveSetWindow : public QFrame
{
    Q_OBJECT

public:
    explicit saveSetWindow(QWidget *parent = 0);
    ~saveSetWindow();

private slots:
    void on_btn_get_clicked();

private:
    Ui::saveSetWindow *ui;
};

#endif // SAVESETWINDOW_H
