#include "mymainwindow.h"
#include "judger.h"

#include <QApplication>

Judger judger;

int main(int argc, char *argv[])
{
    judger.judger_main();
    QApplication a(argc, argv);
    myMainWindow w;
    w.show();
    return a.exec();
}
