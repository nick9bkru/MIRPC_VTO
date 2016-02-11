#include "include/DeviceClass.h"
#include <QDebug>

DeviceClass::DeviceClass( QString _name, int16_t _id ) : name ( _name ),id( _id ), alarm( false )
{
    qDebug(  ) << "DeviceClass::DeviceClass id = " << id << " name = " << _name  ;
}

int16_t DeviceClass::getId() const
{
 return  id;
};

QString DeviceClass::getName() const
{
 return name;
};

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

bool DeviceClass::isAlarm() const
{
  return alarm;
};

void DeviceClass::setAlarm ( const bool _alarm)
{
  alarm = _alarm;
};
