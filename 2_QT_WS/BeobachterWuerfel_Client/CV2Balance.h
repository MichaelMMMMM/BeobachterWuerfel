#ifndef CV2BALANCE_H
#define CV2BALANCE_H
#include "CExperimentWidget.h"
#include "SExpData.h"
#include "CPlot.h"
#include <QPushButton>

class CV2Balance : public CExperimentWidget
{
Q_OBJECT
public slots:
    void expDataReceivedSLOT(const SExpData& data);
    void saveButtonSLOT();
public:
    CV2Balance();
private:
    void createPlots();
    void createControls();
private:
    CPlot* mPhiPlotPtr;
    CPlot* mUKPlotPtr;
    CPlot* mURPlotPtr;
    CPlot* mTMPlotPtr;

    QPushButton* mSaveButtonPtr;
};

#endif // CV2BALANCE_H
