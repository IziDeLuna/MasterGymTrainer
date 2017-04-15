#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"

addEmployeeDialog::addEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeDialog)
{
    ui->setupUi(this);
}

addEmployeeDialog::~addEmployeeDialog()
{
    delete ui;
}

void addEmployeeDialog::on_cancelButton_clicked()
{
    close();
}

void addEmployeeDialog::on_addEmployeeButton_clicked()
{

}
