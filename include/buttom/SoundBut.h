#ifndef SOUNDBUT_H
#define SOUNDBUT_H

#include <QLabel>
#include "include/db/dbSound.h"
class SoundBut : public QLabel
{
    Q_OBJECT
public:
    SoundBut(QWidget * parent = 0);
     ~SoundBut();
public slots:
    /**
     * @brief SoundChange
     * @param sound если true - то звук есть , если false - нет
     */
    void SoundChange ( const bool & sound );
    void SoundChange (  );
private:
    dbSound *db;
};

#endif // SOUNDBUT_H
