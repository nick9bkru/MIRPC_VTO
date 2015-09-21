#include "include/blinkingclass.h"
#include <QDebug>
#include <QObjectList>

BlinkingClass::BlinkingClass( int _msec )
{
    qDebug() << "BlinkingClass::BlinkingClass( |"<< _msec<< "| ";
    t = new QTimer ( );
    connect ( t , SIGNAL(timeout()), this , SLOT( blinkingSlot()) );
    t->start( _msec );
};

BlinkingClass::~BlinkingClass( )
{
    delete t;
}

void BlinkingClass::blinkingSlot()
{
    QObjectList But;

    for ( auto & it : GridFrame )
    {

    }
};

void BlinkingClass::addFrame ( QObject * frame)
{
    GridFrame.push_back( frame );
};
