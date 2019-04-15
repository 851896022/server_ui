#include "main_window.h"
#include "global.h"
#include <QApplication>
#include "background/processmanagement.h"
#include "background/resavedata.h"
#include <QDir>
#include <QFile>
#include <QDateTime>
#include "background/clientSvr/clientserver.h"

global *g;
void setDebugOutput(const QString &targetFilePath, const bool &argDateFlag = false);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setDebugOutput( qApp->applicationDirPath()+"/log/%1.log", true );
    qDebug()<<"new global";
    g=new global;

    processManagement *proManage=new processManagement;
    proManage->initHexToPcm();
    proManage->initAlarm();
    qDebug()<<"new main window";
    main_window w;
    qDebug()<<"new reSavedata";
    reSaveData r;
    g->threadList.append(&r);
    qDebug()<<"new clinet server";
    ClientServer clientServer;
    g->threadList.append(&clientServer);
    qDebug()<<"new clinet server initThis";
    clientServer.initThis();
    QObject::connect(&r,SIGNAL(sendALarm(int,int,QDateTime)),clientServer.alarmServer,SLOT(sendAlarmToClient(int,int,QDateTime)));
    QObject::connect(&r,SIGNAL(sendSim(int,float)),clientServer.alarmServer,SLOT(sendSimtoCLient(int,float)));
    qDebug()<<"new main windows show";
    w.show();

    return a.exec();
}
//日志生成
void setDebugOutput(const QString &rawTargetFilePath_, const bool &argDateFlag_)
{
    static QString rawTargetFilePath;
    static bool argDateFlag;

    rawTargetFilePath = rawTargetFilePath_;
    argDateFlag = argDateFlag_;

    class HelperClass
    {
    public:
        static void messageHandler(QtMsgType type, const QMessageLogContext &, const QString &message_)
        {
            QString message;

            switch ( type )
            {
                case QtDebugMsg:
                {
                    message = message_;
                    break;
                }
                case QtWarningMsg:
                {
                    message.append("Warning: ");
                    message.append(message_);
                    break;
                }
                case QtCriticalMsg:
                {
                    message.append("Critical: ");
                    message.append(message_);
                    break;
                }
                case QtFatalMsg:
                {
                    message.append("Fatal: ");
                    message.append(message_);
                    break;
                }
                default: { break; }
            }

            QString currentTargetFilePath;

            if ( argDateFlag )
            {
                currentTargetFilePath = rawTargetFilePath.arg( ( ( argDateFlag ) ? ( QDateTime::currentDateTime().toString("yyyy_MM_dd") ) : ( "" ) ) );
            }
            else
            {
                currentTargetFilePath = rawTargetFilePath;
            }

            if ( !QFileInfo::exists( currentTargetFilePath ) )
            {
                QDir().mkpath( QFileInfo( currentTargetFilePath ).path() );
            }

            QFile file( currentTargetFilePath );
            file.open( QIODevice::WriteOnly | QIODevice::Append );

            QTextStream textStream( &file );
            textStream << QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" ) << ": " << message << "\r"<<endl;
            {
            QTextStream textStream( stdout );
            textStream << QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss" ) << ": " << message << "\r"<<endl;
            }
        }
    };

    qInstallMessageHandler( HelperClass::messageHandler );
}
