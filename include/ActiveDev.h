#ifndef ACTIVEDEV_H
#define ACTIVEDEV_H

#include "include/db/dbActive.h"
#include "include/ObjectsUpdater.h"
#include <QList>

class ActiveDev
{
public:
    ActiveDev( ObjectsUpdater *_objUpd);
    void update ();
private :
    dbActive *db;
    ObjectsUpdater * objUpd;
    typedef dbActive::ListActiveType ListActiveType;
    ListActiveType list;
};

#endif // ACTIVEDEV_H
