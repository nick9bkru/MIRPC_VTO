#ifndef UBDATERCLASS_H
#define UBDATERCLASS_H

#include <QObject>
#include "include/db/dbFinder.h"
#include "include/ObjectsUpdater.h"
/**
 * @brief The UbdaterClass class
 * Класс обновляющий все
 */
class UbdaterClass: public QObject
{
    Q_OBJECT
    const QString tbl[3] = { "OBJECTS" , "DEVICES", "TEK_FAULT" };
    enum table {
        OBJECTS ,
        DEVICES ,
        FAULTS
    };
public:
    UbdaterClass();
    ~UbdaterClass();
signals:
    /**
     * @brief dbConnect
     * сигнал о состоянии соединенеия с БД, если
     * true - есть соединение
     * false - нет соединения
     */
    void dbConnect ( const bool &);
public slots:
    /**
     * @brief devNotify нотифай от изменения таблицы DEVICES
     * @param name
     */
    void devNotify(  const QString & name  );

    /**
     * @brief objNotify нотифай от изменения таблицы OBJECTS
     * @param name
     */
    void objNotify(  const QString & name  );
    /**
     * @brief faultNotify нотифай от изменения таблицы TEK_FAULT
     *
     */
    void faultNotify(const QString & );
    /**
     * @brief newStateConn
     * @param b
     */
    void newStateConn(const bool & b);
private:
    ObjectsUpdater * objUpd;
    dbFinder * f;
    /**
     * @brief loadNotify
     * загружаем нотифаи
     */
    void loadNotify();

};

#endif // UBDATERCLASS_H
