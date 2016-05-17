#include "include/baseDevice.h"
#include <QDebug>

baseDevice::baseDevice(): alarm ( false ), click ( false ), conf( false ),
    blink ( false ), lErr ( false ), newf(false), reg (false), active(NOACTIVE)
{

}

baseDevice::~baseDevice()
{

}

bool baseDevice::isAlarm() const
{
 return alarm;
};

void baseDevice::setAlarm (const bool al , const bool newf)
{
        alarm = al;
        this->newf = newf;
        if ( al )
        {
              setlostAlarm ( false );
        };
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
    if ( name != _name )
    {
        name = _name;
        emitSigChange();
    };
};

bool baseDevice::isClicked() const
{
 return click;
};

void baseDevice::setClicked( const bool cli )
{
 click= cli;
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

bool baseDevice::islostAlarm() const
{
  return lErr;
};

void baseDevice::setActive( const int8_t active )
{
    if ( this->active != active )
    {
     this->active = CONST_ACTIVE (active);
     emitSigChange();
    };
};

baseDevice::CONST_ACTIVE baseDevice::isActive() const
{
  return active ;
};

void baseDevice::setlostAlarm( const bool lErr )
{
    if ( this->lErr != lErr )
    {
     this->lErr = lErr;
     emitSigChange();
    };
};

bool baseDevice::isNewErr() const
{
return newf;
};

void baseDevice::setConf( const bool ok )
{
  if ( conf != ok )
  {
   conf = ok;
   emitSigChange();
  }
};

void baseDevice::setReg( const bool reg )
{
    if ( this->reg != reg )
    {
     this->reg = reg;
     emitSigChange();
    };
};

bool baseDevice::isReg() const
{
    return reg;
};
