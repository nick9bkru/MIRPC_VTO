#include "include/db/dbMainObject.h"
#include "include/util/Singleton.h"

dbMainObject::dbMainObject (DBClass *_db) : db( _db)
{
};


dbMainObject::Obj dbMainObject::getObject ( int id )
{
    Obj ret;
    db->isOpened ();
    //QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err   from  all_object where index = %1 order by index ;" ).arg( id ) );
    QSqlQuery query ( QString ( "select num, nazv,chng from objects where num = %1 order by num ; " ).arg( id ) );
    db->isValid ( query );
    ret.id = query.value(0).toInt();
    ret.name = query.value(1).toString();
    ret.chng = query.value(2).toInt();
  //  ret.sost = SOST (query.value(2).toInt() );
 //   ret.err = query.value(3).toInt();
    query.exec( QString ("update objects set chng = 0 where num = %1;").arg( id ) );
    return ret;
};

dbMainObject::VecObj dbMainObject::getObject ( )
{

    VecObj ret;
    Obj buf;
    db->isOpened ();

   // QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err  from  all_object order by index ;" ));
   QSqlQuery query ( QString ( "select num , nazv,chng from objects order by num ;" ));
    db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value(0).toInt();
        buf.name = query.value(1).toString();
        buf.chng = query.value(2).toInt();
        //buf.sost = SOST ( query.value(2).toInt() );
        //buf.err = query.value(3).toInt();
        ret.push_back( buf );
    }
    query.exec( "update objects set chng = 0;" );
    return std::move( ret );
};

dbMainObject::VecObjDev dbMainObject::getDev (int id)
{
    db->isOpened ();
    VecObjDev ret;
    ObjDev buf;
    QString str = std::move( QString("SELECT num, nazv FROM devices WHERE kod_obj = %1 order by num;" ).arg( id ) );

    QSqlQuery query ( str );

     db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value( 0 ).toInt();
        buf.name = query.value( 1 ).toString();
        ret.push_back( buf );
    }

    return std::move( ret );
};

dbMainObject::chngType dbMainObject::getChange()
{
    db->isOpened ();
    chngType ret;
    QString str = "SELECT num FROM objects WHERE chng = 1 ;";

    QSqlQuery query ( str );

     db->isValid ( query );
     while (query.next())
     {
         ret.push_back( query.value( 0 ).toInt() );
     }
    return std::move( ret );
};

dbMainObject::FaultsType dbMainObject::getFaults()
{
    FaultsType ret;
    Fault buf;
    QString str = "select dt,obj_num, dev_num from tek_faults order by dt;";
    QSqlQuery query ( str );
    db->isValid ( query );
    while (query.next())
    {
        buf.date = query.value(0).toDate() ;
        buf.id_obj = query.value(1).toInt() ;
        buf.id_dev = query.value(2).toInt() ;
        ret.push_back( buf );
    }
    return std::move( ret );
};

bool dbMainObject::Fault::operator==(const dbMainObject::Fault& left)
{
  return ( left.date == date ) && ( left.id_dev == id_dev ) && ( left.id_obj == id_obj );
};
