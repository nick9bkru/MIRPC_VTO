#include "include/db/dbActive.h"

dbActive::dbActive(DBClass *_db): db( _db)
{

}


dbActive::ListActiveType dbActive::getListActive()
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

bool dbActive::ActiveType::operator==(const dbActive::ActiveType& left)
{
    return ( left.id_dev == id_dev ) &&
              ( left.id_obj == id_obj ) && ( active == active );
};
