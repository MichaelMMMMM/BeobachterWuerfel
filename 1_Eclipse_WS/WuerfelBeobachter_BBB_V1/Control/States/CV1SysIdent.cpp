#include "CV1SysIdent.h"

CV1SysIdent::CV1SysIdent() : mState(sInitial)
{

}
bool CV1SysIdent::dispatch(CMessage& msg)
{
	return (this->*mState)(msg);
}
bool CV1SysIdent::tryEntry(CMessage& msg, AState*& statePtr)
{
	EEvent event = msg.getEvent();
	if(event == EEvent::RUN_V1_SYS_IDENT)
	{
		statePtr = this;
		return true;
	}
	return false;
}
void CV1SysIdent::onEntry()
{
	CMessage msg(EEvent::INIT);
	this->dispatch(msg);
}
void CV1SysIdent::onExit()
{
	CMessage msg(EEvent::EXIT);
	this->dispatch(msg);
}
bool CV1SysIdent::onInitial(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::INIT == event)
	{
		mState = sIdle;
		mAction.onEntryV1SysIdent();
		mAction.onEntryIdle();
		return true;
	}
	return false;
}
bool CV1SysIdent::onIdle(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.onExitIdle();
		mState = sInitial;
		mAction.onExitV1SysIdent();
		return true;
	}
	if(EEvent::START == event)
	{
		mAction.onExitIdle();
		mState = sRunning;
		mAction.onEntryRunning();
		return true;
	}
	if(EEvent::SELECT_NO_SIGNAL == event)
	{
		mAction.selectNoInputSignal();
		return true;
	}
	if(EEvent::SELECT_JUMP_SIGNAL == event)
	{
		float amp = *reinterpret_cast<float*>(msg.getDataPtr());
		mAction.selectJumpSignal(amp);
		return true;
	}
	if(EEvent::SELECT_SINE_SIGNAL == event)
	{
		float amp = *reinterpret_cast<float*>(msg.getDataPtr());
		mAction.selectSineSignal(amp);
		return true;
	}
	if(EEvent::SELECT_MULTISINE_SIGNAL == event)
	{
		float amp = *reinterpret_cast<float*>(msg.getDataPtr());
		mAction.selectMultiSineSignal(amp);
		return true;
	}
	return false;
}
bool CV1SysIdent::onRunning(CMessage& msg)
{
	EEvent event = msg.getEvent();
	if(EEvent::EXIT == event)
	{
		mAction.onExitRunning();
		mState = sInitial;
		mAction.onExitV1SysIdent();
		return true;
	}
	if(EEvent::STOP == event)
	{
		mAction.onExitRunning();
		mState = sIdle;
		mAction.onEntryIdle();
		return true;
	}
	if(EEvent::TIMER_TICK == event)
	{
		mAction.sampleV1SysIdent();
		return true;
	}
	return false;
}
