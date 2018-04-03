#include "CCompFilter.h"

CCompFilter::CCompFilter() : mFirstRun(true)
{

}
const CCompFilter::OutputType& CCompFilter::calcOutput(const CCompFilter::InputType& input)
{
	auto u = input;
	if(mFirstRun == true)
	{
		mFirstRun = false;
		mOutput   = input;
	}
	else
	{
		float recent_phi = mOutput[1][1];
		mOutput[1][1] = sAlpha * (recent_phi + sT * u[2][1]) + (1.0F - sAlpha) * u[1][1];
		mOutput[2][1] = u[2][1];
		mOutput[3][1] = u[3][1];
	}
	return mOutput;
}
const CCompFilter::OutputType& CCompFilter::getValue() const
{
	return mOutput;
}
void CCompFilter::reset()
{
	mFirstRun = true;
}
