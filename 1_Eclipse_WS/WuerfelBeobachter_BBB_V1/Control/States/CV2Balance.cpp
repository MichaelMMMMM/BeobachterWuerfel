#include "CV2Balance.h"

CV2Balance::CV2Balance() : mState(sInitial)
{

}
bool CV2Balance::dispatch(CMessage& msg)
{
	return (this->*mState)(msg);
}
bool CV2Balance::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(event == EEvent::RUN_V2_BALANCE)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CV2Balance::onEntry()
{
	CMessage msg(EEvent::INIT);
	this->dispatch(msg);
}
void CV2Balance::onExit()
{
	CMessage msg(EEvent::EXIT);
	this->dispatch(msg);
}
bool CV2Balance::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		mAction.entryV2Balance();
		mAction.entryIdle();
		return true;
	}
	return false;
}
bool CV2Balance::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.exitIdle();
		mAction.exitV2Balance();
		mState = sInitial;
		return true;
	}
	if(EEvent::IN_BALANCE_AREA == event)
	{
		mAction.exitIdle();
		mState = sBalance;
		mAction.entryBalance();
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleIteration();
		if(mAction.inBalanceArea())
		{
			sInternalQueue = CMessage(EEvent::IN_BALANCE_AREA);
			sQueueSize     = 1U;
		}
		return true;
	}
	return false;
}
bool CV2Balance::onBalance(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.exitBalance();
		mAction.exitV2Balance();
		mState = sInitial;
		return true;
	}
	if(EEvent::NOT_IN_BALANCE_AREA == event)
	{
		mAction.exitBalance();
		mState = sIdle;
		mAction.entryIdle();
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleIteration();
		if(mAction.inBalanceArea() == false)
		{
			sInternalQueue = CMessage(EEvent::NOT_IN_BALANCE_AREA);
			sQueueSize     = 1U;
		}
		mAction.setTorque();
		return true;
	}
	return false;
}
