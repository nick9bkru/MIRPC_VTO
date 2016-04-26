#include "include/DeviceClass.h"
#include <QDebug>

DeviceClass::DeviceClass( const QString _name , const int16_t _id, const bool conf ) :baseDevice()
{
    name = _name;
    id = _id;
    this->conf = conf;
    qDebug(  ) << "DeviceClass::DeviceClass id = " << id << " name = " << _name  ;
 //   connect( this , SIGNAL (baseDevice::changeState ( int16_t & )), this , SIGNAL (changeState ( int16_t & )) );
}

void DeviceClass::setId( int16_t _id )
{
 id = _id;
};

//bool DeviceClass::getConf( ) const
//{
//    return true;
//};

void DeviceClass::emitSigChange()
{
    emit changeState ( id );
};
