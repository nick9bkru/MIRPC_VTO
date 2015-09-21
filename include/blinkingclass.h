#ifndef BLINKINGCLASS_H
#define BLINKINGCLASS_H
#include <QTimer>
#include <vector>

class BlinkingClass : public QObject
{
 Q_OBJECT
 public:
    BlinkingClass( int _msec );
    ~BlinkingClass( );
    void addFrame ( QObject * frame);
 private:
    bool red ;
    QTimer * t;
    std::vector < QObject * > GridFrame;
public slots:
    void blinkingSlot();
};

#endif // BLINKINGCLASS_H
