#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QTreeWidget>
#include <QWidget>

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
    void setNodeInfoZoom(QString loop, QList<QPair<qreal,qreal>>, QString path);

private:
    Ui::ViewWidget *ui;

private slots:
    void slotItemClicked(QTreeWidgetItem* item, int index);
};

#endif // VIEWWIDGET_H
