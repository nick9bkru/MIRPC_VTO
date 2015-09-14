#include <QApplication>
#include "include/MainWindow.h"

#include "include/dbobjectclass.h"

#include "include/define.h"
#include "include/util/Singleton.h"

using namespace std;

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
  DbObjectClass * db;
 try
  {
    db = new DbObjectClass ( "mir_pgdb");
    Util::Singleton<DbObjectClass>::init( db ) ;

  }
  catch ( std::string & s)
  {
      qDebug() << "Error == " << s.c_str();
  }

  QApplication a(argc, argv);
    MainWindow w( argc > 2 );
    w.show();
    return a.exec();
  return 1;

};
