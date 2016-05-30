#include "include/UbdaterClass.h"
#include "include/util/MyException.h"
#include "include/util/Singleton.h"
#include <QDebug>

UbdaterClass::UbdaterClass(  )
{
    qDebug(  ) <<  "Create UbdaterClass::UbdaterClass()" ;

   // dbMainObject * dbMain = new dbMainObject ( bd );

    objUpd = new ObjectsUpdater( );
    Util::Singleton<ObjectsUpdater>::init(  objUpd ) ;
    faultUpd = new FaultsClass ( objUpd );
    activedev = new ActiveDev ( objUpd  );

    f = new dbFinder ( 2000 ); //  2 секунды
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SLOT(newStateConn( const bool & )) );
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SIGNAL( dbConnect ( const bool &)) );
   f->start();
}

UbdaterClass::~UbdaterClass()
{
    delete f;
    delete objUpd;
    delete faultUpd;
    delete activedev;
}

void UbdaterClass::devNotify(  const QString & name  )
{
    qDebug( ) << "1 Notify == "<< name ;
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
    qDebug( ) << "2 Notify == "<< name ;
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
    qDebug( ) << "3 Notify == "<< name ;
    try
    {
          faultUpd->update();
    }
    catch ( Util::MyException & e )
    {
           qDebug() << e.what();
    };

}

void UbdaterClass::Notify(const QString & name )
{
    qDebug( ) << "4 Notify == "<< name ;
    try
    {
        if ( name == tbl [FAULTS])
        {
           faultUpd->update();
        } else
        if ( name == tbl [OBJECTS])
        {
           objUpd->updateObj();
        }else
        if ( name == tbl [DEVICES])
        {
           objUpd->updateDev( );
        } else
        if ( name == tbl [LOSTFAULTS])
        {
           faultUpd->updateLostFaults();
        } else
        if ( name == tbl [ACTPU])
        {
           activedev->update();
        }  else
        if ( name == tbl [SOUND])
        {
           emit ChangeSound ();
        } ;

    }
    catch ( Util::MyException & e )
    {
           qDebug() << e.what();
    };
}

void UbdaterClass::newStateConn( const bool & b)
{
    qDebug() << "UbdaterClass::newStateConn(" ;
   try
   {
    if ( b )
    {
        objUpd->updateObj( true );
        faultUpd->update();
        faultUpd->updateLostFaults();
        activedev->update();
        loadNotify();
    }
   }
   catch ( Util::MyException & e )
   {
           qDebug() << e.what();
   };

} ;

void UbdaterClass::loadNotify()
{
    qDebug() << "UbdaterClass::loadNotify()" ;
    /*
     TODO FIX : почему то при вызове нотифая , вызывается последний подключенный слот
    DBClass::createNotify( tbl [DEVICES] , this, SLOT( devNotify(const QString & )) );
    DBClass::createNotify( tbl [OBJECTS] , this, SLOT( objNotify(const QString & )) );
    DBClass::createNotify( tbl [FAULTS] , this, SLOT( faultNotify(const QString & )) );
*/
    DBClass::createNotify( tbl [DEVICES] , this, SLOT( Notify(const QString & )) );
    DBClass::createNotify( tbl [OBJECTS] , this, SLOT( Notify(const QString & )) );
    DBClass::createNotify( tbl [FAULTS] , this, SLOT( Notify(const QString & )) );
    DBClass::createNotify( tbl [LOSTFAULTS] , this, SLOT( Notify(const QString & )) );
    DBClass::createNotify( tbl [ACTPU] , this, SLOT( Notify(const QString & )) );
    DBClass::createNotify( tbl [SOUND] , this, SLOT( Notify(const QString & )) );
};
