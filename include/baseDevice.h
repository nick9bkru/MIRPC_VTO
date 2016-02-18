#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include <QString>
class baseDevice
{
public:
    baseDevice();
    /**
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    virtual void setName( QString _name ) = 0;
    virtual bool isAlarm() const;
    virtual int16_t getId() const ;
    virtual QString getName() const;
protected:
    /**
     * @brief name
     * название объекта
     */
    QString name;
    /**
     * @brief alarm
     * есть ли авария
     */
    bool alarm ;
    /**
     * @brief id
     * id объекта
     */
    int16_t id;
};

#endif // BASEDEVICE_H
