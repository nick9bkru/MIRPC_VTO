#ifndef OBJECTSUPDATER_H
#define OBJECTSUPDATER_H

#include "include/ObjectClass.h"
#include "include/db/dbMainObject.h"
#include "include/db/dbDevices.h"
#include <vector>
/**
 * @brief The ObjectsUpdater class класс для обновления состояния объектов
 */
class ObjectsUpdater
{

public:
    /**
     * @brief ObjectsUpdater конструктор
     */

    ObjectsUpdater();
    ~ObjectsUpdater();
    /**
     * @brief updateObj обновить объекты
     * @param first - если первый раз, то обновляем все
     */
    void updateObj(const bool first = false);
    /**
     * @brief updateDev обновить устройства
     */
    void updateDev( );
  //  ObjType* getObject ( );
    /**
     * @brief getObject получить указатель на обьект по id
     * @param id
     * @return
     */
    ObjectClass* getObject ( int16_t id) const;
private:
    /**
     * @brief updateObjev обновляем состояния объекта
     * @param obj номер объекта
     */
    void updateObjDev( ObjectClass* obj );
    /**
     * @brief loadNotify загрузить нотифаи
     */
    void loadNotify();
   // typedef QMap< int16_t, ObjectClass* > ObjType;
    typedef std::vector<ObjectClass* > ObjType;
    ObjType Objects;
    dbMainObject * dbObj;
    dbDevices * dbDev;
    /**
     * @brief dbCon соединение с БД
     */
    bool dbCon;
};

#endif // OBJECTSUPDATER_H
