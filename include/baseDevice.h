#ifndef BASEDEVICE_H
#define BASEDEVICE_H

#include <QObject>
#include <QString>
/**
 * @brief The baseDevice class базовый класс устройства
 */
class baseDevice : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief The CONST_ACTIVE enum вид активности
     */
    enum CONST_ACTIVE
    {
        NOACTIVE = 0, /// не активно
        ACTIVE = 1,   /// активно
        CONNECT = 2   ///в соединении
    };

    /**
     * @brief baseDevice конструктор baseDevice
     */
    baseDevice();
    virtual ~baseDevice();
    /**
     * @brief setName - установить имя
     * @param _name - имя объекта
     */
    virtual void setName( QString _name );
    /**
     * @brief isAlarm есть ли авария
     * @return true - есть, false - нет
     */
    virtual bool isAlarm() const;
    /**
     * @brief setAlarm установить аварию
     * @param al - авария
     * @param newf новое или нет ошибка
     */
    virtual void setAlarm (const bool al, const bool newf = false );
    /**
     * @brief getId получить id
     * @return id
     */
    virtual int16_t getId() const ;
    /**
     * @brief getName получить название
     * @return название
     */
    virtual QString getName() const;
    /**
     * @brief getConf в конфигурации или нет
     * @return true - да, false - нет
     */
    virtual bool getConf() const;
    /**
     * @brief SetConf ввести в конфигурацию
     * @param ok true - ввести, false - вывести
     */
    virtual void setConf( const bool ok );
    /**
     * @brief isClicked нажимали ли на кнопку
     * @return  true - да, false - нет
     */
    virtual bool isClicked() const;
    /**
     * @brief setClicked установить нажатие
     * @param cli true - да, false - нет
     */
    virtual void setClicked( const bool cli );
    /**
     * @brief isBlink мигает ли кнопка
     * @return true - да, false - нет
     */
    virtual bool isBlink() const;
    /**
     * @brief setBlink установить  мигание кнопки
     * @param bli
     */
    virtual void setBlink( const bool bli ) ;
    /**
     * @brief setlostAlarm
     * @param lErr
     */
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
     * @return true - да, false - нет
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
