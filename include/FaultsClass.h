#ifndef FAULTSCLASS_H
#define FAULTSCLASS_H

#include "include/ObjectsUpdater.h"
#include <QList>
#include "include/db/dbFaults.h"

/**
 * @brief The FaultsClass class класс содержащий аварийные устройства
 */
class FaultsClass
{
public:
    /**
     * @brief FaultsClass конструктор
     * @param _objUpd указатель на класс для работы с БД
     */
    FaultsClass( ObjectsUpdater *_objUpd );

    ~FaultsClass( );
    /**
     * @brief update обновить состояния аварий
     */
    void update ();
    /**
     * @brief updateLostFaults обновить состояния пропущенных аварий
     */
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
