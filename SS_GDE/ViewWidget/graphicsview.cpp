#include "graphicsview.h"
#include "sensoritem.h"
#include "ui_graphicsview.h"
#include <QGraphicsSvgItem>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
#include <QSqlError>
#include "dbthead.h"
#include <QGraphicsSceneContextMenuEvent>
#include "SqlManager/sqlmanager.h"
#define POS 150
#define SET 100
GraphicsView::GraphicsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicsView)
{
    ui->setupUi(this);

    qRegisterMetaType<QList<SensorItemInfo>>("QList<SensorItemInfo>");
    qRegisterMetaType<QList<SensorItem *>>("QList<SensorItem *>");
    qRegisterMetaType<QPair<qreal, qreal>>("QPair<qreal, qreal>");
    qRegisterMetaType<QList<QPair<qreal,qreal>>>("QList<QPair<qreal,qreal>>");
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
    m_viewScale = 1.0;


    initTableWidget(ui->tableWidgetAlarm);
    initTableWidget(ui->tableWidgetError);


    ui->tBtnSave->setEnabled(false);
    ui->tBtnZoomIn->setEnabled(false);
    ui->tBtnRestore->setEnabled(false);
    ui->tBtnZoomOut->setEnabled(false);

    connect(ui->tBtnEdit,   SIGNAL(clicked(bool)),this,SLOT(slotBtnEdit()));
    connect(ui->tBtnSave,   SIGNAL(clicked(bool)),this,SLOT(slotBtnSave()));
    connect(ui->tBtnZoomIn, SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomIn()));
    connect(ui->tBtnZoomOut,SIGNAL(clicked(bool)),this,SLOT(slotBtnZoomOut()));
    connect(ui->tBtnRestore,SIGNAL(clicked(bool)),this,SLOT(slotBtnRestore()));
    connect(ui->tableWidgetAlarm,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(slotFindItemAlarmPos(int,int)));
    connect(ui->tableWidgetError,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(slotFindItemErrorPos(int,int)));

    DBThead *pDbThread = new DBThead;
    QThread *pThread = new QThread;
    pDbThread->moveToThread(pThread);
    pThread->start();
    connect(this,SIGNAL(sigNodeInfoZoom(QList<SensorItemInfo>,QList<QPair<qreal,qreal>>,QStringList,QString)),
            pDbThread,SLOT(slotNodeInfoZoom(QList<SensorItemInfo>,QList<QPair<qreal,qreal> >,QStringList,QString)));

    m_infoTimer = new QTimer;
    connect(m_infoTimer,SIGNAL(timeout()),this,SLOT(slotInfoTimeOut()));
    m_infoTimer->start(1000);

}

