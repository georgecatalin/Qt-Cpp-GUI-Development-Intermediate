#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QDebug>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // PUSHBUTTON_H
