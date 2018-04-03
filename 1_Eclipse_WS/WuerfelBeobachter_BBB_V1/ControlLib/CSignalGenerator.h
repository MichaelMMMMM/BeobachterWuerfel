#ifndef CSIGNALGENERATOR_H
#define CSIGNALGENERATOR_H
#include "Global.h"

class CSignalGenerator
{
public:
	float getSignal(float time);
	void  selectNoSignal();
	void  selectJumpSignal(float amp);
	void  selectSineSignal(float amp);
	void  selectMultiSineSignal(float amp);
public:
	explicit CSignalGenerator();
	CSignalGenerator(const CSignalGenerator&) = delete;
	CSignalGenerator& operator=(const CSignalGenerator&) = delete;
	~CSignalGenerator() = default;
private:
	enum SignalType{NOSIGNAL, JUMPSIGNAL, SINESIGNAL, MULTISINE};
	SignalType mType;
	float      mAmp;
};

#endif
