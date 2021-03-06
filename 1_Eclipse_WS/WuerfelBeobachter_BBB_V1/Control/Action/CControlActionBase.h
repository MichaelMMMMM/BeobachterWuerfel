/**
 * @file	CControlActionBase.h
 * @author	Michael Meindl
 * @date	5.1.2017
 * @brief	Class definition for the basic Control-Actionhandler.
 */
#ifndef CCONTROLACTIONBASE_H
#define CCONTROLACTIONBASE_H
#include "CBBBHardware.h"
#include "CTimerTask.h"
#include "CThread.h"
#include "CProxy.h"

class CControlActionBase
{
public:
	CControlActionBase() = default;
	CControlActionBase(const CControlActionBase&) = delete;
	CControlActionBase& operator=(const CControlActionBase&) = delete;
	~CControlActionBase() = default;
protected:
	static CBBBHardware sHardware;
	static CTimerTask   sTimerTask;
	static CThread sTimerThread;
	static CProxy& sProxy;
};

#endif
