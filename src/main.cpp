#include <QApplication>
#include "include/MainWindow.h"
#include "include/db/dbMainObject.h"
#include "include/define.h"
#include "include/util/Singleton.h"

#include "include/ObjectsUpdater.h"


#include <QFile>
#include <QSettings>
#include <memory>
using namespace std;

const QString confFile = "/etc/mir_vto.conf";
void start()
{
  cout << "=============================" <<endl;
  cout << "=============================" <<endl;
  cout << "|                           |" <<endl;
  cout << "|    Start MIR VTO program  |" <<endl;
  cout << "|                           |" <<endl;
  cout << "=============================" <<endl;
  cout << "=  " << __TIMESTAMP__ << "  =" <<endl;
  cout << "=============================" <<endl;

}
// добавил , что бы не надо было потом delete делать
std::unique_ptr <QApplication> a;
std::unique_ptr <QSettings> settings( new QSettings ( confFile , QSettings::NativeFormat ) );

// загружаем стили
void loadStyle( QString SFile)
{
    qDebug() << " loadStyle from file  == " << SFile;
    QFile * file = new QFile ( SFile );
    file->open( QFile::ReadOnly );
      // qDebug() <<QLatin1String(file->readAll()) ;
    a->setStyleSheet( QLatin1String(file->readAll()) );
     delete file;
};


int main (int argc, char *argv[])
{

  start();
  UNUSED(argc);UNUSED(argv);

  a.reset( new QApplication (argc, argv) );

  if ( settings->status() != QSettings::NoError )
  {
    qDebug() << " Setting file not loaded error == " << settings->status() ;
    return -1;
  }
  loadStyle( settings->value( "StyleFile" ).toString() );
  std::unique_ptr <DBClass> db ( new DBClass ( settings->value( "db_name" ).toString(), // название БД
                                  settings->value( "db_adress" ).toString(), // адрес хоста
                                   settings->value( "db_user" ).toString() ) ) ; // имя пользователя

  Util::Singleton<DBClass>::init(db.get());
  UbdaterClass updClass ;


   MainWindow w( argc > 1, &updClass );

   w.show();
  return a->exec();

};
