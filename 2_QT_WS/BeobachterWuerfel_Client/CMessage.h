/**
 * @file	CMessage.h
 * @author	Michael Meindl
 * @date	08.02.2016
 * @brief	Data Abstraction for message objects.
 */
#ifndef CMESSAGE_H
#define CMESSAGE_H
#include "Global.h"
#include "EEvent.h"

class CMessage
{
public:
    EEvent  getEvent() const;
    void    setTime(Float32 time);
    Float32 getTime();
    UInt8* 	getDataPtr();
public:
    CMessage();
    CMessage(EEvent event);
    CMessage(EEvent event, Float32 time);
    CMessage(const CMessage&) = default;
    CMessage& operator=(const CMessage&) = default;
    ~CMessage() = default;
private:
    static constexpr UInt32 sDataFieldSize = 32U;
    EEvent mEvent;
    Float32 mTime;
    UInt8 mData[32];
};

#endif
