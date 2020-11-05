#ifndef WATERTANK_H
#define WATERTANK_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class WaterTank : public QWidget
{
    Q_OBJECT
public:
    explicit WaterTank(QWidget *parent = nullptr);
    QSize sizeHint() const override;

    int waterHeight;
    QTimer * myTimer;

signals:
    void emitDanger();// Red line >=300
    void emitWarning();// Yellow line >=201 & <300
    void emitNormal();// Green line <200

protected:
    void paintEvent(QPaintEvent *event) override;

    // QWidget interface
protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // WATERTANK_H
