#include "include/StateChanFrame.h"


StateChanFrame::StateChanFrame( QWidget *parent ):  QFrame( parent ), Ui::ChanFrame()
{
  qDebug( "StateChanFrame::StateChanFrame" );
  setupUi(this);
  db = new BDStateChan ();
  id = 0;
  ClickerMap = new QSignalMapper ( this );
  connect( ClickerMap , SIGNAL(mapped(  QObject * )),
             this, SLOT( clickSlot(  QObject * )));
  changeDirection( id );


  //StateChanGrid->setVerticalSpacing(50);
//StateChanGrid->setHorizontalSpacing(15);
 }
/////////////////////////////////////////////////////
StateChanFrame::~StateChanFrame()
{
  qDebug( "StateChanFrame::~StateChanFrame" );
  delete db;
 
}
/////////////////////////////////////////////////////
void StateChanFrame::createStateBut( )
{
    int num = 0;
    deleteAllBut();
  Dev = std::move( db->getDev( id ) );
  for ( auto &it : Dev)
  {
      DeviceBut* but = new DeviceBut ( this, it.index  );


      connect( but, SIGNAL (released()), ClickerMap , SLOT ( map() ) );
      ClickerMap->setMapping( but, (QObject * )but );
      SetButState ( but, &it);
      but->setBlink( db->getBlink( but->getIndex() ) );
      StateChanGrid->addWidget( but, num / CountRow , num % CountRow);
      StateBut.push_back( but );
      num++;
  }
};
/////////////////////////////////////////////////////
void StateChanFrame::deleteAllBut()
{  
  for( auto &it : StateBut )
  {
      ClickerMap->removeMappings( it );
      it->disconnect();
     delete it;
  };
  StateBut.clear();
};
/////////////////////////////////////////////////////
void StateChanFrame::changeDirection( const int & _id )
{
  //qDebug( "StateChanFrame::changeDirection %d", _id );
  id = _id;
  changeTextDir(  );
    createStateBut();
};
/////////////////////////////////////////////////////
void StateChanFrame::changeTextDir(  )
{
 NumChanLabel->setText( QString::fromUtf8 ("Объект № %1").arg( id + 1 ) );
};
/////////////////////////////////////////////////////
void StateChanFrame::SetButState(DeviceBut* but, BDStateChan::Dev *dv )
{
    //qDebug() << dv->name ;
    but->setText( dv->name );
    but->setColor( DeviceBut::GREY );
    but->setError( dv->err == DeviceBut::ERR );

};
/////////////////////////////////////////////////////
void StateChanFrame::updateState( )
{
    BDStateChan::VecDev _dev= std::move( db->getDev( id ) );
    auto itOld = std::begin ( Dev );
    auto itnew = std::begin ( _dev ) ;
    auto itBut = std::begin ( StateBut ) ;
    for ( ; itnew != std::end( _dev ); itnew++, itOld++, itBut++)
    {
        if ( (*itnew) != (*itOld) )
        {
            SetButState ( (*itBut) ,  &(*itnew) );
            (*itOld) = (*itnew) ;
        }
    }
}

/////////////////////////////////////////////////////
void StateChanFrame::clickSlot( QObject * _but)
{
  DeviceBut* but = (DeviceBut*) _but;
  qDebug() << "void StateChanFrame::clickSlot( text = " << but->text();
  db->setBlink( but->getIndex() ,  false ) ;
  if ( !isBlinkMainBut ())
  {
      emit signalBlink( id , false );
  };
};
/////////////////////////////////////////////////////
bool StateChanFrame::isBlinkMainBut ()
{
    bool _emit = true ;
    for( auto &it : StateBut )
    {
        if ( it -> isErr () && it -> isBlink () )
        {
            _emit = false ;
        };
    };
    return _emit;
};
