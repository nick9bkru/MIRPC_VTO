#include "include/StandBut.h"
#include <QFont>
#include <QApplication>
#include <QDebug>
StandBut::StandBut( DeviceClass* _dev, QWidget * parent ): ButParent( parent )
{
    dev = _dev;
    setFixedHeight( 60 );
    setFixedWidth( 83 );
    QFont f( QApplication::font( ) );
    f.setPointSize( 10 );
    setFont( f );
    updState();

    connect(  _dev , SIGNAL (changeState ( int16_t & )), this , SLOT ( updState() ) );
}

void StandBut::updState()
{
    qDebug( ) << "void StandBut::updState() ";
    setText( dev->getName() );
    if ( ! dev->isBlink() )
    {
        if ( !dev->isAlarm() && dev->isClicked() )
        {
            setColor( getColor() );
        } else
       if ( !dev->isAlarm() && dev->islostErr() )
            {
               setColor( RED, true );
            }
    }
};

void StandBut::reactClick()
{
    if ( dev->isAlarm()  )
    {
       setColor( RED, true );
    } else {
         setColor( getColor() );
    }

};