void GraphicsView::confView(QList<SensorItemInfo> itemInfoList, QString loop, QString hostName,
                            QString hostIP, QString port, QString &backGroundPath, QString dbPath)
{
    /*
     * 1.打开数据,获取节点的地、缩放、安装位置、初始化ItemInfo内容；
     * 2.创建场景,添加图元信息；
     * 3.添加背景图片；
     */
    m_hostIP = hostIP;
    m_dbPaht = dbPath;
    m_loop = loop;
    m_hostName = hostName;
    m_itemInfoList = itemInfoList;
    m_scene = new QGraphicsScene;
    m_scene->addPixmap(QPixmap(backGroundPath));

//    QStringList pInfoList;
//    pInfoList<<m_hostName<<QString::number(1)<<QString::number(1)<<QString("探测器报警")<<QString("2020/14/12 12:00:00");
//    m_alarmInfoList.append(pInfoList);  m_errorInfoList.append(pInfoList);  pInfoList.clear();
//    pInfoList<<m_hostName<<QString::number(1)<<QString::number(2)<<QString("探测器报警")<<QString("2020/14/12 12:00:00");
//    m_alarmInfoList.append(pInfoList);  m_errorInfoList.append(pInfoList);  pInfoList.clear();
//    pInfoList<<m_hostName<<QString::number(1)<<QString::number(3)<<QString("探测器报警")<<QString("2020/14/12 12:00:00");
//    m_alarmInfoList.append(pInfoList);  m_errorInfoList.append(pInfoList);  pInfoList.clear();
//    pInfoList<<m_hostName<<QString::number(1)<<QString::number(4)<<QString("探测器报警")<<QString("2020/14/12 12:00:00");
//    m_alarmInfoList.append(pInfoList);  m_errorInfoList.append(pInfoList);  pInfoList.clear();
//    pInfoList<<m_hostName<<QString::number(1)<<QString::number(5)<<QString("探测器报警")<<QString("2020/14/12 12:00:00");
//    m_alarmInfoList.append(pInfoList);  m_errorInfoList.append(pInfoList);  pInfoList.clear();

    QSqlDatabase pSqlDatabase = SqlManager::openConnection();
    qreal pViewScale = SqlManager::getViewZoom(pSqlDatabase,hostIP,loop);
    qreal pPngsScale = SqlManager::getPngsZoom(pSqlDatabase,hostIP,loop);
    SqlManager::closeConnection(pSqlDatabase);
    m_viewScale = pViewScale;

    //设置底图的缩放比例
    m_scene->items().value(0)->setScale(pPngsScale);
    //设置视窗的缩放比例
    ui->graphicsView->scale(pViewScale,pViewScale);

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    //初始化ItemInfo
    int pRowNum,pColumnNum;
    pRowNum = pColumnNum = 0;

    for (int ind = 0; ind < itemInfoList.count();ind++) {
        SensorItem *pItem = new SensorItem(itemInfoList.value(ind));

        pColumnNum = ind % 10;
        if (ind % 11 == 10) {
            pRowNum += 1;
        }
        //配置位置
        qreal pPosX = itemInfoList.value(ind).m_posX;
        qreal pPosY = itemInfoList.value(ind).m_posY;
        if (0 == pPosX && 0 == pPosY) {
            pItem->setPos(POS + SET * pColumnNum, POS + SET * pRowNum );
        } else {
            pItem->setPos(pPosX, pPosY);
        }
        //配置缩放
        qreal pZoom = itemInfoList.value(ind).m_zoom;
        if (1.0 == pZoom) {
            pItem->setScale(1.0);
        } else {
            pItem->setScale(itemInfoList.value(ind).m_zoom);
        }
        m_scene->addItem(pItem);
    }

    UdpThread *udpThread = new UdpThread(QHostAddress(hostIP) ,port.toUInt());
    QThread *thread = new QThread;
    udpThread->moveToThread(thread);
    m_threadList.append(thread);

    connect(udpThread,SIGNAL(sigHostData(QByteArray)),this,SLOT(slotHostData(QByteArray)));
    connect(thread,SIGNAL(finished()),udpThread,SLOT(deleteLater()),Qt::DirectConnection);
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);
    thread->start();
}

void GraphicsView::initTableWidget(QTableWidget *tableWidget)
{
    QStringList headList;
    headList<<tr("主机名称")<<tr("回路")<<tr("编号")<<tr("事件类型")<<tr("事件时间");
    tableWidget->setColumnCount(headList.size());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(25);
    //tableWidget->horizontalHeader()->setDefaultSectionSize(140);
    QString hstyleStr ="QHeaderView::section{font: 14pt '楷体'; background-color: rgb(0, 125, 165);color: white;}";
    QString vstyleStr ="QHeaderView::section{font: 14pt '楷体'; background-color: rgb(0, 125, 165);color: white;}";
    //tableWidget->setFocusPolicy(Qt::NoFocus);
    tableWidget->verticalHeader()->setStyleSheet(vstyleStr);
    tableWidget->verticalHeader()->setFixedWidth(35);
    tableWidget->verticalHeader()->setEnabled(false);
    tableWidget->verticalHeader()->setVisible(true);
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);

    tableWidget->horizontalHeader()->setStyleSheet(hstyleStr);
    tableWidget->horizontalHeader()->setEnabled(false);
    tableWidget->horizontalHeader()->setVisible(true);
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(0,  125, 165);}");

    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::NoSelection); //设置选择模式，选择单行
    tableWidget->setColumnWidth(0,200);
    tableWidget->setColumnWidth(1,80);
    tableWidget->setColumnWidth(2,80);
    tableWidget->setColumnWidth(3,150);
    tableWidget->setColumnWidth(4,250);

}

