#ifndef DBACTIVE_H
#define DBACTIVE_H
#include "include/db/dbclass.h"

/**
 * @brief The dbActive class класс для запроса из БД инф об активности устройства
 */
class dbActive
{
public:
    /**
     * @brief dbActive конструктор
     * @param _db указатель на класс для работы с БД
     */
    dbActive(DBClass *_db);
    /**
     * @brief The SActive struct
     * активные
     */
    struct SActive
    {
        //QDate date;
       int16_t id_obj; /// id объекта
       int16_t id_dev; /// id ecnhjqcndf
       int8_t active; /// активность
       bool operator==(const struct SActive& left);
    };
    typedef struct SActive ActiveType;
    typedef QList < SActive> ListActiveType;
    /**
     * @brief getListActive получить список активных
     * @return
     */
    ListActiveType getListActive();
private:
    DBClass * db ;
};

#endif // DBACTIVE_H
