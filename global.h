#ifndef GLOBAL_H
#define GLOBAL_H
#include <QTime>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QUdpSocket>
#include "api/myhelper.h"
#include "background/player.h"
#include <QList>
#include <QThread>
struct equStruct
{
    QString chName[18];
    QString ip;
    int port={0};
    int No={0};
    QString name;

};
enum AlarmType
{
    Normal,
    Similar,
    Range,
    All,
    SimilarCancel,
    RangeCancel,
    Other,

};
struct AlarmInfo
{
    int alarmNo=0;
    int alarmCh=0;
    AlarmType alarmType=Other;
    QDateTime startTime;
    QDateTime endTime;
};
class global : public QObject
{
    Q_OBJECT
public:
    explicit global(QObject *parent = nullptr);
    equStruct equ[10];
    int equCount;
    QString mp3SaveDir;
    //==============================
    int apm[200]={0};
    QString nowFileName[200];
    //---------------
    int playingCh=0;

    player *play;
    double zengyi=1;
    //------------------
    QUdpSocket receivePCM;
    //===client-server=============
    QByteArray audioCache[200];
    QList<AlarmInfo> alarmListWaitSend;
    float audioSim[200]={0};
    QList<QObject*> threadList;
    //~global();
signals:

public slots:
    void loadEqu();
    void changePlayCh(int);
    void stopPlay();
    void onReceivePCM();
};
extern global *g;
#endif // GLOBAL_H
