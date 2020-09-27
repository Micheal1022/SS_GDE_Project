#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QTreeWidget>
#include <QWidget>
#include "graphicsview.h"
namespace Ui {
class ViewWidget;
}

class ViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ViewWidget(QWidget *parent = 0);
    ~ViewWidget();
    QList<QStringList> getNodeInfoList(QString loop, QString path);


private:
    Ui::ViewWidget *ui;
    void initWidget();
    void initConnect();
    void initVariable();
    void initConfNode();
    QList<QTreeWidgetItem *> m_LoopItemList;
    QList<GraphicsView *> m_viewWidgetList;

private slots:
    void slotItemClicked(QTreeWidgetItem* item, int index);

public slots:
    void slotConfNode();
};

#endif // VIEWWIDGET_H
