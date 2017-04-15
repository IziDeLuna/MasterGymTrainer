#include "loginform.h"
#include "ui_loginform.h"

#include <QMessageBox>

loginform::loginform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginform)
{
    ui->setupUi(this);
    this->setWindowTitle("Login");
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
    if(username == "admin" && password == "admin") {
        close();
        mainWindow = new Calendar();
        mainWindow->show();
    }
    else {
        QMessageBox::warning(this, "Login", "Incorrect username and/or password");
    }
}
