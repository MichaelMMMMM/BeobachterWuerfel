/**
 * @author	Michael Meindl
 * @file	CControlComp.h
 * @date	5.1.2017
 * @brief	Class defition for the control component.
 */
#ifndef CCONTROLCOMP_H
#define CCONTROLCOMP_H
#include "AComponentBase.h"
#include "TFSM.h"
#include "TTypeList.h"
#include "TLinHierarchy.h"
#include "TStateHolder.h"
#include "CV1SysIdent.h"
#include "CV2Balance.h"

using StateList = TYPELIST_2(CV1SysIdent, CV2Balance);

class CControlComp : public AComponentBase
{
public:
	void init() override;
	void run() override;
public:
	CControlComp() = default;
	CControlComp(const CControlComp&) = delete;
	CControlComp& operator=(const CControlComp&) = delete;
	~CControlComp() = default;
private:
	TFSM<TLinHierarchy<StateList, TStateHolder> > mFSM;
};

#endif
