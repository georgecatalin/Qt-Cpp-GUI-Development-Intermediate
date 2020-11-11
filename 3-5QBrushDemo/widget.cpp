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
    QPainter myPainter(this);

    //define the QBrush object
    QBrush myBrush;
    myBrush.setColor(Qt::yellow);
    myBrush.setStyle(Qt::SolidPattern);

    //first row
    //myPainter.setBrush(QBrush(Qt::red));
    myPainter.setBrush(myBrush);
    myPainter.drawRect(20,20,100,100);

    myBrush.setColor(Qt::red);
    myBrush.setStyle(Qt::Dense1Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(130,20,100,100);

    myBrush.setColor(Qt::blue);
    myBrush.setStyle(Qt::Dense2Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(240,20,100,100);

    myBrush.setColor(Qt::green);
    myBrush.setStyle(Qt::Dense3Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(350,20,100,100);

    myBrush.setColor(Qt::gray);
    myBrush.setStyle(Qt::Dense4Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(460,20,100,100);

    myBrush.setColor(Qt::lightGray);
    myBrush.setStyle(Qt::Dense5Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(570,20,100,100);

    myBrush.setColor(Qt::darkBlue);
    myBrush.setStyle(Qt::Dense6Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(680,20,100,100);

    myBrush.setColor(Qt::darkRed);
    myBrush.setStyle(Qt::Dense7Pattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(790,20,100,100);

    //this is row 2
    myBrush.setColor(Qt::darkCyan);
    myBrush.setStyle(Qt::HorPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(20,130,100,100);

    myBrush.setColor(Qt::darkRed);
    myBrush.setStyle(Qt::VerPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(130,130,100,100);

    myBrush.setColor(Qt::black);
    myBrush.setStyle(Qt::NoBrush);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(240,130,100,100);

    myBrush.setColor(Qt::darkGray);
    myBrush.setStyle(Qt::CrossPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(350,130,100,100);

    myBrush.setColor(Qt::darkGreen);
    myBrush.setStyle(Qt::BDiagPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(460,130,100,100);

    myBrush.setColor(Qt::yellow);
    myBrush.setStyle(Qt::FDiagPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(570,130,100,100);

    myBrush.setColor(Qt::blue);
    myBrush.setStyle(Qt::DiagCrossPattern);
    myPainter.setBrush(myBrush);
    myPainter.drawRect(680,130,100,100);

    QPixmap myPixmap(":/new/images/images/qt-logo.png");
    myBrush.setTexture(myPixmap.scaled(50,50)); //scale the pixmap image to 50,50 px
    myPainter.setBrush(myBrush);
    myPainter.drawRect(20,240,400,100);
}

