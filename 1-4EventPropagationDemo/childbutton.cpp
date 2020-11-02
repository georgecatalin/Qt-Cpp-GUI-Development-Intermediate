#include "childbutton.h"

ChildButton::ChildButton(QWidget *parent) : PushButton(parent)
{

}

void ChildButton::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<" Child mousePressEvent triggered.";
    PushButton::mousePressEvent(event); //propagate the event to the parent class which is called PushButton
}
