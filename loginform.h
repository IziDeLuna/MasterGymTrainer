#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
#include <QtCore/QString>
#include <QtSql/QSqlDatabase>
#include "mainwindow.h"

namespace Ui {
class loginform;
}

class loginform : public QDialog
{
    Q_OBJECT

public:
    explicit loginform(QWidget *parent = 0);
    ~loginform();

private slots:
    void on_pushButton_Login_clicked();

    void on_exitButton_clicked();

private:
    Ui::loginform *ui;
    QSqlDatabase *mydb = new(QSqlDatabase);
    Calendar *mainWindow;
};

#endif // LOGINFORM_H
