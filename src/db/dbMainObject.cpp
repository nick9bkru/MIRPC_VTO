#include "include/db/dbMainObject.h"
#include "include/util/Singleton.h"

dbMainObject::dbMainObject()
{
    db = & Util::Singleton<DBClass>::getInstance();
};

dbMainObject::Obj dbMainObject::getObject ( int id )
{
    Obj ret;
    db->isOpened ();
    QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err   from  all_object where index = %1 order by index ;" ).arg( id ) );
    db->isValid ( query );
    ret.id = query.value(0).toInt();
    ret.name = query.value(1).toString();
    ret.sost = query.value(2).toInt();
    ret.err = query.value(3).toInt();
    return ret;
};

dbMainObject::VecObj dbMainObject::getObject ( )
{

    VecObj ret;
    Obj buf;
    db->isOpened ();

    QSqlQuery query ( QString ( "select index, name_obj,sost_obj, err  from  all_object order by index ;" ));
    db->isValid ( query );
    while (query.next())
    {
        buf.id = query.value(0).toInt();
        buf.name = query.value(1).toString();
        buf.sost = query.value(2).toInt();
        buf.err = query.value(3).toInt();
        ret.push_back( buf );
    }
    return std::move( ret );
};

//////////////////////////////////////////////////////////////////////////
bool dbMainObject::Obj::operator!=( const dbMainObject::Obj & left)
{
 return !(* this == left );
};

bool dbMainObject::Obj::operator==( const dbMainObject::Obj & left)
{
 bool b = ( left.id == id ) && ( left.name == name ) && ( left.sost == sost ) && (err == left.err);
 return b ;
};

dbMainObject::Obj dbMainObject::Obj::operator=( const dbMainObject::Obj & left)
{
   id= left.id;
   name=left.name;
   sost = left.sost;
   err = left.err;
  return *this;
};

