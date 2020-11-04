#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Indicator * myIndicatorWidget=new Indicator(this);
    WaterTank * tankWidget=new WaterTank(this);


    //connect the signals from the water tank widget with the slots from the indicator
    connect(tankWidget,&WaterTank::emitDanger,myIndicatorWidget,&Indicator::activateDanger);
    connect(tankWidget,&WaterTank::emitWarning,myIndicatorWidget,&Indicator::activateWarning);
    connect(tankWidget,&WaterTank::emitNormal,myIndicatorWidget,&Indicator::activateNormal);

   ui->horizontalLayout->addWidget(tankWidget);
   ui->horizontalLayout->addWidget(myIndicatorWidget);

}

Widget::~Widget()
{
    delete ui;
}

