#ifndef CSISTATEESTIMATE_H
#define CSISTATEESTIMATE_H
#include "SCalibData.h"
#include "CStateVector.h"

class CSIStateEstimate
{
public:
	using InputType  = SCalibData;
	using OutputType = CStateVector;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	explicit CSIStateEstimate();
	CSIStateEstimate(const CSIStateEstimate&) = delete;
	CSIStateEstimate& operator=(const CSIStateEstimate&) = delete;
	~CSIStateEstimate() = default;
private:
	OutputType mOutput;

	static constexpr float sR1    = 0.14;		//! Distance Sensor 1 to the rotational axis in meter
	static constexpr float sR2    = 0.061;		//! Distance Sensor 2 to the rotational axis in meter
	static constexpr float sAlpha = sR1/sR2;
};

#endif
