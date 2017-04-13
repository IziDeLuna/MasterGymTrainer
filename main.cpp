#include "loginform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginform window;
    window.show();

    return a.exec();
}
