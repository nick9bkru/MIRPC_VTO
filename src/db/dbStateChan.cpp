#include "include/db/dbStateChan.h"
#include "include/util/Singleton.h"

BDStateChan::BDStateChan()
{
   db = & Util::Singleton<DBClass>::getInstance();
}


BDStateChan::VecDev BDStateChan::getDev (int id)
{
    db->isOpened ();
    VecDev ret;
    Dev buf;
    QString str = std::move( QString("select  index, name, sost, err from  sost_objects where id_obj= %1 order by index;" ).arg( id ) );
    QSqlQuery query ( str );

     db->isValid ( query );
    while (query.next())
    {
       // buf.name = query.value(0).toInt();
        buf.index = query.value(0).toInt();
        buf.name = query.value(1).toString();
        buf.sost = query.value(2).toInt();
        buf.err = query.value(3).toInt();
        ret.push_back( buf );
    }

    return std::move( ret );
};

bool BDStateChan::setBlink ( const int &index , const bool &bl)
{
  db->isOpened ();
  QString str = std::move( QString( "update sost_objects set blink = %2 where index = %1;" ).arg( index ).arg( bl )) ;

  QSqlQuery query ( str );
  db->isValid ( query );
  return 1;
};

bool BDStateChan::getBlink ( const int &index  )
{
    db->isOpened ();
    QString str = std::move( QString( "select blink from sost_objects where index = %1;" ).arg( index )) ;
    QSqlQuery query ( str );
     db->isValid ( query );
    query.next();
    return ( query.value(0).toInt() == 1 ) ;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
bool BDStateChan::Dev::operator!=( const BDStateChan::Dev & left)
{
 return !(* this == left );
};

bool BDStateChan::Dev::operator==( const BDStateChan::Dev & left)
{
 bool b =  ( left.name == name ) && ( left.sost == sost ) && (left.err == err) &&
         ( index == left.index );
 return b ;
};

BDStateChan::Dev BDStateChan::Dev::operator=( const BDStateChan::Dev & left)
{
    index = left.index;
   name=left.name;
   sost = left.sost;
   err = left.err;
  return *this;
};
