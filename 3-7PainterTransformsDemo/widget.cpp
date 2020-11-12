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
    QPainter myPainter(this);
    QPen myPen;
    myPen.setWidth(5);

    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200);

    //Rotate the coordinate system and paint the rectangle
    myPainter.translate(200,200); //We do translate the whole coordinate system and not the rectangle
    myPainter.rotate(45);
    myPainter.translate(-200,-200);

    myPen.setColor(Qt::red);
    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200);

    /* **************************************************
     * How to scale
     * ************************************************ */

    //rotate back the coordinate system

    /* *** translate the origin back to the center of rotation, middle of the rectangle *** */
    myPainter.translate(200,200);
    /* *** rotate back as the initially, -45 degrees so *** */
    myPainter.rotate(-45);
    /* *** translate the origin of the canvas back to the upper left corner *** */
    myPainter.translate(-200,-200);

    //scale down
    myPainter.scale(0.6,0.6);

    myPen.setColor(Qt::green);
    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200);

    /* *** scale up *** */
    myPainter.scale(2,2);

    myPen.setColor(Qt::blue);
    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200);


    //How to reset transforms
    myPainter.resetTransform();


    myPen.setColor(Qt::yellow);
    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200); //this should overlay on the original rectangle

    //Shear

    myPainter.translate(200,200);//translate the origin of the canvas
    myPainter.shear(0.5,0.5);//apply the shear
    myPainter.translate(-200,-200); //move back the origin of the canvas

    myPen.setColor(Qt::gray);
    myPainter.setPen(myPen);
    myPainter.drawRect(100,100,200,200);

}

