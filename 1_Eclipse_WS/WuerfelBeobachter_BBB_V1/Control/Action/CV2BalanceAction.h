#ifndef CV2BALANCEACTION_H
#define CV2BALANCEACTION_H
#include "CControlActionBase.h"
#include "TLinHierarchy.h"
#include "TActionHolder.h"
#include "CSensorCalib.h"
#include "CStateEstimate.h"

class CV2BalanceAction : public CControlActionBase
{
public:
	void entryV2Balance();
	void exitV2Balance();
	void entryIdle();
	void exitIdle();
	void entryBalance();
	void exitBalance();

	bool inBalanceArea();
	void sampleIteration();
	void setTorque();
public:
	explicit CV2BalanceAction();
	CV2BalanceAction(const CV2BalanceAction&) = delete;
	CV2BalanceAction& operator=(const CV2BalanceAction&) = delete;
	~CV2BalanceAction() = default;
private:
	float mTime;

	static constexpr float sPhiMax = 0.1F;

	using ActionList = TYPELIST_2(CSensorCalib, CStateEstimate);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;
};

#endif
