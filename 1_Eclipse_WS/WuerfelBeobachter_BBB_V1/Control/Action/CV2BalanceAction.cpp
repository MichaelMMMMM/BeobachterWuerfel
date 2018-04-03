#include "CV2BalanceAction.h"
#include <iostream>

CV2BalanceAction::CV2BalanceAction() : mTime(0.0F)
{

}
void CV2BalanceAction::entryV2Balance()
{
	std::cout << "[*] Control-Comp: Entering V2 Balance . . . " << std::endl;
	mTime = 0.0F;
	sTimerTask.setPeriodMS(10);
	sTimerTask.resume(true);
}
void CV2BalanceAction::exitV2Balance()
{
	std::cout << "[*] Control-Comp: Exiting V2 Balance . . . " << std::endl;
	sTimerTask.pause(true);
}
void CV2BalanceAction::entryIdle()
{
	std::cout << "[*] Control-Comp: Entering V2 Balance/Idle . . . " << std::endl;
}
void CV2BalanceAction::exitIdle()
{
	std::cout << "[*] Control-Comp: Exiting V2 Balance/Idle . . ." << std::endl;
}
void CV2BalanceAction::entryBalance()
{
	std::cout << "[*] Control-Comp: Entering V2 Balance/Balance . . . " << std::endl;
	//TODO Activate HW
}
void CV2BalanceAction::exitBalance()
{
	std::cout << "[*] Control-Comp: Exiting V2 Balance/Balance . . . " << std::endl;
	//TODO Deactivate HW
}
void CV2BalanceAction::sampleIteration()
{
	SSensorData sensordata;
	if(sHardware.fetchValues(sensordata) == false)
	{
		std::cout << "[*] Control-Comp: Failed to fetch sensor data . . . " << std::endl;
	}
	else
	{
		mSignalFlow.calcOutput(sensordata);

		auto x = mSignalFlow.CStateEstimate::getValue();
		float u = 0.0F;
		SExpData data{mTime, x[1][1], x[2][1], x[3][1], u};
		CProxy::getInstance().transmitExpData(data, false);
	}
	mTime += 0.01F;
}
bool CV2BalanceAction::inBalanceArea()
{
	auto x = mSignalFlow.CStateEstimate::getValue();
	auto phi = x[1][1];
	float phi_abs = phi > 0.0F ? phi : -phi;
	return phi_abs < sPhiMax;
}
void CV2BalanceAction::setTorque()
{
	//TODO set torque
}
