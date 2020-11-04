#include "widget.h"
#include "ui_widget.h"
#include "doubleclickablebutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    DoubleClickableButton * myButton=new DoubleClickableButton(this);
    myButton->setText("Double Clickable Button");

    //set a signal/slot through a lambda function for the moment when double clicking the button
    connect(myButton,&DoubleClickableButton::doubleClicked,this,[=]()
    {
        qDebug()<<" Button double clicked.";
    });
}

Widget::~Widget()
{
    delete ui;
}

