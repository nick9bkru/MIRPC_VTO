#ifndef BSPURBUT_H
#define BSPURBUT_H
#include "include/buttom/StandBut.h"
/**
 * @brief The BSPurBut class
 * кнопка отображения БС-ПУР
 */
class BSPurBut : public StandBut
{
public:
    /**
     * @brief BSPurBut конструктор
     * @param _dev указатель на класс устройства
     * @param parent отец
     */
    BSPurBut(DeviceClass *_dev, QWidget *parent);
    ~BSPurBut();
};

#endif // BSPURBUT_H
