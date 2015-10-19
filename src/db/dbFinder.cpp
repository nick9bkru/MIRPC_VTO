#include "include/db/dbFinder.h"
#include <QDebug>
#include <QSqlDriver>
#include <QSqlDatabase>

dbFinder::dbFinder( int msec ): con( -1 )
{
    qDebug( ) <<"dbFinder::dbFinder( int msec ) == " << msec   ;
    timer = new QTimer (  );
    timer->setInterval( msec );
    connect ( timer, SIGNAL( timeout() ) , this,  SLOT( timerSlot() ) );

};

void dbFinder::start()
{
    timer->start();
};

void dbFinder::timerSlot()
{
    bool b = QSqlDatabase::database().isOpen();

    if ( b != con )
    {
     //   qDebug( ) <<"dbFinder::timerSlot() b == " << b   ;
        con = b ;
       emit dbConnect( b );
    };
};


