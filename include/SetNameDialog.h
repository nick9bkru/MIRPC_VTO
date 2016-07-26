#ifndef SETNAMEDIALOG_H
#define SETNAMEDIALOG_H

#include "ui_SetName.h"
/**
 * @brief The SetNameDialog class сохранить название объекта ( не используется )
 */
class SetNameDialog : public QDialog, Ui::SetName
{
  Q_OBJECT
public:
  SetNameDialog( QWidget *parent = 0, QString str = "" );
  ~SetNameDialog ();
private slots:
  void accept ();
  void reject();
  
signals :
  void TextSig( const QString &);
};

#endif // SETNAMEDIALOG_H
