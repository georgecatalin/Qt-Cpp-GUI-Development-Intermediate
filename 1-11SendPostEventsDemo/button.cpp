#include "button.h"
#include <QDebug>
#include <QMouseEvent>

Button::Button(QWidget *parent) : QPushButton(parent)
{

}

void Button::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<"My Button: Mouse pressed at position: "<< event->pos();
    QPushButton::mousePressEvent(event); // propagate the event to the parent so that signals and slots are made available
}

void Button::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<"My Button: Mouse Released at position: "<<event->pos();
    QPushButton::mousePressEvent(event); //propagate the event to the parent so that signals and slots are made available
}

void Button::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"My Button: Mouse double clicked at position: "<<event->pos();
    QPushButton::mouseDoubleClickEvent(event);
}
