#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

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
    QPainter myPainter(this); //it is given the Widget object that inherits the QPainterDevice

    QPen myPen; // no style specified. By default it is set to Qt::SolidLine
    myPen.setWidth(3);
    myPen.setColor(Qt::black);

    //set a style for the QPen object
    myPen.setStyle(Qt::SolidLine);

    //set the pen to the myPainter object
    myPainter.setPen(myPen);

    //set the brush to the myPainter object (fill)
    myPainter.setBrush(Qt::green);

    //draw a rectangle
    myPainter.drawRect(10,10,100,100); //this draws a rectangle using the style of pen set to SolidLine


    /* *************************************************
     * Draw a rectangle without outline
     * ************************************************ */

    myPen.setStyle(Qt::NoPen);
    myPainter.setPen(myPen);
    myPainter.drawRect(120,10,100,100);

    /* *** Draw a rectangle with Dotline *** */
    myPen.setStyle(Qt::DotLine);
    myPainter.setPen(myPen);
    myPainter.drawRect(230,10,100,100);

    /* *** Draw a rectangle with dashline *** */
    myPen.setStyle(Qt::DashLine);
    myPainter.setPen(myPen);
    myPainter.drawRect(340,10,100,100);

    /* *** Draw a rectangle with DashDotLine *** */
    myPen.setStyle(Qt::DashDotLine);
    myPainter.setPen(myPen);
    myPainter.drawRect(450,10,100,100);


    /* ***  Draw a rectangle with DashDotDotLine *** */
    myPen.setStyle(Qt::DashDotDotLine);
    myPainter.setPen(myPen);
    myPainter.drawRect(560,10,100,100);

    /* *** Custom dashline *** */
    QVector<qreal> dashes;
    qreal space=4;
    dashes <<1 << space<<3<<space<<9<<space<<27<<space<<9<<space;
    myPen.setDashPattern(dashes);
    myPainter.drawRect(670,10,100,100);


    /* ********************************************
     * Using SetCapStyle()
     *
    Qt::FlatCap 0x00 a square line end that does not cover the end point of the line.
    Qt::SquareCap 0x10 a square line end that covers the end point and extends beyond it by half the line width.
    Qt::RoundCap 0x20 a rounded line end.
     * *******************************************/

    /* *** How to use Qt::FlatCap *** */
    QPoint start(100,150);
    QPoint end(500,150);

    myPen.setWidth(20);
    myPen.setStyle(Qt::SolidLine);
    myPen.setCapStyle(Qt::FlatCap);

    myPainter.setPen(myPen);
    myPainter.drawLine(start,end);

    /* *** How to use Qt::SquareCap *** */
    start.setY(200); //this sets the y of the start point to the value 200
    end.setY(200);

    myPen.setCapStyle(Qt::SquareCap);
    myPainter.setPen(myPen);

    myPainter.drawLine(start,end);

    /* *** How to use Qt::RoundCap *** */
    start.setY(250);
    end.setY(250);

    myPen.setCapStyle(Qt::RoundCap);
    myPainter.setPen(myPen);

    myPainter.drawLine(start,end);

    /* ****************************
     * How to set the join style
     *  Qt::MiterJoin 0x00 The outer edges of the lines are extended to meet at an angle, and this area is filled.
        Qt::BevelJoin 0x40 The triangular notch between the two lines is filled.
        Qt::RoundJoin 0x80 A circular arc between the two lines is filled.
        Qt::SvgMiterJoin 0x100 A miter join corresponding to the definition of a miter join in the SVG 1.2 Tiny specification.
     * ************************** */

    // Use the Qt::Miterjoin

    QPointF myPointArray[4]=
    {
        QPointF(10.0,380.0),
        QPointF(50.0,310.0),
        QPointF(320.0,330.0),
        QPointF(250.0,370.0)
    };

    myPen.setStyle(Qt::SolidLine);
    myPen.setJoinStyle(Qt::MiterJoin);

    myPainter.setPen(myPen);
    myPainter.drawPolygon(myPointArray,4);

    // Use the Qt::BevelJoin
    myPointArray[0].setY(myPointArray[0].y()+200.0);
    myPointArray[1].setY(myPointArray[1].y()+200.0);
    myPointArray[2].setY(myPointArray[2].y()+200.0);
    myPointArray[3].setY(myPointArray[3].y()+200.0);

    myPen.setStyle(Qt::SolidLine);
    myPen.setJoinStyle(Qt::BevelJoin);

    myPainter.setPen(myPen);
    myPainter.setBrush(Qt::yellow);

    myPainter.drawPolygon(myPointArray,4);

    // Use the Qt::RoundJoin
    myPointArray[0].setY(myPointArray[0].y()+200.0);
    myPointArray[1].setY(myPointArray[1].y()+200);
    myPointArray[2].setY(myPointArray[2].y()+200.0);
    myPointArray[3].setY(myPointArray[3].y()+200.0);

    myPen.setStyle(Qt::SolidLine);
    myPen.setJoinStyle(Qt::RoundJoin);

    myPainter.setPen(myPen);
    myPainter.setBrush(Qt::blue);

    myPainter.drawPolygon(myPointArray,4);
}

