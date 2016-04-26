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

dbMainObject::VecObjDev dbMainObject::getDev (int id)
{
    db->isOpened ();
    VecObjDev ret;
    ObjDev buf;
    QString str = std::move( QString("SELECT num, nazv, konf, frag FROM devices WHERE kod_obj = %1 order by num;" ).arg( id ) );

    QSqlQuery query ( str );

     db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value( 0 ).toInt();
        buf.name = query.value( 1 ).toString();
        buf.conf = query.value( 2 ).toBool();
        buf.frag = query.value( 3 ).toBool();
        qDebug() << " id = " << buf.id << " name = " << buf.name << " conf = " << buf.conf <<" frag = " << buf.frag ;
        ret.push_back( buf );
    }

    return std::move( ret );
};

 bool dbMainObject::ObjDev::operator==(const  dbMainObject::ObjDev& left)
 {
     return ( left.id == id ) &&
              ( left.frag == frag ) &&
               ( left.conf == conf ) &&
                ( left.name == name ) ;
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
    QString str = "select dt,obj_num, dev_num, newf from tek_faults order by dt;";
    QSqlQuery query ( str );
    db->isValid ( query );
    while (query.next())
    {
        buf.date = query.value(0).toDate() ;
        buf.id_obj = query.value(1).toInt() ;
        buf.id_dev = query.value(2).toInt() ;
        buf.newf = query.value(3).toBool();
        ret.push_back( buf );
    }
    return std::move( ret );
};

bool dbMainObject::Fault::operator==(const dbMainObject::Fault& left)
{
  return ( left.date == date ) &&
          ( left.id_dev == id_dev ) &&
            ( left.id_obj == id_obj ) &&
             ( left.newf == newf ) ;
};

dbMainObject::LostFaultsType dbMainObject::getLostFaults()
{
    LostFaultsType ret;
    LostFault buf;
    QString str = " select obj_num,dev_num from missed_tek_faults where dt_oper is null;";
    QSqlQuery query ( str );
    db->isValid ( query );
    while (query.next())
    {
        buf.id_obj = query.value(0).toInt() ;
        buf.id_dev = query.value(1).toInt() ;
        ret.push_back( buf );
    }
    return std::move( ret );
};

bool dbMainObject::LostFault::operator==(const dbMainObject::LostFault& left)
{
  return ( left.date == date ) &&
          ( left.id_dev == id_dev ) &&
            ( left.id_obj == id_obj );
};

dbMainObject::ListActiveType dbMainObject::getListActive()
{
    ListActiveType ret;
    ActiveType buf;
    QString str = " select obj_num, pu_num, pu_regim from act_pu ;";
    QSqlQuery query ( str );
    db->isValid ( query );
    while (query.next())
    {
        buf.id_obj = query.value(0).toInt() ;
        buf.id_dev = query.value(1).toInt() ;
        buf.active = (query.value(2).toString() == "в соединении" ) + 1 ;
        ret.push_back( buf );
    }
    return ret;
};

bool dbMainObject::ActiveType::operator==(const dbMainObject::ActiveType& left)
{
    return ( left.id_dev == id_dev ) &&
              ( left.id_obj == id_obj ) && ( active == active );
};
