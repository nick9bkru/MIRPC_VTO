#ifndef BSPURBUT_H
#define BSPURBUT_H
#include "include/StandBut.h"
/**
 * @brief The BSPurBut class
 * кнопка отображения БС-ПУР
 */
class BSPurBut : public StandBut
{
public:
    BSPurBut(DeviceClass *_dev, QWidget *parent);
    ~BSPurBut();
};

#endif // BSPURBUT_H
