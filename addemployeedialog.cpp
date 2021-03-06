#include "addemployeedialog.h"
#include "ui_addemployeedialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

addEmployeeDialog::addEmployeeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEmployeeDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add a new Employee");
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
    int eid = 0;
    int level = 2;

    QString firstname = ui->firstNameBox->text();
    QString lastname = ui->lastNameBox->text();
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    QSqlQuery emQry;

    emQry.exec("SELECT MAX(eid) FROM userlogin");
    //Further testing my be needed...
    while (emQry.next()){
        eid = emQry.value(0).toInt();
    }
    //increment eid to store new employee
    eid = eid + 1;

    //Add to employee table
    emQry.prepare("INSERT INTO employee (eid,firstname,lastname)"
                   "VALUES (:eid,:firstname,:lastname)");
    emQry.bindValue(":eid",eid);
    emQry.bindValue(":firstname",firstname);
    emQry.bindValue(":lastname", lastname);

    //FIXME: emQry fails if duplicate, so this is duplicate detecting code for now
    if(!emQry.exec()){
        qDebug() << "Did not insert into table employee";
        QMessageBox::warning(this, "Warning", "Possible duplicate in employee database");
    }

    //Insert into userlogin table
    emQry.prepare("INSERT INTO userlogin (eid,username,password,level)"
                  "VALUES (:eid,:username,:password,:level)");
    emQry.bindValue(":eid",eid);
    emQry.bindValue(":username",username);
    emQry.bindValue(":password",password);
    emQry.bindValue(":level",level);

    //FIXME: emQry fails if duplicate, so this is duplicate detecting code for now
    if(!emQry.exec()){
        qDebug() << "Did not insert into table userlogin";
        QMessageBox::warning(this, "Warning", "Possible duplicate in username database");
    }
    else{
        QMessageBox::information(this,"Employee","Employee added successfully!");
    }
    close();
}
