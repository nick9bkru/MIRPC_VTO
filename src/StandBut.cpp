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
    if ( !dev->getConf() )
    {
      setEnabled( false );
      setBorder( false );
      setColor( GREY );
      return;
    } ;
    if ( dev->isAlarm() ) // если авария
    {
        if ( dev->isNewErr() ) // если новая
        {   setBorder( false );
            setColor( RED, true );
        } else // если старая
          {
            // красный бортик
            setColor( getColor(), true );
            setBorder( true );
          };
    } else
    {
        setColor( getColor(), true );

    };
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
