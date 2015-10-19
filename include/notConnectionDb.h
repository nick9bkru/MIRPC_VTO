#ifndef NOTCONNECTIONDB_H
#define NOTCONNECTIONDB_H

#include <QFrame>

namespace Ui {
class notConnectionDb;
}

class notConnectionDb : public QFrame
{
    Q_OBJECT

public:
    explicit notConnectionDb(QWidget *parent = 0);
    ~notConnectionDb();

private:
    Ui::notConnectionDb *ui;
};

#endif // NOTCONNECTIONDB_H
