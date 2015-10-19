#include "include/rightWidget.h"
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"
#include "include/util/MyException.h"

/////////////////////////////////////////////////////
rightWidget::rightWidget ( QWidget *parent ): QFrame(parent),Ui::rigthFrame()
{
  qDebug( "rightWidget::rightWidget" );
  setupUi(this);
  labelName->setFrameStyle(QFrame::Box | QFrame:: Raised) ;

//  setLineWidth(2);
  ObjectClass* obj = Util::Singleton<ObjectsUpdater>::getInstance().getObject( 1 );
  if ( obj  == NULL )
  {
      qDebug() << "rightWidget don't find object whith id == 0"   ;
      throw Util::MyException( "ERROR !!!!!  rightWidget  don't find object " );

  }

  dev = obj->getDevices() ;

  refresh( -1 );
  connect( obj, SIGNAL( change ( int16_t ) ), this, SLOT( refresh( int16_t ) )  );
};
/////////////////////////////////////////////////////
rightWidget::~rightWidget ( )
{
  
};

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
void rightWidget::deleteAllBut()
{
  for( auto &it : DevBut )
  {
    gridPc->removeWidget( it );
    delete it;
  };
  DevBut.clear();
  qDebug() << "!!!!!!!!!!! == " <<DevBut.size();

};

void rightWidget::refresh( int16_t b )
{
    StandBut * but ;
    int num = 0;
    qDebug( ) <<  "rightWidget::refresh  b == " << b  ;

    if ( b == -1 )
    {
     deleteAllBut();

      for ( auto &it : *dev )
     {
         qDebug() <<  it->getName();
          but =  new StandBut( it, this ) ;
             //  but->setMinimumWidth(70);
              gridPc->addWidget( but, num / CountRow , num % CountRow);
         DevBut.push_back( but );
       //  but->show();
//         qDebug() << "rightWidget::refresh name " << but->text() << " vis" << but->isVisible();
        num++;
     };
    }
//gridPc->setGeometry(QRect(0,0,200,400));
//    qDebug() << "!!!!!!!!!!! == " <<DevBut.size();
}
