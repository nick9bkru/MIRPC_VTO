#include "include/notConnectionDb.h"
#include "ui_notConnectionDb.h"

notConnectionDb::notConnectionDb(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::notConnectionDb)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

notConnectionDb::~notConnectionDb()
{
    delete ui;
}
