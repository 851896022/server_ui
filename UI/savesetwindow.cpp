#include "savesetwindow.h"
#include "ui_savesetwindow.h"

saveSetWindow::saveSetWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::saveSetWindow)
{
    ui->setupUi(this);
}

saveSetWindow::~saveSetWindow()
{
    delete ui;
}

void saveSetWindow::on_btn_get_clicked()
{
    QString file_name = QFileDialog::getExistingDirectory(NULL,"选择保存路径",".");
    ui->txt_saveDir->setText(file_name);
    g->mp3SaveDir=file_name;
}
