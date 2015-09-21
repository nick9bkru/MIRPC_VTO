#ifndef DEVICEBUT_H
#define DEVICEBUT_H

#include "include/butparent.h"

class DeviceBut : public ButParent
{
    Q_OBJECT
public:
    enum STATE
    {
        NORM= 0,
        CALL
    };
    enum
    {
        ERR = 1
    };

  DeviceBut( QWidget * parent = 0 );
private:

};

#endif // DEVICEBUT_H
