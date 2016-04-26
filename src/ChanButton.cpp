#include "include/ChanButton.h"
#include <QDebug>
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"
#include "include/util/MyException.h"
ChanButton::ChanButton( QWidget *parent, int _id  ) : ButParent (parent), id ( _id )
{

    qDebug() << "ChanButton::ChanButton id == " <<  id  ;
    dev = Util::Singleton<ObjectsUpdater>::getInstance().getObject( id + 1) ;
    if ( dev == NULL )
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


    connect ( (ObjectClass* )dev, SIGNAL ( changeState ( int16_t ) ), this, SLOT( refresh() ) );
    refresh();
    qDebug () << "Create but name == " << dev->getName() << " id == " << dev->getId() ;
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
    qDebug()<< "ChanButton::refresh " << dev->getName();
  if ( dev->getConf() )
  {
      setText( dev->getName() );
  } else
  {

      setText( "" );
  };
  setEnabled( dev->getConf() );

  if ( dev->isAlarm() ) // если авария
  {
        setBorder( false );
        setColor( RED, true );

  } else
  {
      if ( dev->islostAlarm() )
      {
          setColor( YELLOW, true );
      } else
      if ( dev->isReg() )
      {
          setColor( BLUE, true );
      } else
      if ( dev->isActive() != baseDevice::NOACTIVE )
      {
          setColor( GREEN , true );
      } else
      {
          setColor( getColor(), true );
      };
  }
}

void ChanButton::reactClick()
{
    if ( dev->isAlarm()  )
    {
       setColor( RED, true );
    } else {
         setColor( getColor() );
    }
};
