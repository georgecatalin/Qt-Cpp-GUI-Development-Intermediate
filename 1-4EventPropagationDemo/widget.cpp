#include "widget.h"
#include "ui_widget.h"
#include "childbutton.h"
#include "childlineedit.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ChildButton * myChild=new ChildButton(this);
    myChild->setText("Child Button");

    ui->verticalLayout->addWidget(myChild);

    // the slot/signal happens at the QPushButton level
    connect(myChild,&ChildButton::clicked,[=]()
    {
        qDebug()<<" Mouse pressed";
    });

    ChildLineEdit * myChildLineEdit=new ChildLineEdit(this);

    ui->verticalLayout->addWidget(myChildLineEdit);
}

Widget::~Widget()
{
    delete ui;
}

