#include "include/dbobjectclass.h"
#include <QSqlError>

DbObjectClass::DbObjectClass( ) : DBClass ()
{
}

DbObjectClass::DbObjectClass( QString _dbName , QString _host ) : DBClass( _dbName , _host  )
{
}

DbObjectClass::Obj DbObjectClass::getObject ( int id )
{
    Obj ret;
    if ( !isOpened () )
    {
        return std::move( ret );
    };
    QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err   from  all_object where index = %1 order by index ;" ).arg( id ) );
    if ( !query.next() )
    {
        throw ( (QString ( " Error getObject for id = %1" ).arg(id) ).toStdString() );
    };
    ret.id = query.value(0).toInt();
    ret.name = query.value(1).toString();
    ret.sost = query.value(2).toInt();
    ret.err = query.value(3).toInt();
    return ret;
};

DbObjectClass::VecObj DbObjectClass::getObject ( )
{

    VecObj ret;
    Obj buf;
    if ( !isOpened () )
    {
        return std::move( ret );
    };

    QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err  from  all_object order by index ;" ));

    while (query.next())
    {
        buf.id = query.value(0).toInt();
        buf.name = query.value(1).toString();
        buf.sost = query.value(2).toInt();
        buf.err = query.value(3).toInt();
        ret.push_back( buf );
    }
    return std::move( ret );
};

DbObjectClass::VecDev DbObjectClass::getDev (int id)
{
    isOpened ();
    VecDev ret;
    Dev buf;
    QString str = std::move( QString("select  name, sost, err from  sost_objects where id_obj= %1 order by index;" ).arg( id ) );
    QSqlQuery query ( str );

    if ( query.lastError().isValid())
    {
        throw ( std::string (" ERROR : ") +  str.toStdString() + (QString (" ::  %1").arg( query.lastError() .type() )).toStdString() );
         qDebug() << query.lastError();
    }
    while (query.next())
    {
       // buf.name = query.value(0).toInt();
        buf.name = query.value(0).toString();
        buf.sost = query.value(1).toInt();
        buf.err = query.value(2).toInt();
        ret.push_back( buf );
    }

    return std::move( ret );
};

DbObjectClass::VecStandDev DbObjectClass::getStandDev( )
{
    isOpened ();
    VecStandDev ret;
    StandDev buf;
    QString str = "select name, err from  stand_device where type = 1 order by index ;" ;
    QSqlQuery query ( str );

    if ( query.lastError().isValid())
    {
        throw ( std::string (" ERROR : ") +  str.toStdString() + (QString (" ::  %1").arg( query.lastError() .type() )).toStdString() );
         qDebug() << query.lastError();
    }

    while (query.next())
    {
       // buf.name = query.value(0).toInt();
        buf.name = query.value(0).toString();
        buf.err = query.value(1).toInt();
        ret.push_back( buf );
    };
    return std::move( ret );
};

DbObjectClass::VecStandDev DbObjectClass::getCPU ()
{
    isOpened ();
    VecStandDev ret;
    StandDev buf;
    QString str = "select name, err from  stand_device where type = 2 order by index ;" ;

    QSqlQuery query ( str );

    if ( query.lastError().isValid())
    {
        throw ( std::string (" ERROR : ") +  str.toStdString() + (QString (" ::  %1").arg( query.lastError() .type() )).toStdString() );
         qDebug() << query.lastError();
    }

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
bool DbObjectClass::Obj::operator!=( const DbObjectClass::Obj & left)
{
  return !(* this == left );
};

bool DbObjectClass::Obj::operator==( const DbObjectClass::Obj & left)
{
  bool b = ( left.id == id ) && ( left.name == name ) && ( left.sost == sost ) && (err == left.err);
  return b ;
};

DbObjectClass::Obj DbObjectClass::Obj::operator=( const DbObjectClass::Obj & left)
{
    id= left.id;
    name=left.name;
    sost = left.sost;
    err = left.err;
   return *this;
};
 //////////////////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////////////////
bool DbObjectClass::Dev::operator!=( const DbObjectClass::Dev & left)
{
  return !(* this == left );
};

bool DbObjectClass::Dev::operator==( const DbObjectClass::Dev & left)
{
  bool b =  ( left.name == name ) && ( left.sost == sost ) && (left.err == err) ;
  return b ;
};

DbObjectClass::Dev DbObjectClass::Dev::operator=( const DbObjectClass::Dev & left)
{

    name=left.name;
    sost = left.sost;
    err = left.err;
   return *this;
};
 //////////////////////////////////////////////////////////////////////////
DbObjectClass::StandDev DbObjectClass::StandDev::operator=( const DbObjectClass::StandDev & left)
{

    name=left.name;
    err = left.err;

   return *this;
};


bool DbObjectClass::StandDev::operator!=( const DbObjectClass::StandDev & left)
{
  return !(* this == left );
};

bool DbObjectClass::StandDev::operator==( const DbObjectClass::StandDev & left)
{
  bool b =  ( left.name == name ) && ( left.err == err );
  return b ;
};
