#ifndef DBSTANDDEVICE_H
#define DBSTANDDEVICE_H
#include "include/db/dbclass.h"

///////////////////////////////////////////////////////
/// \brief The dbStandDevice class
/// класс для чтения из БД информации об оборудовании стойки ( rigthWidget )
class dbStandDevice
{
public:
    dbStandDevice();
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
    /// \brief getStandDev
    /// \return VecStandDev
    /// получаем оборудование стойки
    //////////////////////////////////////////////////////////////////////////
    VecStandDev getStandDev( );
    VecStandDev getCPU ();
private:
    DBClass * db ;
};

#endif // DBSTANDDEVICE_H
