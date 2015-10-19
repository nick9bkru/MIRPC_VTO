#ifndef STATECHANFRAME_H
#define STATECHANFRAME_H

#include "DeviceBut.h"
#include <vector>
#include <QSignalMapper>

#include "ui_StateChanFrame.h"
#include "include/define.h"


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
  void updateState( );
  /**
   * @brief isBlinkMainBut
   * @return
   * мигать или нет кнопкой на MainFrame
   */
  bool isBlinkMainBut ();
public slots:  
  void changeDirection( const int & _id );
  /**
  * @brief clickSlot
  * Нажатие на клавишу , после чего проверяем есть ли мигающие кнопки
  */
  void clickSlot(QObject *_but );

signals:
  void signalBlink(const int & _id ,const bool & blink  );
private:
  /**
   * удаляем все кнопки 
   */
  void deleteAllBut();
  void createStateBut();
  std::vector <DeviceBut*> StateBut;
  void changeTextDir( );
  int id;

  QSignalMapper * ClickerMap;
};

#endif // STATECHANFRAME_H
