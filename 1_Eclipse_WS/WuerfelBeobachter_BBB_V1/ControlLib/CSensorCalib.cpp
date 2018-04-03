#include "CSensorCalib.h"

const CSensorCalib::OutputType& CSensorCalib::calcOutput(const CSensorCalib::InputType& input)
{
	mOutput.mX1_dd  = static_cast<float>(input.mMPU1Data.mX__dd) * sAccelScale;
	mOutput.mX2_dd  = static_cast<float>(input.mMPU2Data.mX__dd) * sAccelScale;
	mOutput.mY1_dd  = static_cast<float>(input.mMPU1Data.mY__dd) * sAccelScale;
	mOutput.mY2_dd  = static_cast<float>(input.mMPU2Data.mY__dd) * sAccelScale;
	mOutput.mPhi1_d = static_cast<float>(input.mMPU1Data.mPhi__d) * sGyroScale;
	mOutput.mPhi2_d = static_cast<float>(input.mMPU2Data.mPhi__d) * sGyroScale;
	mOutput.mPsi_d  = static_cast<float>(input.mADCData) * sADCScale;

	return mOutput;
}
const CSensorCalib::OutputType& CSensorCalib::getValue() const
{
	return mOutput;
}
