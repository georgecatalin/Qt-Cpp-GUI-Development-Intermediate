#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myButton=new Button(this);
    myButton->setText("King sized button");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //define a mouse event below
   QMouseEvent * myMouseEvent=new QMouseEvent(QMouseEvent::MouseButtonPress,QPointF(10,10),Qt::LeftButton,Qt::LeftButton, Qt::NoModifier);


//    //Option 1: send the event
//    if (QApplication::sendEvent(myButton,myMouseEvent))
//    {
//        qDebug()<<"Event accepted";
//    }
//    else
//    {
//        qDebug()<<"Event not accepted";
//    }


    //Option 2:: post the event : in the case of posting the event, the event is placed in a queue waiting for its execution

   QApplication::postEvent(myButton,myMouseEvent);

}
