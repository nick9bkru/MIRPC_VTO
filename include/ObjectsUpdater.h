#ifndef OBJECTSUPDATER_H
#define OBJECTSUPDATER_H

#include "include/ObjectClass.h"
#include "include/db/dbMainObject.h"
#include <vector>
#include <QObject>

class ObjectsUpdater : public QObject
{
    Q_OBJECT
    const QString tbl[2] = { "OBJECTS" , "DEVICES" };
    enum table {
        OBJECTS ,
        DEVICES
    };

public:

    ObjectsUpdater();
    ~ObjectsUpdater();
    void updateAll();
    void updateObj(const bool first = false);
  //  ObjType* getObject ( );
    ObjectClass* getObject ( int16_t id);
signals:
    /**
     * @brief loseConnDb игнал о потере связи с БД
     * если true - потерялся, false - нашелся
     */
    void loseConnDb( bool & );
    /**
     * @brief dbConnect
     * сигнал о состоянии соединенеия с БД, если
     * true - есть соединение
     * false - нет соединения
     */
    void dbConnect ( const bool &);
public slots:
    /**
     * @brief devNotify нотифай от изменения таблицы
     * @param name
     */
    void devNotify(  const QString & name  );

    /**
     * @brief objNotify нотифай от изменения таблицы
     * @param name
     */
    void objNotify(  const QString & name  );

    void newStateConn(const bool & b);
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
