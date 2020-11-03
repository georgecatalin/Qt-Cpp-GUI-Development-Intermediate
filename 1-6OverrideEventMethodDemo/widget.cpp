#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Button * myButton=new Button(this);
    myButton->setText("this button");


    ui->verticalLayout->addWidget(myButton);

    //this is executed only if the event is propagated from the Button Class object to the parent
    connect(myButton,&Button::clicked,[=]()
         {
          qDebug()<<"Button was pressed and this comes from the signal/slot";

         });

}

Widget::~Widget()
{
    delete ui;
}

