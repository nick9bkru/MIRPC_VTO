#include "include/buttom/OtherDevBut.h"
#include <QDebug>

OtherDevBut::OtherDevBut(DeviceClass *_dev, QWidget *parent):StandBut(_dev, parent)
{
    setMaximumSize(parent->maximumWidth(),parent->maximumHeight());
    setMinimumSize(50,20);
    this->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Preferred );


}

OtherDevBut::~OtherDevBut()
{
    qDebug( ) << "OtherDevBut::~OtherDevBut()";
}
