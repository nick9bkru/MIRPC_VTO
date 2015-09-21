#include "include/ChanButton.h"
#include <QDebug>

ChanButton::ChanButton( QWidget *parent, int _id  ) : ButParent (parent), id ( _id )
{
   // setObjectName ( QString( "%1" ).arg( id ) );
    qDebug () << objectName();
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
      ButParent::mousePressEvent ( e );
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

