#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
 #include <QGridLayout>
 #include <QTimer>

#include "include/define.h"
#include "include/rightWidget.h"
#include "include/MainFrame.h"
#include "include/ObjectPA.h"


class MainWindow: public QMainWindow
{
  Q_OBJECT
 enum sizeWin
 {
     WidthScreen = 1280,
     HeightScreen = 960
 };
public:
  MainWindow(bool multDisp = 0, QWidget *parent = 0);
  ~MainWindow();

public  slots:
  void start();
private:
  MainFrame * mainF ;
  rightWidget * rigthFrame ;
  ObjectPA * objpa;
  QTimer * updTimer;
protected:
  
};

#endif // MAINWINDOW_H
