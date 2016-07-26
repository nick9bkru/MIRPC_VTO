#ifndef CHANBUTTON_H
#define CHANBUTTON_H

#include "include/buttom/butparent.h"
#include "include/ObjectsUpdater.h"

#include <QMenu>
#include <QTimer>

#include "include/SetNameDialog.h"

/**
 * @brief The ChanButton class
 * Класс кнопки для отображения объектов системы
 */

class ChanButton : public ButParent
{	
  Q_OBJECT
public:
    /**
   * @brief ChanButton Конструктор
   * @param parent
   * @param _id id объекта
   */
  ChanButton(QWidget *parent = 0, int _id = 0 );
  ~ChanButton();
  /**
   * @brief getId получить объект
   * @return
   */
  int getId();
private :
  int id;
  QMenu * menu;
signals:
  /**
   * сигнал с информацией о обновленной кнопке 
   */
  void signalChange ( int );
public slots:
  /***
   * Обрабатываем нажатия клавишь мышки по кнопке
   * 
   */
  void mousePressEvent ( QMouseEvent * e ) ;

  void refresh();

private slots:
  /**
   * слот вызывающийся от выбора меню 
   */
  void slotChange(QAction*);
protected:
  virtual void reactClick() override;

};

#endif // CHANBUTTON_H
