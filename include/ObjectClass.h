#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

#include "include/DeviceClass.h"
#include "include/baseDevice.h"
#include <QMap>
#include <QObject>
class ObjectClass : public QObject, public baseDevice
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
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    virtual void setName( QString _name ) override;
    /**
     * @brief SetConf ввести в конфигурацию
     * @param ok
     */
    void setConf( bool ok = true);

    bool getConf( ) const ;
    /**
     * @brief emitRefresh если теребуется создает сигнал о перерисовки всего обеъкта
     */
    void emitRefresh()  ;
    /**
     * @brief setAlarmDev установить аварию устройства
     * @param id_dev номер устройства
     * @param alarm true - ключить, false - отключить
     * @return
     */
    bool setAlarmDev( const int16_t id_dev, const bool alarm );


signals:
    void change ( int16_t );
private:
    DevisesType Devices;
    /**
     * @brief conf если true то в конфигурации
     */
    bool conf;

    bool rePaint;
};

#endif // OBJECTCLASS_H
