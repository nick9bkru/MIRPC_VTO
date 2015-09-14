#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QPushButton>
#include <QSignalMapper>
#include <vector>

#include "ui_mainFrame.h"
#include "StateChanFrame.h"
#include "ChanButton.h"
#include "SetNameDialog.h"
#include "dbobjectclass.h"
#include "define.h"

class MainFrame: public QFrame, public Ui::mainFrame
{
   Q_OBJECT
public:
  enum
  {
   countCh = 21 
  };
    MainFrame( QWidget *parent = 0  );

    ~MainFrame();
    void updateState( );
    // фрэйм с обородуванием объекта
   StateChanFrame* stateChan ;
private:
  void setButState(ChanButton * b, const DbObjectClass::Obj *obj);
  //рисуем отображение каналов
  void createChBut();

  std::vector <ChanButton *> ChanBut ;
  
  QSignalMapper *ChanButSig;

  DbObjectClass * db ;



  //состояние всех кналов
  DbObjectClass::VecObj Obj;
  QTimer * timerBlink;

public slots:
  void ChanButClicked( const int & id );
};

#endif // MainFrame_H
