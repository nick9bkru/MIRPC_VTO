#include "include/StateChanFrame.h"


StateChanFrame::StateChanFrame( QWidget *parent ):  QFrame( parent ), Ui::ChanFrame()
{
  qDebug( "StateChanFrame::StateChanFrame" );
  setupUi(this);
  id = 1;
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

 
}
/////////////////////////////////////////////////////
void StateChanFrame::createStateBut( )
{/*
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
  }*/

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
    if ( _id == 0 )
        return;
  id = _id + 1;
  //////////////////////////////////////////////////
  BSPUR1->setColor( ButParent::DEFAULT  );
  if ( id == 2 )
  {
      BSPUR1->setColor( ButParent::GREEN  );
  }
  /////////////////////////////////////////////////
  changeTextDir(  );
    createStateBut();
};
/////////////////////////////////////////////////////
void StateChanFrame::changeTextDir(  )
{
 NumChanLabel->setText( QString::fromUtf8 ("Объект № %1").arg( id  ) );
};
/////////////////////////////////////////////////////

/////////////////////////////////////////////////////
void StateChanFrame::updateState( )
{

}

/////////////////////////////////////////////////////
void StateChanFrame::clickSlot( QObject * _but)
{
  _but=_but;
//  qDebug() << "void StateChanFrame::clickSlot( text = " << but->text();
  if ( !isBlinkMainBut ())
  {
      emit signalBlink( id , false );
  };
};
/////////////////////////////////////////////////////
bool StateChanFrame::isBlinkMainBut ()
{
    bool _emit = true ;
//    for( auto &it : StateBut )
//    {
//        if ( it -> isErr () && it -> isBlink () )
//        {
//            _emit = false ;
//        };
//    };
    return _emit;
};
