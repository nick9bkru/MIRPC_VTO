#ifndef FRAMEBORDER_H
#define FRAMEBORDER_H

#include <QFrame>

/**
 * @brief The FrameBorder class просто фрейм для отрисовки
 */
class FrameBorder : public QFrame
{
    Q_OBJECT
public:
    explicit FrameBorder(QWidget* parent = 0):QFrame(parent) {};

signals:

public slots:

};

#endif // FRAMEBORDER_H
