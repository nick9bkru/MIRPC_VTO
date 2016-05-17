#include "include/PurBut.h"
#include <QDebug>

PurBut::PurBut(DeviceClass *_dev, QWidget *parent):StandBut(_dev, parent)
{
setMaximumSize(parent->maximumWidth(),parent->maximumHeight());
setMinimumSize(0,70);
}

/**
 * слот для установки текста на кнопке
 */
void PurBut::setText (const QString &str)
{
   QString name;
   for ( auto  it2 :  str )
   {
         name += it2 + '\n';
   };
   name.truncate( name.size() - 1  );
   ButParent::setText( name ) ;
};

PurBut::~PurBut()
{
    qDebug() << " PurBut::~PurBut() ";
}
