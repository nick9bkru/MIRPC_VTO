#include "include/ObjectsUpdater.h"
#include "include/util/MyException.h"
#include "include/db/dbFinder.h"
#include <QDebug>

ObjectsUpdater::ObjectsUpdater(): dbCon ( false )
{
    qDebug(  ) <<  "Create ObjectsUpdater::ObjectsUpdater()" ;
    dbObj = new dbMainObject;

    dbObj->getFaults();
    for ( int i = 1; i < 23; i++ ) // первый это состояние объекта руководителя , остальные 21
    {
        Objects.push_back( new ObjectClass ("", i) );
    };

    dbFinder * f = new dbFinder ( 2000 ); //  2 секунды
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SLOT(newStateConn( const bool & )) );
    connect( f, SIGNAL( dbConnect( const bool & ) ), this, SIGNAL( dbConnect ( const bool &)) );
    f->start();

   //qDebug() << QSqlDatabase::database().driver()->subscribedToNotifications();
}

ObjectsUpdater::~ObjectsUpdater()
{
    for ( auto &it : Objects)
    {
        delete it;
    }
};

void ObjectsUpdater::loadNotify()
{
    qDebug() << "ObjectsUpdater::loadNotify()" ;
    DBClass::createNotify( tbl [DEVICES] , this, SLOT(devNotify(const QString & )) );
   DBClass::createNotify( tbl [OBJECTS] , this, SLOT(objNotify(const QString & )) );
    DBClass::createNotify( tbl [FAULTS] , this, SLOT(faultNotify(const QString & )) );
};

void ObjectsUpdater::devNotify(  const QString & name  )
{
    qDebug( ) << "Notify == "<< name ;
    dbMainObject::chngType num = std::move ( dbObj->getChange() );
    try
    {
      for ( auto &it : num )
        {
            updateObjDev( Objects[ it - 1  ] );
        }
    }
    catch ( Util::MyException & e )
    {
        qDebug() << e.what();
    };
};

void ObjectsUpdater::objNotify(  const QString & name  )
{
    qDebug( ) << "Notify == "<< name ;
    try
    {
        updateObj();
    }
    catch ( Util::MyException & e )
    {
        qDebug() << e.what();
    };
};

void ObjectsUpdater::faultNotify(const QString & name )
{
    qDebug( ) << "Notify == "<< name ;
}

void ObjectsUpdater::updateAll()
{
    try
    {
        updateObj( true );
    }
    catch ( Util::MyException & e )
    {
        qDebug() << e.what();
    };
};

void ObjectsUpdater::updateObj( const bool first )
{
    qDebug(  ) <<  "void ObjectsUpdater::updateObj();" ;
   dbMainObject::VecObj obj = std::move ( dbObj->getObject() );
   auto itObj = std::begin ( obj );
   for ( auto &it : Objects)
   {

      if ( (itObj != obj.end()) &&  (it->getId() == itObj->id ) )
      {
        it->setConf( true );
        it->setName ( itObj-> name  );
        if ( itObj-> chng || first )
        {
            updateObjDev ( it );
        }
         itObj++;
      }else
      {
          it->setConf( false );
      };
   };
};

void ObjectsUpdater::updateObjDev(ObjectClass *obj )
{
  dbMainObject::VecObjDev dev = std::move ( dbObj->getDev( obj->getId() ) ) ;
  ObjectClass::DevisesType * vecDev = obj->getDevices() ;
  qDebug () << "ObjectsUpdater::updateObjDev() ID = " << obj->getId() << " name == " << obj->getName() ;
  if ( int( dev.size()) < vecDev->size() )
  {
    obj->removeDevices();
  };
  for ( auto & it : dev)
  {
        auto devIt = vecDev->find( it.id );
        if ( devIt != vecDev->end() )
        {
         /// UPDATE DEVICE
         //прописываем имя в класс и если еще что то надо в будущем !
         devIt.value()->setName( it.name );
         /////
        } else
        {
            DeviceClass* _dev = new DeviceClass ( it.name  , it.id );
            obj->setDevice( _dev->getId() ,  _dev );
        };
//        qDebug () << " ID == " << it.id << " name == "<< it.name ;
  };
 obj->emitRefresh();

};

ObjectClass* ObjectsUpdater::getObject ( int16_t id)
{
  for ( auto &it : Objects )
  {
   if ( it->getId() == id )
       return it;
  }
  qDebug(  ) <<  "ObjectsUpdater::getObject Not find object whith id == " << id  ;
  return NULL;
};

void ObjectsUpdater::newStateConn( const bool & b)
{
    if ( b )
    {        
        updateAll();
        loadNotify();
    }
} ;
