#ifndef CLIENTSERVER_H
#define CLIENTSERVER_H

#include <QObject>
#include "audioserver.h"
#include "dataserver.h"
#include "alarmserver.h"
#include "QThread"
class ClientServer : public QObject
{
    Q_OBJECT
public:
    explicit ClientServer(QObject *parent = nullptr);
    AudioServer *audioServer;
    DataServer  *dataServer;
    AlarmServer *alarmServer;
    QThread dataServerThread;
    QThread audioServerThread;
    QThread alarmServerThread;
signals:

public slots:
    void initThis();
};

#endif // CLIENTSERVER_H
