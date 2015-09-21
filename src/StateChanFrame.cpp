#include "include/StateChanFrame.h"
#include "include/util/Singleton.h"

StateChanFrame::StateChanFrame( QWidget *parent ):  QFrame( parent ), Ui::ChanFrame()
{
  qDebug( "StateChanFrame::StateChanFrame" );
  setupUi(this);
  id = 0;
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
{
    int num = 0;
    deleteAllBut();
  Dev = std::move(Util::Singleton<DbObjectClass>::getInstance().getDev( id ));
  for ( auto &it : Dev)
  {
      DeviceBut* but = new DeviceBut ( this  );
      SetButState ( but, &it);
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
   delete it;
  };
  StateBut.clear();
};
/////////////////////////////////////////////////////
void StateChanFrame::changeDirection( const int & _id )
{
  qDebug( "StateChanFrame::changeDirection %d", _id );
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
void StateChanFrame::SetButState(DeviceBut* but, DbObjectClass::Dev *dv )
{
    but->setText( dv->name );
    but->setColor( DeviceBut::GREY );
    but->setError( dv->err == DeviceBut::ERR );

};
/////////////////////////////////////////////////////
void StateChanFrame::updateState( )
{
    DbObjectClass::VecDev _dev= std::move(Util::Singleton<DbObjectClass>::getInstance().getDev( id ));
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
