#ifndef STATECHANFRAME_H
#define STATECHANFRAME_H

#include "DeviceBut.h"
#include <vector>

#include "ui_StateChanFrame.h"
#include "include/define.h"
#include "include/db/dbDevices.h"
#include "include/BSPurWid.h"
#include "include/OtherDevWid.h"

class StateChanFrame : public QFrame, Ui::ChanFrame
{
  Q_OBJECT
public:
  enum
  {
    CountRow = 4
  };
  StateChanFrame(QWidget *parent = 0);
  ~StateChanFrame();

  /**
   * @brief isBlinkMainBut
   * @return
   * мигать или нет кнопкой на MainFrame
   */
  bool isBlinkMainBut ();
public slots:  
  void changeDirection( const int & _id );
  void updateState(int16_t id);
signals:
private:
  /**
   * удаляем все кнопки 
   */
  void deleteAllBut();
  void createStateBut();
  std::vector <DeviceBut*> StateBut;
  void changeTextDir( );
  int id;
    dbDevices * db;
};

#endif // STATECHANFRAME_H
