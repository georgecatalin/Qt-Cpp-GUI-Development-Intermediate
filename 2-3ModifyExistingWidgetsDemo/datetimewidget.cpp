#include "datetimewidget.h"
#include <QVBoxLayout>

DateTimeWidget::DateTimeWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout * myVBoxLayout=new QVBoxLayout(this);
    QFont myFont("Consolas",20,QFont::Bold);
    QSizePolicy sizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);

    dateString=QDate::currentDate().toString(Qt::TextDate);

    //instantiate the label
    myLabelTop=new QLabel(this);
    //Add text to the label
    myLabelTop->setText(dateString);
    //Add formatting to the label
    myLabelTop->setFont(myFont);
    myLabelTop->setAlignment(Qt::AlignCenter);



    timeString=QTime::currentTime().toString();
    //instantiate the label
    myLabelBottom=new QLabel(this);
    //Add text to the label
    myLabelBottom->setText(timeString);
    //Add formatting to the label
    myLabelBottom->setFont(myFont);
    myLabelBottom->setAlignment(Qt::AlignCenter);
    myLabelBottom->setSizePolicy(sizePolicy);
    QString css=QString("background-color:#00eff9;color:#fffff1");
    myLabelBottom->setStyleSheet(css);

    //Add the labels to the vertical layout widget
    myVBoxLayout->addWidget(myLabelTop);
    myVBoxLayout->addWidget(myLabelBottom);
    //Set the myVBoxLayout to the Widget
    setLayout(myVBoxLayout);
    //Set size policy to the whole widget
    setSizePolicy(sizePolicy);


    //Instantiate the timer object
    myTimer =new QTimer(this);
    //Set the interval in milliseconds
    myTimer->setInterval(1000);
    //Connect signals and slots to simulate time running
    connect(myTimer,&QTimer::timeout,this,&DateTimeWidget::updateTime);

    //start the timer
    myTimer->start();


}

void DateTimeWidget::updateTime()
{
    timeString=QTime::currentTime().toString();
    myLabelBottom->setText(timeString);

    //Change the date if it changes too
    if (dateString!=QDate::currentDate().toString(Qt::TextDate))
    {
        dateString=QDate::currentDate().toString(Qt::TextDate);
        myLabelTop->setText(dateString);
    }
}

