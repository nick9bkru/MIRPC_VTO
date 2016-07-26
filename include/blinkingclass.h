#ifndef BLINKINGCLASS_H
#define BLINKINGCLASS_H
#include <QTimer>
#include <vector>

/**
 * @brief The BlinkingClass class класс отвечает за моргание всех кнопок на экране
 */
class BlinkingClass : public QObject
{
 Q_OBJECT
 public:
    /**
     * @brief BlinkingClass конструктор
     * @param _msec период мигание в мсек
     */
    BlinkingClass( int _msec );
    ~BlinkingClass( );
    /**
     * @brief addFrame добавить фрейм для мигания на нем кнопок
     * @param frame фрейм с кнопками
     */
    void addFrame ( QObject * frame);
 private:
    bool second ;
    QTimer * t;
    std::vector < QObject * > GridFrame;
private slots:
    void blinkingSlot();
};

#endif // BLINKINGCLASS_H
