#include "filter.h"
#include <QEvent>

Filter::Filter(QObject *parent) : QObject(parent)
{

}

bool Filter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type()==QEvent::MouseButtonPress || event->type()==QEvent::MouseButtonDblClick)
    {
        qDebug()<<"Mouse pressed or mouse double click detected. This message occurs within the event filter which hijacks all events. ";

        //return true;
        /* ********************************************************
         * if true is returned then the event will not be sent to the original destination. It will just stop here
         * if not true, then it will not stop here, event shall pass towards the original destination
         * ******************************************************* */
    }

    return QObject::eventFilter(watched,event);
}
