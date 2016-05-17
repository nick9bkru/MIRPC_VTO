#ifndef OTHERDEVWID_H
#define OTHERDEVWID_H

#include <QWidget>
#include <QVBoxLayout>
#include "include/db/dbDevices.h"
#include "include/ObjectClass.h"

class OtherDevWid : public QWidget
{
    Q_OBJECT
public:
    enum GROUP
    {
        KC = 5,  //сревера комутации
        KLS = 6, //KCC
        SHSS1 = 8,  //ШСС1
        SHSS2 = 9,  //ШСС2
        SHSS3 = 10,  //ШСС3
        SHSS4 = 11  //ШСС4
    };
    explicit OtherDevWid( dbDevices* _db,int8_t _id , GROUP _gr,  QWidget *parent );
    ~OtherDevWid();

signals:

public slots:
private:
    void refreshBut();
    void deleteBut();
    QVBoxLayout * butLayout;
    dbDevices * db;
    int id;
    GROUP gr;
    ObjectClass * obj;
};

#endif // OTHERDEVWID_H
