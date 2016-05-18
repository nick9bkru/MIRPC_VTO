#include "include/StateChanFrame.h"
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"

StateChanFrame::StateChanFrame( QWidget *parent ):  QFrame( parent ), Ui::ChanFrame()
{
  qDebug( "StateChanFrame::StateChanFrame" );
  setupUi(this);
  id = -1;
  ClickerMap = new QSignalMapper ( this );
  connect( ClickerMap , SIGNAL(mapped(  QObject * )),
             this, SLOT( clickSlot(  QObject * )));
  db = new dbDevices ( &Util::Singleton<DBClass>::getInstance() );
  Other_frame->setLayout( OtherButLayout );

 // changeDirection( id );

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
    deleteAllBut();
    dbDevices::DevVect vec = std::move ( db->getDevices( id, BSPurWid::BSPUR ) );
    for ( auto & it : vec )
    {
        BSPurWid *bs = new BSPurWid (db, BSPUR_frame );
        bs->refreshWidjet( id, it.id, it.ip );
        BSPURLayout->addWidget( bs );
    }
    OtherDevWid * other = new OtherDevWid ( db, id, OtherDevWid::KLS, Other_frame);
    OtherButLayout->addWidget( other );
    other = new OtherDevWid ( db, id, OtherDevWid::KC, Other_frame);
    OtherButLayout->addWidget( other );
    other = new OtherDevWid ( db, id, OtherDevWid::SHSS1, Other_frame);
    OtherButLayout->addWidget( other );

};
/////////////////////////////////////////////////////
void StateChanFrame::deleteAllBut()
{  
    qDebug() << "StateChanFrame::deleteAllBut()";
    while (QLayoutItem* item = BSPURLayout->takeAt(0))
        {
           // qDebug( ) << item ;
            delete item->widget();
            delete item;
        }
    while (QLayoutItem* item = OtherButLayout->takeAt(0))
        {
           // qDebug( ) << item ;
            delete item->widget();
            delete item;
        }
};
/////////////////////////////////////////////////////
void StateChanFrame::changeDirection( const int & _id )
{
  qDebug( "StateChanFrame::changeDirection %d", _id );
    if ( _id == 0 || id == ( _id + 1 )   )
        return;
  id = _id + 1;

  changeTextDir(  );
    createStateBut();
};
/////////////////////////////////////////////////////
void StateChanFrame::changeTextDir(  )
{
 NumChanLabel->setText( Util::Singleton<ObjectsUpdater>::getInstance().getObject( id )->getName());
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
