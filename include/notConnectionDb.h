#ifndef NOTCONNECTIONDB_H
#define NOTCONNECTIONDB_H

#include <QFrame>

namespace Ui {
class notConnectionDb;
}

/**
 * @brief The notConnectionDb class окно появляющееся если пропадает связь с БД
 */
class notConnectionDb : public QFrame
{
    Q_OBJECT

public:
    /**
     * @brief notConnectionDb конструктор
     * @param parent отец
     */
    explicit notConnectionDb(QWidget *parent = 0);
    ~notConnectionDb();

private:
    Ui::notConnectionDb *ui;
};

#endif // NOTCONNECTIONDB_H
