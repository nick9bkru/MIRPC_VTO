#include "include/ClockFrame.h"

ClockFrame::ClockFrame(QWidget *parent ) : QFrame( parent ), Ui::TimeFrame()
{
  setupUi( this );
  
  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), SLOT(UpdateClock()));
  timer->start(1000);
  UpdateClock();
}

ClockFrame::~ClockFrame()
{

}

void ClockFrame::UpdateClock()
{
  QTime time = QTime::currentTime();
  SecLcd->display( QString("%1").arg( time.second(), 2, 10, QChar('0')) );
  MinLcd->display( time.minute() );
  HourLcd->display( time.hour() );
  
  QDate date = QDate::currentDate();
  DayLcd->display( date.day() );
  MounthLabel->setText( getStrMonth(date.month()) );
  YearLcd->display( date.year() );
};

QString ClockFrame::getStrMonth( int num )
{
  QString month;
  switch ( num )
  {
   case 1 :  month = QString::fromUtf8("Января");
    break;
   case 2 :  month = QString::fromUtf8("Февраля");
    break;
   case 3 :  month = QString::fromUtf8("Марта");
    break;
   case 4 :  month = QString::fromUtf8("Апреля");
    break;
   case 5 :  month = QString::fromUtf8("Мая");
    break;
   case 6 :  month = QString::fromUtf8("Июня");
    break;
   case 7 :  month = QString::fromUtf8("Июля");
    break;
   case 8 :  month = QString::fromUtf8("Августа");
    break;
   case 9 :  month = QString::fromUtf8("Сентября");
    break;
   case 10 :  month = QString::fromUtf8("Октября");
    break;
   case 11 :  month = QString::fromUtf8("Ноября");
    break;
   case 12 :  month = QString::fromUtf8("Декабря");
    break;
   
  }
  return month;
};
