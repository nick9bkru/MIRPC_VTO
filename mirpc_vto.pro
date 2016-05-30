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
    src/ClockFrame.cpp \
    src/SetNameDialog.cpp \
    src/ObjectPA.cpp \
    src/blinkingclass.cpp \
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
    src/BSPurWid.cpp \
    src/OtherDevWid.cpp \
    src/db/dbFaults.cpp \
    src/db/dbActive.cpp \
    src/db/dbSound.cpp \
    src/db/dbclass.cpp \
    src/db/dbDevices.cpp \
    src/db/dbMainObject.cpp \
    src/buttom/BSPurBut.cpp \
    src/buttom/butparent.cpp \
    src/buttom/ChanButton.cpp \
    src/buttom/DeviceBut.cpp \
    src/buttom/OtherDevBut.cpp \
    src/buttom/PurBut.cpp \
    src/buttom/StandBut.cpp \
    src/buttom/SoundBut.cpp

HEADERS  += \
    include/StateChanFrame.h \
    include/rightWidget.h \
    include/ClockFrame.h \
    include/define.h \
    include/SetNameDialog.h \
    include/MainWindow.h \
    include/ObjectPA.h \
    include/MainFrame.h \
    include/util/Singleton.h \
    include/blinkingclass.h \
    include/frameborder.h \
    include/DeviceClass.h \
    include/ObjectClass.h \
    include/ObjectsUpdater.h \
    include/util/MyException.h \
    include/notConnectionDb.h \
    include/FaultsClass.h \
    include/UbdaterClass.h \
    include/baseDevice.h \
    include/ActiveDev.h \
    include/db/dbDevices.h \
    include/BSPurWid.h \
    include/OtherDevWid.h \
    include/db/dbFaults.h \
    include/db/dbActive.h \
    include/db/dbSound.h \
    include/db/dbFinder.h \
    include/db/dbclass.h \
    include/db/dbMainObject.h \
    include/buttom/BSPurBut.h \
    include/buttom/butparent.h \
    include/buttom/ChanButton.h \
    include/buttom/DeviceBut.h \
    include/buttom/OtherDevBut.h \
    include/buttom/PurBut.h \
    include/buttom/StandBut.h \
    include/buttom/SoundBut.h

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

DISTFILES +=

RESOURCES += \
    imageresourse.qrc
