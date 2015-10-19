#include "include/butparent.h"
#include <QDebug>
ButParent::ButParent( QWidget *parent ): QPushButton (parent),color(GREY),
  err( false ), blink (true)
{
   setObjectName ( "Button" );

}

void ButParent::setError( bool b  )
{
    if ( !b )
    {
         setColor ( color );
    } else
        {
           setColor ( RED, true);
        };
    err = b;
    setBlink ( true );
};

bool ButParent::isErr () const
{
    return err;
};
bool ButParent::isBlink () const
{
    return blink;
};

ButParent::CLR ButParent::getColor () const
{
    return color;
};

void ButParent::setBlink ( bool on )
{
  blink = on ;
};

void ButParent::setColor( CLR clr , bool err)
{
   // qDebug(  ) << style() ;
    if ( !err )
        color = clr ;
 // qDebug( "ChanButton::setText" );
    QString sclr;
    switch (clr) {
    case GREEN:
           sclr = "background-color: rgb(49,242,55);";
        break;
    case RED:
            sclr = "background-color: rgb(242,0,0);";
        break;
    case GREY:
            sclr = "background-color: rgb(240,240,240);";
        break;
    default:
        sclr = "background-color: rgb(255,255,255);";
        break;
    }
  //setStyleSheet( sclr );
};


void ButParent::mousePressEvent ( QMouseEvent * e )
{
  if ( e->buttons() & Qt::LeftButton )
  {
      setBlink ( false );
    if ( isErr ( ) )
     setColor( RED , true );

  }
      QPushButton::mousePressEvent ( e );

};

void ButParent::setText (const QString &str)
{
  //qDebug( "ButParent::setText" );
  QPushButton::setText( str );
};

