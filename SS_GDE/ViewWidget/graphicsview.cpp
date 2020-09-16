#include "graphicsview.h"
#include "sensoritem.h"
#include "ui_graphicsview.h"
#include <QGraphicsSvgItem>
GraphicsView::GraphicsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicsView)
{
    ui->setupUi(this);
    initWidget();
}

GraphicsView::~GraphicsView()
{
    delete ui;
}

void GraphicsView::initWidget()
{
    m_zoomLevel = 0;
    m_times = 0;
    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotTimeout()));
    m_timer->start(1000);

    initTabelWidget(ui->tableWidgetAlarm);
    initTabelWidget(ui->tableWidgetError);


//    ui->tBtnEdit->setEnabled(true);
//    ui->tBtnSave->setEnabled(false);
//    ui->tBtnZoomIn->setEnabled(false);
//    ui->tBtnRestore->setEnabled(false);
//    ui->tBtnZoomOut->setEnabled(false);

    m_scene = new QGraphicsScene;
    //m_scene->setSceneRect(0,0,1600,680);
    m_scene->addPixmap(QPixmap(":/Image/plan-Model.png"));

//    //添加背景图元
//    QGraphicsSvgItem *svgItem = new QGraphicsSvgItem(":/Image/plan.svg");
//    svgItem->setScale(2.0);
//    svgItem->setPos(0,0);
//    svgItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
//    m_scene->addItem(svgItem);

    SensorItem *item;
    for (int i = 0 ; i< 5;i++) {
        item = new SensorItem(QString("编号：1-1\n类型：组合式电气火灾传感器\n区域：阿斯顿发生地方大所发生的"));
        m_scene->addItem(item);
        item->setItemState(i);
    }
    ui->graphicsView->setScene(m_scene);

    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    connect(ui->tBtnEdit,   SIGNAL(clicked(bool)),this,SLOT(slotBtnEdit()));
    connect(ui->tBtnSave,   SIGNAL(clicked(bool)),this,SLOT(slotBtnSave()));
    connect(ui->tBtnZoomIn, SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomIn()));
    connect(ui->tBtnZoomOut,SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomOut()));
    connect(ui->tBtnRestore,SIGNAL(clicked(bool)),this,SLOT(slotBtnRestore()));


}

void GraphicsView::initTabelWidget(QTableWidget *tableWidget)
{
    QStringList headList;
    headList<<tr("主机编号")<<tr("探测器编号")<<tr("事件类型")<<tr("事件时间");
    tableWidget->setColumnCount(headList.size());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(25);
    //tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 14pt '楷体'; background-color: rgb(0, 125, 165);"
                       "color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 12pt '楷体'; background-color: rgb(0, 125, 165);"
                       "color: white;}";
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
    //tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(72, 199, 221);}");
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(0,  125, 165);}");

    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::SingleSelection); //设置选择模式，选择单行

    tableWidget->setColumnWidth(0,130);
    tableWidget->setColumnWidth(1,130);
    tableWidget->setColumnWidth(2,200);
    tableWidget->setColumnWidth(3,300);

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

void GraphicsView::slotTimeout()
{
    QList<QGraphicsItem *> itemList = m_scene->items();
    m_times++;
    for(int i = 0; i < itemList.count();i++ )
        qgraphicsitem_cast<SensorItem*>(itemList.at(i))->setItemState(m_times % 4);

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
        //qDebug()<<item->pos();
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
        item->setFlag(QGraphicsItem::ItemIsFocusable,false);
        item->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }
}
