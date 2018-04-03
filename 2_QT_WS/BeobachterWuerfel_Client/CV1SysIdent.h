#ifndef CV1SYSIDENT_H
#define CV1SYSIDENT_H
#include "CExperimentWidget.h"
#include "SExpData.h"
#include "CPlot.h"
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QRadioButton>

class CV1SysIdent : public CExperimentWidget
{
Q_OBJECT
signals:
    void startExperimentSIG();
    void stopExperimentSIG();
    void selectNoSignalSIG();
    void selectJumpSignalSIG(const float amp);
    void selectSineSignalSIG(const float amp);
    void selectMultiSineSignalSIG(const float amp);
public slots:
    void startButtonClickedSLOT();
    void noSignalSelectedSLOT();
    void jumpSignalSelectedSLOT();
    void sineSignalSelectedSLOT();
    void multiSineSignalSelectedSLOT();
    void expDataReceivedSLOT(const SExpData& data);
public:
    CV1SysIdent();
private:
    void createPlots();
    void createControls();
private:
    CPlot* mPhiPlotPtr;
    CPlot* mUKPlotPtr;
    CPlot* mURPlotPtr;
    CPlot* mTMPlotPtr;

    int mNumberOfValues;
    int mReceivedValues;

    QPushButton* mStartButtonPtr;

    QHBoxLayout* mValuesLayoutPtr;
    QLabel*      mValuesLabelPtr;
    QSpinBox*    mValuesSpinBoxPtr;

    QRadioButton* mNoSignalPtr;
    QRadioButton* mJumpSignalPtr;
    QRadioButton* mSineSignalPtr;
    QRadioButton* mMultiSineSignalPtr;

    QHBoxLayout*    mAmpLayoutPtr;
    QLabel*         mAmpLabelPtr;
    QDoubleSpinBox* mAmpSpinBoxPtr;
};

#endif // CV1SYSIDENT_H
