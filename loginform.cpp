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

using namespace std;

loginform::loginform(QWidget *parent) : QDialog(parent), ui(new Ui::loginform) {
    ui->setupUi(this);
    this->setWindowTitle("Login");
    //Opening up database for user login "QSQLITE",, , "QSQLITE"
    *mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb->setDatabaseName("/Users/James/Github/MasterGymTrainer/userlogin.db");

    //Checking to see if database will open up or not
    if (!mydb->open()) {
        //QMessageBox::warning(this, "Database", "Failed to open database");
        qDebug() << "Failed to open database";
    }
    else {
        //QMessageBox::warning(this, "Database", "Opened database successfully");
        qDebug() << "Opened database successfully";
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
    if (qry.exec("SELECT * FROM userlogin WHERE username = '"+username+"' AND password = '"+password+"'")) {
        int count = 0;
        while (qry.next()) {
            count++;
        }
        if (count == 1) {
            //QMessageBox::warning(this, "Login", "Username and Password is correct");
            qDebug() << "Username and Password is correct";
            QString login = "";
            qry.exec("SELECT username FROM userlogin WHERE username = '"+username+"' AND password = '"+password+"'");
            if (qry.next()) {
                login = qry.value(0).toString();
            }
            setusername(login);
            close();
            mainWindow = new Calendar(login, this);
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
    hide();
}
