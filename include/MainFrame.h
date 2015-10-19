#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QPushButton>
#include <QSignalMapper>
#include <vector>

#include "ui_mainFrame.h"
#include "StateChanFrame.h"
#include "ChanButton.h"
#include "SetNameDialog.h"
#include "include/db/dbMainObject.h"
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
   StateChanFrame* stateChan[2] ;
private:
  void setButState(ChanButton * b, const dbMainObject::Obj *obj);
  //рисуем отображение каналов
  void createChBut();

  std::vector <ChanButton *> ChanBut ;
  
  QSignalMapper *ChanButSig;

  dbMainObject * db ;



  //состояние всех кналов
 // dbMainObject::VecObj Obj;
public slots:

  void setBlinkSlot ( const int & id, const bool & blink) ;
  void ChanButClicked ( const int & id );
};

#endif // MainFrame_H
