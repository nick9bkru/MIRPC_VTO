#include "include/UbdaterClass.h"
#include "include/util/MyException.h"
#include "include/util/Singleton.h"
#include <QDebug>

UbdaterClass::UbdaterClass()
{
    qDebug(  ) <<  "Create UbdaterClass::UbdaterClass()" ;

    objUpd = &Util::Singleton<ObjectsUpdater>::getInstance();
    f = new dbFinder ( 2000 ); //  2 секунды
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SLOT(newStateConn( const bool & )) );
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SIGNAL( dbConnect ( const bool &)) );
   f->start();
}

UbdaterClass::~UbdaterClass()
{
    delete f;
}

void UbdaterClass::devNotify(  const QString & name  )
{
    qDebug( ) << "Notify == "<< name ;
    try
    {
      objUpd->updateDev( );
    }
    catch ( Util::MyException & e )
    {
        qDebug() << e.what();
    };
};

void UbdaterClass::objNotify(  const QString & name  )
{
    qDebug( ) << "Notify == "<< name ;
    try
    {
        objUpd->updateObj();
    }
    catch ( Util::MyException & e )
    {
        qDebug() << e.what();
    };
};

void UbdaterClass::faultNotify(const QString & name )
{
    qDebug( ) << "Notify == "<< name ;
}

void UbdaterClass::newStateConn( const bool & b)
{
    if ( b )
    {
        objUpd->updateObj( true );
        loadNotify();
    }
} ;

void UbdaterClass::loadNotify()
{
    qDebug() << "ObjectsUpdater::loadNotify()" ;
    DBClass::createNotify( tbl [DEVICES] , this, SLOT(devNotify(const QString & )) );
   DBClass::createNotify( tbl [OBJECTS] , this, SLOT(objNotify(const QString & )) );
    DBClass::createNotify( tbl [FAULTS] , this, SLOT(faultNotify(const QString & )) );
};
