#include "clientserver.h"

ClientServer::ClientServer(QObject *parent) : QObject(parent)
{

}
void ClientServer::initThis()
{
    qDebug()<<"client server"<<QThread::currentThreadId();
    //==========data=========================

    dataServer=new DataServer;
    dataServer->moveToThread(&dataServerThread);
    g->threadList.append(&dataServerThread);
    connect(&dataServerThread,SIGNAL(started()),dataServer,SLOT(initThis()));
    dataServerThread.start();
    //==========audio========================
    audioServer=new AudioServer;
    audioServer->moveToThread(&audioServerThread);
    g->threadList.append(&dataServerThread);
    connect(&audioServerThread,SIGNAL(started()),audioServer,SLOT(initThis()));
    audioServerThread.start();
    //==========alarm============================
    alarmServer=new AlarmServer;
    alarmServer->moveToThread(&alarmServerThread);
    g->threadList.append(&alarmServerThread);
    connect(&audioServerThread,SIGNAL(started()),alarmServer,SLOT(initThis()));
    alarmServerThread.start();

}
//=============================================================
//=========data===数据交换部分===================================
//=============================================================
