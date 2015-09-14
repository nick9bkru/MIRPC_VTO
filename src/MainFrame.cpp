#include "include/MainFrame.h"
#include "include/util/Singleton.h"

MainFrame::MainFrame( QWidget *parent ): QFrame(parent), Ui::mainFrame()
{
  qDebug( "MainFrame::MainFrame" );
  setupUi(this);
  
  db = &Util::Singleton<DbObjectClass>::getInstance();

 // setFrameStyle(QFrame::Box | QFrame:: Raised);
  stateChan = new StateChanFrame( StateChanWidget );
  ChanButSig = new QSignalMapper ( this );
  timerBlink = new QTimer ( this );
  timerBlink->start( 1000 );
   connect( ChanButSig, SIGNAL(mapped( const int & )),
             this, SLOT( ChanButClicked( const int & )));
  connect( ChanButSig, SIGNAL(mapped( const int & )),
             stateChan, SLOT( changeDirection( const int & )));
//   
  createChBut();

}

MainFrame::~MainFrame()
{
    for( auto &it : ChanBut )
    {
     delete it;
    };
}

/////////////////////////////////////////////////////
void MainFrame::createChBut()
{
  const int row = 3;
  int num = 0;
  int i, j;
  Obj = std::move ( db->getObject() );


  for ( auto &it : Obj)
  {
    j = num % row;
    i = num / row;
    qDebug() << "id = " << it.id << " Name == " <<(it).name << " err == " << it.err ;
    ChanButton * b = new ChanButton (  this, num );
    setButState ( b,  &it);
    ChanBut.push_back( b );
    gridChannel->addWidget( b , i, j);
    ChanButSig->setMapping(  b , b ->getId() );
    connect( ChanBut [ num ] , SIGNAL( clicked() ), ChanButSig, SLOT(map()));
    connect( timerBlink,  SIGNAL(	timeout () ), b , SLOT (slotBlink () ) ) ;

    num++;
  };

};
/////////////////////////////////////////////////////
void MainFrame::ChanButClicked( const int & id)
{
  qDebug( "MainFrame::ChanButClicked %d", id );
  
};

/////////////////////////////////////////////////////
void MainFrame::setButState(ChanButton * b, const DbObjectClass::Obj *obj)
{
  b->setText( obj->name );
  b->setColor( ChanButton::GREY );
  b->setError( obj->err == ChanButton::ERR );
  if ( obj->err == ChanButton::ERR  )
  {
    stateChan->changeDirection( b->getId() );
  };
};
/////////////////////////////////////////////////////
void MainFrame::updateState( )
{
    //qDebug( "MainFrame::updateState");
    DbObjectClass::VecObj _obj = std::move ( db->getObject() );
    auto itOld = std::begin ( Obj );
    auto itnew = std::begin ( _obj ) ;
    auto itBut = std::begin ( ChanBut ) ;
    for ( ; itnew != std::end( _obj ); itnew++, itOld++, itBut++)
    {
        if ( (*itnew) != (*itOld) )
        {
            setButState ( (*itBut) ,  &(*itnew));
            (*itOld) = (*itnew) ;
        }
    }
};

