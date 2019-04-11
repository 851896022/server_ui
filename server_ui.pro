#-------------------------------------------------
#
# Project created by QtCreator 2018-09-19T14:17:25
#
#-------------------------------------------------
 
QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server_ui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    main_window.cpp \
    global.cpp \
    api/app.cpp \
    api/appinit.cpp \
    api/iconhelper.cpp \
    usercontrol/frminputbox.cpp \
    usercontrol/frmmessagebox.cpp \
    UI/setting.cpp \
    UI/ch.cpp \
    background/processmanagement.cpp \
    background/resavedata.cpp \
    UI/savesetwindow.cpp \
    background/player.cpp \
    background/clientSvr/clientserver.cpp \
    background/clientSvr/dataserver.cpp \
    background/clientSvr/audioserver.cpp \
    UI/edityxt.cpp \
    background/clientSvr/alarmserver.cpp \
    api/yxt/qReader.cpp \
    api/yxt/qRedis.cpp

HEADERS += \
    main_window.h \
    global.h \
    api/app.h \
    api/appinit.h \
    api/iconhelper.h \
    api/myhelper.h \
    usercontrol/frminputbox.h \
    usercontrol/frmmessagebox.h \
    UI/setting.h \
    UI/ch.h \
    background/processmanagement.h \
    background/resavedata.h \
    UI/savesetwindow.h \
    background/player.h \
    background/clientSvr/clientserver.h \
    background/clientSvr/dataserver.h \
    background/clientSvr/audioserver.h \
    UI/edityxt.h \
    background/clientSvr/alarmserver.h \
    api/yxt/qReader.h \
    api/yxt/qRedis.h

FORMS += \
    main_window.ui \
    usercontrol/frminputbox.ui \
    usercontrol/frmmessagebox.ui \
    UI/setting.ui \
    UI/ch.ui \
    UI/savesetwindow.ui \
    UI/edityxt.ui
RC_ICONS    = main.ico
RESOURCES += \
    file.qrc \
    other/rc.qrc
