#include "include/ObjectPA.h"
#include "ui_ObjectPA.h"

ObjectPA::ObjectPA(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ObjectPA)
{
    ui->setupUi(this);
}

ObjectPA::~ObjectPA()
{
    delete ui;
}
