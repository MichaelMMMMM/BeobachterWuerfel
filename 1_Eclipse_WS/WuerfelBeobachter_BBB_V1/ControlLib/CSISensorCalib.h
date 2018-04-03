#ifndef CSISENSORCALIB_H
#define CSISENSORCALIB_H
#include "SSensorData.h"
#include "SCalibData.h"

class CSISensorCalib
{
public:
	using InputType  = SSensorData;
	using OutputType = SCalibData;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	explicit CSISensorCalib();
	CSISensorCalib(const CSISensorCalib&) = delete;
	CSISensorCalib& operator=(const CSISensorCalib&) = delete;
	~CSISensorCalib() = default;
private:
	OutputType mOutput;

	static constexpr float sAccelScale = 0.000598F; 		//! Aus /sys/bus/iio/devices/iio:device1/in_accel_scale
	static constexpr float sGyroScale  = 0.001064724F/2.0F; //! Aus /sys/bus/iio/deivces/iio:device1/in_anglvel_scale, *0.5 because of compfilter

	static constexpr float sPi    	   = 3.14F;
	static constexpr float sPsi_dMin   = -10000.0F/60.0F * 2 * sPi; 	//! Min-Psi_d Value in Radiant per second
	static constexpr float sPsi_dMax   =  10000.0F/60.0F * 2 * sPi;	//! Max-Psi_d Value in Radiant per second
	static constexpr float sPsi_dRange = sPsi_dMax - sPsi_dMin; //! Psi_d Range in Radiant per second
	static constexpr float sADCRange   = 4096.0F;				//! Range of the 12-bit ADC
	static constexpr float sADCScale   = -sPsi_dRange / sADCRange;
};

#endif
