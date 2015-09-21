#include "include/rightWidget.h"
#include "include/util/Singleton.h"

/////////////////////////////////////////////////////
rightWidget::rightWidget ( QWidget *parent ): QFrame(parent),Ui::rigthFrame()
{
  qDebug( "rightWidget::rightWidget" );
  setupUi(this);
  labelName->setFrameStyle(QFrame::Box | QFrame:: Raised) ;
  createPCBut();

  // new  ClockFrame ( TimeWidget );
  
};
/////////////////////////////////////////////////////
rightWidget::~rightWidget ( )
{
  
};
/////////////////////////////////////////////////////
void rightWidget::createPCBut()
{
    int num = 0;
    deleteAllBut();
    Dev= std::move(Util::Singleton<DbObjectClass>::getInstance().getStandDev());
   for ( auto &it : Dev)
  {
      DeviceBut* but = new DeviceBut ( this  );
      but->setMinimumWidth(70);
      SetButState ( but, it);
      gridPc->addWidget( but, num / CountRow , num % CountRow);
      DevBut.push_back( but );
      num++;
  }

};

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void rightWidget::deleteAllBut()
{
  for( auto &it : DevBut )
  {
   delete it;
  };
  DevBut.clear();
};

/////////////////////////////////////////////////////
void rightWidget::SetButState(DeviceBut* but, DbObjectClass::StandDev &dv )
{
    but->setText( dv.name );
    but->setError( dv.err );

};

/////////////////////////////////////////////////////
void rightWidget::updateState( )
{
    DbObjectClass::VecStandDev _dev= std::move(Util::Singleton<DbObjectClass>::getInstance().getStandDev());
    auto itOld = std::begin ( Dev );
    auto itnew = std::begin ( _dev ) ;
    auto itBut = std::begin ( DevBut ) ;
    for ( ; itnew != std::end( _dev ); itnew++, itOld++, itBut++)
    {
        if ( (*itnew) != (*itOld) )
        {
            SetButState ( (*itBut) ,  (*itnew));
            (*itOld) = (*itnew) ;
        }
    }
}
