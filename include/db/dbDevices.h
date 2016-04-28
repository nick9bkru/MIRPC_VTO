#ifndef DBOBJECTS_H
#define DBOBJECTS_H

#include "include/db/dbclass.h"
#include <QVector>
#include "include/db/dbclass.h"
class dbDevices
{
public:
    dbDevices(DBClass *_db);
    //////////////////////////////////////////////////////////////////////////
    /// \brief The ObjStruct struct
    ///структура для описания состояния оборудования объекта
    //////////////////////////////////////////////////////////////////////////
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
    //////////////////////////////////////////////////////////////////////////
    /// \brief getDev
    /// \param id номер объекта
    /// \return VecObjDev
    ///получаем оборудование объекта
    //////////////////////////////////////////////////////////////////////////
    VecObjDev getDev (int id);

    struct SDevice
    {
        int8_t id;
        QString ip;

    };
    typedef SDevice Device;
    typedef QVector <Device> DevVect;
    DevVect getDevices( int8_t id, int8_t gr);

    DevVect getPur (const int8_t &gr, const QString &ip);
private:
    DBClass *db;
};

#endif // DBOBJECTS_H
