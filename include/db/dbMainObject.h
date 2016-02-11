#ifndef DBMAINOBJECT_H
#define DBMAINOBJECT_H

#include "include/db/dbclass.h"
#include <QList>
#include <QString>
#include <QDate>
//////////////////////////////////////////////////
/// \brief The dbMainObject class
///класс для чтения из БД информации о объектах ( MainFrame )
//////////////////////////////////////////////////
class dbMainObject
{
public:
    dbMainObject( DBClass * db );

    //////////////////////////////////////////////////////////////////////////
    /// \brief The ObjStruct struct
    /// структура для описания состояния объктов
    //////////////////////////////////////////////////////////////////////////
    struct ObjStruct
    {
      int id;
      QString name;
      int8_t chng;
     };

    typedef struct ObjStruct Obj;
    typedef std::vector < Obj> VecObj;

    //////////////////////////////////////////////////////////////////////////
    /// \brief getObject
    /// \param id
    /// \return Obj
    ///  получаем состояние состояние объекта
    //////////////////////////////////////////////////////////////////////////
    Obj getObject ( int id );
    //////////////////////////////////////////////////////////////////////////
    /// \brief getObject
    /// \return VecObj
    ///  получаем состояние состояние объекта
    //////////////////////////////////////////////////////////////////////////
    VecObj getObject ( );



    //////////////////////////////////////////////////////////////////////////
    /// \brief The ObjStruct struct
    ///структура для описания состояния оборудования объекта
    //////////////////////////////////////////////////////////////////////////
    struct SObjDev
    {
      int16_t id;
      QString name;
    };
    typedef struct SObjDev ObjDev;
    typedef std::vector < ObjDev> VecObjDev;

    //////////////////////////////////////////////////////////////////////////
    /// \brief getDev
    /// \param id номер объекта
    /// \return VecObjDev
    ///получаем оборудование объекта
    //////////////////////////////////////////////////////////////////////////
    VecObjDev getDev (int id);

    typedef std::vector < int16_t> chngType;
    chngType getChange();

    /**
     * @brief The SFaults struct
     * структура для описания ошибки
     */
    struct SFault
    {
        QDate date;
       int16_t id_obj;
       int16_t id_dev;
       bool operator==(const struct SFault& left);
    };
    typedef struct SFault Fault;
    typedef QList < Fault> FaultsType;
    /**
     * @brief getFaults
     * @return получаем вектор с ошибками
     */
    FaultsType getFaults();
private:
    DBClass * db ;

};

#endif // DBMAINOBJECT_H
