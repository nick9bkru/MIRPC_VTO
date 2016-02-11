#ifndef STANDBUT_H
#define STANDBUT_H

#include "include/butparent.h"
#include "include/DeviceClass.h"

/**
 * @brief The StandBut class
 * класс кнопок отображения состояния содержания стойки
 */
class StandBut : public ButParent
{
     Q_OBJECT
public:
    StandBut( DeviceClass* _dev,  QWidget * parent = 0 );

    bool isBlink () const;
public slots:
    /**
     * @brief updState обновить состояние кнопки
     */
    void updState();
private:
    /**
     * @brief _dev
     *указатель на класс с состоянием объекта
     */
    DeviceClass* dev;
};

#endif // STANDBUT_H
