#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);

    ui->listEqu->clear();
    qDebug()<<g->equCount;
    for(int i=0;i<g->equCount;i++)
    {
        qDebug()<<i<<g->equ[i].ip;
        ui->listEqu->addItem(QString(g->equ[i].ip));
    }
    //on_listEqu_currentRowChanged(0);
}

setting::~setting()
{
    delete ui;
}

void setting::on_listEqu_currentRowChanged(int currentRow)
{
    for(int i=0;i<18;i++)
    {
        QTableWidgetItem *item=new QTableWidgetItem(g->equ[currentRow].chName[i]);
        ui->listChName->setItem(i,0,item);
    }

}

void setting::on_listChName_cellChanged(int row, int column)
{
    qDebug()<<row<<column;
    g->equ[ui->listEqu->currentRow()].chName[row]=ui->listChName->item(row,column)->text();
}

void setting::on_save_clicked()
{
    QString data;
    for(int i=0;i<ui->listEqu->count();i++)
    {
        data+=ui->listEqu->item(i)->text();
        data+="|";
        for(int j=0;j<18;j++)
        {
            data+=g->equ[i].chName[j];
            data+="|";
        }
        data+="\r\n";
    }



    //保存到文件
    for(int i=0;i<ui->listEqu->count();i++)
    {
        QString filename;
        filename+=(qApp->applicationDirPath()+"/sav/equ.sav");
        //判断文件是否存在
        QFile *file = new QFile(filename);
        if(file->open(QIODevice::WriteOnly))
        {
            file->write(data.toStdString().data());
            file->flush();
            file->close();
        }
        file->deleteLater();
    }

    QString msg("保存成功");
    frmMessageBox MessageBox;
    MessageBox.SetMessage(msg,0);
    MessageBox.show();
}
