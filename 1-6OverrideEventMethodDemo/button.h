#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QDebug>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = nullptr);

signals:


    // QObject interface
public:
    bool event(QEvent *event) override;
};

#endif // BUTTON_H
