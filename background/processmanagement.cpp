#include "processmanagement.h"

processManagement::processManagement(QObject *parent) : QObject(parent)
{

}
processManagement::~processManagement()
{
    for(int i=0;i<10;i++)
    {
        if(hexToPcm[i]!=NULL)
        {
            hexToPcm[i]->kill();
        }
    }
    alarm->kill();
}
void processManagement::initHexToPcm()
{
    int equCount=10;
    for(int i=0;i<10;i++)
    {
        if(g->equ[i].port==0)
        {
            equCount=i;
            break;
        }
    }

    for (int i=0;i<equCount;i++)
    {
        {
            QString workdir;
            workdir=qApp->applicationDirPath();
            QString program;
            program="hex_to_pcm.exe";
            QStringList arguments;

            QString tmp;
            tmp=QString::number(g->equ[i].port);
            arguments.append(tmp);
            QString tmp1;
            tmp1=QString::number(i);
            arguments.append(tmp1);
            //arguments.append("存储位置");
            hexToPcm[i]=new QProcess(this);
            hexToPcm[i]->setWorkingDirectory(workdir);
            hexToPcm[i]->setProgram(program);
            hexToPcm[i]->setArguments(arguments);
            hexToPcm[i]->start();
            hexToPcm[i]->waitForBytesWritten();
            qDebug()<<"hextopcm"<<i<<hexToPcm[i]->state();
        }
    }

}
void processManagement::initAlarm()
{
    QString workdir;
    workdir=qApp->applicationDirPath();
    QString program;
    program="alarm_server.exe";
    alarm=new QProcess(this);
    alarm->setWorkingDirectory(workdir);
    alarm->setProgram(program);
    alarm->start();
    alarm->waitForBytesWritten();
}

