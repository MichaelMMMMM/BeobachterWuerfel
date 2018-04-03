/**
 * @file	EEvent.h
 * @author	Michael Meindl
 * @date	08.02.2017
 * @brief	Enumeration for the events.
 */
#ifndef EEVENT_H
#define EEVENT_H
#include "Global.h"

enum class EEvent : UInt32
{
    DEFAULT_IGNORE,
    INIT,
    EXIT,
    CLIENT_CONNECT,
    CLIENT_DISCONNECT,
    TIMER_TICK,
    START,
    STOP,
    RUN_V1_SYS_IDENT,
    RUN_V2_BALANCE,
    SELECT_NO_SIGNAL,
    SELECT_JUMP_SIGNAL,
    SELECT_SINE_SIGNAL,
    SELECT_MULTISINE_SIGNAL,
    EXPERIMENT_DATA,
    IN_BALANCE_AREA,
    NOT_IN_BALANCE_AREA
};

#endif
