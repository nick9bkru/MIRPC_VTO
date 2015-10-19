#ifndef BUTPARENT_H
#define BUTPARENT_H

#include <QPushButton>
#include <QMouseEvent>

class ButParent: public QPushButton
{
    Q_OBJECT
public:
    enum CLR //цвет
    {
        GREEN = 0,
        RED,
        GREY
    };
    ButParent(QWidget *parent = 0);
    void setColor( CLR color , bool err = false );
    void setError( bool b = true );
    bool isErr () const ;
    bool isBlink() const ;
    void setBlink ( bool on = true );
    /**
     * слот для установки текста на кнопке
     */
    void setText (const QString &str);

    CLR getColor () const ;
    void mousePressEvent ( QMouseEvent * e );
private :
    CLR color;
    //ошибка
    bool err ;
    //нажата или нет
    bool blink ;
};

#endif // BUTPARENT_H
