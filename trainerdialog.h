#ifndef TRAINERDIALOG_H
#define TRAINERDIALOG_H

#include <QDialog>

namespace Ui {
class TrainerDialog;
}

class TrainerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrainerDialog(QWidget *parent = 0);
    ~TrainerDialog();

private slots:
    void on_cancelButton_clicked();

    void on_addTrainerButton_clicked();

private:
    Ui::TrainerDialog *ui;
};

#endif // TRAINERDIALOG_H
