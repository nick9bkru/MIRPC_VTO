#ifndef BUTPARENT_H
#define BUTPARENT_H

#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include "include/baseDevice.h"
//#include <QFont>

class ButParent: public QPushButton
{
    Q_OBJECT
public:
    enum CLR //цвет
    {
        GREEN = 0,
        RED,
        GREY,
        DEFAULT
    };
    ButParent(QWidget *parent = 0);
    virtual ~ButParent();
    void setColor( CLR color , bool err = false );
    virtual bool isBlink() const ;
    /**
     * слот для установки текста на кнопке
     */
    void setText (const QString &str);

    CLR getColor () const ;
    void mousePressEvent ( QMouseEvent * e );
    void setFont( const QFont & f);
    QString text () const;
private slots:
    void clickSlot();
signals:
    void changeState( int16_t & );
private :
    QVBoxLayout *layout;
    QLabel *lbl;
    CLR color;
    QString defColor;
protected:
    baseDevice * dev;
    virtual void reactClick();
};

#endif // BUTPARENT_H
