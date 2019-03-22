#ifndef ALARMSERVER_H
#define ALARMSERVER_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QTimer>
#include "global.h"
class AlarmServer : public QObject
{
    Q_OBJECT
public:
    explicit AlarmServer(QObject *parent = nullptr);
    QTcpServer *dataTcpServer;
    QList<QTcpSocket*> clientList;
    QTimer *sendTimer;
    QTimer *initTimer;
private:

signals:

public slots:
    void initThis();
    void newConnection();
    void onDisconnect();
    void startSend();
    void sendAlarmToClient(int ch,int type,QDateTime startTime);
    void sendSimtoCLient(int ch,float sim);
};

#endif // ALARMSERVER_H
