#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <QMainWindow>
#include <QDialog>

#include "mainwindow.h"
#include "addeditdialog.h"

Calendar::Calendar(QWidget *parent) : QMainWindow(parent) {
    ui.setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
    ui.calendarWidget->setNavigationBarVisible(false);
    ui.calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    ui.calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    QObject::connect(ui.MonthBackButton,SIGNAL (clicked()),this,SLOT (on_MonthBackButton_clicked()));
    QObject::connect(ui.MonthFrontButton,SIGNAL (clicked()),this,SLOT (on_MonthFrontButton_clicked()));
    QObject::connect(ui.exitButton,SIGNAL (clicked()),this,SLOT(on_exitButton_clicked()));
}

QDate Calendar::currentDate() const {
    return ui.calendarWidget->selectedDate();
}
void Calendar::setCurrentDate(const QDate &d) {
    QDate date = d;
    if (!date.isValid())
    date = QDate::currentDate();
    ui.calendarWidget->setSelectedDate(date);
    ui.calendarWidget->showSelectedDate();
    on_calendar_clicked(date);
}

void Calendar::on_calendar_clicked(const QDate &date) {
    ui.DateLabel->setText(date.toString("dd MMMM yyyy"));
}

//Need to update to where when clicked it'll automatically updates a table
QDate Calendar::getdate () {
    QMessageBox showDateMessage(QMessageBox::Warning, ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"),"",QMessageBox::Ok,0);
    ui.DateLabel->setText(ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));
    showDateMessage.setText("Date Selected is "+ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));
//    int ret = showDateMessage.exec();
//    if(ret == QMessageBox::Ok) {
//        return ui.calendarWidget->selectedDate();s
//    }
//    else {
//        return QDate();
//    }
}


void Calendar::on_MonthFrontButton_clicked() {
    int iterator = 1;
    QDate date = currentDate();
    date = date.addMonths(iterator);
    setCurrentDate(date);
}

void Calendar::on_MonthBackButton_clicked() {
    int subIterator = -1;
    QDate date = currentDate();
    date = date.addMonths(subIterator);
    setCurrentDate(date);
}

void Calendar::on_OkButton_clicked() {
    getdate();
}

void Calendar::on_exitButton_clicked() {
    close();
}

void Calendar::on_AddButton_clicked() {
    addeditdialog = new AddEditDialog(this);
    addeditdialog->show();
}











