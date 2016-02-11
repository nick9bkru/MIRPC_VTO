#include "include/MainFrame.h"
#include "include/ClockFrame.h"
#include "include/util/Singleton.h"

MainFrame::MainFrame( QWidget *parent ): QFrame(parent), Ui::mainFrame()
{
  qDebug( "MainFrame::MainFrame" );
  setupUi(this);

 // setFrameStyle(QFrame::Box | QFrame:: Raised);
  stateChan[0] = new StateChanFrame( StateChanWidget1 );
  stateChan[1] = new StateChanFrame( StateChanWidget2 );


  ChanButSig = new QSignalMapper ( this );
   connect( ChanButSig, SIGNAL(mapped( const int & )),
             this, SLOT( ChanButClicked( const int & )));
  connect( ChanButSig, SIGNAL(mapped( const int & )),
             stateChan[0] , SLOT( changeDirection( const int & )));
//
  createChBut();

  //часы !!
  new  ClockFrame ( TimeWidget );
  QSqlQuery q;


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
  const int count_obj = 21;
  int i, j;

  for ( int num = 0; num < count_obj;  num ++ )
  {
      j = num % row;
      i = num / row;
    // qDebug() << "id = " << it.id << " Name == " <<(it).name << " err == " << it.err ;
      ChanButton * b = new ChanButton (  this, num + 1);
    //  setButState ( b,  &it);
      ChanBut.push_back( b );
      gridChannel->addWidget( b , i, j);
      ChanButSig->setMapping(  b , b ->getId() );
      connect( b, SIGNAL( clicked() ), ChanButSig, SLOT(map()));
  }
};
/////////////////////////////////////////////////////
void MainFrame::ChanButClicked( const int & id)
{
  qDebug( "MainFrame::ChanButClicked %d", id );
};
