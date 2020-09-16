#include "recordinfo.h"
#include "ui_recordinfo.h"

RecordInfo::RecordInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordInfo)
{
    ui->setupUi(this);
}

RecordInfo::~RecordInfo()
{
    delete ui;
}
