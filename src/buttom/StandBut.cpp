#include "include/buttom/StandBut.h"
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
    qDebug( ) << "void StandBut::updState() " << dev->getName();
    setText( dev->getName() );
    dev->setBlink( false );
    setColor( DEFAULT );
    if ( !dev->getConf() )
    {
      setBorder( false );
      setColor( WHITE );
      return;
    } ;
    if ( dev->isActive() != baseDevice::NOACTIVE )
    {
        if ( dev->isActive() == baseDevice::CONNECT )
        {
            setSecondColor( GREEN );
            dev->setBlink( true );

        } else
        {
            setColor( GREEN );
        }
    }

    if ( dev->isAlarm() ) // если авария
    {
        if ( dev->isNewErr() ) // если новая
        {   setBorder( false );
            setColor( RED );
        } else // если старая
          {
            // красный бортик
            setColor( getColor() );
            setBorder( true );
          };
    } else
    {
      //  setColor( getColor(), true );

        setBorder( false );
        if ( dev->islostAlarm() )
        {
            setColor( YELLOW );
        } else
        if ( dev->isReg() )
        {
            setColor( BLUE);
        } ;

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
