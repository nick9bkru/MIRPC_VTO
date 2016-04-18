#ifndef BASEDEVICE_H
#define BASEDEVICE_H
#include <QObject>
#include <QString>
class baseDevice : public QObject
{
    Q_OBJECT
public:
    baseDevice();
    /**
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    virtual void setName( QString _name );
    virtual bool isAlarm() const;
    virtual void setAlarm (const bool al );
    virtual int16_t getId() const ;
    virtual QString getName() const;
    virtual bool getConf() const;
    virtual bool isClicked() const;
    virtual void setClicked( const bool cli );
    virtual bool isBlink() const;
    virtual void setBlink( const bool bli ) ;
    virtual void setlostErr( const bool lErr );
    virtual bool islostErr();
protected:
    virtual void emitSigChange() = 0 ;
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

    /**
     * @brief click
     * Если кликали на кнопку то true
     */
    bool click;

    /**
     * @brief conf если true то в конфигурации
     */
    bool conf;

    /**
     * @brief blink игать или нет
     */
    bool blink;

    /**
     * @brief lErr ропущенная ошибка
     */
    bool lErr;

};

#endif // BASEDEVICE_H
