#ifndef DBCLASS_H
#define DBCLASS_H
#include <string>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>


class DBClass
{
public:
    DBClass( );
    DBClass(QString _dbName , QString _host = "127.0.0.1", QString _user = "root", QString _pass = "rootuser" );
    ~DBClass();
    bool nonSelectSql( QString sqlStr  );
    bool isOpened ();
    bool isValid( QSqlQuery & query );

    /**
     * @brief createNotify Создаем notify
     * @param notify название
     * @param receiver приемник сигнала
     * @param method слот
     * @return
     */
    static bool createNotify(const QString &notify, const QObject * receiver, const char * method );
protected:
    void initDB ();

private:
    QString dbName,
                host,
                user,
                pass;

};

#endif // DBCLASS_H
