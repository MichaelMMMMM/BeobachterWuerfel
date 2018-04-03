#include "CRxThread.h"
#include <unistd.h>
#include <iostream>
#include <QVector>

CRxThread::CRxThread(QObject *parent) :
    QThread(parent),
    mConnectedFlag(false)
{
}
void CRxThread::run()
{
    CMessage msg;
    while(true)
    {
        if(mConnectedFlag)
        {
            if(mClient.readMessage(msg))
            {
                EEvent event = msg.getEvent();
                switch(event)
                {
                case EEvent::EXPERIMENT_DATA:
                {
                    SExpData data = *reinterpret_cast<SExpData*>(msg.getDataPtr());
                    emit expDataReceivedSIG(data);
                }
                default:
                    break;
                }
            }
        }
        else
        {
            sleep(1);
        }
    }
}
void CRxThread::runV1SysIdentSLOT()
{
    if(mConnectedFlag == true)
    {
        mClient.disconnect();
    }

    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_V1_SYS_IDENT);
    mClient.writeMessage(msg);
}
void CRxThread::startExperimentSLOT()
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::START);
        mClient.writeMessage(msg);
    }
}
void CRxThread::stopExperimentSLOT()
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::STOP);
        mClient.writeMessage(msg);
    }
}
void CRxThread::selectNoSignalSLOT()
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::SELECT_NO_SIGNAL);
        mClient.writeMessage(msg);
    }
}
void CRxThread::selectJumpSignalSLOT(float amp)
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::SELECT_JUMP_SIGNAL);
        *reinterpret_cast<float*>(msg.getDataPtr()) = amp;
        mClient.writeMessage(msg);
    }
}
void CRxThread::selectSineSignalSLOT(float amp)
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::SELECT_SINE_SIGNAL);
        *reinterpret_cast<float*>(msg.getDataPtr()) = amp;
        mClient.writeMessage(msg);
    }
}
void CRxThread::selectMultiSineSignalSLOT(float amp)
{
    if(mConnectedFlag == true)
    {
        CMessage msg(EEvent::SELECT_MULTISINE_SIGNAL);
        *reinterpret_cast<float*>(msg.getDataPtr()) = amp;
        mClient.writeMessage(msg);
    }
}

void CRxThread::runV2BalanceSLOT()
{
    if(mConnectedFlag == true)
    {
        mClient.disconnect();
    }
    mConnectedFlag = mClient.connectToServer();
    CMessage msg(EEvent::RUN_V2_BALANCE);
    mClient.writeMessage(msg);
}
