#include "include/blinkingclass.h"
#include <QDebug>
#include <QObjectList>
#include "include/buttom/butparent.h"

BlinkingClass::BlinkingClass( int _msec ): second( false )
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
        QList<ButParent *> b = std::move( it->findChildren<ButParent *>("Button") );
        for ( auto & but : b)
        {
            if ( but->isBlink () )
            {
                ButParent::CLR clr = second ? but->getSecondColor(  ) : but->getColor ();
                but->setColor ( clr, true );

            };

           // but->setColor (DeviceBut::CLR::RED);
        }
    };
    second = !second;
};

void BlinkingClass::addFrame ( QObject * frame)
{
    GridFrame.push_back( frame );
};
