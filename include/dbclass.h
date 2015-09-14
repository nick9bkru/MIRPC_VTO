#ifndef DBCLASS_H
#define DBCLASS_H
#include <string>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>

class DBClass
{
public:
    DBClass( );
    DBClass(QString _dbName , QString _host = "127.0.0.1", QString _user = "root", QString _pass = "rootuser" );
    ~DBClass();
    bool nonSelectSql( QString sqlStr  );
    bool isOpened ();
protected:
    void initDB ();
private:
    QString dbName,
                host,
                user,
                pass;
};

#endif // DBCLASS_H
