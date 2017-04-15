#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#include <QLoginForm>
#include "mainwindow.h"

namespace Ui {
class LoginForm;
}

class LoginForm : public QLoginForm
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginForm *ui;
    //pointer for main window to open
    MainWindow *mainWindow;
};

#endif // LOGIN_FORM_H
