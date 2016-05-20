#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <list>

#include "include/buttom/StandBut.h"

#include "ui_rightWidget.h"
#include "include/ObjectClass.h"

class rightWidget: public QFrame, Ui::rigthFrame
{
    Q_OBJECT
public :
enum 
{
  CountRow = 3
};
  rightWidget ( QWidget *parent = 0 );
  ~rightWidget ( );
public slots:
  void refresh( int16_t b );
private:
  /**
   * @brief dev
   * вектор с указателями на состояния всех кнопкок этого объекта !
   */
  ObjectClass::DevisesType * dev ;
  /**
   * удаляем все кнопки
   */
  void deleteAllBut();

  std::list <StandBut*> DevBut;

    QFrame rigthFrame;
};

#endif // RIGHTWIDGET_H
