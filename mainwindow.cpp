#include <QCalendarWidget>
#include <QDate>
#include <QApplication>
#include <QMessageBox>

#include "mainwindow.h"

Calendar::Calendar(QWidget *parent) : QDialog(parent) {
 ui.setupUi(this);
 setWindowFlags(Qt::FramelessWindowHint);
 ui.calendarWidget->setNavigationBarVisible(false);
 ui.calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
 ui.calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

// QObject::connect(ui.yearBackButton,SIGNAL (clicked()),this,SLOT (on_yearBackButton_clicked()));
// QObject::connect(ui.yearFrontButton,SIGNAL (clicked()),this,SLOT (on_yearFrontButton_clicked()));
 QObject::connect(ui.MonthBackButton,SIGNAL (clicked()),this,SLOT (on_MonthBackButton_clicked()));
 QObject::connect(ui.MonthFrontButton,SIGNAL (clicked()),this,SLOT (on_MonthFrontButton_clicked()));

//QObject::connect(ui.OkButton,SIGNAL (clicked()),this,SLOT (on_OkButton_clicked()));

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

QDate Calendar::getdate ()
{
 QMessageBox showDateMessage(QMessageBox::Warning,
 ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"),"",QMessageBox::Ok,0);
 ui.DateLabel->setText(ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));
 showDateMessage.setText("Date Selected is "+ui.calendarWidget->selectedDate().toString("dd MMMM yyyy"));
 int ret = showDateMessage.exec();
 if(ret == QMessageBox::Ok)
 {

accept();
 return ui.calendarWidget->selectedDate();

}
 else
 {
 return QDate();
 }

}
//void Calendar::on_yearBackButton_clicked() {
// QDate date = currentDate();

//date = date.addYears(–1);
// setCurrentDate(date);
//}

//void Calendar::on_yearFrontButton_clicked() {
// QDate date = currentDate();
// date = date.addYears(+1);
// setCurrentDate(date);
//}

void Calendar::on_MonthFrontButton_clicked() {
 QDate date = currentDate();
 date = date.addMonths(+1);
 setCurrentDate(date);
}

void Calendar::on_MonthBackButton_clicked()
{
 QDate date = currentDate();
 date = date.addMonths(-1);
 setCurrentDate(date);
}

void Calendar::on_OkButton_clicked()
{
 getdate();
}
