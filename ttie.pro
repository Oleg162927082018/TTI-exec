VERSION = 0.1.0.0
QMAKE_TARGET_PRODUCT = Total Test Integrator Testing Plan Executor
QMAKE_TARGET_DESCRIPTION = Testing plans console executor
QMAKE_TARGET_COPYRIGHT = Copyright\xA9 Oleg Kopyev 2018-2019

QT += core
QT -= gui
QT += xml
QT += widgets

CONFIG += c++11

TARGET = ttie
CONFIG += console
CONFIG -= app_bundle
RC_ICONS = tti.ico

TEMPLATE = app

SOURCES += main.cpp \
    tti-executor-application.cpp \
    ../TTI/Common/RunManager/runmanager.cpp \
    ../TTI/Common/RunManager/testexecutor.cpp \
    ../TTI/Common/DllManager/dllmanager.cpp \
    ../TTI/Common/DBManager/dbmanager.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    tti-executor-application.h \
    ../TTI/Common/RunManager/runmanager.h \
    ../TTI/Common/RunManager/testexecutor.h \
    ../TTI/Common/DllManager/dllmanager.h \
    ../TTI/Common/DBManager/dbmanager.h \
    ../TTI/Common/DBManager/run-description.h \
    ../TTI/Common/DBManager/test-case.h \
    ../TTI/Common/DBManager/test-result.h \
    ../TTI/Common/DBManager/test-status.h
