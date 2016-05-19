#ifndef DBACTIVE_H
#define DBACTIVE_H
#include "include/db/dbclass.h"

class dbActive
{
public:
    dbActive(DBClass *_db);
    /**
     * @brief The SActive struct
     * активные
     */
    struct SActive
    {
        //QDate date;
       int16_t id_obj;
       int16_t id_dev;
       int8_t active;
       bool operator==(const struct SActive& left);
    };
    typedef struct SActive ActiveType;
    typedef QList < SActive> ListActiveType;
    ListActiveType getListActive();
private:
    DBClass * db ;
};

#endif // DBACTIVE_H
