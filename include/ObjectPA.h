#ifndef OBJECTPA_H
#define OBJECTPA_H

#include <QFrame>

namespace Ui {
class ObjectPA;
}

class ObjectPA : public QFrame
{
    Q_OBJECT

public:
    explicit ObjectPA(QWidget *parent = 0);
    ~ObjectPA();

private:
    Ui::ObjectPA *ui;
};

#endif // OBJECTPA_H
