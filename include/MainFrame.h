#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QPushButton>
#include <QSignalMapper>
#include <vector>

#include "ui_mainFrame.h"
#include "StateChanFrame.h"
#include "include/buttom/ChanButton.h"
#include "SetNameDialog.h"
#include "include/db/dbMainObject.h"
#include "define.h"

/**
 * @brief The MainFrame class класс главного фрейма
 */
class MainFrame: public QFrame, public Ui::mainFrame
{
   Q_OBJECT
public:

  enum
  {
      ///количество объектов
   countCh = 21
  };
    /**
     * @brief MainFrame конструктор
     * @param parent - родитель
     */
    MainFrame( QWidget *parent = 0  );

    ~MainFrame();

private:
    /**
    * @brief stateChan фрэйм с обородуванием объекта
    */
   StateChanFrame* stateChan[2] ;
  //рисуем отображение каналов
  void createChBut();

  std::vector <ChanButton *> ChanBut ;
  
  QSignalMapper *ChanButSig;




  //состояние всех кналов
 // dbMainObject::VecObj Obj;
public slots:

  void ChanButClicked ( const int & id );
};

#endif // MainFrame_H
