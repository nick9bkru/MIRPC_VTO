#ifndef OTHERDEVWID_H
#define OTHERDEVWID_H

#include <QWidget>
#include <QVBoxLayout>
#include "include/db/dbDevices.h"
#include "include/ObjectClass.h"

/**
 * @brief The OtherDevWid class виджет для остальных устройств (сревера комутаци,KCC ,
 * ШСС1,ШСС2, ШСС3 ,ШСС4)
 */
class OtherDevWid : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief The GROUP enum группы устройсв
     */
    enum GROUP
    {
        KC = 5,  ///сревера комутации
        KLS = 6, ///KCC
        SHSS1 = 8,  ///ШСС1
        SHSS2 = 9,  ///ШСС2
        SHSS3 = 10,  ///ШСС3
        SHSS4 = 11  ///ШСС4
    };
    /**
     * @brief OtherDevWid rjycnhernjh
     * @param _db класс БД
     * @param _id id
     * @param _gr группа
     * @param parent родитель
     */
    explicit OtherDevWid( dbDevices* _db,int16_t _id , GROUP _gr,  QWidget *parent );
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
