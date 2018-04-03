#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include <QMainWindow>
#include <QStackedWidget>
#include <CRxThread.h>
#include "CSensorCalibration.h"
#include "CADCCalibration.h"
#include "CEdgeBalance.h"
#include "CCornerBalance.h"
#include "CV1SysIdent.h"
#include "CV2Balance.h"

class CMainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void selectV1SysIdentSLOT();
    void selectV2BalanceSLOT();
public:
    CMainWindow(QWidget *parent = 0);
    ~CMainWindow();
private:
    void createToolbar();
    void createRxThread();
private:
    CRxThread*          mRxThreadPtr;
    QStackedWidget*     mStackedWidgetPtr;

    QWidget*            mDummyPtr;
    CV1SysIdent*        mV1SysIdentPtr;
    CV2Balance*         mV2BalancePtr;
};

#endif // CMAINWINDOW_H
