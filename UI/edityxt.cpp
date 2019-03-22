#include "edityxt.h"
#include "ui_edityxt.h"
#include "api/yxt/qRedis.h"
EditYxt::EditYxt(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::EditYxt)
{
    ui->setupUi(this);
    //读取发射机列表
    {
        QString fileDir=(qApp->applicationDirPath()+"/sav/transmitterlist.sav");
        QFile *file = new QFile(fileDir);
        if(file->open(QIODevice::ReadOnly))
        {

            for(int i=0;i<10000;i++)
            {
                {
                    QByteArray ba= file->readLine();
                    QString msg(QString::fromUtf8(ba));


                    msg.remove("\r");
                    msg.remove("\n");
                    transmitterName.append(msg);
                }
                if(file->atEnd())break;
            }
            file->close();

        }
        else
        {
            qDebug()<<"open error"<<fileDir;
        }
        qDebug()<<transmitterName;
        file->deleteLater();
    }
    for(int i=0;i<transmitterName.count();i++)
    {
        ui->nameList->addItem(transmitterName.at(i));
    }
}

EditYxt::~EditYxt()
{
    delete ui;
}

void EditYxt::on_btnAdd_clicked()
{
    int fre=ui->txtFre->text().toInt();
    if(fre>28000||fre<200)
    {
        return;
    }
    if(ui->startTime->time()>=ui->endTime->time())
    {
        return;
    }
    QString msg;
    msg.append(ui->startTime->time().toString("hh:mm:ss"));
    msg.append("|");
    msg.append(ui->endTime->time().toString("hh:mm:ss"));
    msg.append("|");
    msg.append(QString::number(fre));
    ui->timeList->addItem(msg);

}

void EditYxt::on_btnDelete_clicked()
{
    ui->timeList->takeItem(ui->timeList->currentRow());
}

void EditYxt::on_btnSave_clicked()
{
    //=========================================================================
    qRedis *redis=new qRedis(QString("127.0.0.1"),6379);
    if (!redis->openConnection())
    {
        QMessageBox::warning(NULL,"错误","保存失败！");
        delete redis;
        return;
    }
    else
    {
        QStringList baseList;
        {
            QString filename;
            filename+=(":/info.txt");
            //判断文件是否存在
            QFile *file = new QFile(filename);
            if(file->open(QIODevice::ReadOnly))
            {
                for(int i=0;i<10;i++)
                {
                    {
                        QString ba(file->readLine());
                        ba.remove('\r');
                        ba.remove('\n');
                        baseList.append(ba);
                    }


                    if(file->atEnd())break;
                }
                file->close();
            }
            file->deleteLater();
        }

        QString info;
        info.append("\"[");
        for(int i=0;i<ui->timeList->count();i++)
        {

            QString msg=ui->timeList->item(i)->text();
            QStringList msgList=msg.split("|");
            QString startTime=msgList.at(0);
            QString endTime=msgList.at(1);
            QString fre=msgList.at(2);
            info.append(baseList.at(0));
            info.append(endTime);
            info.append(baseList.at(1));
            info.append(fre);
            info.append(baseList.at(2));
            info.append(startTime);
            info.append(baseList.at(3));
            info.append(',');
        }
        if(info.count()>5)
        {
             info.chop(1);
        }

        info.append("]\"");

        redis->set(ui->nameList->currentText(),info);

    }
    delete redis;

    QMessageBox::warning(NULL,"信息","保存成功！");

}

void EditYxt::on_nameList_currentIndexChanged(int index)
{
    ui->timeList->clear();
    qRedis *redis=new qRedis(QString("127.0.0.1"),6379);
    if (!redis->openConnection())
    {
        QMessageBox::warning(NULL,"错误","无法连接！");
        delete redis;
        return;
    }
    else
    {
       QString name=ui->nameList->itemText(index);
       QString msg=redis->get(name);
           if(msg.count()<2)
           {
               qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get big error"<<msg;
               //continue;
           }

           //qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<msg.at(0)<<msg.at(msg.count()-1);
           //if((msg.at(0)!='[')||(msg.at(msg.count()-1)!=']')) qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<g->transmitterName.at(i)<<" get error";
           QJsonParseError json_error;
           QJsonDocument parse_doucment = QJsonDocument::fromJson(msg.toStdString().data(),&json_error);
           if(json_error.error == QJsonParseError::NoError)
           {
               //qDebug() << "redis Thread : " << QThread::currentThreadId()<<"|"<<" get "<<g->transmitterName.at(i)<<"ok";

               int atomCount=parse_doucment.array().count();
               //qDebug()<<"共读取到"<<atomCount<<"条";
               //读取N个开机时间段
               for(int i=0;i<atomCount;i++)
               {
                   QJsonObject obj=parse_doucment.array().at(i).toObject();
                   QString endTime=obj.take("endTime").toString().split(' ').at(1);
                   QString freq=obj.take("freq").toString();
                   QString startTime=obj.take("startTime").toString().split(' ').at(1);

                   ui->timeList->addItem(QString(startTime+"|"+endTime+"|"+freq));
               }
           }
           else
           {
               qDebug()  << QThread::currentThreadId()<<"|"<<name<<" get error";
           }

    }
    delete redis;

}
