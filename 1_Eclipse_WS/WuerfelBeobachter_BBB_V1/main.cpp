#include "CThread.h"
#include "CControlComp.h"
#include "CCommComponent.h"
#include "CProxy.h"

int main()
{
	CCommComponent commComp;
	CControlComp   controlComp;

	CThread commThread(&commComp, CThread::PRIORITY_NORM);
	CThread controlThread(&controlComp, CThread::PRIORITY_ABOVE_NORM);

	CProxy& proxy = CProxy::getInstance();
	proxy.registerCommComponent(&commComp);
	proxy.registerControlComponent(&controlComp);

	commThread.start();
	controlThread.start();

	commThread.join();
	controlThread.join();

	return 0;
}
