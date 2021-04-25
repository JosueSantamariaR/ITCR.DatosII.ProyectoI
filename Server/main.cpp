#include <QApplication>
#include "serverInterface.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverInterface serverWin;
    serverWin.show();
    return a.exec();
}
