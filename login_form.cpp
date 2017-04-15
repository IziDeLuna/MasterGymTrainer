#include "login_form.h"
#include "ui_login_form.h"
#include <QMessageBox>
#include <QPixmap>

LoginForm::LoginForm(QWidget *parent) :
    QLoginForm(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    //Need to pass this into database to retrieve login and password information
    if(username == "admin" && password == "admin") {
        QMessageBox::information(this, "Login", "Username and password is correct");

        mainWindow = new MainWindow(this);
        mainWindow->show();
    }
    else {
        QMessageBox::warning(this, "Login", "Incorrect username and/or password");
    }
}
