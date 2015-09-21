#include "include/MainWindow.h"
#include <unistd.h>
#include "include/blinkingclass.h"

////////////////////////////////////////////////////////////////////
MainWindow::MainWindow( bool multDisp, QWidget *parent ) : QMainWindow(parent)
{
    setGeometry (0 ,0 , ( 1 + multDisp * 1)*WidthScreen, HeightScreen);


    setWindowFlags(Qt::FramelessWindowHint/* | Qt::WindowStaysOnBottomHint*/); // отключаем меню сверху окна


    mainF = new MainFrame ( this );
    rigthFrame = new rightWidget( mainF->RmoWidget );
    objpa = new ObjectPA ( mainF->ObjPAWidget );

    mainF->move( WidthScreen * multDisp, 0);

    updTimer = new QTimer ( this );
    connect( updTimer, SIGNAL(timeout()), this, SLOT(start()) ) ;
    updTimer->start( 1000 );

    BlinkingClass * blnk = new BlinkingClass(  1000 );

    blnk->addFrame( rigthFrame );
    blnk->addFrame( mainF );
    blnk->addFrame( objpa );
};
////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{

};
////////////////////////////////////////////////////////////////////
void MainWindow::start()
{
       try
       {
      //  qDebug() << " start() :: " ;
        mainF->updateState();
        mainF->stateChan->updateState();
        rigthFrame-> updateState( );
       } catch ( std::string &e)
       {
           qDebug() << " ERROR on MainWindow::start() :: " << e.c_str();

       }
};
////////////////////////////////////////////////////////////////////


