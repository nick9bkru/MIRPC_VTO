#include "include/BSPurBut.h"
#include <QDebug>
BSPurBut::BSPurBut(DeviceClass *_dev, QWidget *parent):StandBut(_dev, parent)
{
    qDebug( ) << "BSPurBut::BSPurBut()";
    setMaximumSize(parent->maximumWidth(),parent->maximumHeight());
    setMinimumSize(0,parent->minimumHeight()+50);
}


BSPurBut::~BSPurBut()
{
 qDebug( ) << "BSPurBut::~BSPurBut()";
};
