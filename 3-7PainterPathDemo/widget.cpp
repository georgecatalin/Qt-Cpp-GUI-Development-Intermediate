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

    QPainterPath myPainterPath;

    myPainterPath.addRect(100,100,100,100);
    //move the nib of the painter to the new location
    myPainterPath.moveTo(150,150);
    myPainterPath.lineTo(150,50);

    /* ******************************************************************************
     * void QPainterPath::arcTo(const QRectF &rectangle, qreal startAngle, qreal sweepLength)
     * Creates an arc that occupies the given rectangle, beginning at the specified startAngle and extending sweepLength degrees.
     * The measuring of sweepLength in degrees is done counter-clockwise
     * 0 degrees is 3 o'clock
     *  **************************************************************************** */

    myPainterPath.arcTo(50,50,200,200,90,90);
    myPainterPath.lineTo(150,150);


    /* *****************************************************************
     * void QPainterPath::setFillRule(Qt::FillRule fillRule)
     * Sets the fill rule of the painter path to the given fillRule.
     * Qt::OddEvenFill 0 ;  Qt::WindingFill 1
     * **************************************************************** */

    myPainterPath.setFillRule(Qt::OddEvenFill);

    myPainter.setBrush(QBrush(Qt::blue));
    myPainter.drawPath(myPainterPath);

    /* ****************************************************
     * Draw the second figure
     * *************************************************** */

    QPainterPath myPainterPath2;

    myPainterPath2.addEllipse(100,220,100,100); //(100,220) is the upper left point, like a rectangle definition
    myPainterPath2.addEllipse(400,220,100,100);

    /* *** Draw the upper line *** */
    //move the nib to the desired position
    myPainterPath2.moveTo(150,220);
    //draw the line to the desired position
    myPainterPath2.lineTo(450,220);


    /* *** Draw the lower line *** */
    //move the nib to the desired position
    myPainterPath2.moveTo(450,320);
    myPainterPath2.lineTo(150,320);

    myPainter.drawPath(myPainterPath2);


    /* *** How to move the whole painterpath object on the screen *** */
    myPainterPath2.translate(150,150);
    myPainter.setBrush(Qt::yellow);
    myPainter.drawPath(myPainterPath2);

}

