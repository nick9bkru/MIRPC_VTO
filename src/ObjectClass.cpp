#include "include/ObjectClass.h"
#include <QDebug>

ObjectClass::ObjectClass(QString _name, int16_t _id) :	name ( _name ),id( _id ), conf( false ),rePaint ( false )
{
     qDebug(  ) << "ObjectClass::ObjectClass id = " << id << " name = " << _name  ;
}

DeviceClass* ObjectClass::getDevice( const int16_t _id )
{
    auto it = Devices.find( _id ) ;
    return  ( it == Devices.end() ) ?  NULL : (*it);
};


void ObjectClass::setDevice(const int16_t _id  , DeviceClass* _dev)
{
   auto it = Devices.find( _id ) ;
   if ( it != Devices.end() )
    {
       qDebug() << " ObjectClass::setDevice Find device whith name == " << _id ;
        delete *it;
    }
   Devices[ _id ] = _dev;
   rePaint = true;
   //emit change ( getId() );
}

void ObjectClass::removeDevices()
{
    qDebug(  ) << "!!!!!!!!!!!! ObjectClass::removeDevices()";
    foreach( auto it , Devices )
    {
       delete it ;
    } ;
    Devices.clear();
    rePaint = true;
};

int16_t ObjectClass::getId() const
{
 return  id;
};

QString ObjectClass::getName() const
{
 return name;
};

bool ObjectClass::getConf( ) const
{
 return conf;
};

void ObjectClass::setName( QString _name )
{
    if ( _name != name )
    {

     name= _name;
     emit change ( getId() );
    }
};

void ObjectClass::setConf( bool ok )
{
  if ( conf != ok )
  {

   conf = ok;
   emit change ( getId() );
  }
};

ObjectClass::DevisesType * ObjectClass::getDevices()
{
  return &Devices;
};

void ObjectClass::emitRefresh()
{
    qDebug() << "ObjectClass::emitRefresh() !! rePaint == " << rePaint;
  if ( rePaint )
  {
    rePaint = false;
    emit change ( -1 );
  }
}

bool ObjectClass::setAlarmDev( const int16_t id_dev, const bool alarm )
{
    auto dev = getDevice ( id_dev );
    if ( dev != NULL )
        dev->setAlarm( alarm );
        return dev != NULL;
};
