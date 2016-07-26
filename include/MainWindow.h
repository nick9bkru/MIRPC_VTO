#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
 #include <QGridLayout>
 #include <QTimer>

#include "include/define.h"
#include "include/rightWidget.h"
#include "include/MainFrame.h"
#include "include/ObjectPA.h"
#include "include/notConnectionDb.h"
#include "include/UbdaterClass.h"

/**
 * @brief The MainWindow class класс главного объекта
 */
class MainWindow: public QMainWindow
{
  Q_OBJECT
    /**
    * @brief The sizeWin enum размер окна
    */
    enum sizeWin
    {
         WidthScreen = 1280, /// ширина
         HeightScreen = 960  /// высота
    };
public:
    /**
   * @brief MainWindow конструктор
   * @param multDispотображать ли на второй экран
   * @param upb класс следящий за обновлением состояния в системе
   * @param parent - родитель
   */
  MainWindow(bool multDisp , UbdaterClass *upb, QWidget *parent = 0);
  ~MainWindow();

private slots:
  void ShowNoConn (const bool &b);
private:
  MainFrame * mainF ;
  rightWidget * rigthFrame ;
  ObjectPA * objpa;
  QTimer * updTimer;
  notConnectionDb * NonConnDB;
protected:
  
};

#endif // MAINWINDOW_H
