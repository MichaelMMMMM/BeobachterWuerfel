#include "CV1Calib.h"

CV1Calib::CV1Calib() : mNumberOfValues(500), mReceivedValues(0)
{
    this->createPlots();
    this->createControls();
}
void CV1Calib::createPlots()
{
    QVector<QString> legend;
    legend.append("X_dd");
    QVector<QPen> lineColors;
    lineColors.append(QPen(Qt::blue));
    mX_ddPlotPtr = new CPlot(1, "Measurements in 2K", "X_dd", legend, lineColors);
    legend.clear(); legend.append("Z_dd");
    mZ_ddPlotPtr = new CPlot(1, "Measurements in 2K", "Z_dd", legend, lineColors);
    legend.clear(); legend.append("phi2_d");
    mPhi2_dPlotPtr = new CPlot(1, "Measurements in 2K", "phi2_d", legend, lineColors);
    legend.clear(); legend.append("phi3_d Motor 1"); legend.append("phi3_d Motor 2");
    lineColors.append(QPen(Qt::red));
    mPhi3_dPlotPtr = new CPlot(2, "Measurements in 2K", "phi3_d", legend, lineColors);

    mPlotLayoutPtr->addWidget(mX_ddPlotPtr->getPlotPtr(), 0, 0);
    mPlotLayoutPtr->addWidget(mZ_ddPlotPtr->getPlotPtr(), 0, 1);
    mPlotLayoutPtr->addWidget(mPhi2_dPlotPtr->getPlotPtr(), 1, 0);
    mPlotLayoutPtr->addWidget(mPhi3_dPlotPtr->getPlotPtr(), 1, 1);
}
void CV1Calib::createControls()
{
    mStartButtonPtr     = new QPushButton("Start Measurment");
    QObject::connect(mStartButtonPtr, SIGNAL(clicked()),
                     this, SLOT(startButtonClickedSLOT()));
    mControlLayoutPtr->addWidget(mStartButtonPtr);

    mValuesLayoutPtr    = new QHBoxLayout;
    mValuesLabelPtr     = new QLabel("Number of Values");
    mValuesSpinBoxPtr   = new QSpinBox;
    mValuesSpinBoxPtr->setMaximum(10000);
    mValuesSpinBoxPtr->setMinimum(100);
    mValuesSpinBoxPtr->setValue(500);
    mValuesLayoutPtr->addWidget(mValuesLabelPtr);
    mValuesLayoutPtr->addWidget(mValuesSpinBoxPtr);
    mControlLayoutPtr->addLayout(mValuesLayoutPtr);

    mVelLayoutPtr       = new QHBoxLayout;
    mVelLabelPtr        = new QLabel("Motor Velocity in rad/sec");
    mVelSpinBoxPtr      = new QDoubleSpinBox;
    mVelSpinBoxPtr->setMaximum(200.0*3.14);
    mVelSpinBoxPtr->setMinimum(-200.0*3.14);
    mVelSpinBoxPtr->setValue(0.0);
    mVelLayoutPtr->addWidget(mVelLabelPtr);
    mVelLayoutPtr->addWidget(mVelSpinBoxPtr);
    mControlLayoutPtr->addLayout(mVelLayoutPtr);

    mVelButtonPtr = new QPushButton("Update Motor-Velocity");
    mControlLayoutPtr->addWidget(mVelButtonPtr);
    QObject::connect(mVelButtonPtr, SIGNAL(clicked()),
                     this, SLOT(setVelocityButtonClickedSLOT()));

    mControlLayoutPtr->addStretch();
    QObject::connect(mValuesSpinBoxPtr, SIGNAL(valueChanged(int)),
                     this, SLOT(numberOfValuesChangedSLOT(int)));
}
void CV1Calib::sensorDataReceivedSLOT(const CSensorData& data)
{
    QVector<double> dataVector;
    dataVector.append(static_cast<double>(data.mMPUData.mA_x));
    mX_ddPlotPtr->addData(data.mMPUData.mTime, dataVector);

    dataVector.clear();
    dataVector.append(static_cast<double>(data.mMPUData.mA_z));
    mZ_ddPlotPtr->addData(data.mMPUData.mTime, dataVector);

    dataVector.clear();
    dataVector.append(static_cast<double>(data.mMPUData.mW_y));
    mPhi2_dPlotPtr->addData(data.mMPUData.mTime, dataVector);

    dataVector.clear();
    dataVector.append(static_cast<double>(data.mADCData.mADC1Value));
    dataVector.append(static_cast<double>(data.mADCData.mADC2Value));
    mPhi3_dPlotPtr->addData(data.mADCData.mTime, dataVector);

    mReceivedValues++;
    if(mReceivedValues >= mNumberOfValues)
    {
        emit endMeasurementSIG();
        QVector<std::string> varNames;
        varNames.append("x_dd");
        mX_ddPlotPtr->saveCSV("SensorCalibration/x_dd.csv", varNames);
        varNames.clear(); varNames.append("z_dd");
        mZ_ddPlotPtr->saveCSV("SensorCalibration/z_dd.csv", varNames);
        varNames.clear(); varNames.append("phi2_d");
        mPhi2_dPlotPtr->saveCSV("SensorCalibration/phi2_d.csv", varNames);
        varNames.clear(); varNames.append("m1_phi3_d"); varNames.append("m2_phi3_d");
        mPhi3_dPlotPtr->saveCSV("SensorCalibration/phi3_d.csv", varNames);
    }
}
void CV1Calib::startButtonClickedSLOT()
{
    mReceivedValues = 0;
    mX_ddPlotPtr->reset();
    mZ_ddPlotPtr->reset();
    mPhi2_dPlotPtr->reset();
    mPhi3_dPlotPtr->reset();
    emit startCalibSIG();
    emit setVelocitySIG(mVelSpinBoxPtr->value());
}
void CV1Calib::numberOfValuesChangedSLOT(int newValue)
{
    mNumberOfValues = newValue;
}
void CV1Calib::setVelocityButtonClickedSLOT()
{
    double newValue = mVelSpinBoxPtr->value();
    emit setVelocitySIG(newValue);
}
