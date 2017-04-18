#include "appointmentdialog.h"
#include "ui_appointmentdialog.h"

appointmentDialog::appointmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::appointmentDialog)
{
    ui->setupUi(this);
}

appointmentDialog::~appointmentDialog()
{
    delete ui;
}
