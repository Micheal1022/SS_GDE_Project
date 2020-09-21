#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QTimer>
#include "qwgraphicsview.h"
#include <QTableWidget>
#include "sensoriteminfo.h"
#include "udpthread.h"
#include "sensoritem.h"
namespace Ui {
class GraphicsView;
}

class GraphicsView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsView(QWidget *parent = 0);
    ~GraphicsView();
    void confView(QList<SensorItemInfo> itemInfoList, QString IP, QString port, QString &backGroundPath);

private:
    Ui::GraphicsView *ui;
    QGraphicsScene *m_scene;
    void initWidget();
    void initTabelWidget(QTableWidget *tableWidget);
    qreal m_zoomLevel;
    QList<QThread *> m_threadList;
    void setItem(QGraphicsScene *scene, QString loopStr, QString idStr, QString typeStr,QString stateStr);

protected:

private slots:

    void slotBtnZoomIn();
    void slotBtnZoomOut();
    void slotBtnRestore();
    void slotBtnRotate();
    void slotBtnEdit();
    void slotBtnSave();
    void slotHostData(QByteArray hostData);
};

#endif // GRAPHICSVIEW_H
