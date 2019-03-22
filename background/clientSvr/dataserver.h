#ifndef DATASERVER_H
#define DATASERVER_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
#include <QTimer>
#include "global.h"
class DataServer : public QThread
{
    Q_OBJECT
public:
    explicit DataServer(QThread *parent = nullptr);
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
};

#endif // DATASERVER_H
