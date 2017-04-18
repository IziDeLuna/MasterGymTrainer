#include "addeditdialog.h"
#include "ui_addeditdialog.h"
#include <QDialog>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

//Basic constructor
AddEditDialog::AddEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AddEditDialog) {
    ui->setupUi(this);
    this->setWindowTitle("Add a new Client");
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
    int cid = 0;

    //Set textbox text to variables
    QString firstname = ui->firstNameBox->text();
    QString lastname = ui->lastNameBox->text();
    QString email = ui->emailBox->text();
    QString phone = ui->phoneNumBox->text();

    QSqlQuery cQry;

    cQry.exec("SELECT MAX(cid) FROM customers");

    //Further testing my be needed...
    while (cQry.next()){
        cid = cQry.value(0).toInt();
    }
    //increment eid to store new employee
    cid = cid + 1;

    //Add to employee table
    cQry.prepare("INSERT INTO customers (cid,firstname,lastnametext,phonenum,email)"
                   "VALUES (:cid,:firstname,:lastnametext,:phonenum,:email)");
    cQry.bindValue(":cid",cid);
    cQry.bindValue(":firstname",firstname);
    cQry.bindValue(":lastnametext", lastname);
    cQry.bindValue(":phonenum",phone);
    cQry.bindValue(":email",email);

    //FIXME: cQry fails if duplicate, so this is duplicate detecting code for now
    if(!cQry.exec()){
        qDebug() << "Did not insert into table customers";
        QMessageBox::warning(this, "Warning", "Possible duplicate in employee database");
    }
    else{
        QMessageBox::information(this,"Member","Member added successfully!");
    }
    close();
}
