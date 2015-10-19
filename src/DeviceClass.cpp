#include "include/DeviceClass.h"
#include <QDebug>

DeviceClass::DeviceClass( QString _name, int16_t _id ) : name ( _name ),id( _id )
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
