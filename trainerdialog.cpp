#include "trainerdialog.h"
#include "ui_trainerdialog.h"

TrainerDialog::TrainerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainerDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a new Trainer");
}

TrainerDialog::~TrainerDialog()
{
    delete ui;
}

void TrainerDialog::on_cancelButton_clicked()
{
    close();
}

void TrainerDialog::on_addTrainerButton_clicked()
{
    //Add code to add Trainer to database
}
