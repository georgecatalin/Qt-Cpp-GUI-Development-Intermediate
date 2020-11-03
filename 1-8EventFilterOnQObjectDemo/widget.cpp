#include "widget.h"
#include "ui_widget.h"
#include "keyboardfilter.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // this is a version of instantiating directly the KeyboardFilter Class in here
    //ui->lineEdit->installEventFilter(new KeyboardFilter(this));


    /* ***  by declaring a myFilter private variable we will be able to access it elsewhere *** */
    myFilter=new KeyboardFilter(this);

    ui->lineEdit->installEventFilter(myFilter);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->lineEdit->removeEventFilter(myFilter);
}
