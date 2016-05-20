#include "include/OtherDevWid.h"
#include "include/buttom/OtherDevBut.h"
#include "include/ObjectsUpdater.h"
#include "include/util/Singleton.h"

OtherDevWid::OtherDevWid(dbDevices* _db, int8_t _id , GROUP _gr,  QWidget *parent ) :
    QWidget(parent), db( _db ), id ( _id ), gr( _gr )
{
     butLayout = new QVBoxLayout( this );
    obj =  Util::Singleton<ObjectsUpdater>::getInstance().getObject( id );
//    qDebug() << "!!!!!!!!!!!!!!!!!!! parent->width() == " << width() << " parent->height() == " << height();
    refreshBut();
}

OtherDevWid::~OtherDevWid()
{
    qDebug( ) << "OtherDevWid::~OtherDevWid()" ;
    deleteBut();
    delete butLayout;
}

void OtherDevWid::refreshBut()
{
    deleteBut();
    dbDevices::DevVect vec = std::move ( db->getDevices( id, gr ) );

    for ( auto & it : vec )
    {
        OtherDevBut *bs = new OtherDevBut ( obj->getDevice( it.id ), this );
        butLayout->addWidget( bs );
    }

}

void OtherDevWid::deleteBut()
{
    while (QLayoutItem* item = butLayout->takeAt(0))
        {
           // qDebug( ) << item ;
            delete item->widget();
            delete item;
        }
}
