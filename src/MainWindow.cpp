#include "include/MainWindow.h"
#include <unistd.h>
#include "include/blinkingclass.h"
#include "include/util/Singleton.h"
#include "include/ObjectsUpdater.h"
////////////////////////////////////////////////////////////////////
MainWindow::MainWindow( bool multDisp,UbdaterClass *upb ,  QWidget *parent ) : QMainWindow(parent), NonConnDB( nullptr )
{
    setGeometry (WidthScreen *multDisp  ,0 ,WidthScreen, HeightScreen);


    setWindowFlags(Qt::FramelessWindowHint/* | Qt::WindowStaysOnBottomHint*/); // отключаем меню сверху окна

    if ( multDisp)
    {
        setWindowFlags ( this->windowFlags( ) | Qt::X11BypassWindowManagerHint ) ;
    }

    mainF = new MainFrame ( this );
    rigthFrame = new rightWidget( mainF->RmoWidget );
    objpa = new ObjectPA ( mainF->ObjPAWidget );

//  mainF->move( WidthScreen * multDisp, 0);

    BlinkingClass * blnk = new BlinkingClass(  1000 );

    blnk->addFrame( rigthFrame );
    blnk->addFrame( mainF );
    blnk->addFrame( objpa );

    connect( upb,
            SIGNAL(dbConnect ( const bool &)),
               this, SLOT( ShowNoConn ( const bool &) ) );

    connect( upb, SIGNAL ( ChangeSound() ), (mainF->SoundLabel), SLOT ( SoundChange() ) );

};
////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow()
{
    delete NonConnDB;
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

