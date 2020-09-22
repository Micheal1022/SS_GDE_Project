#include "sensoritem.h"

#include <QPainter>
#include <QCursor>
#include <QBrush>
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#define SIZE_WIDTH  60
#define SIZE_HEIGHT SIZE_WIDTH
#define X_POS   SIZE_WIDTH/12*4
#define Y_POX   SIZE_WIDTH/12*5
#define WIDTH   SIZE_WIDTH/12*5
#define HEIGHT  SIZE_WIDTH/12*3

#define NORMAL  0
#define ERROR   1
#define ALARM   2
#define OFFLINE 3


SensorItem::SensorItem(SensorItemInfo itemInfo, QObject *parent, QGraphicsItem *parent1)
    :QObject(parent),QGraphicsItem(parent1)
{
    m_state = 0;
    m_times = 0;
    m_oldState = 0;
    m_loopStr = itemInfo.m_loopStr;
    m_idStr   = itemInfo.m_idStr;
    m_typeStr = itemInfo.m_typeStr;
    m_areaStr = itemInfo.m_areaStr;
    setScale(itemInfo.m_zoom);
    setPos(itemInfo.m_posX,itemInfo.m_posY);
    setItemType(m_typeStr.toInt());
    setToolTipString();
    setCursor(Qt::PointingHandCursor);
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);

    m_stateTimer = new QTimer;
    QObject::connect(m_stateTimer,SIGNAL(timeout()),this,SLOT(slotStateTimeOut()));
    m_stateTimer->start(500);



}

void SensorItem::setItemState(int state)
{
    m_state = state;
    m_oldState = state;

}

void SensorItem::setItemType(int type)
{
    if (1 == type) {
        m_typeStr = tr("组合式电气火灾探测器");
    } else if (2 == type) {

    }
}

void SensorItem::setToolTipString()
{
    QString toolTipStr1;
    if (m_idStr.toInt() < 10) {
        toolTipStr1 = QString("编号:%1-00%2\n").arg(m_loopStr).arg(m_idStr);
    } else if (m_idStr.toInt() >= 10 && m_idStr.toInt() < 100) {
        toolTipStr1 = QString("编号:%1-0%2\n").arg(m_loopStr).arg(m_idStr);
    } else if (m_idStr.toInt() >= 100) {
        toolTipStr1 = QString("编号:%1-%2\n").arg(m_loopStr).arg(m_idStr);
    }
    QString toolTipStr2 = QString("类型:%1\n").arg(m_typeStr);
    QString toolTipStr3 = QString("区域:%1").arg(m_areaStr);
    setToolTip(toolTipStr1+toolTipStr2+toolTipStr3);
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
    if (NORMAL == m_state) {
        brush.setColor(Qt::green);
    } else if (ERROR == m_state) {
        brush.setColor(Qt::yellow);
    } else if (ALARM == m_state) {
        brush.setColor(Qt::red);
    } else if (OFFLINE == m_state) {
        brush.setColor(Qt::gray);
    } else {
        brush.setColor(QColor(0xA0,0xA0,0xA4,0));
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
}

void SensorItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug()<<"point "<<this->pos();
    QGraphicsItem::mouseMoveEvent(event);
}

void SensorItem::slotStateTimeOut()
{
    m_times++;
    if (m_times == 1) {
        m_state = 5;
    } else if (m_times == 2) {
        m_state = m_oldState;
        m_times = 0;
    }
    update();
}
