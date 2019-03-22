#ifndef PROCESSMANAGEMENT_H
#define PROCESSMANAGEMENT_H

#include <QObject>
#include <global.h>
class processManagement : public QObject
{
    Q_OBJECT
public:
    explicit processManagement(QObject *parent = nullptr);
    QProcess *hexToPcm[10];
    QProcess *alarm;
    ~processManagement();
signals:

public slots:
    void initHexToPcm();
    void initAlarm();
};

#endif // PROCESSMANAGEMENT_H
