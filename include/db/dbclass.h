#ifndef DBCLASS_H
#define DBCLASS_H
#include <string>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QDebug>
#include <QSqlError>

/**
 * @brief The DBClass class класс для работы с бозой данных
 */
class DBClass
{
public:
    /**
     * @brief DBClass конструктор для singleton
     */
    DBClass( );
    /**
     * @brief DBClass конструктор
     * @param _dbName имя БД
     * @param _host ip адрус хоста
     * @param _user пользователь
     * @param _pass пароль
     */
    DBClass(QString _dbName , QString _host = "127.0.0.1", QString _user = "root", QString _pass = "rootuser" );
    ~DBClass();
    /**
     * @brief nonSelectSql запрос
     * @param sqlStr сторка запроса
     * @return
     */
    bool nonSelectSql( QString sqlStr  );
    /**
     * @brief isOpened открыто ли ?
     * @return
     */
    bool isOpened ();
    /**
     * @brief isValid правильно ли закончилось выполнения запроса
     * @param query
     * @return
     */
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
