#ifndef OBJECTCLASS_H
#define OBJECTCLASS_H

#include "include/DeviceClass.h"
#include <QMap>
#include <QObject>
class ObjectClass : public QObject
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
     * @brief setId - установить id
     * @param _id - объекта
     */
    void setId( int16_t _id );
    /**
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    void setName( QString _name );
    /**
     * @brief SetConf ввести в конфигурацию
     * @param ok
     */
    void setConf( bool ok = true);

    bool getConf( ) const ;
    int16_t getId() const ;
    QString getName() const;
    /**
     * @brief emitRefresh если теребуется создает сигнал о перерисовки всего обеъкта
     */
    void emitRefresh()  ;
signals:
    void change ( int16_t );
private:
    DevisesType Devices;
    /**
     * @brief name
     * название объекта
     */
    QString name;
    /**
     * @brief id
     * id объекта
     */
    int8_t id;
    /**
     * @brief conf если true то в конфигурации
     */
    bool conf;

    bool rePaint;
};

#endif // OBJECTCLASS_H
