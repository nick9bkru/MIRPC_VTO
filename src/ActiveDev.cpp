#include "include/ActiveDev.h"
#include "include/util/Singleton.h"

ActiveDev::ActiveDev(ObjectsUpdater * _objUpd): objUpd( _objUpd )
{
    db = new dbActive ( &Util::Singleton<DBClass>::getInstance() );
    list.clear();
}

ActiveDev::~ActiveDev()
{
 delete db;
}

void ActiveDev::update (  )
{
    ListActiveType buf = std::move ( db->getListActive() ) ;
    foreach ( auto it , buf) {
          auto it2 = qFind( std::begin (list), std::end( list ), it);
          if ( it2 == std::end( list ) )
          {
            //включаем
             objUpd->getObject( it.id_obj )->setActiveDev( it.id_dev, it.active ) ;
              qDebug() << "ActiveDev::update (  ) it.id_obj  ========" << it.id_obj << " = " <<  it.id_dev;
            //  objUpd->getObject( it.id_obj )->set);

          } else
          {
              list.erase( it2 );
          }
    }
    foreach ( auto it, list)
    {
        // выключаем
       objUpd->getObject( it.id_obj )->setActiveDev( it.id_dev, 0 ) ;
    }
    list.clear();
    list.swap( buf );
};
