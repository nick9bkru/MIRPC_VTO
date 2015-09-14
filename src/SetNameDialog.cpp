#include "include/SetNameDialog.h"

SetNameDialog::SetNameDialog(QWidget *parent, QString str ): QDialog( parent ), Ui::SetName()
{
  setupUi( this );
  connect(OkBut, SIGNAL(clicked()), this, SLOT(accept()));
  connect(CanselBut, SIGNAL(clicked()), this, SLOT(reject()));
  NameEdit->setText( str );
};
////////////////////////////////////////////////////////////
SetNameDialog::~SetNameDialog ()
{
  
};


void SetNameDialog::accept ()
{
  emit TextSig( NameEdit->text() );
  QDialog::accept();
};

void SetNameDialog::reject()
{
  QDialog::reject();
};
