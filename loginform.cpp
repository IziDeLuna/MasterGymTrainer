#include "loginform.h"
#include "ui_loginform.h"

#include <QMessageBox>
#include <QtCore/QCoreApplication>
#include <QDebug>
#include <iostream>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>

loginform::loginform(QWidget *parent) : QDialog(parent), ui(new Ui::loginform) {
    ui->setupUi(this);
    this->setWindowTitle("Login");
    //Opening up database for user login "QSQLITE",, , "QSQLITE"
    *mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb->setDatabaseName("/Users/ismaeldeluna/MasterGymTrainer/userlogin.db");

    //Checking to see if database will open up or not
    if (!mydb->open()) {
        QMessageBox::warning(this, "Database", "Failed to open database");
    }
    else {
        QMessageBox::warning(this, "Database", "Opened database successfully");
    }
}

loginform::~loginform()
{
    delete ui;
}

void loginform::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    //Needs code here to hide password from others being able to see it
    QString password = ui->lineEdit_password->text();

    //Need to pass this into database to retrieve login and password information
    if (!mydb->open()) {
       qDebug() << "Error: connection with database fail";
       return;
    }

    QSqlQuery qry;
    //QSqlQuery *query = new QSqlQuery(db);
    //QSqlQuery *qry = new QSqlQuery(mydb);
    if (qry.exec("SELECT * FROM userlogin WHERE username = '"+username+"' AND password = '"+password+"'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            QMessageBox::warning(this, "Login", "Username and Password is correct");
            close();
            mainWindow = new Calendar();
            mainWindow->show();
        }
        if (count > 1) {
            QMessageBox::warning(this, "Login", "Duplicate username and/or password");
        }
        if (count < 1) {
            QMessageBox::warning(this, "Login", "Incorrect username and/or password");
        }

    }
}

void loginform::on_exitButton_clicked()
{
    close();
}
