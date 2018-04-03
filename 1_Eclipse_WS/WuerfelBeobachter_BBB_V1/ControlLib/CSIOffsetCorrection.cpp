#include <CSIOffsetCorrection.h>

CSIOffsetCorrection::CSIOffsetCorrection() : mOffset("/root/config/sysident_offsets.csv")
{

}
const CSIOffsetCorrection::OutputType& CSIOffsetCorrection::calcOutput(const CSIOffsetCorrection::InputType& input)
{
	mOutput = input - mOffset;
	return mOutput;
}
const CSIOffsetCorrection::OutputType& CSIOffsetCorrection::getValue() const
{
	return mOutput;
}
