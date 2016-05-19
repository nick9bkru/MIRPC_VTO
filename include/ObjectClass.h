#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

#include "include/DeviceClass.h"
#include "include/baseDevice.h"
#include "include/db/dbMainObject.h"
#include <QMap>

class ObjectClass : public baseDevice
{
     Q_OBJECT
public:
    typedef QMap< int16_t , DeviceClass* > DevisesType ;

    ObjectClass(QString _name , int16_t _id );

    DevisesType* getDevices( );
    /**
     * @brief getDevice - получить устройство
     * @param _name - имя устройства
     * @return - указатель на устройство
     */
    DeviceClass* getDevice(const int16_t _id );
    /**
     * @brief setDevice - внести устройство в объект
     * @param _name - имя устройства
     * @param _dev - устройство
     */
    void setDevice( const int16_t _id , DeviceClass* _dev);
    /**
     * @brief removeDevices
     * удалить все девайсы
     */
    void removeDevices();

    /**
     * @brief emitRefresh если теребуется создает сигнал о перерисовки всего обеъкта
     */
    void emitRefresh()  ;
    /**
     * @brief setAlarmDev установить аварию устройства
     * @param id_dev номер устройства
     * @param alarm true - ключить, false - отключить
     * @param newf - true то кнопка красная , false - расная рамка
     * @return
     */
    bool setAlarmDev(const int16_t id_dev, const bool alarm , const bool newf = false );
    /**
     * @brief setActive сделать устройство активным
     * @param id_dev
     * @param active
     * @return
     */
    bool setActiveDev ( const int16_t id_dev, const int8_t active);
    /**
     * @brief setLostAlarmDevпотерянная авария
     * @param id_dev номер устройства
     * @param alarm true - ключить, false - отключить
     * @return
     */
    bool setLostAlarmDev( const int16_t id_dev, const bool alarm);
protected:
    virtual void emitSigChange() ;

signals:
    void changeState ( int16_t );
private slots:

private:
    DevisesType Devices;


    bool rePaint;
};

#endif // OBJECTCLASS_H
