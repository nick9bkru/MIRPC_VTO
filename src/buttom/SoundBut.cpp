#include "include/buttom/SoundBut.h"
#include <QPixmap>
#include "include/util/Singleton.h"
#include <QDebug>

SoundBut::SoundBut(QWidget *parent) : QLabel ( parent )
{
 qDebug() << "@@@@@@@@@@@@@@@@ SoundBut";
     Q_INIT_RESOURCE(imageresourse);
 // setStyleSheet("");
 setScaledContents(  true );

//setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
 db = new dbSound ( &Util::Singleton<DBClass>::getInstance() );
 SoundChange ( db->isMute() );
}


SoundBut::~SoundBut()
{
    Q_CLEANUP_RESOURCE(imageresourse);

}

void SoundBut::SoundChange ( const bool & sound )
{
    QPixmap pix;
    if ( sound )
    {
        pix.load( ":/image/ON_SOUND" );
    } else
        {
         pix.load( ":/image/OFF_SOUND" );
        }
    setPixmap( pix.scaled(width(),height() ,Qt::KeepAspectRatio,Qt::SmoothTransformation) );

};

void SoundBut::SoundChange (  )
{
   SoundChange ( db->isMute() );
};
