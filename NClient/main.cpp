#include "widget.h"
#include <QApplication>

using namespace NChat;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    a.setStyle("plastique");
    Widget w;
    w.show();
    return a.exec();
}
