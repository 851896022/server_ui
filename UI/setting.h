#ifndef SETTING_H
#define SETTING_H

#include <QFrame>
#include "global.h"

namespace Ui {
class setting;
}

class setting : public QFrame
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();

private slots:
    void on_listEqu_currentRowChanged(int currentRow);

    void on_listChName_cellChanged(int row, int column);

    void on_save_clicked();

private:
    Ui::setting *ui;
};

#endif // SETTING_H
