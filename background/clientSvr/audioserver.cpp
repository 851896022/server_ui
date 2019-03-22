#include "audioserver.h"

AudioServer::AudioServer(QObject *parent) : QObject(parent)
{

}
void AudioServer::initThis()
{
    audioTcpServer=new QTcpServer;
    for(int i=0;i<200;i++)receivePcm[i]=new QUdpSocket;
    sendPcm= new QUdpSocket;
    //for(int i=0;i<100;i++)listenList[i]=new ListenList;
    //========================================================
    connect(audioTcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
    audioTcpServer->listen(QHostAddress::Any,59878);
    //========================================================
    for(int i=0;i<200;i++)
    {
        connect(receivePcm[i],SIGNAL(readyRead()),this,SLOT(readPcmData()));
        receivePcm[i]->bind(50000+(i*10)+3);
    }

      qDebug()<<QString("client listen server init success Thread")<<QThread::currentThreadId()<<QString("listen 59878");
}
void AudioServer::newConnection()
{
    if(audioTcpServer->hasPendingConnections())
    {

        clientList.append(audioTcpServer->nextPendingConnection());
        connect(clientList.last(),SIGNAL(disconnected()),this,SLOT(onDisconnect()));

        connect(clientList.last(),SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    }
    qDebug()<<"new connect";

}
void AudioServer::onDisconnect()
{
    //BUG 预警，当run发送时，删除socket，会发生不可预料的事情。
    //int count=clientList.count();
    for(int i=0;i<clientList.count();i++)
    {
        if(clientList.at(i)->state()==QAbstractSocket::UnconnectedState)
        {
            QTcpSocket *tmp=clientList.at(i);
            clientList.removeAt(i);

            qDebug()<<" remove audio client"<<i<<tmp->peerAddress()<<tmp->peerPort()<<tmp->peerName();
            tmp->deleteLater();
        }
    }
}
void AudioServer::onReadyRead()
{
    //qDebug()<<1;
    for(int i=0;i<clientList.count();i++)
    {
        //qDebug()<<2;
        if(clientList.at(i)->bytesAvailable()>0)
        {
            //qDebug()<<3;
            //====处理上传数据====
            QByteArray ba=clientList.at(i)->readAll();
            QString msg(ba);
            //qDebug()<<msg;
            QStringList msgList=msg.split("|");
            //qDebug()<<msgList.first().toInt();
            if(msgList.first().toInt()==0)
            {
                //qDebug()<<msgList.count();
                if(msgList.count()>=3)
                {
                    QString receIp=msgList.at(1);
                    //qDebug()<<receIp;
                    int count=listenList.count();
                    for(int i=0;i<=count;i++)
                    {
                        //qDebug()<<i<<listenList.count();
                        if(i==count)
                        {
                            ListenList tmp;
                            tmp.ip=msgList.at(1);
                            tmp.ch=msgList.at(2).toInt();
                            listenList.append(tmp);
                            qDebug()<<"add listen"<<tmp.ip<<tmp.ch;
                        }
                        else
                        {
                            if(listenList.at(i).ip==receIp)
                            {

                                ListenList tmp;
                                tmp.ip=msgList.at(1);
                                tmp.ch=msgList.at(2).toInt();
                                listenList.append(tmp);
                                listenList.removeAt(i);
                                qDebug()<<"change listen"<<tmp.ip<<tmp.ch;
                                break;
                            }
                        }

                    }
                }
            }


        }
        else
        {
            QByteArray ba;
            ba=clientList.at(i)->readAll();
        }

    }
    /*
    qDebug()<<"------------";
    foreach (ListenList tmp, listenList) {
        qDebug()<<tmp.ip<<tmp.ch;
    }
    qDebug()<<"------------";
    */
}
void AudioServer::readPcmData()
{
    QObject *sed=sender();
    int i=0;
    for(i=0;i<200;i++)
    {
        if(receivePcm[i]==sed)
        {
            break;
        }
    }



        if(receivePcm[i]->hasPendingDatagrams())
        {
            //qDebug()<<"recev pcm "<<i<<receivePcm[i]->bytesAvailable();
            char ch[32768];
            if(receivePcm[i]->bytesAvailable()==2304)
            {

                int size=receivePcm[i]->readDatagram(ch,32768);
                g->audioCache[i].clear();
                g->audioCache[i].append(ch,size);
                int tmpCh=i;
                for(int i=0;i<listenList.count();i++)
                {
                    if(listenList.at(i).ch==tmpCh)
                    {
                        sendPcm->writeDatagram(ch,size,QHostAddress(listenList.at(i).ip) ,59876);
                    }
                }
            }
            else
            {
                receivePcm[i]->readDatagram(ch,32768);
            }
        }

}
