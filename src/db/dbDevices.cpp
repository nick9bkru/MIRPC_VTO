#include "include/db/dbDevices.h"

dbDevices::dbDevices(DBClass *_db): db( _db)
{
}

dbDevices::VecObjDev dbDevices::getDev (int id)
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

 bool dbDevices::ObjDev::operator==(const  dbDevices::ObjDev& left)
 {
     return ( left.id == id ) &&
              ( left.frag == frag ) &&
               ( left.conf == conf ) &&
                ( left.name == name ) ;
 };

dbDevices::DevVect dbDevices::getDevices( int8_t id, int8_t gr)
{
    db->isOpened ();
    DevVect ret;
    Device buf;
    QString str = std::move( QString("SELECT num, adr FROM devices WHERE kod_obj = %1 and gr = %2 order by num;" ).arg( id ).arg( gr ) );

    QSqlQuery query ( str );

     db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value( 0 ).toInt();
        buf.ip = query.value( 1 ).toString();
       // qDebug() << " id = " << buf.id << " ip = " << buf.ip ;
        ret.push_back( buf );
    }

    return std::move( ret );
};

dbDevices::DevVect dbDevices::getPur (const int8_t &gr, const QString &ip)
{
    db->isOpened ();
    DevVect ret;
    Device buf;
    QString str = std::move( QString("select num, adr from devices where  adr LIKE '%1;%' and gr = %2 order by num;" ).arg(ip).arg(gr) );
    qDebug() << str;
    QSqlQuery query ( str );

     db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value( 0 ).toInt();
        buf.ip = query.value( 1 ).toString();
       // qDebug() << " id = " << buf.id << " ip = " << buf.ip ;
        ret.push_back( buf );
    }

    return std::move( ret );
};
