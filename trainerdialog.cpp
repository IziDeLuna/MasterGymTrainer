#include "trainerdialog.h"
#include "ui_trainerdialog.h"
#include <QSqlQuery>
#include <Qdebug>
#include <QMessageBox>

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
    int eid = 0;
    int level = 1;

    QString firstname = ui->firstNameBox->text();
    QString lastname = ui->lastNameBox->text();
    QString username = ui->usernameBox->text();
    QString password = ui->passwordBox->text();

    QSqlQuery trQry;

    trQry.exec("SELECT MAX(eid) FROM userlogin");
    while (trQry.next()){
        eid = trQry.value(0).toInt();
    }

    //Increment eid to store new employee
    eid = eid + 1;

    //Add to trainer table
    trQry.prepare("INSERT INTO trainer (eid,firstname,lastname)"
                  "VALUES (:eid,:firstname,:lastname)");
    trQry.bindValue(":eid",eid);
    trQry.bindValue(":firstname",firstname);
    trQry.bindValue(":lastname",lastname);

    //FIXME: trQry fails if duplicate, so this is duplicate detecting code for now
    if(!trQry.exec()){
        qDebug() << "Did not insert into trainer";
        QMessageBox::warning(this,"Warning", "Possible duplicate in trainer database");
    }

    //Add to userlogin table
    trQry.prepare("INSERT INTO userlogin (eid,username,password,level)"
                  "VALUES (:eid,:username,:password,:level)");
    trQry.bindValue(":eid",eid);
    trQry.bindValue(":username",username);
    trQry.bindValue(":password",password);
    trQry.bindValue(":level",level);

    //FIXME: trQry fails if duplicate, so this is duplicate detecting code for now
    if(!trQry.exec()){
        qDebug() << "Did not insert into userlogin";
        QMessageBox::warning(this,"Warning", "Possible duplicate in userlogin database");
    }
    else{
        QMessageBox::information(this,"Trainer","Trainer added successfully!");
    }
    close();
}
