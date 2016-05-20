#include "include/buttom/butparent.h"

#include <QDebug>

#include <QFontMetrics>

ButParent::ButParent( QWidget *parent ): QPushButton (parent), lbl(new QLabel ( parent )) ,color(DEFAULT), dev ( NULL )
{
   setObjectName ( "Button" );
   lbl->setAlignment(Qt::AlignCenter);
   lbl->setWordWrap( true );
       setFixedHeight(lbl->height()*1.8);

       layout = new QVBoxLayout(this);
       layout->setSpacing(0);
       layout->setContentsMargins(4,4,4,4);
       layout->addWidget(lbl,0,Qt::AlignCenter);

       setLayout(layout);
       defColor = styleSheet();
      // connect( this, SIGNAL ( clicked() ) , this , SLOT ( clickSlot ()) );
}
ButParent::~ButParent()
{

    delete layout;
    delete lbl;
};

bool ButParent::isBlink () const
{
    return dev->isBlink() ;
};

ButParent::CLR ButParent::getColor () const
{
    return color;
};



void ButParent::setColor( CLR clr , bool err)
{
   // qDebug(  ) << style() ;
    if ( !err )
        color = clr ;
 // qDebug( "ChanButton::setText" );
  setStyleSheet( getColotStr( clr ) );
};

void ButParent::setSecondColor( CLR clr )
{
  secColor =  clr ;
};

ButParent::CLR ButParent::getSecondColor(  ) const
{
  return  secColor ;
};

QString ButParent::getColotStr( CLR clr )
{
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
    case WHITE:
            sclr = "background-color: rgb(255,255,255);";
        break;
    case YELLOW:
            sclr = "background-color: rgb(255,255,0);";
        break;
    case BLUE:
            sclr = "background-color: rgb(12,155,255);";
        break;
    case DEFAULT:
            sclr = defColor;
        break;
    default:
        sclr = "background-color: rgb(255,255,255);";
        break;
    }
    return sclr;
};

void ButParent::mousePressEvent ( QMouseEvent * e )
{
  if ( e->buttons() & Qt::LeftButton )
  {
      //setBlink ( false );
  //  if ( isErr ( ) )
    // setColor( RED , true );

  }
      QPushButton::mousePressEvent ( e );

};

void ButParent::setText (const QString &str)
{
        lbl->setText( str );
};

void ButParent::setFont(const QFont &f)
{
  lbl->setFont (f );
};

QString ButParent::text () const
{
  return lbl->text();
}

void ButParent::clickSlot()
{
 //   qDebug() << "void ButParent::clickSlot()" ;
    if ( dev )
    {
        dev->setClicked( true );
        reactClick();
    };
};

void ButParent::reactClick()
{
    if ( dev->isAlarm() )
    {
       setColor( RED, true );
    }
};

void ButParent::setBorder( const bool &b )
{
    QString str;
    if ( b )
    {
        str = "QPushButton {border: 4px solid red;}";
    } else
    {
        str = "QPushButton {border: 2px solid #6593cf;border-color: navy}";
    };
    setStyleSheet( str );
};


