#include <QApplication>
#include "include/MainWindow.h"
#include "include/db/dbclass.h"
#include "include/define.h"
#include "include/util/Singleton.h"

#include "include/ObjectsUpdater.h"

#include <QFile>
#include <QSettings>

using namespace std;

const QString confFile = "../mirpc_vto/mir_vto.conf";
void start()
{
  cout << "=============================" <<endl;
  cout << "=============================" <<endl;
  cout << "|                           |" <<endl;
  cout << "|    Start TESTER program   |" <<endl;
  cout << "|                           |" <<endl;
  cout << "=============================" <<endl;
  cout << "=  " << __TIMESTAMP__ << "  =" <<endl;
  cout << "=============================" <<endl;

}

int main (int argc, char *argv[])
{

  start();
  UNUSED(argc);UNUSED(argv);
  QApplication a(argc, argv);

  QSettings * settings = new QSettings ( confFile , QSettings::NativeFormat );
  if ( settings->status() != QSettings::NoError )
  {
    qDebug() << " Setting file not loaded error == " << settings->status() ;
    return -1;
  }
  qDebug() << "!!!!!!!!! " <<settings->value( "db_adress" ).toString();
  Util::Singleton<DBClass>::init(  new DBClass ( settings->value( "db_name" ).toString(), // название БД
                                                         settings->value( "db_adress" ).toString(), // адрес хоста
                                                           settings->value( "db_user" ).toString() ) ) ; // имя пользователя

  // класс со всеми состояниями кнопок 

  Util::Singleton<ObjectsUpdater>::init(  new ObjectsUpdater() ) ;


    QFile * file = new QFile ( settings->value( "StyleFile" ).toString() );
    file->open( QFile::ReadOnly );
    // qDebug() <<QLatin1String(file->readAll()) ;
   a.setStyleSheet( QLatin1String(file->readAll()) );
   delete file;
   delete settings;
    MainWindow w( argc > 2 );
    w.show();
    return a.exec();
  return 1;

};
