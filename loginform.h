#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QDialog>
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

private:
    Ui::loginform *ui;
    //pointer for main window to open
    //MainWindow *mainWindow;
    Calendar *mainWindow;
    //w.show();
};

#endif // LOGINFORM_H
