#ifndef STATECHANFRAME_H
#define STATECHANFRAME_H

#include "include/buttom/DeviceBut.h"
#include <vector>

#include "ui_StateChanFrame.h"
#include "include/define.h"
#include "include/db/dbDevices.h"
#include "include/BSPurWid.h"
#include "include/OtherDevWid.h"

/**
 * @brief The StateChanFrame class класс с состояниями устройств объекта
 */
class StateChanFrame : public QFrame, Ui::ChanFrame
{
  Q_OBJECT
public:
    /**
   * столбцы
   */
  enum
  {
    CountRow = 4 ///столбцы
  };
  /**
   * @brief StateChanFrame конструктор класса
   * @param parent
   */
  StateChanFrame(QWidget *parent = 0);
  ~StateChanFrame();

  /**
   * @brief isBlinkMainBut мигать или нет кнопкой на MainFrame
   * @return мигать или нет кнопкой на MainFrame
   */
  bool isBlinkMainBut ();
public slots:  
  /**
   * @brief changeDirection меняем объект на другой
   * @param _id id объекта
   */
  void changeDirection( const int & _id );
  /**
   * @brief updateState обновляем состояние
   * @param id
   */
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