void GraphicsView::setItem(QGraphicsScene *scene, QString loopStr, QString idStr, QString typeStr, QString stateStr)
{
    SensorItem *pItem;
    QList<QGraphicsItem *> pItemList = scene->items();

    for (int i = 1; i < pItemList.count(); i++) {
        pItem = qgraphicsitem_cast<SensorItem*>(pItemList.at(pItemList.count() - 1 - i));
        if (pItem->m_loopStr == loopStr && pItem->m_idStr == idStr) {
            pItem->setItemType(typeStr.toInt());
            pItem->setItemState(stateStr.toInt());
            pItem->setToolTipString();
        }
    }
}

void GraphicsView::setNodeInfoZoom(QString loop, QString id, QPair<qreal, qreal> pox, QString scale, QString path)
{
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        database = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        database = QSqlDatabase::addDatabase("QSQLITE");
    }
    database.setDatabaseName(path);

    if (!database.open()) {
        qDebug() << "Error: Failed to connect database."<<database.lastError();
    } else {
        qDebug() << "Succeed to connect database : loop "<<loop;
    }

    QSqlQuery query(database);

    QString sqlQuery = QString("update NODELIST set ZOOM = %1,POS_X = %2,POS_Y = %3 where LOOP = %4 and ID = %5;").\
            arg(scale).arg(QString::number(pox.first)).arg(QString::number(pox.second)).arg(loop).arg(id);
    qDebug()<<sqlQuery;
    query.exec(sqlQuery);
    query.finish();
    query.clear();
    database.close();
    //QT数据库移除
    QSqlDatabase::removeDatabase("QSQLITE");
}


void GraphicsView::slotBtnZoomIn()
{
    //放大
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1) {
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setScale(item->scale() * 1.1);
    } else {
        m_viewScale *= 1.1;
        ui->graphicsView->scale(1.1,1.1);
    }
}

void GraphicsView::slotBtnZoomOut()
{
    //缩小
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1) {
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setScale(item->scale()*0.9);
    } else {
        ui->graphicsView->scale(0.9,0.9);
        m_viewScale *= 0.9;
    }
}

