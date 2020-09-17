#include "recordinfo.h"
#include "ui_recordinfo.h"
#include "SqlManager/sqlmanager.h"
#include <QScrollBar>
#include <QMessageBox>
#include "MsgBox/msgbox.h"

#define R_HOST  0
#define R_LOOP  1
#define R_ID    2
#define R_TYPE  3
#define R_STS   4
#define R_TIME  5
#define R_ADDR  6

RecordInfo::RecordInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordInfo)
{
    ui->setupUi(this);
    initTableWidget(ui->tableWidget);
    initConnect();
}

RecordInfo::~RecordInfo()
{
    delete ui;
}

void RecordInfo::initConnect()
{
    connect(ui->tBtnCheck,SIGNAL(clicked(bool)),this,SLOT(slotBtnCheck()));
    connect(ui->tBtnAllDel,SIGNAL(clicked(bool)),this,SLOT(slotBtnAllDel()));
    connect(ui->tBtnExport,SIGNAL(clicked(bool)),this,SLOT(slotBtnExport()));
    connect(ui->tBtnPageUp,SIGNAL(clicked(bool)),this,SLOT(slotBtnPageUp()));
    connect(ui->tBtnPageDown,SIGNAL(clicked(bool)),this,SLOT(slotBtnPageDown()));
    connect(this,SIGNAL(sigPageUp(int)),ui->tableWidget->verticalScrollBar(),SLOT(setValue(int)));
    connect(this,SIGNAL(sigPageDown(int)),ui->tableWidget->verticalScrollBar(),SLOT(setValue(int)));
}

void RecordInfo::initTableWidget(QTableWidget *tableWidget)
{
    QString styleStr = "QHeaderView::section{font: 14pt '楷体';background-color:rgb(0, 125, 165);color: white;}";
    tableWidget->horizontalHeader()->setStyleSheet(styleStr);
    tableWidget->verticalHeader()->setStyleSheet(styleStr);
    tableWidget->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tableWidget->horizontalHeader()->setEnabled(false);
    tableWidget->horizontalHeader()->setVisible(true);//设置表头显示
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->horizontalHeader()->setHighlightSections(false);

    //tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);//单元格不可编
    tableWidget->setSelectionBehavior (QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    tableWidget->setSelectionMode (QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    tableWidget->setStyleSheet("QTableWidget::item:selected {color: rgb(255, 255, 255);background-color: rgb(0,  125, 165);}");

    QStringList headList;
    headList<<tr("主机")<<tr("回路")<<tr("探测器编号")<<tr("探测器类型")<<tr("事件类型")<<tr("事件时间")<<tr("安装区域");
    tableWidget->setColumnCount(headList.count());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(30);
    tableWidget->verticalHeader()->setFixedWidth(30);

    tableWidget->setColumnWidth(0, 250);
    tableWidget->setColumnWidth(1, 100);
    tableWidget->setColumnWidth(2, 150);
    tableWidget->setColumnWidth(3, 250);
    tableWidget->setColumnWidth(4, 150);
    tableWidget->setColumnWidth(5, 400);
    tableWidget->setColumnWidth(6, 300);

}

QString RecordInfo::confQuerySql()
{
    QString pQuerySql = "select HOST,LOOP,ID,TYPE,STS,TIME from RECORD where ";
    QString pStartTime = QString::number(ui->dateEditStart->dateTime().toTime_t());
    QString pStopTime  = QString::number(ui->dateEditStop->dateTime().toTime_t());
    pQuerySql += QString("TIME between %1 and %2 order by TIME desc;").arg(pStartTime).arg(pStopTime);
    return pQuerySql;
}

void RecordInfo::showRecordList(QTableWidget *tableWidget, QString querySql)
{
    tableWidget->clearContents();
    int columnCount = tableWidget->columnCount();
    //获取数据列表
    QSqlDatabase db = SqlManager::openConnection();
    QList<QStringList> nodeList = SqlManager::getRecordList(db,querySql);
    SqlManager::closeConnection(db);

    tableWidget->setRowCount(nodeList.count());
    QFont ft("楷体",14);
    QTableWidgetItem *item;
    for (int row = 0; row < nodeList.count(); row++) {
        QStringList itemStr = nodeList.at(row);
        QString pHost,pLoop,pID,pType,pSts,pTime;
        pHost = itemStr.at(0);
        pLoop = itemStr.at(1);
        pID   = itemStr.at(2);
        pType = itemStr.at(3);
        pSts  = itemStr.at(4);
        pTime = itemStr.at(5);
        //tableWidget->setRowHeight(row,27);
        for (int column = 0;column < columnCount; column++) {
            item = new QTableWidgetItem;
            item->setFont(ft);
            item->setTextAlignment(Qt::AlignCenter);
            item->setTextColor(Qt::black);
            switch (column) {
            case R_HOST://主机地址
                item->setText(pHost);
                break;
            case R_LOOP://回路
                item->setText(pLoop);
                break;
            case R_ID://地址
                item->setText(pID);
                break;
            case R_TYPE://探测器类型
                item->setText(pType);
                break;
            case R_STS://事件类型
                item->setText(pSts);
                break;
            case R_TIME://事件时间
                item->setText(QDateTime::fromTime_t(pTime.toUInt()).toString("yyyy/MM/dd hh:mm:ss"));
                break;
            case R_ADDR://安装区域
                break;
            }
            tableWidget->setItem(row,column,item);
        }
    }
}

void RecordInfo::slotBtnCheck()
{
    //qDebug()<<"QuerySql ---> "<<confQuerySql();
    showRecordList(ui->tableWidget,confQuerySql());
}

void RecordInfo::slotBtnPageUp()
{
    emit sigPageUp(500);
}

void RecordInfo::slotBtnAllDel()
{
    int ret = MsgBox::showQuestion(this,tr(" 记录删除"),tr("你确定要删除全部的记录信息吗？"),tr("取消"),tr("确定"));
    if (ret) {
        QString sql = "delete from RECORD;";
        QSqlDatabase db = SqlManager::openConnection();

        if(SqlManager::delAllData(db,sql)) {
            ui->tableWidget->clearContents();
            ui->tableWidget->setRowCount(0);
        }
        SqlManager::closeConnection(db);
    }
}

void RecordInfo::slotBtnExport()
{

}

void RecordInfo::slotBtnPageDown()
{
    emit sigPageDown(-500);
}
