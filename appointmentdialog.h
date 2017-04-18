#ifndef APPOINTMENTDIALOG_H
#define APPOINTMENTDIALOG_H

#include <QDialog>

namespace Ui {
class appointmentDialog;
}

class appointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit appointmentDialog(QWidget *parent = 0);
    ~appointmentDialog();

private:
    Ui::appointmentDialog *ui;
};

#endif // APPOINTMENTDIALOG_H
