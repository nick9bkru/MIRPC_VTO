#include "include/MainWindow.h"
#include <unistd.h>
#include "include/blinkingclass.h"
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"
////////////////////////////////////////////////////////////////////
MainWindow::MainWindow( bool multDisp, QWidget *parent ) : QMainWindow(parent), NonConnDB( nullptr )
{
    setGeometry (0 ,0 , ( 1 + multDisp * 1)*WidthScreen, HeightScreen);


    setWindowFlags(Qt::FramelessWindowHint/* | Qt::WindowStaysOnBottomHint*/); // отключаем меню сверху окна



    mainF = new MainFrame ( this );
    rigthFrame = new rightWidget( mainF->RmoWidget );
    objpa = new ObjectPA ( mainF->ObjPAWidget );

    mainF->move( WidthScreen * multDisp, 0);

    updTimer = new QTimer ( this );
    connect( updTimer, SIGNAL(timeout()), this, SLOT(start()) ) ;
    updTimer->start( 10000 );

    BlinkingClass * blnk = new BlinkingClass(  1000 );

    blnk->addFrame( rigthFrame );
    blnk->addFrame( mainF );
    blnk->addFrame( objpa );

    connect( &Util::Singleton<ObjectsUpdater>::getInstance(),
            SIGNAL(dbConnect ( const bool &)),
               this, SLOT( ShowNoConn ( const bool &) ) );



};
////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete NonConnDB;
};
////////////////////////////////////////////////////////////////////
void MainWindow::start()
{
       try
       {
       // Util::Singleton<ObjectsUpdater>::getInstance().updateAll(); ;
      //  qDebug() << " start() :: " ;
       // mainF->updateState();
    //    mainF->stateChan->updateState();
//        rigthFrame-> updateState( );
       } catch ( std::string &e)
       {
           qDebug() << " ERROR on MainWindow::start() :: " << e.c_str();

       }
};
////////////////////////////////////////////////////////////////////
void MainWindow::ShowNoConn ( const bool & b)
{
    qDebug() << "ShowNoConn ( const bool & b) == " << b;
    if ( b )
    {
        delete NonConnDB;
        NonConnDB = nullptr;
    } else
    {
        NonConnDB = new notConnectionDb(this);
        NonConnDB->show();
        NonConnDB->activateWindow();
    };
};

