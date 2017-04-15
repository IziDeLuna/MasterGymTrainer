#include "addeditdialog.h"
#include "ui_addeditdialog.h"
#include <QDialog>

AddEditDialog::AddEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddEditDialog) {
    ui->setupUi(this);
}

AddEditDialog::~AddEditDialog() {
    delete ui;
}

void AddEditDialog::on_cancelButton_clicked() {
    close();
}


void AddEditDialog::on_addCustButton_clicked() {

}
