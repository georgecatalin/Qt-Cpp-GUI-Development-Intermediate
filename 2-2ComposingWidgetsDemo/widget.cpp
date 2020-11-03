#include "widget.h"
#include "ui_widget.h"
#include "colorpicker.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    /* *** Add the custom made widget to appear on the application widget *** */
    ColorPicker * colorPicker = new ColorPicker(this);
    ui->verticalLayout->addWidget(colorPicker);

    /* *** connect the signal emitted from the colorPicker with the slot in this Widget object *** */
    connect(colorPicker,&ColorPicker::colorChanged,this, &Widget::colorChanged);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::colorChanged(QColor color)
{
    qDebug()<<" The new color is :"<<color.name();
}

