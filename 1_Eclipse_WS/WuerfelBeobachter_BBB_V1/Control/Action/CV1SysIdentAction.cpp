#include "CV1SysIdentAction.h"
#include <iostream>

CV1SysIdentAction::CV1SysIdentAction() : mTime(0.0F)
{

}
void CV1SysIdentAction::onEntryV1SysIdent()
{
	std::cout << "[*] Control-Comp: Entering V1 System-Identification . . . " << std::endl;
	mSignalGenerator.selectNoSignal();
}
void CV1SysIdentAction::onExitV1SysIdent()
{
	std::cout << "[*] Control-Comp: Exiting V1 System-Identification . . . " << std::endl;
}
void CV1SysIdentAction::onEntryIdle()
{
	std::cout << "[*] Control-Comp: Entering V1 System-Identification/Idle . . . " << std::endl;
}
void CV1SysIdentAction::onExitIdle()
{
	std::cout << "[*] Control-Comp: Exiting V1 System-Identification/Idle . . . " << std::endl;
}
void CV1SysIdentAction::onEntryRunning()
{
	std::cout << "[*] Control-Comp: Entering V1 System-Identification/Running . . ." << std::endl;
	sTimerTask.setPeriodMS(10);
	mTime = 0.0F;
	sHardware.enableMotor();
	mSignalFlow.CCompFilter::reset();
	sTimerTask.resume(true);
}
void CV1SysIdentAction::onExitRunning()
{
	std::cout << "[*] Control-Comp: Exiting V1 System-Identification/Running . . . " << std::endl;
	sTimerTask.pause(false);
	sHardware.disableMotor();
}
void CV1SysIdentAction::sampleV1SysIdent()
{
	SSensorData sensorData;
	sHardware.fetchValues(sensorData);
	mSignalFlow.calcOutput(sensorData);
	auto const_x = mSignalFlow.CCompFilter::getValue();
	CStateVector x = const_x;

	float tm = mSignalGenerator.getSignal(mTime);
	sHardware.setTorque(tm);

	SExpData data{mTime, x[1][1], x[2][1], x[3][1], tm};
	mTime += 0.01F;
	CProxy::getInstance().transmitExpData(data, false);
}
void CV1SysIdentAction::selectNoInputSignal()
{
	std::cout << "[*] Control-Comp/V1 System-Identification: Selecting no input signal . . . " << std::endl;
	mSignalGenerator.selectNoSignal();
}
void CV1SysIdentAction::selectJumpSignal(float amp)
{
	std::cout << "[*] Control-Comp/V1 System-Identification: Selecting Jump-Signal, Amplitude: " << amp << std::endl;
	mSignalGenerator.selectJumpSignal(amp);
}
void CV1SysIdentAction::selectSineSignal(float amp)
{
	std::cout << "[*] Control-Comp/V1 System-Identification: Selecting Sine-Signal, Amplitude: " << amp << std::endl;
	mSignalGenerator.selectSineSignal(amp);
}
void CV1SysIdentAction::selectMultiSineSignal(float amp)
{
	std::cout << "[*] Control-Comp/V1 System-Identification: Selecting Multisine-Signal, Ampliteud: " << amp << std::endl;
	mSignalGenerator.selectMultiSineSignal(amp);
}
