#include "include/FaultsClass.h"
#include "include/util/Singleton.h"

FaultsClass::FaultsClass(ObjectsUpdater * _objUpd ) :
    objUpd( _objUpd )
{
    db = new dbFaults ( &Util::Singleton<DBClass>::getInstance() );
 fault.clear();
 lostFault.clear();
}

FaultsClass::~FaultsClass( )
{
   delete db;
}

void FaultsClass::update (  )
{
    FaultsType buf = std::move ( db->getFaults() ) ;
    foreach ( auto it , buf) {
          auto it2 = qFind( std::begin (fault), std::end( fault ), it);
          if ( it2 == std::end( fault ) )
          {
            //включаем аварию на кнопке
              objUpd->getObject( it.id_obj )->setAlarmDev( it.id_dev, true , it.newf ) ;
              qDebug() << "  it.id_obj  ========" << it.id_obj << " = " <<  it.id_dev;
            //  objUpd->getObject( it.id_obj )->set);

          } else
          {
              fault.erase( it2 );
          }
    }
    foreach ( auto it, fault)
    {
        //выключаем аварию на кнопке
        objUpd->getObject( it.id_obj )->setAlarmDev( it.id_dev, false ) ;
    }
    fault.clear();
    fault.swap( buf );
};

void FaultsClass::updateLostFaults()
{
    qDebug() << " FaultsClass::updateLostFaults() " ;
    LostFaultsType buf = std::move ( db->getLostFaults() ) ;
    foreach ( auto it , buf) {
          auto it2 = qFind( std::begin ( lostFault ), std::end( lostFault ), it);
          if ( it2 == std::end( lostFault ) )
          {
            //включаем аварию на кнопке
             objUpd->getObject( it.id_obj )->setLostAlarmDev( it.id_dev, true ) ;
              qDebug() << "  it.id_obj  ========" << it.id_obj << " = " <<  it.id_dev;

          } else
          {
              lostFault.erase( it2 );
          }
    }
    foreach ( auto it, lostFault)
    {
        //выключаем аварию на кнопке
        objUpd->getObject( it.id_obj )->setLostAlarmDev( it.id_dev, false ) ;
    }
    lostFault.clear();
    lostFault.swap( buf );
};
