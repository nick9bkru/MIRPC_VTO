#ifndef DBFAULTS_H
#define DBFAULTS_H
#include "include/db/dbclass.h"
#include <QDate>
/**
 * @brief The dbFaults class класс для запроса из бд состояния об ошибках
 */
class dbFaults
{
public:
    /**
     * @brief dbFaults конструктор
     * @param _db указатель на класс работы с БД
     */
    dbFaults(DBClass *_db);

    /**
     * @brief The SFaults struct
     * структура для описания ошибки
     */
    struct SFault
    {
        QDate date;
       int16_t id_obj;
       int16_t id_dev;
       bool newf;
       bool operator==(const struct SFault& left);
    };
    typedef struct SFault Fault;
    typedef QList < Fault> FaultsType;
    /**
     * @brief getFaults
     * @return получаем вектор с ошибками
     */
    FaultsType getFaults();
    /**
     * @brief The SLostFault struct
     * структура для описания пропущенной ошибки
     */
    struct SLostFault
    {
        QDate date;
       int16_t id_obj;
       int16_t id_dev;
       bool operator==(const struct SLostFault& left);
    };
    typedef struct SLostFault LostFault;
    /**
     * @brief LostFaultsType
     * контейнер с пропущеными ошибками
     */
    typedef QList < LostFault> LostFaultsType;
    /**
     * @brief getLostFaults
     * @return получаем вектор с пропущенными ошибками
     */
    LostFaultsType getLostFaults();
private:
    DBClass *db;
};

#endif // DBFAULTS_H
