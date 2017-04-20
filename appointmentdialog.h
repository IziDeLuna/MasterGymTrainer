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

private slots:
    void on_cancelButton_clicked();

    void on_addApptButton_clicked();

private:
    Ui::appointmentDialog *ui;
};

#endif // APPOINTMENTDIALOG_H
