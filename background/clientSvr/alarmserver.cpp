#include "alarmserver.h"

AlarmServer::AlarmServer(QObject *parent) : QObject(parent)
{

}
void AlarmServer::initThis()
{
    dataTcpServer= new QTcpServer;
    sendTimer=new QTimer;
    //===============================
    connect(dataTcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
    dataTcpServer->listen(QHostAddress::AnyIPv4,59879);
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(startSend()));
    //不定期发送
    //sendTimer->start(200);
    qDebug()<<QString("client alarm server init success Thread")<<QThread::currentThreadId()<<QString("listen 59879");

}
void AlarmServer::newConnection()
{
    if(dataTcpServer->hasPendingConnections())
    {

        clientList.append(dataTcpServer->nextPendingConnection());
        connect(clientList.last(),SIGNAL(disconnected()),this,SLOT(onDisconnect()));
        qDebug()<<" new client alarm"<<clientList.last()->peerAddress()<<clientList.last()->peerPort()<<clientList.last()->peerName();
        //connect(&clientList.end(),SIGNAL(readyRead()),this,SLOT(onDisconnect()));
    }

}
void AlarmServer::onDisconnect()
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
            qDebug()<<" remove client alarm"<<i<<tmp->peerAddress()<<tmp->peerPort()<<tmp->peerName();
            tmp->deleteLater();
        }
    }
}
void AlarmServer::startSend()
{
    return;//无用函数
    QString str;
    str+="0|";
    for(int i=0;i<200;i++)
    {
        str+=QString::number(g->apm[i]);//测试用到时吧0改成i
        str+="|";
    }
    QByteArray ba=str.toLatin1();
    for(int i=0;i<clientList.count();i++)
    {
        //qDebug()<<i<<clientList.count();
        clientList.at(i)->write(ba);
        qDebug()<<"send to"<<clientList.at(i)->peerAddress()<<clientList.at(i)->peerPort();
    }
}
void AlarmServer::sendAlarmToClient(int ch,int type,QDateTime startTime)
{

    QString data;
    data+="2|";
    data+=QString::number(ch);
    data+="|";

    data+=QString::number(type);
    data+="|";
    data+=startTime.toString("yyyy-MM-dd hh:mm:ss");
    data+=";";
    QByteArray ba=data.toLatin1();
    for(int i=0;i<clientList.count();i++)
    {
        //qDebug()<<i<<clientList.count();
        clientList.at(i)->write(ba);
        qDebug()<<"send to alarm"<<clientList.at(i)->peerAddress()<<clientList.at(i)->peerPort();
    }


}
void AlarmServer::sendSimtoCLient(int ch,float sim)
{
    QString data;
    data+="3|";
    data+=QString::number(ch);
    data+="|";
    data+=QString::number(sim);
    data+="|";
    data+=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    data+=";";
    QByteArray ba=data.toLatin1();
    for(int i=0;i<clientList.count();i++)
    {
        //qDebug()<<i<<clientList.count();
        clientList.at(i)->write(ba);
        //qDebug()<<"send to sim"<<clientList.at(i)->peerAddress()<<clientList.at(i)->peerPort();
    }

}

