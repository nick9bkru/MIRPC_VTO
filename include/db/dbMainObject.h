#ifndef DBMAINOBJECT_H
#define DBMAINOBJECT_H

#include "include/db/dbclass.h"
//////////////////////////////////////////////////
/// \brief The dbMainObject class
///класс для чтения из БД информации о объектах ( MainFrame )
//////////////////////////////////////////////////
class dbMainObject
{
public:
    dbMainObject();

    //////////////////////////////////////////////////////////////////////////
    /// \brief The ObjStruct struct
    /// структура для описания состояния объктов
    //////////////////////////////////////////////////////////////////////////
    struct ObjStruct
    {
      int id;
      QString name;
      int sost;
      int err;
      bool operator==( const struct ObjStruct & left);
      bool operator!=( const struct ObjStruct & left);
      struct ObjStruct operator=( const struct ObjStruct & left);
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

private:
    DBClass * db ;
};

#endif // DBMAINOBJECT_H
