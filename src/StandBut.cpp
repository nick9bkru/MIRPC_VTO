#include "include/StandBut.h"
#include <QFont>
#include <QApplication>
StandBut::StandBut( QWidget * parent ): ButParent(parent)
{
    setMinimumHeight( 50 );
    QFont f( QApplication::font( ) );
    f.setPointSize( 10 );
    setFont( f );
    setMinimumWidth( 92 );

}

