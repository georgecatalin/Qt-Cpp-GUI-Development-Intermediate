#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("How to draw different stuff with QPaint object");
    w.show();
    return a.exec();
}
