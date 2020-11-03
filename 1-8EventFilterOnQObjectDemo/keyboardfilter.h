#ifndef KEYBOARDFILTER_H
#define KEYBOARDFILTER_H

#include <QObject>
#include <QDebug>

class KeyboardFilter : public QObject
{
    Q_OBJECT
public:
    explicit KeyboardFilter(QObject *parent = nullptr);

signals:


    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // KEYBOARDFILTER_H
