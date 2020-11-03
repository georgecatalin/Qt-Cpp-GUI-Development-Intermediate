#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>
#include <QColor>
#include <QGridLayout>
#include <QLabel>

class ColorPicker : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPicker(QWidget *parent = nullptr);

    QColor getMyColor() const;
    void setMyColor(const QColor &value);

signals:
    void colorChanged(QColor newColor);

public slots:
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();


private:
    QColor myColor;
    QList<QColor> myColorList;
    QGridLayout * gLayout;
    QLabel * myLabel;

    void populateColors();
    void setupUI();

};

#endif // COLORPICKER_H
