#ifndef BUTPARENT_H
#define BUTPARENT_H

#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include "include/baseDevice.h"
//#include <QFont>

/**
 * @brief The ButParent class класс родитель всех кнопок
 */
class ButParent: public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief The CLR enum цвет кнопки
     */
    enum CLR //цвет
    {
        GREEN = 0, /// зеленый
        RED,       /// красный
        GREY,      /// зеленый
        WHITE,     ///белый
        YELLOW,    /// желтый
        BLUE,      /// синий
        DEFAULT    /// по умолчанию
    };
    ButParent(QWidget *parent = 0);
    virtual ~ButParent();
    /**
     * @brief setColor установить цвет
     * @param color цвет
     * @param err если true то меняется только цвет кнопки но не переменная color
     */
    void setColor( CLR color , bool err = false );
    /**
     * @brief setSecondColor Установить второй цвет для мигания кнопки
     * @param clr второй цвет
     */
    void setSecondColor( CLR clr );
    /**
     * @brief getSecondColor получить второй цвет
     * @return
     */
    CLR getSecondColor(  ) const ;
    /**
     * @brief isBlink мигать или нет
     * @return
     */
    virtual bool isBlink() const ;
    /**
     * слот для установки текста на кнопке
     */
    virtual void setText (const QString &str);
    /**
     * @brief getColor получить цвет
     * @return
     */
    CLR getColor () const ;
    /**
     * @brief mousePressEvent обработчик мыши
     * @param e
     */
    void mousePressEvent ( QMouseEvent * e );
    /**
     * @brief setFont установить шрифт
     * @param f
     */
    void setFont( const QFont & f);
    /**
     * @brief text получить цвет
     * @return
     */
    QString text () const;
    /**
     * @brief setBorder установить рамку
     * @param b да, нет
     */
    void setBorder( const bool &b );
private slots:
    void clickSlot();
signals:
    /**
     * @brief changeState измнилось состояние кнопки
     */
    void changeState( int16_t & );
private :
    QVBoxLayout *layout;
    QLabel *lbl;
    CLR color;
    QString defColor;
    QString getColotStr( CLR clr );
    CLR secColor;
protected:
    /**
     * @brief dev указатель на класс устройство
     */
    baseDevice * dev;
    /**
     * @brief reactClick реакция на клик мышкой
     */
    virtual void reactClick();
};

#endif // BUTPARENT_H
