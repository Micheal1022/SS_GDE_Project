#ifndef SYSTEMCONF_H
#define SYSTEMCONF_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class SystemConf;
}

class SystemConf : public QWidget
{
    Q_OBJECT

public:
    explicit SystemConf(QWidget *parent = 0);
    ~SystemConf();

private:
    Ui::SystemConf *ui;

    enum TableWidgetType{
        IP = 1,
        DATA= 2
    };

private:
    void initTableWidget(QTableWidget *tableWidget,SystemConf::TableWidgetType type);
};

#endif // SYSTEMCONF_H
