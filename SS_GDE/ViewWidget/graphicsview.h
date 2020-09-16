#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QWidget>
#include <QTimer>
#include "qwgraphicsview.h"
#include <QTableWidget>
namespace Ui {
class GraphicsView;
}

class GraphicsView : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsView(QWidget *parent = 0);
    ~GraphicsView();

private:
    Ui::GraphicsView *ui;
    QGraphicsScene *m_scene;
    void initWidget();
    void initTabelWidget(QTableWidget *tableWidget);
    QTimer *m_timer;
    int m_times;
    qreal m_zoomLevel;

protected:

private slots:

    void slotBtnZoomIn();
    void slotBtnZoomOut();
    void slotBtnRestore();
    void slotBtnRotate();
    void slotTimeout();
    void slotBtnEdit();
    void slotBtnSave();
};

#endif // GRAPHICSVIEW_H
