#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "mainwindow.h"

namespace Ui {
    class Calendar;
};


class Calendar : public QDialog
{
    Q_OBJECT

public:
    explicit Calendar(QWidget *parent = 0);
    //~Calendar();
    private:
    Ui::MainWindow ui;

private:
    QDate getdate();
    QDate currentDate() const;
    void setCurrentDate(const QDate &d);
    void on_calendar_clicked(const QDate &date);

private slots:

    void on_MonthFrontButton_clicked();
    void on_MonthBackButton_clicked();

//void on_yearBackButton_clicked();
// void on_yearFrontButton_clicked();

void on_OkButton_clicked();
};

#endif // MAINWINDOW_H
