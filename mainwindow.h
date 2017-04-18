#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include "addeditdialog.h"
#include "trainerdialog.h"
#include "addemployeedialog.h"

namespace Ui {
    class Calendar;
};


class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar(const QString &userlogin, QWidget *parent = 0);
    private:
    Ui::MainWindow ui;
    //Setting user level
    int getLevel() {return level_id;}
    void setLevel(const int given) {level_id = given;}
    //Setting username
    QString getUserName() { return username; }
    void setusername(const QString login) {username = login; }
    //void nopermission();

private:
    QDate getdate();
    QDate currentDate() const;
    void setCurrentDate(const QDate &d);
    void on_calendar_clicked(const QDate &date);
    AddEditDialog *addeditdialog;
    TrainerDialog *addtrainerdialog;
    addEmployeeDialog *addemployeedialog;


    QString username;
    int level_id;

private slots:

    void on_MonthFrontButton_clicked();
    void on_MonthBackButton_clicked();
    void on_exitButton_clicked();
    void on_AddButton_clicked();
    void on_OkButton_clicked();
    void on_trainerButton_clicked();
    void on_frontButton_clicked();
};

#endif // MAINWINDOW_H
