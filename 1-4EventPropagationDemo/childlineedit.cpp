#include "childlineedit.h"
#include <QKeyEvent>

ChildLineEdit::ChildLineEdit(QWidget *parent) : ParentLineEdit(parent)
{

}

void ChildLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<<" ChildLineEdit keyPressEvent triggered.";
    qDebug()<<" Verify if ChildLineEdit keyPressEvent is Accepted: "<<event->isAccepted();

    event->ignore(); //the event will be ignored after propagation to the parent (Line 24)


    if (event->key()==Qt::Key_C)
    {
        qDebug()<<"You pressed the C key. Fuck off, alligator.";
        clear();
    }
    else
    {
        ParentLineEdit::keyPressEvent(event);
    }
}
