#include "include/DeviceClass.h"
#include <QDebug>

DeviceClass::DeviceClass( QString _name, int16_t _id )
{
    name = _name;
    id = _id;
    qDebug(  ) << "DeviceClass::DeviceClass id = " << id << " name = " << _name  ;
}

void DeviceClass::setId( int16_t _id )
{
 id = _id;
};

void DeviceClass::setName( QString _name )
{
    if ( name != _name )
    {
        name = _name;
        emit changeState( id );
    };
};

void DeviceClass::setAlarm ( const bool _alarm)
{
  alarm = _alarm;
};
