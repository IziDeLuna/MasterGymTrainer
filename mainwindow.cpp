#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <QMainWindow>
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QListWidget>
#include <QPixmap>

#include "mainwindow.h"
#include "trainerdialog.h"
#include "addeditdialog.h"
#include "appointmentdialog.h"


//The main function call for this calendar
Calendar::Calendar(const QString &userlogin, QWidget *parent) : QMainWindow(parent), username(userlogin) {
    //ui gets set up
    ui.setupUi(this);
    QPixmap pix("/Users/ismaeldeluna/MasterGymTrainer/logo.jpg");
    ui.logo->setPixmap(pix);

    this->setWindowTitle("MasterGymTrainer");
    QString username = userlogin;
    setusername(username);
    int accesslevel = 0;

    //Query to set accesslevel
    QSqlQuery uqry;
    uqry.exec("SELECT level FROM userlogin WHERE username = '"+username+"'");
    if (uqry.next()) {
        accesslevel = uqry.value(0).toInt();
    }
    setLevel(accesslevel);

    //Calendar widget and signal/listener functions started
    ui.calendarWidget->setNavigationBarVisible(false);
    ui.calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    ui.calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    QObject::connect(ui.MonthBackButton,SIGNAL (clicked()),this,SLOT (on_MonthBackButton_clicked()));
    QObject::connect(ui.MonthFrontButton,SIGNAL (clicked()),this,SLOT (on_MonthFrontButton_clicked()));
    QObject::connect(ui.exitButton,SIGNAL (clicked()),this,SLOT(on_exitButton_clicked()));
}

QDate Calendar::currentDate() const {
    return ui.calendarWidget->selectedDate();
}

void Calendar::setCurrentDate(const QDate &d) {
    QDate date = d;
    if (!date.isValid())
    date = QDate::currentDate();
    ui.calendarWidget->setSelectedDate(date);
    ui.calendarWidget->showSelectedDate();
    on_calendar_clicked(date);
}
//Should be updating datelabel, but waits for listener instead on the widget from
//get date
void Calendar::on_calendar_clicked(const QDate &date) {
    ui.DateLabel->setText(date.toString("dd MMMM yyyy"));
}

//Need to update to where when clicked it'll automatically updates a table
QDate Calendar::getdate () {
    QMessageBox showDateMessage(QMessageBox::Warning, ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"),"",QMessageBox::Ok,0);
    ui.DateLabel->setText(ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));
    showDateMessage.setText("Date Selected is "+ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));

    //QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery uqry,eqry,cqry;
    int eid, cid;
    QString username = getUserName();
    QString schedule;
    QString trainee;
    QString trainer;
    QString date;
    QString combined;
    //QListWidgetItem *newItem = new QListWidgetItem;
    ui.apptList->clear();
    int row = 0;
    date = ui.calendarWidget->selectedDate().toString("MM/dd/yyyy");
    //So far this only works with exact dates, can't figure out how to use date for query
    uqry.prepare("SELECT * FROM appt WHERE date = '4/17/2017'");
    //uqry.bindValue(":dat",date);
    if(!uqry.exec()){
        QMessageBox::warning(this,"Warning","Query did not execute");
    }
    //Put Trainer, Trainee, date, and time
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem->setText("Trainer\tTrainee\tDate\tTime");
    ui.apptList->addItem(newItem);

    while(uqry.next()) {
        eqry.prepare("SELECT firstname FROM trainer WHERE eid = :eid");
        //eid = uqry.value(0).toInt();
        eqry.exec();
        trainer = eqry.value(0).toString();
        uqry.bindValue(":EID", QVariant(trainer));
        if(!eqry.exec())
            qDebug() << "Did not get from trainer table" << endl;


        cqry.prepare("SELECT firstname FROM customers WHERE cid = :cid");
        //cid = uqry.value(1).toInt();
        cqry.exec();
        trainee = cqry.value(1).toString();
        uqry.bindValue(":CID", QVariant(trainee));

        if(!cqry.exec())
            qDebug() << "Did not get from customer table" << endl;


        QListWidgetItem *newItem = new QListWidgetItem;

        //trainee = eqry.value(1).toString() + uqry.value(0).toString() + cqry.value(1).toString();

        //This will display the current database, will only show eid, cid, date, and time
        schedule =  uqry.value(0).toString() +"\t"+ uqry.value(1).toString()  +"\t"+  uqry.value(2).toString() + "\t" +
                 uqry.value(3).toString();
        newItem->setText(schedule);
        ui.apptList->addItem(newItem);
        row++;
    }

    /*
    uqry.prepare("SELECT C.firstname FROM userlogin U, customer C, appdate A WHERE U.username = '"+username+"' AND U.eid = A.eid AND A.cid = C.cid");
    uqry.exec();
    //modal->setQuery(uqry);
    //ui.tableWidget->setModel(modal);
    //QListWidget *apptList = new QListWidget(this);
    if(uqry.next()) {
        QListWidgetItem *newItem = new QListWidgetItem;
        trainee = uqry.value(0).toString();
        //date = uqry.value(1).toString();
        //combined = trainee + " " + date;
        newItem->setText(trainee);
        ui.apptList->addItem(newItem);
        row++;
    }*/



//    login = qry.value(0).toString();
//    newItem->setText(itemText);
//    apptList->insertItem(row, newItem);

    return QDate();
}


//Need to update to move forward only 1 month,
//Curently moves two
void Calendar::on_MonthFrontButton_clicked() {
    int iterator = 1;
    QDate date = currentDate();
    date = date.addMonths(iterator);
    setCurrentDate(date);
}
//Same as month forward, needs updated to do only 1 month at
//a time
void Calendar::on_MonthBackButton_clicked() {
    int subIterator = -1;
    QDate date = currentDate();
    date = date.addMonths(subIterator);
    setCurrentDate(date);
}

void Calendar::on_OkButton_clicked() {
    getdate();
}

void Calendar::on_exitButton_clicked() {
    close();
}
//Calls Add New Member box,
//i.e. ---->addeditdialog

void Calendar::on_AddButton_clicked() {
    int accesslevel = getLevel();
    if ((accesslevel == 2) || (accesslevel == 3)) {
       addeditdialog = new AddEditDialog(this);
       addeditdialog->show();
    } else {
    //do nothing because you don't have permissions
    }
}

void Calendar::on_trainerButton_clicked()
{
    int accesslevel = getLevel();
    if (accesslevel == 3) {
        addtrainerdialog = new TrainerDialog(this);
        addtrainerdialog->show();
    } else {
    //do nothing because you don't have permissions
    }

}

void Calendar::on_frontButton_clicked()
{
    int accesslevel = getLevel();
    if (accesslevel == 3) {
        addemployeedialog = new addEmployeeDialog(this);
        addemployeedialog->show();
    } else {
    //do nothing because you don't have permissions
    }

}

void Calendar::on_schdeuleAppt_clicked()
{
    //FIXME: Add access level code
    appointmentdialog = new appointmentDialog(this);
    appointmentdialog->show();

}

