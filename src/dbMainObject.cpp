#include "include/dbMainObject.h"
#include "include/dbclass.h"
#include "include/util/Singleton.h"

dbMainObject::dbMainObject()
{
    db = & Util::Singleton<DBClass>::getInstance();
}
