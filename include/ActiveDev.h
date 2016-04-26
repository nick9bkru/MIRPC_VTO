#ifndef ACTIVEDEV_H
#define ACTIVEDEV_H

#include "include/db/dbMainObject.h"
#include "include/ObjectsUpdater.h"
#include <QList>

class ActiveDev
{
public:
    ActiveDev(dbMainObject *_dbMain, ObjectsUpdater *_objUpd);
    void update ();
private :
    dbMainObject *dbMain;
    ObjectsUpdater * objUpd;
    typedef dbMainObject::ListActiveType ListActiveType;
    ListActiveType list;
};

#endif // ACTIVEDEV_H
