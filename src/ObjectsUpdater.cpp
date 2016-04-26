#include "include/ObjectsUpdater.h"
#include "include/util/MyException.h"

#include <QDebug>
ObjectsUpdater::ObjectsUpdater()
{
 throw Util::MyException(  "ObjectsUpdater::ObjectsUpdater() ERROR !!!!! " ) ;
}

ObjectsUpdater::ObjectsUpdater(dbMainObject *_dbObj): dbObj ( _dbObj ) , dbCon ( false )
{
    qDebug(  ) <<  "Create ObjectsUpdater::ObjectsUpdater()" ;
//    dbObj = new dbMainObject;
    for ( int i = 1; i < 23; i++ ) // первый это состояние объекта руководителя , остальные 21
    {
        Objects.push_back( new ObjectClass ("", i) );
    };

       //qDebug() << QSqlDatabase::database().driver()->subscribedToNotifications();
}

ObjectsUpdater::~ObjectsUpdater()
{
    for ( auto &it : Objects)
    {
        delete it;
    }
    delete dbObj;
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
       //////////////////////
        it->setConf( true );
        it->setName ( itObj-> name  );
        it->setReg ( itObj-> reg );
        it->setAlarm ( itObj-> fault );
        it->setlostAlarm ( itObj-> lost_fault );
        it->setActive ( itObj-> active );
       /////////////////////////////
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
         devIt.value()->setConf( it.conf );
         devIt.value()->setReg ( it.conf && it.frag );
         /////
        } else
        {
            DeviceClass* _dev = new DeviceClass ( it.name  , it.id, it.conf );
            obj->setDevice( _dev->getId() ,  _dev );
            /// UPDATE DEVICE
            //прописываем имя в класс и если еще что то надо в будущем !
            _dev->setName( it.name );
            _dev->setConf( it.conf );
            _dev->setReg ( it.conf && it.frag );
        };
//        qDebug () << " ID == " << it.id << " name == "<< it.name ;
  };
 obj->emitRefresh();

};

ObjectClass* ObjectsUpdater::getObject ( int16_t id) const
{
  for ( auto &it : Objects )
  {
   if ( it->getId() == id )
       return it;
  }
  qDebug(  ) <<  "ObjectsUpdater::getObject Not find object whith id == " << id  ;
  return NULL;
};


void ObjectsUpdater::updateDev( )
{
    qDebug() << "ObjectsUpdater::updateDev( )";
    dbMainObject::chngType num = std::move ( dbObj->getChange() );
    for ( auto &it : num )
      {
          updateObjDev( Objects[ it - 1  ] );
      }
};
