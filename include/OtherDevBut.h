#ifndef OTHERDEVBUT_H
#define OTHERDEVBUT_H
#include "include/StandBut.h"
class OtherDevBut : public StandBut
{

public:
    OtherDevBut(DeviceClass *_dev, QWidget *parent);
    ~OtherDevBut();
};

#endif // OTHERDEVBUT_H
