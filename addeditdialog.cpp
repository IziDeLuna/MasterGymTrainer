#include "addeditdialog.h"
#include "ui_addeditdialog.h"
#include <QDialog>

//Basic constructor
AddEditDialog::AddEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddEditDialog) {
    ui->setupUi(this);
}

//Destructor for the dialog
AddEditDialog::~AddEditDialog() {
    delete ui;
}

//Closes the dialog box
void AddEditDialog::on_cancelButton_clicked() {
    close();
}


void AddEditDialog::on_addCustButton_clicked() {
    //Data inside of here needs to get attached straight
    //to the data base so when added, the customer will show up
    //for future appointments
}
