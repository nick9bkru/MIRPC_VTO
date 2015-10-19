#ifndef STANDBUT_H
#define STANDBUT_H

#include "include/butparent.h"

/**
 * @brief The StandBut class
 * класс кнопок отображения состояния содержания стойки
 */
class StandBut : public ButParent
{
     Q_OBJECT
public:
    enum STATE
    {
        NORM= 0,
        CALL
    };
    StandBut( QWidget * parent = 0 );
private:
};

#endif // STANDBUT_H
