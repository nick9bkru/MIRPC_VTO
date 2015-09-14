#ifndef CHANBUTTON_H
#define CHANBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QMenu>
#include <QTimer>

#include "SetNameDialog.h"

class ChanButton : public QPushButton
{	
  Q_OBJECT
public:
    enum CLR //цвет
    {
        GREEN = 0,
        RED,
        GREY
    };

    enum SOST
    {
        NORM = 0,
        ERR
    };

  ChanButton(QWidget *parent = 0, int _id = 0 );
  ~ChanButton();
  int getId();
  void setColor( CLR color , bool blink = false );
  void setError( bool b = true );
private :
  //таймер для мерцании кнопки
  const int blinkTimer = 1000;
  int id;
  QMenu * menu; 
  //мигает или нет
  bool blink = false;

  //цвет кнопки
  CLR colr;
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
  /**
   * слот для установки текста на кнопке 
   */
  void setText (const QString &str);

  /**
   * слот для мигания кнопки
   */
  void slotBlink ( );
private slots:
  /**
   * слот вызывающийся от выбора меню 
   */
  void slotChange(QAction*);
};

#endif // CHANBUTTON_H
