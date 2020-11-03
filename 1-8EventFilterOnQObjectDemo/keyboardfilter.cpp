#include "keyboardfilter.h"
#include <QKeyEvent>

KeyboardFilter::KeyboardFilter(QObject *parent) : QObject(parent)
{

}

bool KeyboardFilter::eventFilter(QObject *watched, QEvent *event)
{
    QString numbers=QString("1234567890");

    if (event->type()==QEvent::KeyPress)
    {
        QKeyEvent * myEvent=static_cast<QKeyEvent *>(event);

        if (numbers.indexOf(myEvent->text())!=-1)
        {
            qDebug()<<" Number filtered out";

            return true; //if returned true it means that the event was handled here, no need to notify the initial destination

            //return  false; //if returned false it means that the event was NOT handled here, hence it will be notified to the initial destination
        }
    }

    return  QObject::eventFilter(watched,event);
}
