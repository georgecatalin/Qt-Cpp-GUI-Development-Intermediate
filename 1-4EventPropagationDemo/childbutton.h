#ifndef CHILDBUTTON_H
#define CHILDBUTTON_H

#include "pushbutton.h"
#include <QDebug>

class ChildButton : public PushButton
{
    Q_OBJECT
public:
    explicit ChildButton(QWidget *parent = nullptr);

signals:


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CHILDBUTTON_H
