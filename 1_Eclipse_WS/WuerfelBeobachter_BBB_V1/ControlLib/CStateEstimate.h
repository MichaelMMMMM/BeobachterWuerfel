#ifndef CSTATEESTIMATE_H
#define CSTATEESTIMATE_H
#include "SCalibData.h"
#include "CStateVector.h"

class CStateEstimate
{
public:
	using InputType  = SCalibData;
	using OutputType = CStateVector;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	CStateEstimate() = default;
	CStateEstimate(const CStateEstimate&) = delete;
	CStateEstimate& operator=(const CStateEstimate&) = delete;
	~CStateEstimate() = default;
private:
	OutputType mOutput;

	static constexpr float sR1    = 0.14F;
	static constexpr float sR2    = 0.061F;
	static constexpr float sAlpha = sR1/sR2;
};


#endif
