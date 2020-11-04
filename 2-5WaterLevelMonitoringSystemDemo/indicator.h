#ifndef INDICATOR_H
#define INDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QTimer>

class Indicator : public QWidget
{
    Q_OBJECT
public:
    explicit Indicator(QWidget *parent = nullptr);
     QSize sizeHint() const override;

signals:

public slots:
     void activateDanger(); //red colour
     void activateNormal();// green colour
     void activateWarning(); // yellow colour



protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool redActive;
    bool greenActive;
    bool yellowActive;

    bool lightOn;

    QTimer * myTimer;

    void toggleLights();


};

#endif // INDICATOR_H
