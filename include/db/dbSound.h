#ifndef DBSOUND_H
#define DBSOUND_H

#include "include/db/dbclass.h"
/**
 * @brief The dbSound class
 * Класс читает из БД состояние звука
 */
class dbSound
{
public:
    dbSound(DBClass *_db);
    /**
     * @brief isMute
     * Есть ли звук или нет
     * @return
     *  true - отключен
     *  false - есть звук
     */
    bool isMute();
    static bool isMute(DBClass *db );
private:
    DBClass *db;
};

#endif // DBSOUND_H
