#include "include/db/dbSound.h"

dbSound::dbSound(DBClass *_db): db( _db)
{

}

bool dbSound::isMute()
{
   return  isMute ( db );
}


 bool dbSound::isMute( DBClass *db )
{
    db->isOpened ();
    bool buf = false ;

    QSqlQuery query (  "SELECT zvuk from flags;" );

    db->isValid ( query );

    while (query.next())
    {
        buf = query.value( 0 ).toBool();
    }

    return buf;
}
