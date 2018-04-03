#include "CV2Balance.h"

CV2Balance::CV2Balance()
{
    this->createPlots();
    this->createControls();
}
void CV2Balance::createPlots()
{
    QVector<QString> legend;
    legend.append("Phi");
    QVector<QPen> lineColors;
    lineColors.append(QPen(Qt::blue));
    mPhiPlotPtr = new CPlot(1, "Phi in Radiant", "Phi", legend, lineColors);

    legend.clear(); legend.append("UK");
    mUKPlotPtr  = new CPlot(1, "UK in Radiant per Second", "UK", legend, lineColors);

    legend.clear(); legend.append("UR");
    mURPlotPtr  = new CPlot(1, "UR in Radiant per Second", "UR", legend, lineColors);

    legend.clear(); legend.append("TM");
    mTMPlotPtr  = new CPlot(1, "TM in Newtonmeter", "TM", legend, lineColors);

    mPlotLayoutPtr->addWidget(mPhiPlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mUKPlotPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mURPlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mTMPlotPtr->getPlotPtr(), 1, 1);
}
void CV2Balance::createControls()
{
    mSaveButtonPtr = new QPushButton("Save Data");
    mControlLayoutPtr->addWidget(mSaveButtonPtr);

    QObject::connect(mSaveButtonPtr, SIGNAL(clicked()),
                     this, SLOT(saveButtonSLOT()));

    mControlLayoutPtr->addStretch();
}
void CV2Balance::expDataReceivedSLOT(const SExpData& data)
{
    mPhiPlotPtr->addData(data.mTime, data.mPhi, 0);
    mUKPlotPtr->addData(data.mTime, data.mUK, 0);
    mURPlotPtr->addData(data.mTime, data.mUR, 0);
    mTMPlotPtr->addData(data.mTime, data.mTM, 0);
}
void CV2Balance::saveButtonSLOT()
{
    QVector<std::string> varNames;
    varNames.append("phi");
    mPhiPlotPtr->saveCSV("Data/balance_phi.csv", varNames);
    varNames.clear(); varNames.append("uk");
    mUKPlotPtr->saveCSV("Data/balance_uk.csv", varNames);
    varNames.clear(); varNames.append("ur");
    mURPlotPtr->saveCSV("Data/balance_ur.csv", varNames);
    varNames.clear(); varNames.append("tm");
    mTMPlotPtr->saveCSV("Data/balance_tm.csv", varNames);
}
