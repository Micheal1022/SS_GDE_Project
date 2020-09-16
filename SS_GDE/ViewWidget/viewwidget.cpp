#include "viewwidget.h"
#include "ui_viewwidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "sensoritem.h"
#include "graphicsview.h"

ViewWidget::ViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewWidget)
{
    ui->setupUi(this);
    GraphicsView *view = new GraphicsView;
    ui->stackedWidgetBuild->addWidget(view);






}

ViewWidget::~ViewWidget()
{
    delete ui;
}
