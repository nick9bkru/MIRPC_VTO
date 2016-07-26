#ifndef DEVICEBUT_H
#define DEVICEBUT_H

#include "include/buttom/butparent.h"

/**
 * @brief The DeviceBut class
 * класс кнопок отображения состояния содержания объекта
 */
class DeviceBut : public ButParent
{
    Q_OBJECT
public:

  DeviceBut(QWidget * parent = 0 , int8_t _index = 0);
  int8_t getIndex();
private:
 int8_t index;
};

#endif // DEVICEBUT_H
