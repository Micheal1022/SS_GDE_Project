#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initVariable();
    initWidegt();
    initConnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initVariable()
{
    m_viewWidget = new ViewWidget;
    m_recordInfo = new RecordInfo;
    m_systemConf = new SystemConf;
    m_userLogin  = new UserLgoin;
    ui->stackedWidget->addWidget(m_viewWidget);
    ui->stackedWidget->addWidget(m_systemConf);
    ui->stackedWidget->addWidget(m_recordInfo);
    ui->stackedWidget->setCurrentIndex(0);

    m_systemTimer = new QTimer;
    m_systemTimer->start(1000);
    ui->lbSystemTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss "));
}

void MainWindow::initConnect()
{
    connect(ui->menutBtn,SIGNAL(clicked(bool)),this,SLOT(slotSystemMenu()));
    connect(m_systemTimer,SIGNAL(timeout()),this,SLOT(slotSystemTime()));
}

void MainWindow::initWidegt()
{
    showFullScreen();
    //setWindowFlags(Qt::FramelessWindowHint);
#ifdef BEVONE
    ui->lbLogoBevone->setStyleSheet("border-image: url(:/Image/Bevone.png);");
    ui->lbCompany->setText(tr("北京北元安达电子有限公司"));
#elif  SENSOR
    ui->menutBtn->setStyleSheet("border-image: url(:/Image/Sensor.png);");
    ui->lbCompany->setText(tr("西安盛赛尔电子有限公司"));
#endif
}

//#define ICON
QMenu *MainWindow::createSystemMenu()
{
    QMenu *pMainMenu = new QMenu(this);
    QString nStyleSheet = "QMenu {background-color: rgb(255, 255, 255); margin: 5px;}"
                          "QMenu::item {font: 18pt '楷体';padding: 5px 10px 5px 20px; border: 1px solid transparent;"
                          "min-height: 30px; min-width: 110px; border-radius: 4px;}"
                          "QMenu::separator{"
                          "height: 2px; "
                          "background: #FFFFFF; "
                          "margin-left: 10px; "
                          "margin-right: 5px;}"
                          "QMenu::item:selected {"
                          "color: rgb(255, 255, 255);"
                          "background-color:rgb(0, 125, 165); "
                          "border-color: rgb(0, 125, 165);}";

    pMainMenu->setStyleSheet(nStyleSheet);
#ifdef ICON
    pMainMenu->addAction(QIcon(":/pic/run.png"),       tr("监控界面"), this, SLOT(slotViewWidget()));
    pMainMenu->addAction(QIcon(":/pic/tools.png"),     tr("系统设置"), this, SLOT(slotSystemConf()));
    pMainMenu->addAction(QIcon(":/pic/dataSearch.png"),tr("历史记录"), this, SLOT(slotRecordInfo()));
    pMainMenu->addAction(QIcon(":/pic/login.png"),     tr("用户登录"), this, SLOT(slotUserLogin()));
#else
    pMainMenu->addAction(tr("监控界面"), this, SLOT(slotViewWidget()));
    pMainMenu->addAction(tr("系统设置"), this, SLOT(slotSystemConf()));
    pMainMenu->addAction(tr("历史记录"), this, SLOT(slotRecordInfo()));
    pMainMenu->addAction(tr("用户登录"), this, SLOT(slotUserLogin()));
    pMainMenu->addAction(tr("程序退出"), this, SLOT(slotAppQuit()));
#endif
    return pMainMenu;
}

void MainWindow::slotSystemMenu()
{
    if(m_sysMainMenu && !m_sysMainMenu->isHidden()) {
        delete m_sysMainMenu;
        m_sysMainMenu = NULL;
    }else{
        delete m_sysMainMenu;
        m_sysMainMenu = createSystemMenu();
        if(m_sysMainMenu != NULL) {
            QPoint nPos;
            nPos.setX(5);
            nPos.setY(m_sysMainMenu->sizeHint().height()-150);
            nPos = ui->menutBtn->mapToGlobal(nPos);
            m_sysMainMenu->popup(nPos);
        }
    }
}

void MainWindow::slotViewWidget()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::slotSystemConf()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::slotRecordInfo()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::slotUserLogin()
{
    m_userLogin->show();
    int height = geometry().height();
    int width  = geometry().width();

    int h = (height - m_userLogin->geometry().height()) / 2;
    int w = (width  - m_userLogin->geometry().width()) / 2;

    int x_pos = pos().x();
    int y_pos = pos().y();
    m_userLogin->move(x_pos+w,y_pos+h);

}

void MainWindow::slotAppQuit()
{
    QApplication::quit();
}
void MainWindow::slotSystemTime()
{
    QDate::currentDate().dayOfWeek();
    ui->lbSystemTime->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss "));
}
