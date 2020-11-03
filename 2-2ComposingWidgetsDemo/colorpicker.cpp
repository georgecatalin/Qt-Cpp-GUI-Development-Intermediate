#include "colorpicker.h"
#include <QVBoxLayout>
#include <QPushButton>


ColorPicker::ColorPicker(QWidget *parent) : QWidget(parent)
{
    populateColors();
    setupUI();
}

QColor ColorPicker::getMyColor() const
{
    return myColor;
}

void ColorPicker::setMyColor(const QColor &value)
{
    myColor = value;
}

void ColorPicker::button1Clicked()
{
    QString css=QString("background-color: %0").arg(myColorList.at(0).name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList.at(0));
}

void ColorPicker::button2Clicked()
{
    QString css=QString("background-color: %0").arg(myColorList.at(1).name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList.at(1));
}

void ColorPicker::button3Clicked()
{
    QString css=QString("background-color:%0").arg(myColorList[2].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[2]);

}

void ColorPicker::button4Clicked()
{
    QString css =QString("background-color=: %0").arg(myColorList[3].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[3]);
}

void ColorPicker::button5Clicked()
{
    QString css=QString("background-color:%0").arg(myColorList[4].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[4]);
}

void ColorPicker::button6Clicked()
{
    QString css=QString("background-css:%0").arg(myColorList[5].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[5]);
}

void ColorPicker::button7Clicked()
{
    QString css=QString("background-color:%0").arg(myColorList[6].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[6]);
}

void ColorPicker::button8Clicked()
{
    QString css = QString("background-color: %0").arg(myColorList[7].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[7]);
}

void ColorPicker::button9Clicked()
{
    QString css=QString("background-color: %0").arg(myColorList[8].name());
    myLabel->setStyleSheet(css);

    emit colorChanged(myColorList[8]);
}

void ColorPicker::populateColors()
{
    myColorList<<Qt::red<<Qt::green<<Qt::blue<<Qt::cyan<<Qt::darkRed<<Qt::darkGray<<Qt::gray<<Qt::yellow<<Qt::darkYellow;
}

void ColorPicker::setupUI()
{
    QVBoxLayout * vBoxLayout=new QVBoxLayout(this);
    gLayout= new QGridLayout(this);

    /* *** he QSizePolicy class is a layout attribute describing horizontal and vertical resizing policy. *** */
    QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);

    /* *** Place the button on the UI *** */
    QPushButton * button1 = new QPushButton("one", this);
    button1->setSizePolicy(sizePolicy);

    QString css1=QString("background-color: %0").arg(myColorList.at(0).name());
    button1->setStyleSheet(css1);

    connect(button1,&QPushButton::clicked,this,&ColorPicker::button1Clicked);


    /* *** this is button 2 *** */
    QPushButton * button2=new QPushButton("two", this);
    button2->setSizePolicy(sizePolicy);
    QString css2=QString("background-color: %0").arg(myColorList.at(1).name());
    button2->setStyleSheet(css2);

    connect(button2,&QPushButton::clicked,this,&ColorPicker::button2Clicked);

    /* *** this is button 3 *** */
    QPushButton * button3=new QPushButton("three",this);
    button3->setSizePolicy(sizePolicy);
    QString css3=QString("background-color: %0").arg(myColorList.at(2).name());
    button3->setStyleSheet(css3);

    connect(button3,&QPushButton::clicked, this, &ColorPicker::button3Clicked);


    /* *** this is button 4 *** */
    QPushButton * button4=new QPushButton("four", this);
    button4->setSizePolicy(sizePolicy);
    QString css4=QString("background-color:%0").arg(myColorList.at(3).name());
    button4->setStyleSheet(css4);

    connect(button4,&QPushButton::clicked,this,&ColorPicker::button4Clicked);

    /* *** this is button 5 *** */
    QPushButton * button5=new QPushButton("five", this);
    button5->setSizePolicy(sizePolicy);
    QString css5=QString("background-color:%0").arg(myColorList.at(4).name());
    button5->setStyleSheet(css5);

    connect(button5,&QPushButton::clicked, this, &ColorPicker::button5Clicked);

    /* *** this is button 6 *** */
    QPushButton * button6= new QPushButton("six", this);
    button6->setSizePolicy(sizePolicy);
    QString css6=QString("background-color:%0").arg(myColorList.at(5).name());
    button6->setStyleSheet(css6);

    connect(button6,&QPushButton::clicked,this,&ColorPicker::button6Clicked);

    /* *** this is button 7 *** */
    QPushButton * button7=new QPushButton("seven",this);
    button7->setSizePolicy(sizePolicy);
    QString css7=QString("background-color:%0").arg(myColorList.at(6).name());
    button7->setStyleSheet(css7);

    connect(button7,&QPushButton::clicked, this, &ColorPicker::button7Clicked);

    /* *** this is button 8 *** */
    QPushButton *  button8=new QPushButton("eight", this);
    button8->setSizePolicy(sizePolicy);
    QString css8=QString("background-color:%0").arg(myColorList.at(7).name());
    button8->setStyleSheet(css8);

    connect(button8,&QPushButton::clicked, this, &ColorPicker::button8Clicked);

    /* *** this is button 9 *** */
    QPushButton * button9=new QPushButton("nine", this);
    button9->setSizePolicy(sizePolicy);
    QString css9=QString("background-color:%0").arg(myColorList.at(8).name());
    button9->setStyleSheet(css9);

    connect(button9,&QPushButton::clicked,this, &ColorPicker::button9Clicked);

    /* ***  Add the buttons to the grid layout 3x3 *** */
    gLayout->addWidget(button1,0,0);
    gLayout->addWidget(button2,0,1);
    gLayout->addWidget(button3,0,2);

    gLayout->addWidget(button4,1,0);
    gLayout->addWidget(button5,1,1);
    gLayout->addWidget(button6,1,2);

    gLayout->addWidget(button7,2,0);
    gLayout->addWidget(button8,2,1);
    gLayout->addWidget(button9,2,2);

    /* *** Add the label above which will contain the settings *** */
    myLabel=new QLabel("Color");
    QString myLabelCss=QString("background-color: #eeeab6");
    myLabel->setStyleSheet(myLabelCss);
    myLabel->setFixedHeight(50);

    /* *** Add the label to the layout *** */
    vBoxLayout->addWidget(myLabel);
    vBoxLayout->addLayout(gLayout);
}
