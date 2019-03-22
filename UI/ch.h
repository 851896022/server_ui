#ifndef CH_H
#define CH_H

#include <QFrame>
#include "global.h"
#include "QTimer"
namespace Ui {
class ch;
}

class ch : public QFrame
{
    Q_OBJECT

public:
    explicit ch(QWidget *parent = 0);
    ~ch();
    int No;
    QTimer timer;
private:
    Ui::ch *ui;
public slots:
    void setName(QString str);
    void setAPM(int num);
    void setFilename(QString str,int value);
    void setPlayState(bool state);
    void refProg();
private slots:
    void on_play_clicked();

signals:
    void changePlayCh(int);
};

#endif // CH_H
