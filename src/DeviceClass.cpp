#include "include/DeviceClass.h"
#include <QDebug>

DeviceClass::DeviceClass( QString _name, int16_t _id ) :baseDevice()
{
    name = _name;
    id = _id;
    qDebug(  ) << "DeviceClass::DeviceClass id = " << id << " name = " << _name  ;
 //   connect( this , SIGNAL (baseDevice::changeState ( int16_t & )), this , SIGNAL (changeState ( int16_t & )) );
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
        emitSigChange();
    };
};

bool DeviceClass::getConf( ) const
{
    return true;
};

void DeviceClass::emitSigChange()
{
    emit changeState ( id );
};
