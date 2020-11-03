#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    /* *** the following code will only be executed if the event propagates downwards to its original destination.
     * Check the sketch image in the project
     * *** */

    qDebug()<<"This is executed at the button destination. It is the original destination, beyond QObject.";
}
