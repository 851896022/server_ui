#include "qredismanager.h"
#include "QThread"
qRedisManager::qRedisManager(QObject *parent) : QObject(parent)
{
    tmpt=new QTimer;
    connect(tmpt,SIGNAL(timeout()),this,SLOT(linkstart()));
    tmpt->setSingleShot(true);
    tmpt->start(50);

}
void qRedisManager::linkstart()
{
    qDebug() << "redis Thread 1: " << QThread::currentThreadId()<<"start to connect"<<g->redisIp<<g->redisPort;
    redis = new qRedis(g->redisIp,g->redisPort);


    if (!redis->openConnection())
    {
        qDebug() << "redis Thread 1: " << QThread::currentThreadId() << "Could not connect to server...";
        return;
    }
    else
    {
        qDebug() << "redis Thread 1: " << QThread::currentThreadId() << "redis connect success";
    }

    timer=new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(timerTimeOut()),Qt::QueuedConnection);
    timer->start(50);
}
void qRedisManager::timerTimeOut()
{
    timer->stop();
    //qDebug() << "redis Thread 2: " << QThread::currentThreadId();

    //读取18个发射机数据
    for(int i=0;i<g->transmitterName.count();i++)
    {//qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get "<<g->transmitterName.at(i);
    {
        QString msg=redis->get(g->transmitterName.at(i));
        if(msg.count()<2)
        {
            qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get big error"<<msg;
            //continue;
        }

        //qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<msg.at(0)<<msg.at(msg.count()-1);
        if((msg.at(0)!='[')||(msg.at(msg.count()-1)!=']')) qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<g->transmitterName.at(i)<<" get error";
        QJsonParseError json_error;
        QJsonDocument parse_doucment = QJsonDocument::fromJson(msg.toStdString().data(),&json_error);
        if(json_error.error == QJsonParseError::NoError)
        {
            //qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get "<<g->transmitterName.at(i)<<"ok";

            int atomCount=parse_doucment.array().count();
            //qDebug()<<"共读取到"<<atomCount<<"条";
            //读取N个开机时间段
            yxtbase atom[atomCount];
            for(int i=0;i<atomCount;i++)
            {
                QJsonObject obj=parse_doucment.array().at(i).toObject();
                atom[i].afterGapMinute=int(obj.take("afterGapMinute").toDouble());
                atom[i].antUsedCode=obj.take("antUsedCode").toString();
                atom[i].azimuthM=obj.take("azimuthM").toString();
                atom[i].beforeGapMinute=int(obj.take("beforeGapMinute").toDouble());

                atom[i].days=obj.take("days").toString();
                atom[i].endTime=obj.take("endTime").toString();
                atom[i].freq=obj.take("freq").toString();
                atom[i].power=obj.take("power").toString();

                atom[i].progChannel=obj.take("progChannel").toString();
                atom[i].progCode=obj.take("progCode").toString();
                atom[i].progName=obj.take("progName").toString();
                atom[i].rmks=obj.take("rmks").toString();

                atom[i].runid=int(obj.take("runid").toDouble());
                atom[i].startTime=obj.take("startTime").toString();
                atom[i].syncTime=obj.take("syncTime").toString();
                atom[i].taskType=obj.take("taskType").toString();

                atom[i].transUsedCode=obj.take("transUsedCode").toString();

                QStringList startlist1=atom[i].startTime.split(" ");
                if(startlist1.count()==2)
                {
                    QStringList startlist2=startlist1.at(1).split(":");
                    if(startlist2.count()==3)
                    {
                        atom[i].startTimeInt=startlist2.at(0).toInt()*60+startlist2.at(1).toInt();

                    }
                }

                QStringList endlist1=atom[i].endTime.split(" ");
                if(endlist1.count()==2)
                {
                    QStringList endlist2=endlist1.at(1).split(":");
                    if(endlist2.count()==3)
                    {
                        atom[i].endTimeInt=endlist2.at(0).toInt()*60+endlist2.at(1).toInt();
                        if(atom[i].endTimeInt==0)atom[i].endTimeInt=1440;
                    }
                }
                /*
                qDebug()<<atom[i].freq;
                qDebug()<<atom[i].startTime<<"--"<<atom[i].endTime;
                qDebug()<<atom[i].startTimeInt<<"--"<<atom[i].endTimeInt;
                */
            }
            //将开机时间段处理成7天运行图

            //运行图排序
            {

                for(int i=0;i<atomCount-1;i++)
                {
                    for(int j=0;j<atomCount-1;j++)
                    {
                        if(atom[j].startTimeInt>atom[j+1].startTimeInt)
                        {
                            yxtbase atomtmp=atom[j];
                            atom[j]=atom[j+1];
                            atom[j+1]=atomtmp;
                        }
                    }
                }


            }


            int tmp=atomCount;
            QList<yxtbase> yxtatom;
            yxtbase yxtnone;


            for(int i=0;i<tmp;i++)
            {
                yxtatom<<atom[i];
            }
            if(tmp==0)//ru guo mei you,tian jia
            {
                yxtbase yxt=g->yxtEmpty;
                yxt.startTimeInt=0;
                yxt.endTimeInt=1440;
                yxtatom.insert(0,yxt);
                tmp++;
            }
            //yun xing tu shai xuan,you hen da wen ti
            /*
            for(int i=0;i<tmp;i++)
            {
                QStringList strlist;
                strlist=yxtatom.at(i).startTime.split(" ");
                QDateTime local(QDateTime::currentDateTime());
                QString localTime = local.toString("yyyy-MM-dd");
                //qDebug()<<strlist.at(0)<<"\t"<<localTime;
                if(!(strlist.at(0)==localTime))
                {
                    yxtatom.removeAt(i);
                    tmp--;
                }
            }
            */

            //yun xing tu qu chong
            for(int i=0;i<tmp-1;i++)
            {
                if(yxtatom.at(i).freq==yxtatom.at(i+1).freq
                        &&yxtatom.at(i).progCode==yxtatom.at(i+1).progCode
                        &&yxtatom.at(i).startTimeInt==yxtatom.at(i+1).startTimeInt
                        &&yxtatom.at(i).endTimeInt==yxtatom.at(i+1).endTimeInt
                        )
                {
                    yxtatom.removeAt(i+1);
                    //qDebug()<<"qu chong"<<yxtatom.at(i+1).startTime;
                    tmp--;
                }
            }
            //插入空白运行图

            if((!(yxtatom.at(0).startTimeInt==0)))
            {
                yxtbase yxt=g->yxtEmpty;
                yxt.startTimeInt=0;
                yxt.endTimeInt=yxtatom.at(0).startTimeInt;
                yxtatom.insert(0,yxt);
                tmp++;

            }

            for(int i=0;i<tmp-1;i++)
            {
                if(!(yxtatom.at(i).endTimeInt==yxtatom.at(i+1).startTimeInt))
                {
                    yxtbase yxt=g->yxtEmpty;
                    yxt.startTimeInt=yxtatom.at(i).endTimeInt;
                    yxt.endTimeInt=yxtatom.at(i+1).startTimeInt;
                    yxtatom.insert(i+1,yxt);
                    tmp++;

                }
            }
            if(!(yxtatom.last().endTimeInt==1440))
            {
                yxtbase yxt=g->yxtEmpty;
                yxt.startTimeInt=yxtatom.last().endTimeInt;
                yxt.endTimeInt=1440;
                yxtatom.append(yxt);
                tmp++;
            }



            //合并运行图，bug预警
            for(int i=0;i<tmp-1;i++)
            {
                if(yxtatom.at(i).freq==yxtatom.at(i+1).freq&&yxtatom.at(i).progCode==yxtatom.at(i+1).progCode)
                {
                    yxtbase yxt=yxtatom.at(i);
                    yxt.endTimeInt=yxtatom.at(i+1).endTimeInt;
                    yxt.endTime=yxtatom.at(i+1).endTime;
                    yxtatom.removeAt(i+1);
                    yxtatom.insert(i,yxt);
                    yxtatom.removeAt(i+1);
                    i--;
                    tmp--;
                }
            }


            //把给人看的写进去

            g->ch[i].name=g->transmitterName.at(i);
            for(int day=0;day<7;day++)
            {
                for(int cot=0;cot<50;cot++)
                {

                    {
                        g->ch[i].day[day].timeQuantum[cot]=yxtnone;
                    }
                }
            }
            for(int day=0;day<7;day++)
            {
                for(int cot=0;cot<50;cot++)
                {
                    if(cot<yxtatom.count())
                    {
                        g->ch[i].day[day].timeQuantum[cot]=yxtatom.at(cot);
                    }
                }
            }


                for(int each=0;each<50;each++)
                {

                    //qDebug()<<g->ch[i].day[0].timeQuantum[each].startTimeInt<<"\t"<<g->ch[i].day[0].timeQuantum[each].endTimeInt<<"\t"<<g->ch[i].day[0].timeQuantum[each].freq;
                }
            //把给机器看的写进去
            int yxtnum=0;
            for(int day=0;day<7;day++)
            {
                yxtnum=0;
                for(int min=0;min<1440;min++)
                {
                    if(yxtatom.at(yxtnum).endTimeInt>min)
                    {
                        g->ch[i].day[day].min[min].info=yxtatom.at(yxtnum);
                        g->ch[i].day[day].min[min].timeFormStart=min-yxtatom.at(yxtnum).startTimeInt;
                        g->ch[i].day[day].min[min].timeToEnd=yxtatom.at(yxtnum).endTimeInt-min;
                        if(yxtatom.at(yxtnum).freq=="")
                        {
                            g->ch[i].day[day].min[min].transmit=false;
                        }
                        else
                        {
                            g->ch[i].day[day].min[min].transmit=true;
                        }

                    }
                    else
                    {
                        yxtnum++;
                        if(yxtnum<yxtatom.count())min--;
                        else break;

                    }


                }
            }
            for(int min=0;min<1440;min++)
            {
                //qDebug()<<min<<"\t"<<g->ch[i].day[0].min[min].timeFormStart<<"\t"<<g->ch[i].day[0].min[min].timeToEnd<<"\t"<<g->ch[i].day[0].min[min].transmit<<"\t"<<g->ch[i].day[0].min[min].info.freq;
            }
            //g->yxtAtomCh[i]=yxtatom;
            //qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get "<<g->transmitterName.at(i)<<"do end";
        }
        else
        {
            qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<g->transmitterName.at(i)<<" get error";
        }
    }
    }
    timer->start(10000);
}
