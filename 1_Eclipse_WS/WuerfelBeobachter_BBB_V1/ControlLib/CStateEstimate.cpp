#include "CStateEstimate.h"
#include <cmath>

const CStateEstimate::OutputType& CStateEstimate::calcOutput(const CStateEstimate::InputType& input)
{
	auto u = input;
	mOutput[1][1] = -atan2f(u.mX1_dd - sAlpha * u.mX2_dd, u.mY1_dd - sAlpha * u.mY2_dd);
	mOutput[2][1] = (u.mPhi1_d + u.mPhi2_d) / 2.0F;
	mOutput[3][1] = mOutput[2][1] + u.mPsi_d;

	return mOutput;
}
const CStateEstimate::OutputType& CStateEstimate::getValue() const
{
	return mOutput;
}
