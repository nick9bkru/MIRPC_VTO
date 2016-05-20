#include "include/buttom/DeviceBut.h"
#include <QDebug>

DeviceBut::DeviceBut( QWidget * parent, int8_t _index ): ButParent(parent), index ( _index )
{
  setMinimumHeight( 80 );

  setMinimumWidth( 104 );

};

int8_t DeviceBut::getIndex()
{
    return index;
};

