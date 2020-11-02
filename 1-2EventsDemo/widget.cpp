#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QMenu>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<" Mouse Pressed Event"<<event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug()<<" Mouse Released Event"<<event->pos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<" Mouse Moved Event"<<event->pos();
}

/* *** This event handler is called with the given event when Qt receives a window close request for a top-level widget from the window system. *** */

void Widget::closeEvent(QCloseEvent *event)
{
    qDebug()<<" Window is about to close.";
    event->accept();
    //event->ignore();
}

void Widget::contextMenuEvent(QContextMenuEvent *event)
{
    qDebug()<< " Context Menu is pressed.";

    /* *** QPoint QWidget::mapToGlobal(const QPoint &pos) const
     * *** Translates the widget coordinate pos to global screen coordinates.
     * *** For example, mapToGlobal(QPoint(0,0)) would give the global coordinates of the top-left pixel of the widget.
     * *** */

    QMenu * myMenu=new QMenu(this);
    myMenu->addAction(tr("First Action"));
    myMenu->addAction(tr("Second Action"));

    myMenu->popup(mapToGlobal(event->pos()));

    qDebug()<<" Context Menu pressed while x coordinate was: "<<event->x()<<" and y coordinate was : "<< event->y();

    /* **************************************************************
     * QContextMenuEvent::reason() const : Returns the reason for this context event.
     * ************************************************************** */

    /* **************************************************************
     * enum QContextMenuEvent::Reason
     * This enum describes the reason why the event was sent.
     * QContextMenuEvent:: Mouse value = 0
     * The mouse caused the event to be sent. Normally this means the right mouse button was clicked, but this is platform dependent.
     * QContextMenuEvent::Keyboard value = 1 The keyboard caused this event to be sent. On Windows, this means the menu button was pressed.
     * QContextMenuEvent::Other 2
     * The event was sent by some other means (i.e. not by the mouse or keyboard).
     * ****************************************************************/


    qDebug()<<" Context Menu was triggered due to: "<<event->reason();
}


/* ************************************************************************
 * QWidget::keyPressEvent(QKeyEvent *event)
 * ************************************************************************ */
void Widget::keyPressEvent(QKeyEvent *event)

{
    qDebug()<<" KeyPressEvent was raised with the following key: "<<event->key()<<" ("<<event->text()<<" )";

    /* *** Detecting key presses with modifiers (Shit, Alt, Control...) *** */

    /*
    if (event->modifiers() & Qt::ShiftModifier)
    {
        qDebug()<<" Key pressed Shift + " << event->text();
    }
    */

    if (event->modifiers() & Qt::ControlModifier)
    {
        qDebug()<< " Key pressed Control + "<< event->text();
    }

    if (event->modifiers() & Qt:: AltModifier)
    {
        qDebug()<< " Key pressed Alt + "<<event->text();
    }

    if (event->modifiers() & Qt::ShiftModifier)
    {
      if(event->key()==Qt::Key_A)
      {
          qDebug()<<" You pressed the A key.";
      }
    }
}




/* ********************************************************
 * QWidget::enterEvent(QEvent *event)
 * An event is sent to the widget when the mouse cursor enters the widget.
 * ******************************************************** */
void Widget::enterEvent(QEvent *event)
{
    qDebug()<<" Enter Event was triggered; Mouse entered the Widget Area";
}




/* *********************************************************
 * QWidget::leaveEvent(QEvent *event)
 * A leave event is sent to the widget when the mouse cursor leaves the widget.
 * ********************************************************* */
void Widget::leaveEvent(QEvent *event)
{
    qDebug()<< " Leave Event was triggered; mouse left the Widget area";
}


/* **********************************************************
 * QWidget::wheelEvent(QWheelEvent *event)
 * ********************************************************** */

void Widget::wheelEvent(QWheelEvent *event)
{

   /* **********************************************************
    * delta() is deprecated not recommended in new code;
    * ********************************************************** */
   qDebug()<<" The WheelEvent was triggered. "<< event->delta();


   /* ***************************************************************
    * QPoint QWheelEvent::pixelDelta() const
    * Returns the scrolling distance in pixels on screen.
    * This value is provided on platforms that support high-resolution pixel-based delta
    * values, such as macOS. The value should be used directly to scroll content on screen.
    * *************************************************************** */
   qDebug()<<" The WheelEvent was triggered. The scrolling distance is:  "<< event->pixelDelta();

   /* ***************************************************************
    * QPoint QWheelEvent::angleDelta() const
    * Returns the relative amount that the wheel was rotated, in eighths of a degree.
    * A positive value indicates that the wheel was rotated forwards away from the user;
    * a negative value indicates that the wheel was rotated backwards toward the user.
    * **************************************************************** */
   qDebug()<<" The WheelEvent was triggered. The angle delta is:  "<< event->angleDelta();


   qDebug()<<" x is "<<event->x()<< " and y is "<<event->y();

   /* ****************************************************************************
    * Qt::Orientation QWheelEvent::orientation() const
    * This function is obsolete.
    * **************************************************************************** */
   qDebug()<<" Orientation is "<<event->orientation();
}

/* *********************************************************************************
 * void QWidget::paintEvent(QPaintEvent *event)
 * Occurs in many situations like: anytime when resizing a widget window, or
 * after minimizing before getting to normal size etc
 * ********************************************************************************** */
void Widget::paintEvent(QPaintEvent *event)
{
    qDebug()<<" paintEvent was triggered.";
}


/* *****************************************************************************
 * void QWidget::resizeEvent(QResizeEvent *event)
 * When resizeEvent() is called, the widget already has its new geometry.
 * The old size is accessible through QResizeEvent::oldSize().
 * ***************************************************************************** */

void Widget::resizeEvent(QResizeEvent *event)
{
    qDebug()<<" QResizeEvent triggered. Old size was :"<<event->oldSize();
    qDebug()<<" QResizeEvent triggered. New size was : "<<event->size();
}

