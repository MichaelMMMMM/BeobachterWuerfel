#ifndef CCOMPFILTER_H
#define CCOMPFILTER_H
#include "CStateVector.h"

class CCompFilter
{
public:
	using InputType  = CStateVector;
	using OutputType = CStateVector;
public:
	const OutputType& calcOutput(const InputType& input);
	const OutputType& getValue() const;
	void reset();
public:
	explicit CCompFilter();
	CCompFilter(const CCompFilter&) = delete;
	CCompFilter& operator=(const CCompFilter&) = delete;
	~CCompFilter() = default;
private:
	OutputType mOutput;

	bool mFirstRun;

	static constexpr float sAlpha = 0.995F;
	static constexpr float sT     = 0.01F;
};

#endif
