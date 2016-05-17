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
    src/DeviceClass.cpp \
    src/ObjectClass.cpp \
    src/ObjectsUpdater.cpp \
    src/util/MyException.cpp \
    src/db/dbFinder.cpp \
    src/notConnectionDb.cpp \
    src/FaultsClass.cpp \
    src/UbdaterClass.cpp \
    src/baseDevice.cpp \
    src/ActiveDev.cpp  \
    src/db/dbDevices.cpp \
    src/BSPurWid.cpp \
    src/PurBut.cpp \
    src/BSPurBut.cpp \
    src/OtherDevWid.cpp \
    src/OtherDevBut.cpp

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
    include/StandBut.h \
    include/frameborder.h \
    include/DeviceClass.h \
    include/ObjectClass.h \
    include/ObjectsUpdater.h \
    include/util/MyException.h \
    include/db/dbFinder.h \
    include/notConnectionDb.h \
    include/FaultsClass.h \
    include/UbdaterClass.h \
    include/baseDevice.h \
    include/ActiveDev.h \
    include/db/dbDevices.h \
    include/BSPurWid.h \
    include/PurBut.h \
    include/BSPurBut.h \
    include/OtherDevWid.h \
    include/OtherDevBut.h

FORMS    += \
    ui/rightWidget.ui \
    ui/ClockFrame.ui \
    ui/SetName.ui \
    ui/StateChanFrame.ui \
    ui/mainFrame.ui \
    ui/ObjectPA.ui \
    ui/notConnectionDb.ui

OTHER_FILES += \
    style.qss \
    mir_vto.conf
