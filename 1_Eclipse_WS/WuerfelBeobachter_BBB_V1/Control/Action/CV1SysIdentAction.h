#ifndef CV1SYSIDENTACTION_H
#define CV1SYSIDENTACTION_H
#include <CSIOffsetCorrection.h>
#include <CSISensorCalib.h>
#include <CSIStateEstimate.h>
#include "CControlAction.h"
#include "TActionHolder.h"
#include "TLinHierarchy.h"
#include "CCompFilter.h"
#include "CSignalGenerator.h"

class CV1SysIdentAction : public CControlAction
{
public:
	void onEntryV1SysIdent();
	void onExitV1SysIdent();
	void onEntryIdle();
	void onExitIdle();
	void onEntryRunning();
	void onExitRunning();
	void sampleV1SysIdent();
	void selectNoInputSignal();
	void selectJumpSignal(float amp);
	void selectSineSignal(float amp);
	void selectMultiSineSignal(float amp);
public:
	explicit CV1SysIdentAction();
	CV1SysIdentAction(const CV1SysIdentAction&) = delete;
	CV1SysIdentAction& operator=(const CV1SysIdentAction&) = delete;
	~CV1SysIdentAction() = default;
private:
	float mTime;

	using ActionList = TYPELIST_4(CSISensorCalib, CSIStateEstimate, CSIOffsetCorrection, CCompFilter);
	TLinHierarchy<ActionList, TActionHolder> mSignalFlow;

	CSignalGenerator mSignalGenerator;
};

#endif
