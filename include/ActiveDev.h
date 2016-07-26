#ifndef ACTIVEDEV_H
#define ACTIVEDEV_H

#include "include/db/dbActive.h"
#include "include/ObjectsUpdater.h"
#include <QList>

/**
 * @brief The ActiveDev class
 * Класс содержащий состояние активных устройств
 */
class ActiveDev
{
public:
    /**
     * @brief ActiveDev  Конструктор ActiveDev
     * @param _objUpd указатель на для работы с БД
     */
    ActiveDev( ObjectsUpdater *_objUpd);
    ~ActiveDev();
    /**
     * @brief update
     */
    void update ();
private :
    dbActive *db;
    ObjectsUpdater * objUpd;
    typedef dbActive::ListActiveType ListActiveType;
    ListActiveType list;
};

#endif // ACTIVEDEV_H
