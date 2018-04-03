#ifndef COFFSETCORRECTION_H
#define COFFSETCORRECTION_H
#include "CStateVector.h"

class CSIOffsetCorrection
{
public:
	using InputType  = CStateVector;
	using OutputType = CStateVector;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
public:
	explicit CSIOffsetCorrection();
	CSIOffsetCorrection(const CSIOffsetCorrection&) = delete;
	CSIOffsetCorrection& operator=(const CSIOffsetCorrection&) = delete;
	~CSIOffsetCorrection() = default;
private:
	OutputType mOutput;

	CStateVector mOffset;
};

#endif
