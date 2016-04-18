#ifndef DEVICECLASS_H
#define DEVICECLASS_H

#include <cstdint>
#include <QString>
#include "include/baseDevice.h"

/**
 * @brief DeviceClass::DeviceClass
 * класс описывающий состояние устройства на объекте
 */
class DeviceClass : public baseDevice
{
    Q_OBJECT
public:
    DeviceClass( QString _name , int16_t _id = 0);
    void setId( int16_t _id );
    virtual void setName( QString _name ) override;
signals:
    void changeState( int16_t & );
private:
    bool getConf( ) const override;
protected:
    virtual void emitSigChange() ;
};

#endif // DEVICECLASS_H
