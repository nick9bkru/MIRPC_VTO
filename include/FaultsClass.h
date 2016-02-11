#ifndef FAULTSCLASS_H
#define FAULTSCLASS_H

#include "include/db/dbMainObject.h"
#include "include/ObjectsUpdater.h"
#include <QList>

class FaultsClass
{
public:
    FaultsClass(dbMainObject * _dbMain , ObjectsUpdater *_objUpd);
    void update ();
private :
    dbMainObject *dbMain;
    typedef dbMainObject::FaultsType FaultsType  ;
    FaultsType fault;
    ObjectsUpdater * objUpd;
};

#endif // FAULTSCLASS_H
