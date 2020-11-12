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

    QLinearGradient myLinearGradient(QPointF(70,20),QPointF(70,170));
    myLinearGradient.setColorAt(0,Qt::red);

    //add a color between the colors [0]  and [1]
    myLinearGradient.setColorAt(0.5,Qt::gray);

    myLinearGradient.setColorAt(1,Qt::yellow);

    //how to set what happens after the transition of the color is completed in the gradient
    /* *******************************************************************************
     *
     * enum QGradient::Spread   Specifies how the area outside the gradient area should be filled.
     * Constant Value Description
     * QGradient::PadSpread 0 The area is filled with the closest stop color. This is the default.
     * QGradient::RepeatSpread 2 The gradient is repeated outside the gradient area.
     * QGradient::ReflectSpread 1 The gradient is reflected outside the gradient area.
     * *********************************************************************************** */


    //myLinearGradient.setSpread(QGradient::PadSpread); //this is the default
    //myLinearGradient.setSpread(QGradient::RepeatSpread);
    myLinearGradient.setSpread(QGradient::ReflectSpread);

    QBrush myBrush(myLinearGradient);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(20,20,100,300);
    myPainter.drawLine(QPointF(70,20),QPointF(70,170));

    /* *********************************************************************************************
     * How to set a radial gradient
     * ******************************************************************************************** */
     QRadialGradient myRadialGradient(QPointF(280,170),75);
     myRadialGradient.setColorAt(0,Qt::yellow);
     myRadialGradient.setColorAt(1,Qt::blue);

     /* ****************************************************************************************
      * QRadialGradient(qreal cx, qreal cy, qreal radius)
      * *************************************************************************************** */

     /* ****************************************************************************************
      * How to set the spread: what happens after transition to the new color finished
      * myRadialGradient.setSpread(QGradient::PadSpread); //this is the default behaviour
      * myRadialGradient.setSpread(QGradient::RepeatSpread);//this repeats the same transition of colours over and over again
      * myRadialGradient.setSpread(QGradient::ReflectSpread); //this makes another gradients in mirror like
      * **************************************************************************************** */

    QBrush myRadialBrush(myRadialGradient);
    myPainter.setBrush(myRadialBrush);
    myPainter.drawRect(130,20,300,300);



    /* ***********************************************************************************************
     * How to set a conical gradient
     * ********************************************************************************************* */
    QConicalGradient myConicalGradient(QPointF(600,170),90);

    /* *******************************************************************
     * QConicalGradient(const QPointF &center, qreal angle): 0 degrees is 3 o'clock
     * The QPointF class defines a point in the plane using floating point precision.
     * The QPoint class defines a point in the plane using integer precision.
     * ******************************************************************* */

    myConicalGradient.setColorAt(0,Qt::blue);
    myConicalGradient.setColorAt(1,Qt::yellow);

    QBrush myConicalBrush(myConicalGradient);
    myPainter.setBrush(myConicalBrush);
    myPainter.drawEllipse(450,20,300,300);
}

