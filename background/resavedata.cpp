#include "resavedata.h"

reSaveData::reSaveData(QObject *parent) : QObject(parent)
{
    qDebug()<<"new socket";
    socket=new QUdpSocket;
    g->threadList.append(socket);
    qDebug()<<"socket connect";
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReceived()));
    qDebug()<<"socket bind";
    socket->bind(2500,QAbstractSocket::DontShareAddress);
}
void reSaveData::onReceived()
{
    unsigned char ch[65536]={0};
    int realsize=socket->readDatagram((char*)ch, 65536);
    if(realsize>0)
    {
        QStringList rDataList= QString(QByteArray((char*)ch,realsize)).split(";");
        for(int i=0;i<rDataList.count()-1;i++)
        {
            QStringList rData= rDataList.at(i).split("|");
            int num=rData.at(0).toInt();
            switch (num)
            {
            case 0://APM
                {
                    int num=rData.at(1).toInt();
                    for(int i=0;i<18;i++)
                    {
                        g->apm[num*18+i]=rData.at(i+2).toInt();
                    }
                    break;
                }
            case 1://录音信息
                {
                    int num=rData.at(1).toInt();

                    g->nowFileName[num]=QString(QByteArray::fromBase64(rData.at(2).toLatin1()));

                    break;
                }
            case 2://报警信息
                {

                    AlarmInfo msg;
                    if(rData.count()>=4)
                    {
                        msg.alarmCh=rData.at(1).toInt();
                        msg.alarmType=AlarmType(rData.at(2).toInt()) ;
                        msg.startTime=QDateTime::fromString(rData.at(3),"yyyy-MM-dd hh:mm:ss");
                    }
                    g->alarmListWaitSend.append(msg);
                    emit sendALarm(msg.alarmCh,msg.alarmType,msg.startTime);
                    break;
                }
            case 3://相似度信息
                {
                    if(rData.count()>=3)
                    {
                        int ch=rData.at(1).toInt();
                        float sim=rData.at(2).toFloat();
                        g->audioSim[ch]=sim;
                        emit sendSim(ch,sim);

                    }
                    break;
                }
            default:
                break;
            }
        }


    }
}
