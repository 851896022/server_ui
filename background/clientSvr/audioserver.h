#ifndef AUDIOSERVER_H
#define AUDIOSERVER_H

#include <QObject>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <global.h>
struct ListenList
{
    QString ip;
    int ch=999;
};
class AudioServer : public QObject
{
    Q_OBJECT
public:
    explicit AudioServer(QObject *parent = nullptr);
    QTcpServer *audioTcpServer;
    QUdpSocket *receivePcm[200];
    QUdpSocket *sendPcm;
    QList<ListenList> listenList;
    QList<QTcpSocket*> clientList;
signals:

public slots:
    void initThis();
    void newConnection();
    void onDisconnect();
    void onReadyRead();
    void readPcmData();
};

#endif // AUDIOSERVER_H
