#include "include/blinkingclass.h"
#include <QDebug>
#include <QObjectList>
#include "include/butparent.h"

BlinkingClass::BlinkingClass( int _msec ): red( false )
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
            if ( ! but->isClicked () && but->isErr () )
            {
                ButParent::CLR clr = red ? ButParent::CLR::RED : but->getColor ();
                but->setColor ( clr, true );

            };

           // but->setColor (DeviceBut::CLR::RED);
        }
    };
    red = !red;
};

void BlinkingClass::addFrame ( QObject * frame)
{
    GridFrame.push_back( frame );
};
