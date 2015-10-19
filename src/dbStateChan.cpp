#include "include/bdstatechan.h"
#include "include/dbclass.h"
#include "include/util/Singleton.h"

BDStateChan::BDStateChan()
{
   db = & Util::Singleton::getInstance();
}
