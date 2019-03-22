#include "ch.h"
#include "ui_ch.h"

ch::ch(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ch)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(refProg()));
    timer.start(10);
}

ch::~ch()
{
    delete ui;
}
void ch::setName(QString str)
{
    ui->name->setText(str);
}
void ch::setAPM(int num)
{
    if(num<0) num=0;
    if(num>100)num=100;
    ui->apm->setValue(num);
    ui->apm->setFormat(QString::number(num));
}
void ch::setFilename(QString str,int value)
{
    if(str==QString(""))
    {
        ui->saveProgress->setValue(0);
        QString str("未录制");
        ui->saveProgress->setFormat(str);
    }
    else
    {
        ui->saveProgress->setValue(value);
        str+=" 已录制%p%";
        ui->saveProgress->setFormat(str);
    }

}

void ch::on_play_clicked()
{
    if(ui->play->text()==QString("播放"))
    {
        g->playingCh=No;
        g->changePlayCh(No);
        emit changePlayCh(No);
    }
    else
    {
        g->playingCh=999;
        g->stopPlay();
        emit changePlayCh(No);
    }

}
void ch::setPlayState(bool state)
{
    if(state)
    {
        ui->play->setText("停止");
    }
    else
    {
        ui->play->setText("播放");

    }
}
void ch::refProg()
{
    ui->apm->setValue(ui->apm->value()-1);
}
