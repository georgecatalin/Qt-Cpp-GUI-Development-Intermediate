#include "pushbutton.h"

PushButton::PushButton(QWidget *parent) : QPushButton(parent)
{

}

void PushButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<" Parent mousePressEvent raised.";
    QPushButton::mousePressEvent(event); // propagate the event to the parent of the PushButton Class which parent is QPushButton Class
}
