#ifndef PURBUT_H
#define PURBUT_H
#include "include/StandBut.h"
/**
 * @brief The PurBut class
 * кнопка отображения ПУР и ПУС
 */
class PurBut : public StandBut
{
public:
    PurBut(DeviceClass* _dev, QWidget * parent );
    ~PurBut();
    /**
     * слот для установки текста на кнопке
     */
    virtual void setText (const QString &str);
};

#endif // PURBUT_H
