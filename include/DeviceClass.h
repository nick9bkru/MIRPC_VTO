#ifndef DEVICECLASS_H
#define DEVICECLASS_H

#include <cstdint>
#include <QString>
#include <QObject>
/**
 * @brief DeviceClass::DeviceClass
 * класс описывающий состояние устройства на объекте
 */
class DeviceClass : public QObject
{
    Q_OBJECT
public:
    DeviceClass( QString _name , int16_t _id = 0);
    int16_t getId() const ;
    QString getName() const;
    bool isAlarm() const;
    void setId( int16_t _id );
    void setName( QString _name );
    void setAlarm ( const bool _alarm);
signals:
    void changeState( int16_t & );
private:
    /**
     * @brief name название устройства
     */
    QString name;
    /**
     * @brief id устройства
     */
    int16_t id;
    /**
     * @brief _alarm авария
     */
    bool alarm;
};

#endif // DEVICECLASS_H
