#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include "addeditdialog.h"
#include "trainerdialog.h"

namespace Ui {
    class Calendar;
};


class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = 0);
    private:
    Ui::MainWindow ui;

private:
    QDate getdate();
    QDate currentDate() const;
    void setCurrentDate(const QDate &d);
    void on_calendar_clicked(const QDate &date);
    AddEditDialog *addeditdialog;
    TrainerDialog *addtrainerdialog;

private slots:

    void on_MonthFrontButton_clicked();
    void on_MonthBackButton_clicked();
    void on_exitButton_clicked();
    void on_AddButton_clicked();
    void on_OkButton_clicked();
    void on_trainerButton_clicked();
};

#endif // MAINWINDOW_H
