#include "include/baseDevice.h"
#include <QDebug>

baseDevice::baseDevice(): alarm ( false ), click ( false ), conf( false ),
    blink ( false ), lErr ( false )
{

}

bool baseDevice::isAlarm() const
{
 return alarm;
};

void baseDevice::setAlarm ( const bool al )
{
        setClicked( false );
        setBlink ( al );
        alarm = al;
        setlostErr ( true );
     //   qDebug( ) << "void baseDevice::setAlarm " << al;
        emitSigChange();
};

int16_t baseDevice::getId() const
{
 return  id;
};

QString baseDevice::getName() const
{
 return name;
};

void baseDevice::setName( QString _name )
{
    name = _name;
};

bool baseDevice::isClicked() const
{
 return click;
};

void baseDevice::setClicked( const bool cli )
{
 click= cli;
 if ( click )
 {
     setlostErr ( false );
    setBlink(  false );
 }
};

bool baseDevice::getConf( ) const
{
 return conf;
};

 bool baseDevice::isBlink() const
 {
  return blink;
 };

void baseDevice::setBlink( const bool bli )
{
  blink = bli;
};

bool baseDevice::islostErr()
{
  return lErr;
}

void baseDevice::setlostErr( const bool lErr )
{
  this->lErr = lErr;
}

