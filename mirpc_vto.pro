#-------------------------------------------------
#
# Project created by QtCreator 2015-09-03T10:20:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mirpc_vto
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
LIBS +=

SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/StateChanFrame.cpp \
    src/MainFrame.cpp \
    src/rightWidget.cpp \
    src/DeviceBut.cpp \
    src/ClockFrame.cpp \
    src/SetNameDialog.cpp \
    src/ChanButton.cpp \
    src/ObjectPA.cpp \
    src/blinkingclass.cpp \
    src/butparent.cpp \
    src/StandBut.cpp \
    src/db/dbclass.cpp \
    src/db/dbMainObject.cpp \
    src/db/dbStandDevice.cpp \
    src/db/dbStateChan.cpp

HEADERS  += \
    include/StateChanFrame.h \
    include/DeviceBut.h \
    include/rightWidget.h \
    include/ClockFrame.h \
    include/define.h \
    include/ChanButton.h \
    include/SetNameDialog.h \
    include/MainWindow.h \
    include/ObjectPA.h \
    include/MainFrame.h \
    include/util/Singleton.h \
    include/blinkingclass.h \
    include/butparent.h \
    include/db/dbclass.h \
    include/db/dbMainObject.h \
    include/db/dbStandDevice.h \
    include/db/dbStateChan.h \
    include/StandBut.h

FORMS    += \
    ui/rightWidget.ui \
    ui/ClockFrame.ui \
    ui/SetName.ui \
    ui/StateChanFrame.ui \
    ui/mainFrame.ui \
    ui/ObjectPA.ui

OTHER_FILES += \
    style.qss
