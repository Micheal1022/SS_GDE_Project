#include "sensoritem.h"

#include <QPainter>
#include <QCursor>
#include <QBrush>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#define SIZE_WIDTH  60
#define SIZE_HEIGHT SIZE_WIDTH
#define X_POS   SIZE_WIDTH/12*4
#define Y_POX   SIZE_WIDTH/12*5
#define WIDTH   SIZE_WIDTH/12*5
#define HEIGHT  SIZE_WIDTH/12*3


SensorItem::SensorItem()
{

}

SensorItem::SensorItem(QString info)
{
    state = 0;
    setToolTip(info);
    setCursor(Qt::PointingHandCursor);
    //setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
}

void SensorItem::setItemState(int state)
{
    this->state = state;
    update();

}

QRectF SensorItem::boundingRect() const
{
    return QRectF(0, 0, 70, 70);
}


//#define SOLID

void SensorItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    //绘制图片
    QRect rect(5, 5, SIZE_WIDTH, SIZE_HEIGHT);
    QPixmap pixmap(":/Image/detector.png");
    painter->drawPixmap(rect,pixmap);
    //绘制矩形区域
    QBrush brush;
    if (0 == state) {
        brush.setColor(Qt::green);
    } else if (1 == state) {
        brush.setColor(Qt::yellow);
    } else if (2 == state) {
        brush.setColor(Qt::red);
    } else {
        brush.setColor(Qt::gray);
    }

    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    QRect r(X_POS,Y_POX,WIDTH,HEIGHT);
    painter->drawRect(r);

    // 选中时绘制
    if (option->state & QStyle::State_Selected) {
        // 边框区域颜色
        QColor color = QColor(Qt::black);
#ifdef SOLID
        // 绘制实线
        painter->setPen(QPen(color, 2, Qt::SolidLine));
#else
        // 绘制虚线
        painter->setPen(QPen(color, 2, Qt::DashLine));
#endif
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(boundingRect());
    }
    update();

}

void SensorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //QPointF point = this->pos();
    //qDebug()<<"this  "<<this;
    //qDebug()<<"point "<<point;
    //emit mouseMovePiont(point);
    QGraphicsItem::mouseMoveEvent(event);
}
