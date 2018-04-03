#ifndef CRXTHREAD_H
#define CRXTHREAD_H
#include "CClient.h"
#include "CMPUData.h"
#include "CADCData.h"
#include "E1DControlSystem.h"
#include <QThread>
#include <QVector>
#include "CSensorData.h"
#include "SExpData.h"

class CRxThread : public QThread
{
    Q_OBJECT
public:
    explicit CRxThread(QObject *parent = 0);
    void run() override;
signals:
    void expDataReceivedSIG(const SExpData& data);
public slots:
    void runV1SysIdentSLOT();
    void startExperimentSLOT();
    void stopExperimentSLOT();
    void selectNoSignalSLOT();
    void selectJumpSignalSLOT(float amp);
    void selectSineSignalSLOT(float amp);
    void selectMultiSineSignalSLOT(float amp);

    void runV2BalanceSLOT();
private:
    CClient mClient;
    bool mConnectedFlag;
};

#endif // CRXTHREAD_H
