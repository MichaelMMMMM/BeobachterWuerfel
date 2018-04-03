#include "CMainWindow.h"
#include <QApplication>
#include "CMPUData.h"
#include "CADCData.h"
#include "TMatrix.h"
#include <QVector>
#include "Global.h"
#include "CSensorData.h"
#include "SExpData.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<CMPUData>("CMPUData");
    qRegisterMetaType<CADCData>("CADCData");
    qRegisterMetaType<QVector<double> >("Qvector<double>");
    qRegisterMetaType<CSensorData>("CSensorData");
    qRegisterMetaType<SExpData>("SExpData");

    CMainWindow w;
    w.show();

    return a.exec();
}
