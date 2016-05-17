#ifndef BSPURWID_H
#define BSPURWID_H

#include <QWidget>
#include <QVector>
#include "include/ObjectClass.h"
#include "include/db/dbDevices.h"
 #include <QVBoxLayout>
 #include <QHBoxLayout>
 #include <QWidget>
/**
 * @brief The BSPurWid class
 * Класс виджета, отображающий кнопку БС - ПУРа , и его содержание
 */
class BSPurWid : public QWidget
{
    Q_OBJECT


public:
    enum GROUP
    {
        BSPUR = 15,
        PUR = 1,
        PUS = 2
    };
    explicit BSPurWid( dbDevices* _db,  QWidget *parent );
    ~BSPurWid();
    /**
     * @brief refreshWidjet
     * @param id_obj - id объекта
     * @param id - id БС-ПУР
     */
    void refreshWidjet(const int8_t &id_obj, const int8_t &id, const QString &ip);

private:
    /**
     * @brief deleteBut
     * удаляем кнопки с виджета
     */
    void deleteBut();
    ObjectClass * obj;
    dbDevices * db;
    void getBSPUR();
    /**
     * @brief id
     * омер объекта
     */
    int8_t id;

    QVBoxLayout * BSPurLayout;
    QHBoxLayout * PurLayout;
    QWidget * PurWid;
    void addPurButton( const dbDevices::DevVect * vec );
signals:

public slots:

};

#endif // BSPURWID_H
