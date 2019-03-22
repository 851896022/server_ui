#ifndef QREDISMANAGER_H
#define QREDISMANAGER_H

#include <QObject>
#include <QDebug>
#include <QMap>
#include "qRedis.h"
#include <QTime>
#include <QTimer>
#include "global.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include <QList>
class qRedisManager : public QObject
{
    Q_OBJECT
public:
    explicit qRedisManager(QObject *parent = nullptr);
    qRedis *redis;
    QTimer *timer;
    QTimer *tmpt;

public slots:
    void timerTimeOut();
    void linkstart();

signals:
    void yxtReady();
public slots:
};

#endif // QREDISMANAGER_H
