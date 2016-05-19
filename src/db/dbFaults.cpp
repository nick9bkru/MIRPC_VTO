#include "include/db/dbFaults.h"

dbFaults::dbFaults(DBClass *_db): db( _db)
{

}


dbFaults::FaultsType dbFaults::getFaults()
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

bool dbFaults::Fault::operator==(const dbFaults::Fault& left)
{
  return ( left.date == date ) &&
          ( left.id_dev == id_dev ) &&
            ( left.id_obj == id_obj ) &&
             ( left.newf == newf ) ;
};

dbFaults::LostFaultsType dbFaults::getLostFaults()
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

bool dbFaults::LostFault::operator==(const dbFaults::LostFault& left)
{
  return ( left.date == date ) &&
          ( left.id_dev == id_dev ) &&
            ( left.id_obj == id_obj );
};
