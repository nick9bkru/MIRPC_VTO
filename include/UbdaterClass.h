#ifndef UBDATERCLASS_H
#define UBDATERCLASS_H

#include <QObject>
#include "include/db/dbFinder.h"
#include "include/ObjectsUpdater.h"
#include "include/FaultsClass.h"
#include "include/ActiveDev.h"
/**
 * @brief The UbdaterClass class  Класс следит за обновлением всех состояний в программе
 */
class UbdaterClass: public QObject
{
    Q_OBJECT
    /// массив с названиями нотифаев
    const QString tbl[6] = { "OBJECTS" , "DEVICES", "TEK_FAULT", "MISSED", "ACTPU", "SOUND" };
    /**
     * @brief The table enum отслеживаемые таблицы
     */
    enum table {
        OBJECTS ,
        DEVICES ,
        FAULTS,
        LOSTFAULTS,
        ACTPU,
        SOUND
    };
public:
    /**
     * @brief UbdaterClass конструктор
     */
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
    void Notify(const QString & name );
    /**
     * @brief newStateConn
     * @param b
     */
    void newStateConn(const bool & b);
private:
    ObjectsUpdater * objUpd;
    FaultsClass * faultUpd;
    ActiveDev * activedev;
    dbFinder * f;
    /**
     * @brief loadNotify
     * загружаем нотифаи
     */
    void loadNotify();
signals:
    void ChangeSound();

};

#endif // UBDATERCLASS_H
