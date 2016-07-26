#ifndef DBMAINOBJECT_H
#define DBMAINOBJECT_H

#include "include/db/dbclass.h"
#include <QList>
#include <QString>
#include <QDate>

         /**
         * @brief The dbMainObject class класс для чтения из БД информации о объектах ( MainFrame )
         */
class dbMainObject
{
public:
    /**
     * @brief dbMainObject конструктор
     * @param db указатель на калсс работы с БД
     */
    dbMainObject( DBClass * db );

    /**
     * @brief The ObjStruct struct структура для описания состояния объктов
     */
    struct ObjStruct
    {
      int id; /// id
      QString name; ///название
      int8_t chng; ///изменялся ли
      bool reg; ///регламент
      bool fault; /// ошибка
      bool lost_fault; /// пропущеная ошибка
      int8_t active; /// активен ли
     };

    typedef struct ObjStruct Obj;
    typedef std::vector < Obj> VecObj;

    /**
     * @brief getObject получаем состояние состояние объекта
     * @param id id объекта
     * @return
     */
    Obj getObject ( int id );

    /**
     * @brief getObject получаем состояние состояние объекта
     * @return
     */
    VecObj getObject ( );
    /**
     * @brief chngType структура для описания состояния оборудования объект
     */
    typedef std::vector < int16_t> chngType;
    chngType getChange();

private:
    DBClass * db ;

};

#endif // DBMAINOBJECT_H
