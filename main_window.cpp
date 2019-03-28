#include "main_window.h"
#include "ui_main_window.h"
#include <QDateTime>
main_window::main_window(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);
    //========================================
    vBoxSet.addWidget(&set);
    ui->page_set->setLayout(&vBoxSet);
    //=========================================
    ///////////////////////////////

    int equCount=10;
    for(int i=0;i<10;i++)
    {
        if(g->equ[i].port==0)
        {
            equCount=i;
            break;
        }
    }
    g->equCount=equCount;
    for(int i=0;i<equCount;i++)
    {
        for(int j=0;j<18;j++)
        {
            int c=i*18+j;
            lych[c]=new ch;
            lych[c]->No=c;
            vBoxlych.addWidget(lych[c]);
            lych[c]->setName(g->equ[i].chName[j]);
            connect(lych[c],SIGNAL(changePlayCh(int)),this,SLOT(changePlayBtnState(int)));
        }

    }
    ui->scrollAreaWidgetContents->setLayout(&vBoxlych);

    //===========================================
    saveSet=new saveSetWindow;
    vBoxSaveSet.addWidget(saveSet);
    ui->page_saveSet->setLayout(&vBoxSaveSet);
    //===========================================
    editYxt = new EditYxt;
    vBoxEditYxt.addWidget(editYxt);
    ui->page_yxt->setLayout(&vBoxEditYxt);


    //===========================
    connect(&timer100ms,SIGNAL(timeout()),this,SLOT(onTimeOut100ms()));
    timer100ms.start(100);


}

main_window::~main_window()
{
    delete ui;
    {
        QProcess p;
        QString c = "taskkill /im pcm_to_mp3.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im hex_to_pcm.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im alarm_server.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im "+qApp->applicationName()+".exe /f";
        p.execute(c);
        p.close();

    }
}
void main_window::closeEvent(QCloseEvent *event)
{
    {
        QProcess p;
        QString c = "taskkill /im pcm_to_mp3.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im hex_to_pcm.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im alarm_server.exe /f";
        p.execute(c);
        p.close();

    }
    {
        QProcess p;
        QString c = "taskkill /im server_ui.exe /f";
        p.execute(c);
        p.close();

    }
    for(int i=0;i<g->threadList.count();i++)
    {

        while(g->threadList[i]!=NULL)
        {

            g->threadList[i]->deleteLater();
            qDebug()<<"exit"<<i;

        }

        QThread::msleep(500);
    }

    event->accept();
}

void main_window::on_control_currentRowChanged(int currentRow)
{
    ui->stackedWidget->setCurrentIndex(currentRow);
}
void main_window::setAPM()
{
    for(int i=0;i<(g->equCount*18);i++)
    {
        lych[i]->setAPM(g->apm[i]);
    }
}
void main_window::setFileName()
{
    int sec =QTime::currentTime().second();
    for(int i=0;i<(g->equCount*18);i++)
    {
        lych[i]->setFilename(g->nowFileName[i],sec);
    }
}
void main_window::onTimeOut100ms()
{
    countTimeOut100ms++;
    if((countTimeOut100ms%10)==0)
    {
        setFileName();
    }
    if((countTimeOut100ms%3)==0)
    {
        setAPM();
    }
    //==========500ms==================
    timer500ms++;
    if((timer500ms%5)==0)
    {
        ui->nowTime->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    }
}
void main_window::changePlayBtnState(int ch)
{
    qDebug()<<ch;
    int chCount =g->equCount*18;
    for(int i=0;i<chCount;i++)
    {
        if(g->playingCh==i)
        {
            lych[i]->setPlayState(true);

        }
        else
        {
            lych[i]->setPlayState(false);
        }

    }
    ch=ch;
}
