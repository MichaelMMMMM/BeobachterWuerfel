#include "CMainWindow.h"
#include <QMenuBar>

CMainWindow::CMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->createToolbar();

    mStackedWidgetPtr       = new QStackedWidget;
    mDummyPtr               = new QWidget;
    mV1SysIdentPtr          = new CV1SysIdent;
    mV2BalancePtr           = new CV2Balance;

    mStackedWidgetPtr->addWidget(mDummyPtr);
    mStackedWidgetPtr->addWidget(mV1SysIdentPtr);
    mStackedWidgetPtr->addWidget(mV2BalancePtr);

    this->createRxThread();

    this->setCentralWidget(mStackedWidgetPtr);
    this->showMaximized();
}
void CMainWindow::createToolbar()
{
    auto menuBarPtr     = menuBar();
    auto experimentPtr  = menuBarPtr->addMenu("Select Experiment");

    auto v1Ptr          = new QAction("Run System-Identification", menuBarPtr);
    experimentPtr->addAction(v1Ptr);
    QObject::connect(v1Ptr, SIGNAL(triggered()),
                     this, SLOT(selectV1SysIdentSLOT()));

    auto v2Ptr          = new QAction("Run Balance-Experiment", menuBarPtr);
    experimentPtr->addAction(v2Ptr);
    QObject::connect(v2Ptr, SIGNAL(triggered()),
                     this, SLOT(selectV2BalanceSLOT()));
}
void CMainWindow::createRxThread()
{
    mRxThreadPtr = new CRxThread;

    //Connect V1 System-Identification
    QObject::connect(mV1SysIdentPtr, SIGNAL(startExperimentSIG()),
                     mRxThreadPtr, SLOT(startExperimentSLOT()));
    QObject::connect(mV1SysIdentPtr, SIGNAL(stopExperimentSIG()),
                     mRxThreadPtr, SLOT(stopExperimentSLOT()));
    QObject::connect(mV1SysIdentPtr, SIGNAL(selectNoSignalSIG()),
                     mRxThreadPtr, SLOT(selectNoSignalSLOT()));
    QObject::connect(mV1SysIdentPtr, SIGNAL(selectJumpSignalSIG(float)),
                     mRxThreadPtr, SLOT(selectJumpSignalSLOT(float)));
    QObject::connect(mV1SysIdentPtr, SIGNAL(selectSineSignalSIG(float)),
                     mRxThreadPtr, SLOT(selectSineSignalSLOT(float)));
    QObject::connect(mV1SysIdentPtr, SIGNAL(selectMultiSineSignalSIG(float)),
                     mRxThreadPtr, SLOT(selectMultiSineSignalSLOT(float)));
    QObject::connect(mRxThreadPtr, SIGNAL(expDataReceivedSIG(const SExpData&)),
                     mV1SysIdentPtr, SLOT(expDataReceivedSLOT(const SExpData&)));


    //Connect V2 Balance-Experiment
    QObject::connect(mRxThreadPtr, SIGNAL(expDataReceivedSIG(const SExpData&)),
                     mV2BalancePtr, SLOT(expDataReceivedSLOT(const SExpData&)));

    mRxThreadPtr->start();
}

CMainWindow::~CMainWindow()
{

}
void CMainWindow::selectV1SysIdentSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mV1SysIdentPtr);
    mRxThreadPtr->runV1SysIdentSLOT();

}
void CMainWindow::selectV2BalanceSLOT()
{
    mStackedWidgetPtr->setCurrentWidget(mV2BalancePtr);
    mRxThreadPtr->runV2BalanceSLOT();
}
