#include "include/StandBut.h"
#include <QFont>
#include <QApplication>
#include <QDebug>
StandBut::StandBut( DeviceClass* _dev, QWidget * parent ): ButParent( parent ), dev( _dev )
{

    setFixedHeight( 60 );
    setFixedWidth( 83 );
    QFont f( QApplication::font( ) );
    f.setPointSize( 10 );
    setFont( f );
    updState();

    connect( dev, SIGNAL (changeState ( int16_t & )), this , SLOT ( updState() ) );
}

void StandBut::updState()
{
    //qDebug( ) << "void StandBut::updState() ";
//    qDebug( ) << "dev->getName() " << dev->getName();
//    qDebug( ) << "dev->getId() " << dev->getId();
    setText( dev->getName() );
};


bool StandBut::isBlink () const
{
    return dev->isAlarm(); // ::TODO delete
};
