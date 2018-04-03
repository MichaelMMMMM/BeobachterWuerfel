#ifndef CV1CALIB_H
#define CV1CALIB_H
#include "CExperimentWidget.h"
#include "CSensorData.h"
#include "CPlot.h"
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>

class CV1Calib : public CExperimentWidget
{
    Q_OBJECT
signals:
    void startCalibSIG();
    void endMeasurementSIG();
    void setVelocitySIG(float velocity);
public slots:
    void sensorDataReceivedSLOT(const CSensorData& data);

    void startButtonClickedSLOT();
    void numberOfValuesChangedSLOT(int newValue);
    void setVelocityButtonClickedSLOT();
public:
    CV1Calib();
private:
    void createPlots();
    void createControls();
private:
    int mNumberOfValues;
    int mReceivedValues;

    QPushButton* mStartButtonPtr;

    QHBoxLayout* mValuesLayoutPtr;
    QLabel*      mValuesLabelPtr;
    QSpinBox*    mValuesSpinBoxPtr;

    QHBoxLayout*    mVelLayoutPtr;
    QLabel*         mVelLabelPtr;
    QDoubleSpinBox* mVelSpinBoxPtr;

    QPushButton*   mVelButtonPtr;

    CPlot*       mX_ddPlotPtr;
    CPlot*       mZ_ddPlotPtr;
    CPlot*       mPhi2_dPlotPtr;
    CPlot*       mPhi3_dPlotPtr;
};

#endif // CV1CALIB_H

