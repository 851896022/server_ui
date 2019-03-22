#ifndef EDITYXT_H
#define EDITYXT_H

#include <QFrame>
#include "global.h"
namespace Ui {
class EditYxt;
}

class EditYxt : public QFrame
{
    Q_OBJECT

public:
    explicit EditYxt(QWidget *parent = 0);
    ~EditYxt();
    QStringList transmitterName;
private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnSave_clicked();

    void on_nameList_currentIndexChanged(int index);

private:
    Ui::EditYxt *ui;
};

#endif // EDITYXT_H
