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

private:
    void initTableWidget(QTableWidget *tableWidget);
};

#endif // SYSTEMCONF_H
