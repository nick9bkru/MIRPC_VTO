#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <vector>

#include "DeviceBut.h"

#include "ui_rightWidget.h"
#include "include/ClockFrame.h"
#include "include/dbobjectclass.h"

class rightWidget: public QFrame, Ui::rigthFrame
{
public :
enum 
{
  CountPc = 20,
  CountRow = 5
};
  rightWidget ( QWidget *parent = 0 );
  ~rightWidget ( );
  void SetButState(DeviceBut* but, DbObjectClass::StandDev &dv );
  void updateState( );
private:
  /**
   * удаляем все кнопки
   */
  void deleteAllBut();

  void createPCBut();
  std::vector <DeviceBut*> DevBut;

   DbObjectClass::VecStandDev Dev;

};

#endif // RIGHTWIDGET_H
