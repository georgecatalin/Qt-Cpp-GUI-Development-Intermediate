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
    QPainter myPainter(this); // Passed the Widget object as a QPainterDevice

    QPen myPen(Qt::blue);
    myPen.setWidth(3);
    myPainter.setPen(myPen);

    //Draw a rectangle
    myPainter.setBrush(Qt::yellow);
    myPainter.drawRect(10,10,100,100);

    // Draw an ellipse
    myPainter.setBrush(Qt::green);
    myPainter.drawEllipse(120,10,200,100);

    //Draw round rectangle
    myPainter.setBrush(Qt::gray);
    myPainter.drawRoundRect(330,10,200,100);

    //Draw Line
    myPainter.drawLine(550,30,650,30);
    myPainter.drawLine(550,50,650,50);
    myPainter.drawLine(550,70,650,70);
    myPainter.drawLine(550,90,650,90);

    myPen.setColor(Qt::black);
    myPainter.setPen(myPen);

    //Draw Line using overload
    /* ***
     * void QPainter::drawLine(const QPointF &p1, const QPointF &p2)
       This is an overloaded function.
       Draws a line from p1 to p2.
       ****
       void QPainter::drawLines(const QVector<QPointF> &pointPairs)
       This is an overloaded function.
       Draws a line for each pair of points in the vector pointPairs using the current pen.
       If there is an odd number of points in the array, the last point will be ignored.
     * *** */

    QVector<QPointF> myVector;

    myVector<<QPointF(660,30)<<QPointF(760,30);
    myVector<<QPointF(660,50)<<QPointF(760,50);
    myVector<<QPointF(660,70)<<QPointF(760,70);
    myVector<<QPointF(660,90)<<QPointF(760,90);

    myPainter.drawLines(myVector);

    //Draw a polygon

    /* ***
     * QPolygonF Class
    The QPolygonF class provides a vector of points using floating point precision.
     * *** */
    QPolygonF myPolygonF;

    myPolygonF<<QPointF(240.0,150.0)<<QPointF(10.0,150.0)<<QPointF(60.0,200.0)<<QPointF(30.0,250.0)<<QPointF(120.0,250.0);
    myPainter.drawPolygon(myPolygonF);

    //Draw Arcs
    QRectF rectangle(250.0,150.0,150.0,150.0);
    int startAngle=30*16;
    int stopAngle=270*16;


    /* ********************
     * void QPainter::drawArc(const QRectF &rectangle, int startAngle, int spanAngle)
     * Draws the arc defined by the given rectangle, startAngle and spanAngle.
     * The startAngle and spanAngle must be specified in 1/16th of a degree, i.e. a full circle equals 5760 (16 * 360).
     * Positive values for the angles mean counter-clockwise while negative values mean the clockwise direction.
     * ZERO degrees is at the 3 o'clock position.
     * **** */

     myPainter.drawArc(rectangle,startAngle,stopAngle);

     //Draw a chord : a chord is an arc with the two endpoints connected

     QRectF myRectangleF(450.0,150.0,150.0,150.0);
     int startAngle1=30*16;
     int endAngle=270*16;
     myPainter.drawChord(myRectangleF,startAngle1,endAngle);

     //Draw a pie
     QRectF myRectangleF_for_Pie(650.0,150.0,150.0,150.0);
     int startAngle_Pie=30*16;
     int endAngle_Pie=270*16;

     /* *****************************************************************
      * void QPainter::drawPie(const QRectF &rectangle, int startAngle, int spanAngle)
      * Draws a pie defined by the given rectangle, startAngle and spanAngle.
      * The pie is filled with the current brush().
      * The startAngle and spanAngle must be specified in 1/16th of a degree, i.e. a full circle equals 5760 (16 * 360).
      * Positive values for the angles mean counter-clockwise while negative values mean the clockwise direction.
      * ZERO degrees is at the 3 o'clock position.
      * **************************************************************** */

     myPainter.drawPie(myRectangleF_for_Pie,startAngle_Pie, endAngle_Pie);

     //Draw Text
     myPen.setColor(Qt::red);
     myPainter.setPen(myPen);

     myPainter.setFont(QFont("Times",20,QFont::Bold));
     myPainter.drawText(50.0,400.0,"I am loving Qt"); //top left corner point of the text stated

     //Draw Pixmap
     //define the target rectangle
     QRectF myRectangleF_for_Pixmap(520.0,350.0,250.0,250.0);
     //define the pixmap
     QPixmap myPixmap(":/new/images/images/cpp-qt.jpg");
     //get the rectangular source portion of the pixmap
     QRect sourceRectangle=myPixmap.rect();

     /* ******************************************
      * void QPainter::drawPixmap(const QRectF &target, const QPixmap &pixmap, const QRectF &source)
      * Draws the rectangular portion source of the given pixmap into the given target in the paint device.
      * ****************************************** */
     myPainter.drawPixmap(myRectangleF_for_Pixmap,myPixmap,sourceRectangle);

}

