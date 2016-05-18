#include "include/ObjectClass.h"
#include <algorithm>
#include <QDebug>

ObjectClass::ObjectClass(QString _name, int16_t _id) :	rePaint ( false )
{
    name = _name;
    id = _id ;
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
    emit changeState ( -1 );
  }
}

bool ObjectClass::setAlarmDev( const int16_t id_dev, const bool alarm, const bool newf )
{
    auto dev = getDevice ( id_dev );

    if ( dev == NULL )
        return false;

    dev->setAlarm( alarm, newf );/*
    if ( !alarm )
    {
        bool _alarm = false;
        foreach (auto &it, Devices)
        {
        if ( it->isAlarm() )
          {
            _alarm = true;
           break;
           }
         };
        //emitSigChange();
        setAlarm ( _alarm );
    } else
    {
        setAlarm ( true );
    };*/
    return true;
};

bool ObjectClass::setLostAlarmDev( const int16_t id_dev, const bool alarm)
{
    auto dev = getDevice ( id_dev );

    if ( dev == NULL )
        return false;

    dev->setlostAlarm( alarm );

    return true;
};

bool ObjectClass::setActiveDev( const int16_t id_dev, const int8_t active)
{
    auto dev = getDevice ( id_dev );

    if ( dev == NULL )
        return false;

    dev->setActive( active );

    return true;
};

void ObjectClass::emitSigChange()
{
    emit changeState ( id );
};


