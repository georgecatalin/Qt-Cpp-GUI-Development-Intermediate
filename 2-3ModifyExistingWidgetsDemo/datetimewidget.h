#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include <QWidget>
#include <QDate>
#include <QTimer>
#include <QLabel>

class DateTimeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DateTimeWidget(QWidget *parent = nullptr);

signals:

private:
    QTimer * myTimer;
    QLabel * myLabelTop;
    QLabel * myLabelBottom;
    QString dateString;
    QString timeString;

private slots:
    void updateTime();

};

#endif // DATETIMEWIDGET_H
