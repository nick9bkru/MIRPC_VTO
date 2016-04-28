#ifndef BSPURWID_H
#define BSPURWID_H

#include <QWidget>
#include <QVector>
#include "include/ObjectClass.h"
#include "include/db/dbDevices.h"
 #include <QVBoxLayout>
 #include <QHBoxLayout>
 #include <QWidget>
 #include <QPushButton>

class BSPurWid : public QWidget
{
    Q_OBJECT
    enum GROUP
    {
        BSPUR = 15,
        PUR = 1,
        PUS = 2
    };

public:
    explicit BSPurWid( QWidget *parent = 0);
    ~BSPurWid();
    /**
     * @brief refreshWidjet
     * @param id - id БС-ПУР
     */
    void refreshWidjet(const int8_t &id, const QString &ip);

private:
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
