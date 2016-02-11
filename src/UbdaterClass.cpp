#include "include/UbdaterClass.h"
#include "include/util/MyException.h"
#include "include/util/Singleton.h"
#include <QDebug>

UbdaterClass::UbdaterClass( DBClass* bd )
{
    qDebug(  ) <<  "Create UbdaterClass::UbdaterClass()" ;

    dbMainObject * dbMain = new dbMainObject ( bd );

    objUpd = new ObjectsUpdater( dbMain );
    Util::Singleton<ObjectsUpdater>::init(  objUpd ) ;
    faultUpd = new FaultsClass ( dbMain, objUpd );

    f = new dbFinder ( 2000 ); //  2 секунды
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SLOT(newStateConn( const bool & )) );
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SIGNAL( dbConnect ( const bool &)) );
   f->start();
}

UbdaterClass::~UbdaterClass()
{
    delete f;
    delete objUpd;
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
    try
    {
          faultUpd->update();
    }
    catch ( Util::MyException & e )
    {
           qDebug() << e.what();
    };

}

void UbdaterClass::newStateConn( const bool & b)
{
    if ( b )
    {
        objUpd->updateObj( true );
        faultUpd->update();
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
