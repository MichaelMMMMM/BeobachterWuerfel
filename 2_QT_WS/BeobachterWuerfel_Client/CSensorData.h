#ifndef CSENSORDATA_H
#define CSENSORDATA_H
#include "CMPUData.h"
#include "CADCData.h"

class CSensorData
{
public:
	void display();
public:
	CSensorData() = default;
	CSensorData(const CSensorData&) = default;
	CSensorData& operator=(const CSensorData&) = default;
	~CSensorData() = default;
public:
	CMPUData mMPUData;
	CADCData mADCData;
};


#endif
