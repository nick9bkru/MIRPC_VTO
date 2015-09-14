#include "include/DeviceBut.h"

DeviceBut::DeviceBut( QWidget * parent ): QPushButton(parent)
{
  setMinimumHeight( 70 );
  setMinimumWidth( 70 );
};

void DeviceBut::setColor( CLR color )
{
 // qDebug( "ChanButton::setText" );
    QString clr;
    switch (color) {
    case GREEN:
           clr = "background-color: rgb(49,242,55);";
        break;
    case RED:
            clr = "background-color: rgb(242,0,0);";
        break;
    case GEY:
            clr = "background-color: rgb(240,240,240);";
        break;
    default:
        clr = "background-color: rgb(255,255,255);";
        break;
    }
  setStyleSheet( clr );
};

void DeviceBut::setText (const QString &str)
{
  qDebug( "DeviceBut::setText" );
  qDebug("%d", height () );
  QPushButton::setText( str );
};
