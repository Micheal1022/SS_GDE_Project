#include "systemconf.h"
#include "ui_systemconf.h"

SystemConf::SystemConf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemConf)
{
    ui->setupUi(this);
    initTableWidget(ui->tableWidgetIP,SystemConf::IP);
}

SystemConf::~SystemConf()
{
    delete ui;
}

void SystemConf::initTableWidget(QTableWidget *tableWidget)
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
    QStringList headList;
    headList<<tr("主机IP地址")<<tr("端口-1")<<tr("图纸-1")<<tr("端口-2")<<tr("图纸-2")<<tr("端口-3")<<tr("图纸-3")<<tr("端口-4")<<tr("图纸-4")
           <<tr("端口-5")<<tr("图纸-5")<<tr("端口-6")<<tr("图纸-6")<<tr("图纸-7")<<tr("端口-7")<<tr("端口-8")<<tr("图纸-8")<<tr("数据库")<<tr("启用状态")<<tr("安装地址");
    tableWidget->setColumnCount(headList.count());
    tableWidget->setHorizontalHeaderLabels(headList);
    tableWidget->horizontalHeader()->setFixedHeight(30);
    tableWidget->verticalHeader()->setFixedWidth(30);
    tableWidget->setColumnWidth(0, 250);
    tableWidget->setColumnWidth(1,  90);
    tableWidget->setColumnWidth(2,  90);
    tableWidget->setColumnWidth(3,  90);
    tableWidget->setColumnWidth(4,  90);
    tableWidget->setColumnWidth(5,  90);
    tableWidget->setColumnWidth(6,  90);
    tableWidget->setColumnWidth(7,  90);
    tableWidget->setColumnWidth(8,  90);
    tableWidget->setColumnWidth(9,  90);
    tableWidget->setColumnWidth(10, 90);
    tableWidget->setColumnWidth(11, 90);
    tableWidget->setColumnWidth(12, 90);
    tableWidget->setColumnWidth(13, 90);
    tableWidget->setColumnWidth(14, 90);
    tableWidget->setColumnWidth(15, 90);
    tableWidget->setColumnWidth(16, 90);
    tableWidget->setColumnWidth(17, 90);
    tableWidget->setColumnWidth(18, 90);
    tableWidget->setColumnWidth(19,350);


}
