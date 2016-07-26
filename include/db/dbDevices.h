#ifndef DBOBJECTS_H
#define DBOBJECTS_H

#include "include/db/dbclass.h"
#include <QVector>
/**
 * @brief The dbDevices class класс для запроса из БД состояния об устройствах
 */
class dbDevices
{
public:
    /**
     * @brief dbDevices конструктор
     * @param _db класс бд
     */
    dbDevices(DBClass *_db);

    /**
     * @brief The SObjDev struct структура для описания состояния оборудования объекта
     */
    struct SObjDev
    {
      int16_t id;
      QString name;
      bool conf;
      bool frag;
      bool operator==(const struct SObjDev& left);
    };
    typedef struct SObjDev ObjDev;
    typedef QVector < ObjDev> VecObjDev;

    /**
     * @brief getDev получаем оборудование объекта
     * @param id номер объекта
     * @return
     */
    VecObjDev getDev (int id);
    /**
     * @brief The SDevice struct струстура инф об устройстве
     */
    struct SDevice
    {
        int16_t id;
        QString ip;

    };
    typedef SDevice Device;
    typedef QVector <Device> DevVect;
    /**
     * @brief getDevices запрос состояния устройства
     * @param id id устройства
     * @param gr номер группы
     * @return
     */
    DevVect getDevices( int16_t id, int8_t gr);
    /**
     * @brief getPur запросить состояния ПУРА
     * @param gr группа
     * @param ip ip адрес
     * @return
     */
    DevVect getPur (const int8_t &gr, const QString &ip);
private:
    DBClass *db;
};

#endif // DBOBJECTS_H
