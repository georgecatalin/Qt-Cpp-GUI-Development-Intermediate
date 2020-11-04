#include "watertank.h"
#include <QDebug>
#include <QWheelEvent>

WaterTank::WaterTank(QWidget *parent) : QWidget(parent),
    waterHeight(50),
    myTimer(new QTimer(this))
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));

    myTimer->setInterval(1000);
    connect(myTimer,&QTimer::timeout,[=]()
    {
        waterHeight+=20;
        update();

        qDebug()<<waterHeight;

        //emit signals
        if(waterHeight<=100)
        {
            emit emitNormal();
        }
        else if (waterHeight>=101 && waterHeight<200)
        {
            emit emitWarning();
        }
        else if (waterHeight>=200)
        {
            emit emitDanger();
        }

    });

   myTimer->start();

}

QSize WaterTank::sizeHint() const
{
    return QSize(400,400);
}

void WaterTank::paintEvent(QPaintEvent *event)
{
    //Initialize the QPen Object
    QPen myPen;
    myPen.setWidth(3);
    myPen.setColor(Qt::black);

    //Initialize the QPainter Object
    QPainter myPainter(this);
    myPainter.setPen(myPen);

    //Draw the lines with the QPainter Object = draw the tank
    myPainter.drawLine(10,10,10,300); //this is the left line of the U-like drawing
    myPainter.drawLine(10,300,300,300); //this is the bottom line of the U-like drawing
    myPainter.drawLine(300,10,300,300); //this is the right line of the U-like drawing

    //Draw the water inside the tank
    myPainter.setBrush(Qt::blue);
    myPainter.drawRect(10,300-waterHeight,300-10,waterHeight);
}

void WaterTank::wheelEvent(QWheelEvent *event)
{
    if(event->delta()<0 && waterHeight>10)
    {
        waterHeight-=20; //rotate the mouse wheel to decrease the water level when it exceeds the cylinder drawing
        update();

    }
}
