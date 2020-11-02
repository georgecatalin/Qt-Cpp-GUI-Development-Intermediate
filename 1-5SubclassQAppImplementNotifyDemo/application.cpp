#include "application.h"
#include <QEvent>
#include "widget.h"

Application::Application(int argc, char *argv[]) : QApplication(argc,argv)
{

}

/* *** Application::notify(QObject *, QEvent *) catches all events before being propagated downwards *** */
bool Application::notify(QObject * destination, QEvent * event)
{
    //qDebug()<<"Application notify called";

    /* *** catching the mouse click and double click events) *** */
    if (event->type()==QEvent::MouseButtonPress || event->type()==QEvent::MouseButtonDblClick)
    {
        qDebug()<<"Application detected mouse click or mouse double click. Will not propagate the event any further";

        Widget * myWidget=dynamic_cast<Widget *>(destination);
        if(myWidget)
        {
            qDebug()<<"Cast was successful";
        }
        else
        {
            //it is a nullptr in this case
            qDebug()<<"Cast was not successful";
        }

        // when executing this, the cast will be not successful

        //what is the class name of the destination??

        /* ************************************************
         *  QMetaObject *QObject::metaObject() const
         * Returns a pointer to the meta-object of this object.
         * A meta-object contains information about its class that inherits QObject:
         *  e.g. class name, superclass name, properties, signals and slots....
         * *********************************************** */
         qDebug()<<" Class name of the destination object in the notify() function is :"<<destination->metaObject()->className();

        return false;
    }
    else
    {
    return QApplication::notify(destination,event); // if this is commented then no event propagates down from here, including QPaint() which is ubiquitous
    }

    //return false;
}
