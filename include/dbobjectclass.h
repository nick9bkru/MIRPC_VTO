#ifndef DBOBJECTCLASS_H
#define DBOBJECTCLASS_H
#include "include/dbclass.h"
#include <vector>

class DbObjectClass : public DBClass
{
  public:
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
    /// \brief The DevStruct struct
    /// структура для описания состояния оборудования объекта
    //////////////////////////////////////////////////////////////////////////
    struct DevStruct
    {
      QString name;
      int sost;
      bool operator==( const struct DevStruct & left);
      bool operator!=( const struct DevStruct & left);
      struct DevStruct operator=( const struct DevStruct & left);
    };
    typedef struct DevStruct Dev;
    typedef std::vector < Dev> VecDev;

    //////////////////////////////////////////////////////////////////////////
    /// \brief The _StandDev struct
    ///структура для описания состояния оборудования стойки
    //////////////////////////////////////////////////////////////////////////
    struct _StandDev
    {
      QString name;
      int err;
      bool operator==( const struct _StandDev & left);
      bool operator!=( const struct _StandDev & left);
      struct _StandDev operator=( const struct _StandDev & left);
    };
    typedef struct _StandDev StandDev;
    typedef std::vector < StandDev> VecStandDev;
    //////////////////////////////////////////////////////////////////////////
    DbObjectClass( );
    DbObjectClass( QString _dbName , QString _host = "127.0.0.1" );
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
    /// \brief getDev
    /// \param id
    /// \return VecDev
    ///получаем оборудование объекта
    //////////////////////////////////////////////////////////////////////////
    VecDev getDev (int id);
    //////////////////////////////////////////////////////////////////////////
    /// \brief getStandDev
    /// \return VecStandDev
    /// получаем оборудование стойки
    //////////////////////////////////////////////////////////////////////////
    VecStandDev getStandDev( );
  protected:

  private:
};

#endif // DBOBJECTCLASS_H
