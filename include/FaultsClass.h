#ifndef FAULTSCLASS_H
#define FAULTSCLASS_H

#include "include/ObjectsUpdater.h"
#include <QList>
#include "include/db/dbFaults.h"

class FaultsClass
{
public:
    FaultsClass( ObjectsUpdater *_objUpd );
    void update ();
    void updateLostFaults();
private :
    dbFaults *db;
    typedef dbFaults::FaultsType FaultsType  ;
    FaultsType fault;
    ObjectsUpdater * objUpd;

    typedef dbFaults::LostFaultsType LostFaultsType;
    LostFaultsType lostFault;
};

#endif // FAULTSCLASS_H
