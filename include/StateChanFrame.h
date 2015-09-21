#ifndef STATECHANFRAME_H
#define STATECHANFRAME_H

#include "DeviceBut.h"
#include <vector>

#include "ui_StateChanFrame.h"
#include "include/define.h"
#include "include/dbobjectclass.h"



class StateChanFrame : public QFrame, Ui::ChanFrame
{
  Q_OBJECT
public:
  enum
  {
    CountBut = 15,
    CountRow = 3
  };
  StateChanFrame(QWidget *parent = 0);
  ~StateChanFrame();
  void SetButState(DeviceBut* but, DbObjectClass::Dev *dv );
  void updateState( );
public slots:  
  void changeDirection( const int & _id );
private:
  /**
   * удаляем все кнопки 
   */
  void deleteAllBut();
  void createStateBut();
  std::vector <DeviceBut*> StateBut;
  void changeTextDir( );
  int id;
  DbObjectClass::VecDev Dev;
};

#endif // STATECHANFRAME_H
