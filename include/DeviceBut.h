#ifndef DEVICEBUT_H
#define DEVICEBUT_H

#include <QPushButton>

class DeviceBut : public QPushButton
{
    Q_OBJECT
public:
    enum CLR
    {
        GREEN = 0,
        RED,
        GEY
    };
    enum STATE
    {
        NORM= 0,
        CALL
    };
    enum
    {
        ERR = 1
    };

  DeviceBut( QWidget * parent = 0 );
  void setColor( CLR color );
  void setText (const QString &str);
  void setState (const QString &str);
private:

};

#endif // DEVICEBUT_H
