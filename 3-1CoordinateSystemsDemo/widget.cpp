#include "widget.h"
#include "ui_widget.h"

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

void Widget::paintEvent(QPaintEvent *event)
{
    QPen myPen(Qt::red);
    myPen.setWidth(3);

    QPainter myPainter(this); //this myPainter object applies to the object Widget
    myPainter.setPen(myPen);

    /* *** QRect QPainter::window() const
    Returns the window rectangle
    * *** */
    qDebug()<<"Logical coordinates: "<<myPainter.window();

    /* *** QRect QPainter::viewport() const
    Returns the viewport rectangle.
    * *** */
    qDebug()<<"Physical coordinates:"<<myPainter.viewport();

    myPainter.drawRect(50,50,100,100);

    //change the logical coordinates, and keep the physical coordinates. What happens?

    /* ***
     * void QPainter::save()
       Saves the current painter state (pushes the state onto a stack).
       A save() must be followed by a corresponding restore();
     * *** */
    myPainter.save();

    myPainter.setWindow(0,0,300,200);
    qDebug()<<"change the logical coordinates, but keep the physical ones. What happens?";
    qDebug()<<"Logical coordinates:"<<myPainter.window();
    qDebug()<<"Physical coordinates:"<<myPainter.viewport();

    myPen.setColor(Qt::green);
    myPainter.setPen(myPen);
    myPainter.drawRect(0,0,100,100);

    myPainter.restore();


    //change the physical coordinates, but keep the logical ones. What happens?
    myPainter.save();


    myPainter.setViewport(0,0,300,200);
    qDebug()<<"change the physical coordinates, but keep the logical ones. What happens?";
    qDebug()<<"Logical coordinates:"<<myPainter.window();
    qDebug()<<"Physical coordinates:"<<myPainter.viewport();
    myPen.setColor(Qt::blue);
    myPainter.setPen(myPen);
    myPainter.drawRect(0,0,100,100);



    myPainter.restore();
}

