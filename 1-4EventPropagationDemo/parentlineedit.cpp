#include "parentlineedit.h"
#include <QKeyEvent>

ParentLineEdit::ParentLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void ParentLineEdit::keyPressEvent(QKeyEvent *event)
{
    qDebug()<< " ParentLineEdit keyPressEvent triggered.";
    qDebug()<< " Verify if ParentLineEdit keyPressEvent is Accepted: "<<event->isAccepted();
    QLineEdit::keyPressEvent(event);
}
