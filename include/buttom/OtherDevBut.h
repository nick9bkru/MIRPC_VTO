#ifndef OTHERDEVBUT_H
#define OTHERDEVBUT_H
#include "include/buttom/StandBut.h"

/**
 * @brief The OtherDevBut class
 * Класс кнопки для отображения различных устройст
 */
class OtherDevBut : public StandBut
{

public:
    OtherDevBut(DeviceClass *_dev, QWidget *parent);
    ~OtherDevBut();
};

#endif // OTHERDEVBUT_H
