#ifndef ADDEDITDIALOG_H
#define ADDEDITDIALOG_H

#include <QDialog>

namespace Ui {
class AddEditDialog;
}

class AddEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEditDialog(QWidget *parent = 0);
    ~AddEditDialog();
//    AddEditDialog() {
//        QDialog *addDialog = new QDialog;
//        addDialog->setWindowTitle("Add a new member");
//        QPushButton *addButton = new QPushButton("Add Member", this);
//        connect(addButton, SIGNAL(clicked()), addDialog, SLOT(show));
//    }

private:
    Ui::AddEditDialog *ui;

private slots:

    void on_cancelButton_clicked();
    void on_addCustButton_clicked();
};

#endif // ADDEDITDIALOG_H
