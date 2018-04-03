#include <CSIStateEstimate.h>
#include <cmath>

CSIStateEstimate::CSIStateEstimate()
{

}
const CSIStateEstimate::OutputType& CSIStateEstimate::calcOutput(const CSIStateEstimate::InputType& input)
{
	mOutput[1][1] = atan2f(input.mX1_dd - sAlpha * input.mX2_dd, input.mY1_dd - sAlpha * input.mY2_dd);
	mOutput[2][1] = (input.mPhi1_d + input.mPhi2_d) / 2.0F;
	mOutput[3][1] = input.mPsi_d + mOutput[2][1];

	return mOutput;
}
const CSIStateEstimate::OutputType& CSIStateEstimate::getValue() const
{
	return mOutput;
}

