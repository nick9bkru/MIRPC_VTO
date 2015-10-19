#include <QApplication>
#include "include/MainWindow.h"
#include "include/db/dbclass.h"
#include "include/define.h"
#include "include/util/Singleton.h"
#include <QFile>

using namespace std;

const QString StyleFile = "../mirpc_vto/style.qss";
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
 try
  {
     Util::Singleton<DBClass>::init(  new DBClass ( "mir_pgdb" ) ) ;
  }
  catch ( std::string & s)
  {
      qDebug() << "Error == " << s.c_str();
  }

  QApplication a(argc, argv);
    QFile * file = new QFile ( StyleFile );
    file->open( QFile::ReadOnly );
    // qDebug() <<QLatin1String(file->readAll()) ;
   a.setStyleSheet( QLatin1String(file->readAll()) );
    MainWindow w( argc > 2 );
    w.show();
    return a.exec();
  return 1;

};
