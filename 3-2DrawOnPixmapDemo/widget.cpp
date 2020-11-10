#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap myPixmap(width()-5,height()-5);
    myPixmap.fill(Qt::gray);



    QPainter myPainter(&myPixmap);

    QPen myPen(Qt::blue);
    myPen.setWidth(5);

    myPainter.setPen(Qt::white);
    myPainter.setBrush(Qt::yellow);
    myPainter.drawRect(myPixmap.rect());

    myPen.setColor(Qt::blue);
    myPainter.setPen(myPen);
    myPainter.drawRect(50,50,100,100);

    QFont myFont("Consolas",20,QFont::Bold);
    myPainter.setFont(myFont);
    myPainter.drawText(50,320,"I love Qt programming.");

    qDebug()<<"The logical coordinates are: "<<myPainter.window(); //this is used by the QPainter object
    qDebug()<<"The physical coordinates are: "<<myPainter.viewport(); //this is used by the QPaintDevice object

    ui->label->setPixmap(myPixmap);
}

Widget::~Widget()
{
    delete ui;
}

