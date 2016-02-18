#include "include/baseDevice.h"


baseDevice::baseDevice(): alarm ( false )
{


}

bool baseDevice::isAlarm() const
{
 return alarm;
};

int16_t baseDevice::getId() const
{
 return  id;
};

QString baseDevice::getName() const
{
 return name;
};
