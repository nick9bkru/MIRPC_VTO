#include "include/dbclass.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlRecord>

DBClass::DBClass( )
{
    if ( !QSqlDatabase::database().isOpen() )
    {
         throw ( std::string ( "DBClass constructor not started ") ) ;
    }
}

DBClass::DBClass( QString _dbName, QString _host, QString _user, QString _pass ):
    dbName( _dbName ), host ( _host ), user( _user ), pass ( _pass )
{
    if ( !QSqlDatabase::database().isOpen() )
    {
         initDB ();
    }
    isOpened ();
}

DBClass::~DBClass()
{
};

void DBClass::initDB ()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName(  host );
    db.setDatabaseName(  dbName );
    db.setUserName( user );
    db.setPassword( pass );
    qDebug () << "DBClass::initDB () _dbName = "<< dbName << "  host = " << host << " ok = "<< db.open() ;
}


bool DBClass::nonSelectSql( QString sqlStr  )
{
    isOpened ();
    QSqlQuery query ( sqlStr );


    return query.exec();
}

bool DBClass::isOpened ()
{
    if ( !QSqlDatabase::database().isOpen() )
    {
        throw ( std::string ( "DBClass not opened DB ") ) ;
        return false ;
    }
    return true ;
}
