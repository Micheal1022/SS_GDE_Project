#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ViewWidget/viewwidget.h"
#include "RecordInfo/recordinfo.h"
#include "SystemConf/systemconf.h"
#include "UserLgoin/userlgoin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    ViewWidget *m_viewWidget;
    RecordInfo *m_recordInfo;
    SystemConf *m_systemConf;
    UserLgoin  *m_userLogin;
    QTimer *m_systemTimer;

    QMenu  *m_sysMainMenu;
    void initVariable();
    void initConnect();

private:
    void initWidegt();
    QMenu *createSystemMenu();
private slots:
    void slotSystemMenu();
    void slotViewWidget();
    void slotSystemConf();
    void slotRecordInfo();
    void slotUserLogin();
    void slotAppQuit();
    void slotSystemTime();
};

#endif // MAINWINDOW_H
