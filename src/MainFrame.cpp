#include "include/MainFrame.h"
#include "include/ClockFrame.h"
#include "include/util/Singleton.h"

MainFrame::MainFrame( QWidget *parent ): QFrame(parent), Ui::mainFrame()
{
  qDebug( "MainFrame::MainFrame" );
  setupUi(this);
  

  db = new dbMainObject();

 // setFrameStyle(QFrame::Box | QFrame:: Raised);
  stateChan = new StateChanFrame( StateChanWidget );

  connect( stateChan, SIGNAL ( signalBlink( const int &, const bool &) ),
           this, SLOT (setBlinkSlot ( const int & , const bool & ) ));
  ChanButSig = new QSignalMapper ( this );
   connect( ChanButSig, SIGNAL(mapped( const int & )),
             this, SLOT( ChanButClicked( const int & )));
  connect( ChanButSig, SIGNAL(mapped( const int & )),
             stateChan, SLOT( changeDirection( const int & )));
//   
  createChBut();
  new  ClockFrame ( TimeWidget );
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
    connect( b, SIGNAL( clicked() ), ChanButSig, SLOT(map()));
    num++;
  };

};
/////////////////////////////////////////////////////
void MainFrame::ChanButClicked( const int & id)
{
  qDebug( "MainFrame::ChanButClicked %d", id );
  
};

/////////////////////////////////////////////////////
void MainFrame::setButState(ChanButton * b, const dbMainObject::Obj *obj)
{
  b->setText( obj->name );
  b->setColor( ChanButton::GREY );
  b->setError( obj->err );
  if ( obj->err != ChanButton::NORM )
  {
    stateChan->changeDirection( b->getId() );
    b->setBlink( obj->err == ChanButton::BLINK );
  };

};
/////////////////////////////////////////////////////
void MainFrame::updateState( )
{
    //qDebug( "MainFrame::updateState");
    dbMainObject::VecObj _obj = std::move ( db->getObject() );
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

/////////////////////////////////////////////////////
void MainFrame::setBlinkSlot ( const int & id, const bool & blink)
{
 qDebug() << "void MainFrame::NotBlinkSlot id =" << id  ;
 ChanBut [ id ] ->setBlink( blink );
}
