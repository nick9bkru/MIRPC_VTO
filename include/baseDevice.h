#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include <QObject>
#include <QString>
class baseDevice : public QObject
{
    Q_OBJECT
public:

    enum CONST_ACTIVE
    {
        NOACTIVE = 0,
        ACTIVE = 1,
        CONNECT = 2
    };

    baseDevice();
    virtual ~baseDevice();
    /**
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    virtual void setName( QString _name );
    virtual bool isAlarm() const;
    virtual void setAlarm (const bool al, const bool newf = false );
    virtual int16_t getId() const ;
    virtual QString getName() const;
    virtual bool getConf() const;
    /**
     * @brief SetConf ввести в конфигурацию
     * @param ok
     */
    virtual void setConf( const bool ok );
    virtual bool isClicked() const;
    virtual void setClicked( const bool cli );
    virtual bool isBlink() const;
    virtual void setBlink( const bool bli ) ;
    virtual void setlostAlarm( const bool lErr );
    virtual bool islostAlarm() const;
    virtual bool isNewErr() const ;
    /**
     * @brief setActive становить активность
     * @param active
     */
    void setActive(const int8_t active );
    /**
     * @brief isActive активно ли ?
     * @return
     */
    CONST_ACTIVE isActive() const;
    /**
     * @brief setReg становить регламент
     * @param active
     */
    void setReg(const bool reg );
    /**
     * @brief isReg регламент ли ?
     * @return
     */
    bool isReg() const;
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

    /**
     * @brief newf новое или нет ошибка
     */
    bool newf;

    /**
     * @brief reg регламент
     */
    bool reg;
    /**
     * @brief active ктивность
     */
    CONST_ACTIVE active ;

};

#endif // BASEDEVICE_H
