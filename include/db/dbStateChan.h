#ifndef BDSTATECHAN_H
#define BDSTATECHAN_H
#include "include/db/dbclass.h"

class BDStateChan
{
public:
    BDStateChan();

    //////////////////////////////////////////////////////////////////////////
    /// \brief The DevStruct struct
    /// структура для описания состояния оборудования объекта
    //////////////////////////////////////////////////////////////////////////
    struct DevStruct
    {
      int index;
      QString name;
      int sost;
      int err;
      bool operator==( const struct DevStruct & left);
      bool operator!=( const struct DevStruct & left);
      struct DevStruct operator=( const struct DevStruct & left);
    };
    typedef struct DevStruct Dev;
    typedef std::vector < Dev> VecDev;

    //////////////////////////////////////////////////////////////////////////
    /// \brief getDev
    /// \param id
    /// \return VecDev
    ///получаем оборудование объекта
    //////////////////////////////////////////////////////////////////////////
    VecDev getDev (int id);
    //////////////////////////////////////////////////////////////////////////
    /// \brief setBlink
    /// \param index объекта
    /// \param bl мигать или нет
    /// \return bool
    /// устанавливаем блинк на кнопке
    //////////////////////////////////////////////////////////////////////////
    bool setBlink (const int &index , const bool &bl );
    ///////////////////////////////////////
    /// \brief getBlink
    /// \param index
    /// \return
    /// получаем мигает ли кнопка
    bool getBlink (const int &index );
private:
    DBClass * db ;
};

#endif // BDSTATECHAN_H
