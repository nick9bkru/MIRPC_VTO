#ifndef DBFINDER_H
#define DBFINDER_H
#include <QTimer>
#include <QStringList>
#include <QObject>
class dbFinder: public QObject
{
    Q_OBJECT
public:
    dbFinder(int msec = 1000);
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
