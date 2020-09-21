#include "graphicsview.h"
#include "sensoritem.h"
#include "ui_graphicsview.h"
#include <QGraphicsSvgItem>
#include <QThread>


GraphicsView::GraphicsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicsView)
{
    ui->setupUi(this);
    qRegisterMetaType<QList<SensorItem *> >("QList<SensorItem *>");
    initWidget();
}

GraphicsView::~GraphicsView()
{
    delete ui;
    delete m_scene;

    //配置网络和端口，创建线程
    QThread *t;
    foreach (t, m_threadList) {
        t->quit();
        t->wait();
    }

    qDeleteAll(m_threadList.begin(),m_threadList.end());
    m_threadList.clear();
}

void GraphicsView::initWidget()
{
    m_zoomLevel = 0;

    initTabelWidget(ui->tableWidgetAlarm);
    initTabelWidget(ui->tableWidgetError);


    //QPoint pSendMenuEventPos;
    //QGraphicsItem *pFocusItem = m_scene->focusItem();
    //if (m_scene->views().first() != NULL) {
    //    QGraphicsView *v = m_scene->views().first();
    //    QPointF sceneP = pFocusItem->mapToScene(pFocusItem->boundingRect().bottomRight());
    //    QPoint viewP = v->mapFromScene(sceneP);
    //    pSendMenuEventPos = v->viewport()->mapToGlobal(viewP);
    //}

    connect(ui->tBtnEdit,   SIGNAL(clicked(bool)),this,SLOT(slotBtnEdit()));
    connect(ui->tBtnSave,   SIGNAL(clicked(bool)),this,SLOT(slotBtnSave()));
    connect(ui->tBtnZoomIn, SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomIn()));
    connect(ui->tBtnZoomOut,SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomOut()));
    connect(ui->tBtnRestore,SIGNAL(clicked(bool)),this,SLOT(slotBtnRestore()));


}

void GraphicsView::confView(QList<SensorItemInfo> itemInfoList, QString IP, QString port, QString &backGroundPath)
{
    /* 1.打开数据,获取节点的地、缩放、安装位置、初始化ItemInfo内容；
     * 2.创建场景,添加图元信息；
     * 3.添加背景图片；
     */
    m_scene = new QGraphicsScene;
    //m_scene->setSceneRect(0,0,1600,680);
    m_scene->addPixmap(QPixmap(backGroundPath));

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    //初始化ItemInfo
    for (int ind = 0; ind < itemInfoList.count();ind++) {
        SensorItem *pItem = new SensorItem(itemInfoList.value(ind));
        m_scene->addItem(pItem);
    }

    UdpThread *udpThread = new UdpThread(QHostAddress(IP) ,port.toUInt());
    QThread *thread = new QThread;
    udpThread->moveToThread(thread);
    m_threadList.append(thread);

    connect(udpThread,SIGNAL(sigHostData(QByteArray)),this,SLOT(slotHostData(QByteArray)));
    connect(thread,SIGNAL(finished()),udpThread,SLOT(deleteLater()),Qt::DirectConnection);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);
    thread->start();
}

void GraphicsView::initTabelWidget(QTableWidget *tableWidget)
{
    QStringList headList;
    headList<<tr("主机编号")<<tr("探测器编号")<<tr("事件类型")<<tr("事件时间");
    tableWidget->setColumnCount(headList.size());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(25);
    //tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 14pt '楷体'; background-color: rgb(0, 125, 165);color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 12pt '楷体'; background-color: rgb(0, 125, 165);color: white;}";
    //tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->verticalHeader()->setStyleSheet(vstyleStr);
    tableWidget->verticalHeader()->setFixedWidth(35);
    tableWidget->verticalHeader()->setEnabled(false);
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);

    tableWidget->horizontalHeader()->setStyleSheet(hstyleStr);
    tableWidget->horizontalHeader()->setEnabled(false);
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(0,  125, 165);}");

    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    tableWidget->setColumnWidth(0,130);
    tableWidget->setColumnWidth(1,130);
    tableWidget->setColumnWidth(2,200);
    tableWidget->setColumnWidth(3,300);

}

void GraphicsView::setItem(QGraphicsScene *scene, QString loopStr, QString idStr, QString typeStr, QString stateStr)
{
    SensorItem *pItem;
    QList<QGraphicsItem *> pItemList = scene->items();
    for (int i = 0; i < pItemList.count(); i++) {
        pItem = qgraphicsitem_cast<SensorItem*>(pItemList.at(i));
        if (pItem->m_loopStr.compare(loopStr) && pItem->m_idStr.compare(idStr)) {
            pItem->setItemType(typeStr.toInt());
            pItem->setItemState(stateStr.toInt());
            pItem->setToolTipString();
        }
    }
}

#define ZOOMSCENE

void GraphicsView::slotBtnZoomIn()
{
#ifdef ZOOMSCENE
    //放大
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1) {
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setScale(0.1+item->scale());
    } else {
        ui->graphicsView->scale(1.1,1.1);
    }
#else
    m_zoomLevel += 1.1;
    ui->graphicsView->scale(1.1,1.1);
#endif
}

void GraphicsView::slotBtnZoomOut()
{
#ifdef ZOOMSCENE
    //缩小
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1) {
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setScale(item->scale()-0.1);
    } else {
        ui->graphicsView->scale(0.9,0.9);
    }
#else
    m_zoomLevel -= 0.9;
    ui->graphicsView->scale(0.9,0.9);
#endif
}

void GraphicsView::slotBtnRestore()
{
#ifdef ZOOMSCENE
    //取消所有变换
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1){
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setRotation(0);
        item->setScale(1.0);
    } else {
        ui->graphicsView->resetTransform();
    }
#else
    m_zoomLevel = 1;
    ui->graphicsView->resetTransform();
#endif
}

void GraphicsView::slotBtnRotate()
{

}

//编辑模式
void GraphicsView::slotBtnEdit()
{
    ui->tBtnEdit->setEnabled(false);
    ui->tBtnSave->setEnabled(true);
    ui->tBtnZoomIn->setEnabled(true);
    ui->tBtnRestore->setEnabled(true);
    ui->tBtnZoomOut->setEnabled(true);
    QList<QGraphicsItem *> itemList = m_scene->items();
    foreach (QGraphicsItem *item, itemList) {
        item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    }

}
//保存编辑
void GraphicsView::slotBtnSave()
{
    ui->tBtnEdit->setEnabled(true);
    ui->tBtnSave->setEnabled(false);
    ui->tBtnZoomIn->setEnabled(false);
    ui->tBtnRestore->setEnabled(false);
    ui->tBtnZoomOut->setEnabled(false);

    QList<QGraphicsItem *> itemList = m_scene->items();
    foreach (QGraphicsItem *item, itemList) {
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
        item->setFlag(QGraphicsItem::ItemIsFocusable,false);
        item->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }
}

void GraphicsView::slotHostData(QByteArray hostData)
{
    QString pLoopStr = QString::number(hostData.at(DATA_LOOP));
    QString pIDStr   = QString::number(hostData.at(DATA_ID));
    QString pType    = QString::number(hostData.at(DATA_TYPE));
    QString pState   = QString::number(hostData.at(DATA_STATE));
    setItem(m_scene,pLoopStr,pIDStr,pType,pState);
}
