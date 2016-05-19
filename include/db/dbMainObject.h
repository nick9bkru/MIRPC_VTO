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
      bool reg; //регламент
      bool fault; // ошибка
      bool lost_fault; // пропущеная ошибка
      int8_t active;
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

    typedef std::vector < int16_t> chngType;
    chngType getChange();

private:
    DBClass * db ;

};

#endif // DBMAINOBJECT_H
