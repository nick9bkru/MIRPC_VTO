#include "include/BSPurWid.h"
#include "include/ObjectsUpdater.h"
#include "include/util/Singleton.h"
#include "include/PurBut.h"
#include "include/BSPurBut.h"

BSPurWid::BSPurWid(  dbDevices* _db,  QWidget *parent) : db( _db ) ,
    QWidget(parent)
{
    qDebug() << "BSPurWid::BSPurWid()";
    setObjectName ( "BSPurWid" );
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
    deleteBut();

    delete PurLayout;
    delete PurWid;
    delete BSPurLayout;
}

void BSPurWid::refreshWidjet( const int8_t &id_obj, const int8_t &id, const QString &ip)
{
  deleteBut();
  qDebug() << "BSPurWid::refreshWidjet()";
  obj =  Util::Singleton<ObjectsUpdater>::getInstance().getObject( id_obj );
  if ( obj == NULL )
      return;
  this->id = id ;
  QPushButton *but = new BSPurBut ( obj->getDevice( id ), this ); // кнопка БС-ПУРа

  BSPurLayout->addWidget( but );

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
        but = new PurBut ( obj->getDevice( it.id ), PurWid );// кнопка ПУРа, ПУСа
        BSPurLayout->addWidget( but );

       PurLayout->addWidget( but );
    }

}

void BSPurWid::deleteBut()
{
    while (QLayoutItem* item = PurLayout->takeAt(0))
    {
            delete item->widget();
            delete item;
    }
    while (QLayoutItem* item = BSPurLayout->takeAt(1))
    {
               delete item->widget();
            delete item;
    }
}
