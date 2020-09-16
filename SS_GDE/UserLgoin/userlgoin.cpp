#include "userlgoin.h"
#include "ui_userlgoin.h"

UserLgoin::UserLgoin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLgoin)
{
    ui->setupUi(this);
    setModal(true);
    setWindowFlags(Qt::FramelessWindowHint);
    hide();
}

UserLgoin::~UserLgoin()
{
    delete ui;
}