void GraphicsView::slotBtnRestore()
{
    //取消所有变换
    int cnt = m_scene->selectedItems().count();
    if (cnt == 1){
        QGraphicsItem *item = m_scene->selectedItems().at(0);
        item->setRotation(0);
        item->setScale(1.0);
    } else {
        m_viewScale = 1.0;
        ui->graphicsView->scale(1.0,1.0);
    }
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

    for (int ind = 0; ind < itemList.count(); ind++) {
        if (ind < itemList.count()- 1) {
            QGraphicsItem *item = itemList.value(ind);
            item->setFlag(QGraphicsItem::ItemIsSelectable);
            item->setFlag(QGraphicsItem::ItemIsFocusable);
            item->setFlag(QGraphicsItem::ItemIsMovable);
        }
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
    QSqlDatabase pSqlDatabase = SqlManager::openConnection();
    SqlManager::setViewZoom(pSqlDatabase,m_loop,QString::number(m_viewScale),m_hostIP);
    SqlManager::closeConnection(pSqlDatabase);

    qreal pScale;
    QStringList pScaleList;
    QList<QPair<qreal, qreal>> poxList;
    //获取item的列表，列表的顺序是最小的位置保存最上层的item;
    QList<QGraphicsItem *> itemList = m_scene->items();
    for (int i = 0; i < itemList.count(); i++) {
        SensorItem* pItem = qgraphicsitem_cast<SensorItem*>(itemList.value(itemList.count()- 1 - i));
        if (itemList.count()- 1 - i == 0) {
            //查找背景图片，保存缩放等级
            pScale = pItem->scale();
            QSqlDatabase pSqlDatabase = SqlManager::openConnection();
            SqlManager::setPngsZoom(pSqlDatabase,m_loop,QString::number(pScale),m_hostIP);
            SqlManager::closeConnection(pSqlDatabase);
        } else {
            //查找节点土元，保存缩放等级
            QPointF pScenePos = pItem->scenePos();
            pScale = pItem->scale();
            QPair<qreal,qreal> pPairPos;
            pPairPos.first = pScenePos.x();
            pPairPos.second= pScenePos.y();
            poxList.append(pPairPos);
            pScaleList.append(QString::number(pScale));
        }
        pItem->setFlag(QGraphicsItem::ItemIsMovable,   false);
        pItem->setFlag(QGraphicsItem::ItemIsFocusable, false);
        pItem->setFlag(QGraphicsItem::ItemIsSelectable,false);
    }
    emit sigNodeInfoZoom(m_itemInfoList, poxList, pScaleList,m_dbPaht);
}

void GraphicsView::analysisData(QByteArray hostData)
{
    int pLoop = hostData.at(DATA_LOOP);
    int pID   = hostData.at(DATA_ID);
    QString pLootStr = QString::number(pLoop);
    QString pIDStr   = QString::number(pID);

    int index;
    QString dateTimeStr = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
    QStringList pInfoList;
    int pState =  hostData.at(DATA_STATE);
    switch (pState) {
    case NORMAL:

        index = findItemIndex(m_itemInfoList,pLootStr,pIDStr);
        if (index < 0) {
            return;
        }
        if (true == m_itemInfoList.value(index).m_errorFlag) {
            m_itemInfoList[index].m_errorFlag = false;
            delStringList(m_errorInfoList,pLoop,pID,ERROR);
        }
        if (true == m_itemInfoList.value(index).m_alarmFlag) {
            m_itemInfoList[index].m_alarmFlag = false;
            delStringList(m_alarmInfoList,pLoop,pID,ALARM);
        }
        if (true == m_itemInfoList.value(index).m_offLineFlag) {
            m_itemInfoList[index].m_offLineFlag = false;
            delStringList(m_errorInfoList,pLoop,pID,OFFLINE);
        }
        break;

    case ERROR:
        index = findItemIndex(m_itemInfoList,pLootStr,pIDStr);
        if (index < 0) {
            return;
        }
        if (false == m_itemInfoList.value(index).m_errorFlag) {
            m_itemInfoList[index].m_errorFlag = true;
            QString pLoopStr  = QString::number(pLoop);
            QString pIDStr    = QString::number(pID);
            QString pStateStr = QString("探测器故障");
            QString pAreaStr  = m_itemInfoList.value(index).m_areaStr;
            //实时故障列表
            pInfoList<<m_hostName<<pLoopStr<<pIDStr<<pStateStr<<dateTimeStr;
            m_errorInfoList.append(pInfoList);
            //历史故障列表
            pInfoList.insert(1,m_hostIP);
            pInfoList.insert(5,pAreaStr);
            QSqlDatabase pDbDatabase = SqlManager::openConnection();
            SqlManager::insertAlarmRecord(pDbDatabase,pInfoList);
            SqlManager::closeConnection(pDbDatabase);

        }
        break;

    case ALARM:
        index = findItemIndex(m_itemInfoList,pLootStr,pIDStr);
        if (index < 0) {
            return;
        }
        if (false == m_itemInfoList.value(index).m_alarmFlag) {
            m_itemInfoList[index].m_alarmFlag = true;          
            QString pLoopStr  = QString::number(pLoop);
            QString pIDStr    = QString::number(pID);
            QString pStateStr = QString("探测器报警");
            QString pAreaStr  = m_itemInfoList.value(index).m_areaStr;
            //实时报警列表
            pInfoList<<m_hostName<<pLoopStr<<pIDStr<<pStateStr<<dateTimeStr;
            m_errorInfoList.append(pInfoList);
            //历史报警列表
            pInfoList.insert(1,m_hostIP);
            pInfoList.insert(5,pAreaStr);
            QSqlDatabase pDbDatabase = SqlManager::openConnection();
            SqlManager::insertAlarmRecord(pDbDatabase,pInfoList);
            SqlManager::closeConnection(pDbDatabase);


        }
        break;

    case OFFLINE:
        index = findItemIndex(m_itemInfoList,pLootStr,pIDStr);
        if (index < 0) {
            return;
        }
        if (false == m_itemInfoList.value(index).m_offLineFlag) {
            m_itemInfoList[index].m_offLineFlag = true;
            QString pLoopStr  = QString::number(pLoop);
            QString pIDStr    = QString::number(pID);
            QString pStateStr = QString("探测器掉线");
            QString pAreaStr  = m_itemInfoList.value(index).m_areaStr;
            //实时掉线列表
            pInfoList<<m_hostName<<pLoopStr<<pIDStr<<pStateStr<<dateTimeStr;
            m_errorInfoList.append(pInfoList);
            //历史掉线列表
            pInfoList.insert(1,m_hostIP);
            pInfoList.insert(5,pAreaStr);
            QSqlDatabase pDbDatabase = SqlManager::openConnection();
            SqlManager::insertAlarmRecord(pDbDatabase,pInfoList);
            SqlManager::closeConnection(pDbDatabase);
        }
        break;
    }
}

void GraphicsView::slotHostData(QByteArray hostData)
{
    QString pLoopStr = QString::number(hostData.at(DATA_LOOP));
    QString pIDStr   = QString::number(hostData.at(DATA_ID));
    QString pType    = QString::number(hostData.at(DATA_TYPE));
    QString pState   = QString::number(hostData.at(DATA_STATE));
    setItem(m_scene,pLoopStr,pIDStr,pType,pState);
    analysisData(hostData);

}

void GraphicsView::showInfoList(QTableWidget *tableWidget, QList<QStringList> infoList)
{
    tableWidget->clearContents();
    int columnCount = tableWidget->columnCount();
    //获取数据列表

    tableWidget->setRowCount(infoList.count());
    QFont ft("楷体",14);
    int pRowCount = infoList.count();
    QTableWidgetItem *item;
    for (int row = 0; row < infoList.count();row++) {
        QStringList itemStr = infoList.at(pRowCount - 1 - row);
        tableWidget->setRowHeight(row,25);
        for (int column = 0;column < columnCount;column++) {
            item = new QTableWidgetItem;
            item->setFont(ft);
            item->setTextAlignment(Qt::AlignCenter);
            item->setTextColor(QColor(0,0,0));
            item->setText(itemStr.at(column));
            tableWidget->setItem(row,column,item);
        }
    }
}

void GraphicsView::delStringList(QList<QStringList> &infoList, int loop, int Id, int state)
{
    QString pLoopStr = QString::number(loop);
    QString canIdStr= QString::number(Id);
    QString pStateStr;

    switch (state) {
    case ERROR:
        pStateStr = QString("探测器故障");
        break;
    case ALARM:
        pStateStr = QString("探测器报警");
        break;
    case OFFLINE:
        pStateStr = QString("探测器掉线");
        break;
    }
    for( int index = 0;index < infoList.count();index++) {
        QString loopStr  = infoList.at(index).at(1);
        QString idStr    = infoList.at(index).at(2);
        QString stateStr = infoList.at(index).at(3);
        if(loopStr == pLoopStr && idStr == canIdStr && stateStr == pStateStr) {
            infoList.removeAt(index);
        }
    }
}

int GraphicsView::findItemIndex(QList<SensorItemInfo> itemInfoList, QString loop, QString id)
{
    for (int index = 0; index < itemInfoList.count(); index++) {
        SensorItemInfo itemInfo = itemInfoList.value(index);
        if (loop == itemInfo.m_loopStr && id == itemInfo.m_idStr) {
            return index;
        }
    }
    return -1;
}

void GraphicsView::slotInfoTimeOut()
{
    showInfoList(ui->tableWidgetAlarm,m_alarmInfoList);
    showInfoList(ui->tableWidgetError,m_errorInfoList);
}

void GraphicsView::slotFindItemAlarmPos(int row, int column)
{
    if (true == ui->tableWidgetAlarm->item(row,column)->isSelected()) {
        QString pLoopStr = ui->tableWidgetAlarm->item(row,1)->text();
        QString pIdStr   = ui->tableWidgetAlarm->item(row,2)->text();

        int index = findItemIndex(m_itemInfoList,pLoopStr,pIdStr);
        QPoint itemPos;
        itemPos.setX(m_itemInfoList.at(index).m_posX);
        itemPos.setY(m_itemInfoList.at(index).m_posY);
    }
}

void GraphicsView::slotFindItemErrorPos(int row, int column)
{
    if (true == ui->tableWidgetError->item(row,column)->isSelected()) {
        QString pLoopStr = ui->tableWidgetError->item(row,1)->text();
        QString pIdStr   = ui->tableWidgetError->item(row,2)->text();

        int index = findItemIndex(m_itemInfoList,pLoopStr,pIdStr);
        QPointF itemPos;//item的坐标
        itemPos.setX(m_itemInfoList.at(index).m_posX);
        itemPos.setY(m_itemInfoList.at(index).m_posY);
        //qDebug()<<"*********itemPos**********";
        //qDebug()<<"m_posX    -----> "<<itemPos.x();
        //qDebug()<<"m_posY    -----> "<<itemPos.y();
    }
}






