#ifndef ADDEMPLOYEEDIALOG_H
#define ADDEMPLOYEEDIALOG_H

#include <QDialog>

namespace Ui {
class addEmployeeDialog;
}

class addEmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addEmployeeDialog(QWidget *parent = 0);
    ~addEmployeeDialog();

private slots:
    void on_cancelButton_clicked();

    void on_addEmployeeButton_clicked();

private:
    Ui::addEmployeeDialog *ui;
};

#endif // ADDEMPLOYEEDIALOG_H
