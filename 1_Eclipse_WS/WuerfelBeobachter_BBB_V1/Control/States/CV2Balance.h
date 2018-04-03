#ifndef CV2BALANCE_H
#define CV2BALANCE_H
#include "AState.h"
#include "CV2BalanceAction.h"

class CV2Balance : public AState
{
public:
	bool dispatch(CMessage& msg) override;
	bool tryEntry(CMessage& msg, AState*& statePtr) override;
	void onEntry() override;
	void onExit() override;
	bool onInitial(CMessage& msg);
	bool onIdle(CMessage& msg);
	bool onBalance(CMessage& msg);
public:
	explicit CV2Balance();
	CV2Balance(const CV2Balance&) = delete;
	CV2Balance& operator=(const CV2Balance&) = delete;
	~CV2Balance() = default;
private:
	CV2BalanceAction mAction;

	using StatePtr = bool (CV2Balance::*)(CMessage&);

	static constexpr StatePtr sInitial = static_cast<StatePtr>(&CV2Balance::onInitial);
	static constexpr StatePtr sIdle    = static_cast<StatePtr>(&CV2Balance::onIdle);
	static constexpr StatePtr sBalance = static_cast<StatePtr>(&CV2Balance::onBalance);

	StatePtr mState;
};

#endif
