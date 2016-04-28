#include "include/BSPurWid.h"
#include "include/ObjectsUpdater.h"
#include "include/util/Singleton.h"


BSPurWid::BSPurWid( QWidget *parent) :
    QWidget(parent)
{
    qDebug() << "BSPurWid::BSPurWid()";
     db = new dbDevices ( &Util::Singleton<DBClass>::getInstance() );
    BSPurLayout = new QVBoxLayout ( this );
    PurWid = new QWidget ( this);
    PurWid->setMinimumHeight( 100 );
    BSPurLayout->addWidget( PurWid );
    BSPurLayout->setSpacing( 0 );
    PurLayout = new QHBoxLayout ( PurWid );

    setLayout( BSPurLayout );
}

BSPurWid::~BSPurWid()
{
    qDebug() << "BSPurWid::~BSPurWid()";
     delete db;
    delete BSPurLayout;
    delete PurWid;

}

void BSPurWid::refreshWidjet( const int8_t &id, const QString &ip)
{
  obj =  Util::Singleton<ObjectsUpdater>::getInstance().getObject( 12 );
  if ( obj == NULL )
      return;
  this->id = id ;
  QPushButton *but = new QPushButton ( this );
  but->setMaximumHeight( 40 );
  but->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
  BSPurLayout->addWidget( but );
  but->setText( obj->getDevice( id)->getName()  );

  dbDevices::DevVect vec = std::move ( db->getPur( PUR, ip ) );
  addPurButton( &vec );
  vec = std::move ( db->getPur( PUS, ip ) );
  addPurButton( &vec );

};


void BSPurWid::getBSPUR()
{
    qDebug() << "BSPurWid::getBSPUR()";

    dbDevices::DevVect vec = std::move ( db->getDevices( id , BSPUR) );


};

void BSPurWid::addPurButton( const dbDevices::DevVect * vec )
{
    QPushButton *but;
    for ( auto & it : *vec )
    {
        QString name  ;
        for ( auto  it2 :  obj->getDevice( it.id )->getName() )
        {
              name += it2 + '\n';
        };
        name.truncate( name.size() - 1  );
        but = new QPushButton ( PurWid );
        but-> setMinimumHeight( PurWid->minimumHeight() );
        BSPurLayout->addWidget( but );

        but->setText( name  );
       PurLayout->addWidget( but );
    }

}
