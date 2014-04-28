#include <QtGui/QApplication>
#include "wresistors.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    wResistors w;
    w.show();
    return a.exec();
}
