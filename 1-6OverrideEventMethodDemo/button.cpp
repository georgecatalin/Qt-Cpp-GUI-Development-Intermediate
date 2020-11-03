#include "button.h"
#include <QEvent>
#include <QPushButton>

Button::Button(QWidget *parent) : QPushButton(parent)
{

}

bool Button::event(QEvent *event)
{
    if (event->type()==QEvent::MouseButtonPress || event->type()==QEvent::MouseButtonDblClick)
    {
        qDebug()<<"Mouse pressed or mouse double click detected.";

        //return true; //this hijacks the normal propagation of the event to the parent, in this case the QPushButton class and its signal/slots

    }

    return  QPushButton::event(event);
}
