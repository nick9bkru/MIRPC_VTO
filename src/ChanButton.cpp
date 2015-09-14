#include "include/ChanButton.h"

ChanButton::ChanButton( QWidget *parent, int _id  ) : QPushButton (parent), id ( _id ),
    colr(GREY)
{
    setObjectName ( QString( "%1" ).arg( id ) );
    QPushButton::setText( QString( "%1" ).arg( id + 1 ) );
        menu = new QMenu ( this );
    menu->addAction ( QString::fromUtf8 ("Изменить название объекта" ) );
    connect( menu , SIGNAL(triggered(QAction*)), this, SLOT(slotChange(QAction*)));
    setFont( QFont ( "Ubuntu", 15) );
    setMaximumHeight( 100 );
};

ChanButton::~ChanButton()
{

}

int ChanButton::getId()
{
 return id; 
};

void ChanButton::mousePressEvent ( QMouseEvent * e ) 
{
  if ( e->buttons() & Qt::RightButton )
  {

    menu -> show();
    menu->move( QCursor::pos().x(), QCursor::pos().y() );
  } else 
    {
      QPushButton::mousePressEvent ( e );
    };
};

void ChanButton::slotChange(QAction*)
{
  qDebug( "ChanButton::slotChange(QAction*) id = %d", id );
  qDebug("%d", width( ) );
  SetNameDialog * dialog = new SetNameDialog ( this , text() ); 
  connect( dialog , SIGNAL(TextSig(QString)), this, SLOT(setText(QString)));
  if ( dialog->exec() )
  {
    qDebug( "dialog -- OK" );
  } else 
    {
    qDebug( "dialog -- Cansel" );
    }
  
  emit signalChange( id );
  
};

void ChanButton::setText (const QString &str)
{
  qDebug( "ChanButton::setText" );
  QPushButton::setText( str );
};

void ChanButton::setColor( CLR color , bool blink )
{
  //qDebug( "ChanButton::setText" );
    if ( ! blink )
    {
        colr = color;
    };
    QString clr;
    switch (color) {
    case GREEN:
           clr = "background-color: rgb(49,242,55);";
        break;
    case RED:
            clr = "background-color: rgb(242,0,0);";
        break;
    case GREY:
            clr = "background-color: rgb(240,240,240);";
        break;
    default:
        clr = "background-color: rgb(255,255,255);";
        break;
    }
  setStyleSheet( clr );

};

void ChanButton::setError( bool b )
{
    if ( !b )
    {
         setColor ( colr );
         blink = false;
    } else
    {
        blink = true;
    }

}

void ChanButton::slotBlink ( )
{
    if ( blink )
    {
        static CLR _color = colr;
        _color = (_color == colr)  ? RED  : colr ;
        setColor( _color , true);
    }
};
