#include "loginform.h"
#include "ui_loginform.h"

#include <QMessageBox>

loginform::loginform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginform)
{
    ui->setupUi(this);
}

loginform::~loginform()
{
    delete ui;
}

void loginform::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //Need to pass this into database to retrieve login and password information
    if(username == "admin" && password == "admin") {
        mainWindow = new Calendar(this);
        mainWindow->show();
//        Calendar w;
//        w.show();
    }
    else {
        QMessageBox::warning(this, "Login", "Incorrect username and/or password");
    }
}
