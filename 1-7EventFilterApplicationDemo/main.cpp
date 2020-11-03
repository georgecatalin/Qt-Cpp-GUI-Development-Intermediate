#include "widget.h"
#include "filter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Widget w;

    Filter * myFilter=new Filter(&w);
    a.installEventFilter(myFilter);

    /* *** now, all events will use the filter implemented in the Filter class.
     * The event will pass or not towards the original destination, depending if return true or false in this filter method
     * *** */


    w.show();
    return a.exec();
}
