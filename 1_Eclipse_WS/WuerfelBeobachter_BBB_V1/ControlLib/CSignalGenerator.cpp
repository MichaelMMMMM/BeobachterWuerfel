#include "CSignalGenerator.h"
#include <cmath>

CSignalGenerator::CSignalGenerator() : mType(NOSIGNAL),
									   mAmp(0.0F)
{

}
float CSignalGenerator::getSignal(float time)
{
	switch (mType)
	{
	case NOSIGNAL:
		return 0.0F;
		break;
	case JUMPSIGNAL:
		return time >= 1.0F ? mAmp : 0.0F;
		break;
	case SINESIGNAL:
		return sinf(2.0F * 3.14F * 1.0F/100.0F * time * time) * mAmp;
		break;
	case MULTISINE:
		return mAmp * ( sinf(2.0F*3.14F*0.25F*time) +
						sinf(2.0F*3.14F*0.5F*time)  +
						sinf(2.0F*3.14F*0.75F*time) +
						sinf(2.0F*3.14F*1.0F*time) );
		break;
	default:
		return 0.0F;
		break;
	}
}
void CSignalGenerator::selectNoSignal()
{
	mType = NOSIGNAL;
	mAmp  = 0.0F;
}
void CSignalGenerator::selectJumpSignal(float amp)
{
	mType = JUMPSIGNAL;
	mAmp  = amp;
}
void CSignalGenerator::selectSineSignal(float amp)
{
	mType = SINESIGNAL;
	mAmp  = amp;
}
void CSignalGenerator::selectMultiSineSignal(float amp)
{
	mType = MULTISINE;
	mAmp  = amp;
}
