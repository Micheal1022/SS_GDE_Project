#ifndef SENSORITEM_H
#define SENSORITEM_H

#include <QGraphicsItem>
#include <QMouseEvent>
#include <QDebug>
#include <QObject>
class SensorItem : public QGraphicsItem
{
public:
    SensorItem();
    SensorItem(QString info);
    void setItemState(int state);
    int state;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SENSORITEM_H
