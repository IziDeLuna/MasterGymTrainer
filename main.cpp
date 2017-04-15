#include "loginform.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginform window;
    window.show();

    return a.exec();
}
