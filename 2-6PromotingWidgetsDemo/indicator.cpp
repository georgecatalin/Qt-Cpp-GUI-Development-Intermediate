#include "indicator.h"

Indicator::Indicator(QWidget *parent) : QWidget(parent),
    redActive(false),
    greenActive(false),
    yellowActive(false),
    lightOn(true)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));

    activateNormal();

    myTimer=new QTimer(this);
    myTimer->setInterval(300);
    connect(myTimer,&QTimer::timeout,this,[=]()
    {
        toggleLights();
    });
    myTimer->start();

}

QSize Indicator::sizeHint() const
{
    return QSize(120,350);
}

void Indicator::activateDanger()
{
    redActive=true;
    greenActive=false;
    yellowActive=false;
}

void Indicator::activateNormal()
{
    redActive=false;
    greenActive=true;
    yellowActive=false;
}

void Indicator::activateWarning()
{
    redActive=false;
    greenActive=false;
    yellowActive=true;
}

void Indicator::paintEvent(QPaintEvent *event)
{
   //instantiate the QPen object on the stack
    QPen myPen;
    //set the width of the QPen object
    myPen.setWidth(3);
    //set the color of the QPen object
    myPen.setColor(Qt::black);

    //instantiate the QPaint object on the stack; it will dissapear once it is no longer used
    QPainter myPainter(this);
    //set the pen of the QPainter object on the stack- this is the stroke
    myPainter.setPen(myPen);
    //set the brush of the QPainter object on the stack - this is the fill in
    myPainter.setBrush(Qt::gray);


    //draw with the QPainter object
    myPainter.drawRect(0,0,120,350);

    if (redActive)
    {
        //draw the traffic lights
        myPainter.setBrush((lightOn) ? Qt::red : Qt::black); //set the colour
        myPainter.drawEllipse(10,10,100,100); // set x, y, w, h

        myPainter.setBrush(Qt::black);
        myPainter.drawEllipse(10,115,100,100);

        myPainter.setBrush(Qt::black);
        myPainter.drawEllipse(10,220,100,100);
    }
    else if(greenActive)
    {
        //draw the traffic lights
        myPainter.setBrush(Qt::black); //set the colour
        myPainter.drawEllipse(10,10,100,100); // set x, y, w, h

        myPainter.setBrush((lightOn) ? Qt::green : Qt::black);
        myPainter.drawEllipse(10,115,100,100);

        myPainter.setBrush(Qt::black);
        myPainter.drawEllipse(10,220,100,100);
    }
    else if (yellowActive)
    {
        //draw the traffic lights
        myPainter.setBrush(Qt::black); //set the colour
        myPainter.drawEllipse(10,10,100,100); // set x, y, w, h

        myPainter.setBrush(Qt::black);
        myPainter.drawEllipse(10,115,100,100);

        myPainter.setBrush((lightOn) ? Qt::yellow : Qt::black);
        myPainter.drawEllipse(10,220,100,100);
    }

}

void Indicator::toggleLights()
{
    if (!lightOn)
    {
        lightOn=true;
    }
    else
    {
        lightOn=false;
    }

    /* *** void QWidget::update()
    Updates the widget unless updates are disabled or the widget is hidden.
    * *** */
    update();
}
