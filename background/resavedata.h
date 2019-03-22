#ifndef RESAVEDATA_H
#define RESAVEDATA_H

#include <QObject>
#include <QHostAddress>
#include <QUdpSocket>
#include "global.h"
class reSaveData : public QObject
{
    Q_OBJECT
public:
    explicit reSaveData(QObject *parent = nullptr);
    QUdpSocket *socket;
signals:
    //void sendALarm(AlarmInfo msg);
    void sendALarm(int,int,QDateTime);
    void sendSim(int ch,float sim);
public slots:
    void onReceived();
};

#endif // RESAVEDATA_H
