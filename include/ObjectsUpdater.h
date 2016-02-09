#ifndef OBJECTSUPDATER_H
#define OBJECTSUPDATER_H

#include "include/ObjectClass.h"
#include "include/db/dbMainObject.h"
#include <vector>
class ObjectsUpdater
{

public:

    ObjectsUpdater();
    ~ObjectsUpdater();
   // void updateAll();
    void updateObj(const bool first = false);
    void updateDev( );
  //  ObjType* getObject ( );
    ObjectClass* getObject ( int16_t id);
private:
    /**
     * @brief updateObjev обновляем состояния объекта
     * @param obj номер объекта
     */
    void updateObjDev( ObjectClass* obj );

    void loadNotify();
   // typedef QMap< int16_t, ObjectClass* > ObjType;
    typedef std::vector<ObjectClass* > ObjType;
    ObjType Objects;
    dbMainObject * dbObj;
    /**
     * @brief dbCon соединение с БД
     */
    bool dbCon;
};

#endif // OBJECTSUPDATER_H
