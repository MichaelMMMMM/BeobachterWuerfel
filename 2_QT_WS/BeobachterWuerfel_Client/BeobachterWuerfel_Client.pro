#-------------------------------------------------
#
# Project created by QtCreator 2018-02-16T15:12:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeobachterWuerfel_Client
TEMPLATE = app
CONFIG   += c++11
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    Assertion.cpp \
    CADCCalibration.cpp \
    CADCData.cpp \
    CClient.cpp \
    CCornerBalance.cpp \
    CEdgeBalance.cpp \
    CExperimentWidget.cpp \
    CMainWindow.cpp \
    CMessage.cpp \
    CMPUData.cpp \
    CPlot.cpp \
    CRxThread.cpp \
    CSensorCalibration.cpp \
    CSensorData.cpp \
    CV1Calib.cpp \
    QCustomPlot.cpp \
    CV1SysIdent.cpp \
    CV2Balance.cpp

HEADERS  += \
    Assertion.h \
    CADCCalibration.h \
    CADCData.h \
    CClient.h \
    CCornerBalance.h \
    CEdgeBalance.h \
    CExperimentWidget.h \
    CMainWindow.h \
    CMessage.h \
    CMPUData.h \
    CRxThread.h \
    CSensorCalibration.h \
    CSensorData.h \
    CV1Calib.h \
    E1DControlSystem.h \
    EEvent.h \
    Global.h \
    QCustomPlot.h \
    TMatrix.h \
    CV1SysIdent.h \
    SExpData.h \
    CV2Balance.h
