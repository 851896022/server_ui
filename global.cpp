#include "global.h"

global::global(QObject *parent) : QObject(parent)
{
    //myHelper::SetStyle(":/qss/dev.css");

    //============================================================
    {
        QString base_dir=qApp->applicationDirPath()+"/sav";
        QDir *temp = new QDir;
        bool exist = temp->exists(base_dir);
        if(!exist)
        {
            temp->mkdir(base_dir);
        }
    }
    {
        QString base_dir=qApp->applicationDirPath()+"/sav";
        QDir *temp = new QDir;
        bool exist = temp->exists(base_dir);
        if(!exist)
        {
            temp->mkdir(base_dir);
        }
    }
    loadEqu();
//========================================================
    connect(&receivePCM,SIGNAL(readyRead()),this,SLOT(onReceivePCM()));
    play=new player;

}
/*
global::~global()
{



}
*/
void global::loadEqu()
{
    //================================================================
    {
        QString filename;
        filename+=(qApp->applicationDirPath()+"/sav/equ.sav");
        //判断文件是否存在
        QFile *file = new QFile(filename);
        if(file->open(QIODevice::ReadOnly))
        {
            for(int i=0;i<10;i++)
            {
                {
                    QString ba(file->readLine());
                    QStringList list=ba.split("|");
                    equ[i].name=list.at(0);
                    equ[i].ip=equ[i].name.split(":").at(0);
                    equ[i].port=equ[i].name.split(":").at(1).toInt();
                    for(int j=0;j<18;j++)
                    {
                        equ[i].chName[j]=list.at(j+1);
                    }
                }


                if(file->atEnd())break;
            }
            file->close();
        }
        file->deleteLater();
    }

    //--------------------------
    int equCount=10;
    for(int i=0;i<10;i++)
    {
        if(equ[i].port==0)
        {
            equCount=i;
            break;
        }
    }
    this->equCount=equCount;
}
void global::changePlayCh(int ch)
{
    if(receivePCM.state()==QAbstractSocket::BoundState)
    {
        receivePCM.close();
    }
    receivePCM.bind((50000+(ch*10)));
}
void global::stopPlay()
{
    receivePCM.close();
}
void global::onReceivePCM()
{


    char ch[23040]={0};

    int len=receivePCM.readDatagram(ch,23040);


    if(len>2304)
    {
        qDebug()<<len;
    }
    if(len<2304)return;


    /*
    {
        short* schr=(short*)ch;
        int avr=0;
        for(int i=0;i<len/2;i++)
        {
            double tmp =schr[i]*zengyi;
            avr=avr+sqrt(tmp*tmp);
        }
        avr=avr/(len/2);


            double cha=0;
            cha=((avr-3000.0)/10000.0);
            if(cha<0) cha*=0.5;
            if(cha>0) cha*=1.5;
            cha=(1.0-cha);
            if(cha<0.1) cha=0.1;
            if(cha>2) cha=2;
            zengyi*=cha;
            //qDebug()<<cha;
            if(zengyi<0.01) zengyi=0.01;
            if(zengyi>10)zengyi=10;
            //if(avr<2800) zengyi*=1.1;
            //if(avr>3200) zengyi*=0.9    ;

        for(int i=0;i<len/2;i++)
        {
            schr[i]=schr[i]*zengyi;
        }

    }
    */


        play->tempBuffer.append(ch,len);


}
