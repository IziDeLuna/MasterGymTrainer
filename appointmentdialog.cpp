#include "appointmentdialog.h"
#include "ui_appointmentdialog.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

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

void appointmentDialog::on_cancelButton_clicked(){
    close();
}

void appointmentDialog::on_addApptButton_clicked(){
    QString cid = ui->custIDBox->text();
    QString eid = ui->employIDBox->text();
    QString date = ui->apptDateBox->text();
    QString time = ui->apptTimeBox->text();
    //QString datetime = date + " " + time;
    QSqlQuery qry;

    //Add to appt table
    qry.prepare("INSERT INTO appt (eid,cid,date,time)"
                "VALUES (:eid,:cid,:date,:time)");
    qry.bindValue(":eid",eid);
    qry.bindValue(":cid",cid);
    //need to find out how to query datetime
    qry.bindValue(":date",date);
    qry.bindValue(":time",time);

    //qry.bindValue(":appdate",date + "/2017 " + time);

    if(!qry.exec()) {
        qDebug() << "Did not insert into table appt";
        QMessageBox::warning(this,"Warning", "Possible Dupliate in database");
    }
    else{
        QMessageBox::information(this,"Employee","Appointment added successfully!");
    }
    close();
}
