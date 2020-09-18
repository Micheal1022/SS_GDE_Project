#ifndef RECORDINFO_H
#define RECORDINFO_H

#include <QWidget>
#include <QTableWidget>
namespace Ui {
class RecordInfo;
}

class RecordInfo : public QWidget
{
    Q_OBJECT

public:
    explicit RecordInfo(QWidget *parent = 0);
    ~RecordInfo();

private:
    Ui::RecordInfo *ui;
    struct NodeInfo
    {
        NodeInfo() {
         host.clear();
         addr.clear();
         loop = 0;
         id   = 0;
        }
        int id;
        int loop;
        QString host;
        QString addr;
    };
    int m_rowCount;
    int m_pageCount;
    int m_pageNumber;
    void initWidget();
    void initConnect();
    void initVariable();
    void initTableWidget(QTableWidget *tableWidget);
    QString confQuerySql();
    void showRecordList(QTableWidget *tableWidget, QString querySql);
signals:
    void sigPageUp(int step);
    void sigPageDown(int step);

private slots:
    void slotBtnCheck();
    void slotBtnPageUp();
    void slotBtnAllDel();
    void slotBtnExport();
    void slotBtnPageDown();

};

#endif // RECORDINFO_H
