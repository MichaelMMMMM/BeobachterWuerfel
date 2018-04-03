#ifndef SSENSORDATA_H
#define SSENSORDATA_H
#include "SMPU6050Data.h"

struct SSensorData
{
	SMPU6050Data mMPU1Data;
	SMPU6050Data mMPU2Data;
	UInt16       mADCData;
};

#endif
