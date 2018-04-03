/**
 * @author	Michael Meindl
 * @date	6.12.2016
 * @brief	Method definitions for CBBBHardware.
 */
#include "CBBBHardware.h"

CBBBHardware::CBBBHardware() : mSensor1(1),
							   mSensor2(2)
{

}
bool CBBBHardware::fetchValues(SSensorData& data)
{
	if(!mADC.fetchValue(data.mADCData))
	{
		return false;
	}
	if(!mSensor1.fetchValues(data.mMPU1Data))
	{
		return false;
	}
	if(!mSensor2.fetchValues(data.mMPU2Data))
	{
		return false;
	}
	return true;
}
bool CBBBHardware::enableMotor()
{
	return mMotor.enableMotor();
}
bool CBBBHardware::disableMotor()
{
	return mMotor.disableMotor();
}
bool CBBBHardware::setTorque(float torque)
{
	mBrake.openBrake();
	return mMotor.setTorque(torque);
}
bool CBBBHardware::openBrake()
{
	mMotor.enableMotor();
	return mBrake.openBrake();
}
bool CBBBHardware::closeBrake()
{
	mMotor.disableMotor();
	return mBrake.closeBrake();
}
