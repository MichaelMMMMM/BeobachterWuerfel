#ifndef SCALIBDATA_H
#define SCALIBDATA_H
#include "Global.h"

struct SCalibData
{
	float mX1_dd;		//! Acceleration Sensor 1 X-Direction in meter per second^2
	float mY1_dd;		//! Acceleration Sensor 1 Y-Direction in meter per second^2
	float mX2_dd;		//! Acceleration Sensor 2 X-Direction in meter per second^2
	float mY2_dd;		//! Acceleration Sensor 2 Y-Direction in meter per second^2
	float mPhi1_d;		//! Angular Velocity Phi_d Sensor 1 in Radiant per second
	float mPhi2_d;		//! Angular Velocity Phi_d Sensor 2 in Radiant per second
	float mPsi_d;		//! Angular Velocity Psi_d in Radiant per second
};

#endif
