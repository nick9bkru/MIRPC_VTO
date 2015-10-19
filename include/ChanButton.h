#ifndef CHANBUTTON_H
#define CHANBUTTON_H

#include "include/butparent.h"

#include <QMenu>
#include <QTimer>

#include "SetNameDialog.h"

class ChanButton : public ButParent
{	
  Q_OBJECT
public:


    enum SOST
    {
        NORM = 0,
        ERR,
        BLINK
    };

  ChanButton(QWidget *parent = 0, int _id = 0 );
  ~ChanButton();
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

private slots:
  /**
   * слот вызывающийся от выбора меню 
   */
  void slotChange(QAction*);
};

#endif // CHANBUTTON_H
