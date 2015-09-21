#include "include/butparent.h"

ButParent::ButParent( QWidget *parent ): QPushButton (parent),color(GREY),
  err( false ), clck (false)
{
    setObjectName ( "Button" );
}

void ButParent::setError( bool b  )
{
    if ( !b )
    {
         setColor ( color );
    }
    err = b;
    clck = false;
};

bool ButParent::isErr () const
{
    return err;
};
bool ButParent::isClicked () const
{
    return clck;
};

ButParent::CLR ButParent::getColor () const
{
    return color;
};

void ButParent::setColor( CLR clr , bool err)
{
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
  setStyleSheet( sclr );
};


void ButParent::mousePressEvent ( QMouseEvent * e )
{
  if ( e->buttons() & Qt::LeftButton )
  {
    clck = true;
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


