#ifndef DBFINDER_H
#define DBFINDER_H
#include <QTimer>
#include <QStringList>
#include <QObject>
/**
 * @brief The dbFinder class класс следит за подключением к БД
 */
class dbFinder: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief dbFinder конструктор
     * @param msec период опроса состояния подключения
     */
    dbFinder(int msec = 1000);
    /**
     * @brief start запуск
     */
    void start();
signals:
    /**
     * @brief dbConnect сигнал о том появилось или пропало соединение с БД
     * true - появилась
     * false - пропало
     */
    void dbConnect( const bool & );
private slots:
    void timerSlot();
private:
    QTimer * timer;
    int8_t con;
};

#endif // DBFINDER_H
