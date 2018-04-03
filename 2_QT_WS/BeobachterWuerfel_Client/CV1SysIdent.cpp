#include "CV1SysIdent.h"

CV1SysIdent::CV1SysIdent() : mNumberOfValues(1000),
                             mReceivedValues(0)
{
    this->createPlots();
    this->createControls();
}
void CV1SysIdent::expDataReceivedSLOT(const SExpData& data)
{
    mPhiPlotPtr->addData(data.mTime, data.mPhi, 0);
    mUKPlotPtr->addData(data.mTime, data.mUK, 0);
    mURPlotPtr->addData(data.mTime, data.mUR, 0);
    mTMPlotPtr->addData(data.mTime, data.mTM, 0);

    mReceivedValues++;
    if(mReceivedValues >= mNumberOfValues)
    {
        emit stopExperimentSIG();
        QVector<std::string> varNames;
        varNames.append("phi");
        mPhiPlotPtr->saveCSV("Data/phi.csv", varNames);
        varNames.clear(); varNames.append("uk");
        mUKPlotPtr->saveCSV("Data/uk.csv", varNames);
        varNames.clear(); varNames.append("ur");
        mURPlotPtr->saveCSV("Data/ur.csv", varNames);
        varNames.clear(); varNames.append("tm");
        mTMPlotPtr->saveCSV("Data/tm.csv", varNames);
    }
}
void CV1SysIdent::createPlots()
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
void CV1SysIdent::createControls()
{
    //Create the input box for the number of values
    mValuesLayoutPtr  = new QHBoxLayout;
    mValuesLabelPtr   = new QLabel("Number of Values");
    mValuesSpinBoxPtr = new QSpinBox;
    mValuesSpinBoxPtr->setMaximum(100000);
    mValuesSpinBoxPtr->setMinimum(100);
    mValuesSpinBoxPtr->setValue(1000);
    mValuesLayoutPtr->addWidget(mValuesLabelPtr);
    mValuesLayoutPtr->addWidget(mValuesSpinBoxPtr);
    mControlLayoutPtr->addLayout(mValuesLayoutPtr);

    //Create the radio buttons to select the input signal
    QFrame* radioFrame = new QFrame;
    radioFrame->setFrameStyle(QFrame::Box);
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Foreground, Qt::black);
    radioFrame->setPalette(*palette);
    QVBoxLayout* radioLayout = new QVBoxLayout;
    radioFrame->setLayout(radioLayout);

    QLabel* radioLabel = new QLabel("Select Input-Signal");
    mNoSignalPtr       = new QRadioButton("No Input-Signal");
    mNoSignalPtr->setChecked(true);
    mJumpSignalPtr      = new QRadioButton("Jump-Signal");
    mSineSignalPtr      = new QRadioButton("Sine-Signal");
    mMultiSineSignalPtr = new QRadioButton("Multi-Sine-Signal");

    QObject::connect(mNoSignalPtr, SIGNAL(clicked()),
                     this, SLOT(noSignalSelectedSLOT()));
    QObject::connect(mJumpSignalPtr, SIGNAL(clicked()),
                     this, SLOT(jumpSignalSelectedSLOT()));
    QObject::connect(mSineSignalPtr, SIGNAL(clicked()),
                     this, SLOT(sineSignalSelectedSLOT()));
    QObject::connect(mMultiSineSignalPtr, SIGNAL(clicked()),
                     this, SLOT(multiSineSignalSelectedSLOT()));

    radioLayout->addWidget(radioLabel);
    radioLayout->addWidget(mNoSignalPtr);
    radioLayout->addWidget(mJumpSignalPtr);
    radioLayout->addWidget(mSineSignalPtr);
    radioLayout->addWidget(mMultiSineSignalPtr);

    mControlLayoutPtr->addWidget(radioFrame);

    //Create the selection for the amplitude
    mAmpLayoutPtr  = new QHBoxLayout;
    mAmpLabelPtr   = new QLabel("Input-Amplitude");
    mAmpSpinBoxPtr = new QDoubleSpinBox;
    mAmpSpinBoxPtr->setMaximum(0.1);
    mAmpSpinBoxPtr->setMinimum(0.0);
    mAmpSpinBoxPtr->setDecimals(5);
    mAmpSpinBoxPtr->setSingleStep(0.005);
    mAmpSpinBoxPtr->setValue(0.0);
    mAmpLayoutPtr->addWidget(mAmpLabelPtr);
    mAmpLayoutPtr->addWidget(mAmpSpinBoxPtr);
    mControlLayoutPtr->addLayout(mAmpLayoutPtr);

    //Create the start button
    mStartButtonPtr = new QPushButton("Start Experiment");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClickedSLOT()));
    mControlLayoutPtr->addWidget(mStartButtonPtr);

    mControlLayoutPtr->addStretch();
}
void CV1SysIdent::startButtonClickedSLOT()
{
    mNumberOfValues = mValuesSpinBoxPtr->value();
    mReceivedValues = 0;
    mPhiPlotPtr->reset();
    mUKPlotPtr->reset();
    mURPlotPtr->reset();
    mTMPlotPtr->reset();
    emit startExperimentSIG();
}
void CV1SysIdent::noSignalSelectedSLOT()
{
    emit selectNoSignalSIG();
}
void CV1SysIdent::jumpSignalSelectedSLOT()
{
    float amp = static_cast<float>(mAmpSpinBoxPtr->value());
    emit selectJumpSignalSIG(amp);
}
void CV1SysIdent::sineSignalSelectedSLOT()
{
    float amp = static_cast<float>(mAmpSpinBoxPtr->value());
    emit selectSineSignalSIG(amp);
}
void CV1SysIdent::multiSineSignalSelectedSLOT()
{
    float amp = static_cast<float>(mAmpSpinBoxPtr->value());
    emit selectMultiSineSignalSIG(amp);
}
