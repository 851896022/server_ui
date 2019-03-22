#include "dataserver.h"

DataServer::DataServer(QThread *parent) : QThread(parent)
{
    /*
    initTimer= new QTimer;
    initTimer->setSingleShot(true);
    connect(initTimer,SIGNAL(timeout()),this,SLOT(initThis()));
    initTimer->start(200);
    */

}
void DataServer::initThis()
{
    dataTcpServer= new QTcpServer;
    sendTimer=new QTimer;
    //===============================
    connect(dataTcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
    dataTcpServer->listen(QHostAddress::AnyIPv4,59877);
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(startSend()));
    sendTimer->start(200);
    qDebug()<<QString("client data server init success Thread")<<QThread::currentThreadId()<<QString("listen 59877");

}
void DataServer::newConnection()
{
    if(dataTcpServer->hasPendingConnections())
    {

        clientList.append(dataTcpServer->nextPendingConnection());
        connect(clientList.last(),SIGNAL(disconnected()),this,SLOT(onDisconnect()));
        qDebug()<<" new client data"<<clientList.last()->peerAddress()<<clientList.last()->peerPort()<<clientList.last()->peerName();
        //connect(&clientList.end(),SIGNAL(readyRead()),this,SLOT(onDisconnect()));
    }

}
void DataServer::onDisconnect()
{
    //BUG 预警，当run发送时，删除socket，会发生不可预料的事情。
    int count=clientList.count();
    for(int i=0;i<count;i++)
    {
        if(clientList.at(i)->state()==QAbstractSocket::UnconnectedState)
        {
            QTcpSocket *tmp=clientList.at(i);
            clientList.removeAt(i);
            count--;
            qDebug()<<" remove client data"<<i<<tmp->peerAddress()<<tmp->peerPort()<<tmp->peerName();
            tmp->deleteLater();
        }
    }
}
void DataServer::startSend()
{
    QString str;
    str+="0|";
    for(int i=0;i<200;i++)
    {
        str+=QString::number(g->apm[i]);//测试用到时吧0改成i
        str+="|";
    }
    str+=";";
    QByteArray ba=str.toLatin1();
    for(int i=0;i<clientList.count();i++)
    {
        //qDebug()<<i<<clientList.count();
        clientList.at(i)->write(ba);
        //qDebug()<<"send to"<<clientList.at(i)->peerAddress()<<clientList.at(i)->peerPort();
    }

}

