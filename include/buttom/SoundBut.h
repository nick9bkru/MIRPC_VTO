#ifndef SOUNDBUT_H
#define SOUNDBUT_H

#include <QLabel>
#include "include/db/dbSound.h"

/**
 * @brief The SoundBut class класс значка показывающий наличие или отсутсвие звука
 */
class SoundBut : public QLabel
{
    Q_OBJECT
public:
    /**
     * @brief SoundBut конструктор
     * @param parent отец
     */
    SoundBut(QWidget * parent = 0);
     ~SoundBut();
public slots:
    /**
     * @brief SoundChange изменить состояние звука
     * @param sound если true - то звук есть , если false - нет
     */
    void SoundChange ( const bool & sound );
    /**
     * @brief SoundChange изменить состояние звука считанного из БД
     */
    void SoundChange (  );
private:
    dbSound *db;
};

#endif // SOUNDBUT_H