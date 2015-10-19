#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <vector>

#include "include/StandBut.h"

#include "ui_rightWidget.h"

#include "include/db/dbStandDevice.h"

class rightWidget: public QFrame, Ui::rigthFrame
{
public :
enum 
{
  CountRow = 3
};
  rightWidget ( QWidget *parent = 0 );
  ~rightWidget ( );
  void SetButState(StandBut* but, dbStandDevice::StandDev &dv );
  void updateState( );
private:
  /**
   * удаляем все кнопки
   */
  void deleteAllBut();

  void createPCBut();
  std::vector <StandBut*> DevBut;

   dbStandDevice::VecStandDev Dev;

   dbStandDevice * db ;
    QFrame rigthFrame;
};

#endif // RIGHTWIDGET_H
