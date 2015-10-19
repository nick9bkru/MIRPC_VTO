#include "include/ChanButton.h"
#include <QDebug>
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"
#include "include/util/MyException.h"
ChanButton::ChanButton( QWidget *parent, int _id  ) : ButParent (parent), id ( _id )
{

    obj = Util::Singleton<ObjectsUpdater>::getInstance().getObject( id + 1) ;
    if ( obj == NULL )
    {
        qDebug() << "ChanButton::ChanButton don't find object whith id == " <<  id  ;
        throw Util::MyException( "ChanButton::ChanButton don't find object" );
    }
   // setObjectName ( QString( "%1" ).arg( id ) );
  //  qDebug () << objectName();
    ButParent::setText( QString( "%1" ).arg( id + 1 ) );
        menu = new QMenu ( this );
    menu->addAction ( QString::fromUtf8 ("Изменить название объекта" ) );
    connect( menu , SIGNAL(triggered(QAction*)), this, SLOT(slotChange(QAction*)));
    ButParent::setFont( QFont ( "Ubuntu", 12) );
    setMaximumHeight( 100 );
    setMaximumWidth( 120 );


    connect ( obj, SIGNAL ( change ( int16_t ) ), this, SLOT( refresh() ) );
    refresh();
    qDebug () << "Create but name == " << obj->getName() << " id == " << obj->getId() ;
};

ChanButton::~ChanButton()
{
    delete menu ;
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

void ChanButton::refresh()
{
    qDebug()<< "ChanButton::refresh " << obj->getName();

  if ( obj->getConf() )
  {
      setText( obj->getName() );
  } else
  {

      setText( "" );
  };
  setEnabled( obj->getConf() );
}
