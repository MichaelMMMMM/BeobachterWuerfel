#ifndef CV1SYSIDENT_H
#define CV1SYSIDENT_H
#include "AState.h"
#include "CV1SysIdentAction.h"

class CV1SysIdent : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
	bool onInitial(CMessage& msg);
	bool onIdle(CMessage& msg);
	bool onRunning(CMessage& msg);
public:
	explicit CV1SysIdent();
	CV1SysIdent(const CV1SysIdent&) = delete;
	CV1SysIdent& operator=(const CV1SysIdent&) = delete;
	~CV1SysIdent() = default;
private:
	CV1SysIdentAction mAction;

	using StatePtr = bool (CV1SysIdent::*)(CMessage&);

	static constexpr StatePtr sInitial = static_cast<CV1SysIdent::StatePtr>(&CV1SysIdent::onInitial);
	static constexpr StatePtr sIdle    = static_cast<CV1SysIdent::StatePtr>(&CV1SysIdent::onIdle);
	static constexpr StatePtr sRunning = static_cast<CV1SysIdent::StatePtr>(&CV1SysIdent::onRunning);

	StatePtr mState;
};

#endif
