#ifndef CLOCKFRAME_H
#define CLOCKFRAME_H

#include <QTimer>
#include <QTime>
#include <QDate>

#include "ui_ClockFrame.h"

class ClockFrame : public QFrame, Ui::TimeFrame
{
  Q_OBJECT
public:
ClockFrame( QWidget *parent = 0 );
~ClockFrame();

private:
  QTime time;
  QString getStrMonth( int num);
private slots:
  void UpdateClock();
};

#endif // CLOCKFRAME_H
