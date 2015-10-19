#include "include/db/dbStandDevice.h"
#include "include/util/Singleton.h"

dbStandDevice::dbStandDevice()
{
    db = & Util::Singleton<DBClass>::getInstance();
}

dbStandDevice::VecStandDev dbStandDevice::getStandDev( )
{
    db->isOpened ();
    VecStandDev ret;
    StandDev buf;
    QString str = "select name, err from  stand_device where type = 1 order by index ;" ;
    QSqlQuery query ( str );

    db->isValid ( query );

    while (query.next())
    {
       // buf.name = query.value(0).toInt();
        buf.name = query.value(0).toString();
        buf.err = query.value(1).toInt();
        ret.push_back( buf );
    };
    return std::move( ret );
};

dbStandDevice::VecStandDev dbStandDevice::getCPU ()
{
    db->isOpened ();
    VecStandDev ret;
    StandDev buf;
    QString str = "select name, err from  stand_device where type = 2 order by index ;" ;

    QSqlQuery query ( str );

    db->isValid ( query );

    while (query.next())
    {
       // buf.name = query.value(0).toInt();
        buf.name = query.value(0).toString();
        buf.err = query.value(1).toInt();
        ret.push_back( buf );
    };
    return std::move( ret );

};

//////////////////////////////////////////////////////////////////////////
dbStandDevice::StandDev dbStandDevice::StandDev::operator=( const dbStandDevice::StandDev & left)
{

   name=left.name;
   err = left.err;

  return *this;
};


bool dbStandDevice::StandDev::operator!=( const dbStandDevice::StandDev & left)
{
 return !(* this == left );
};

bool dbStandDevice::StandDev::operator==( const dbStandDevice::StandDev & left)
{
 bool b =  ( left.name == name ) && ( left.err == err );
 return b ;
};
