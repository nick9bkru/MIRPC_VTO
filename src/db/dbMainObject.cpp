#include "include/db/dbMainObject.h"
#include "include/util/Singleton.h"

dbMainObject::dbMainObject (DBClass *_db) : db( _db)
{
};


dbMainObject::Obj dbMainObject::getObject ( int id )
{
    Obj ret;
    db->isOpened ();
    QSqlQuery query ( QString ( "select num, nazv,chng,reg,fault, missed_fault, active from objects where num = %1 and ( gr = 2 or gr = 1 ) order by num ; " ).arg( id ) );
    db->isValid ( query );
    ret.id = query.value(0).toInt();
    ret.name = query.value(1).toString();
    ret.chng = query.value(2).toInt();
    ret.reg = query.value( 3 ).toBool();
    ret.fault = query.value( 4 ).toBool();
    ret.lost_fault = query.value( 5 ).toBool();
    ret.active = query.value( 6 ).toInt();
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
   QSqlQuery query ( QString ( "select num ,nazv , chng, reg, fault, missed_fault, active from objects where ( gr = 2 or gr = 1 ) order by num ;" ));
    db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value(0).toInt();
        buf.name = query.value(1).toString();
        buf.chng = query.value(2).toInt();
        buf.reg = query.value( 3 ).toBool();
        buf.fault = query.value( 4 ).toBool();
        buf.lost_fault = query.value( 5 ).toBool();
        buf.active = query.value( 6 ).toInt();
        //buf.sost = SOST ( query.value(2).toInt() );
        //buf.err = query.value(3).toInt();
     //   qDebug() << " id = " << buf.id << " name = " << buf.name << " chng = " << buf.chng << " reg = " << buf.reg
   //                     << " buf.fault = " << buf.fault << " buf.lost_fault = " << buf.lost_fault;
        ret.push_back( buf );
    }
    query.exec( "update objects set chng = 0;" );
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

