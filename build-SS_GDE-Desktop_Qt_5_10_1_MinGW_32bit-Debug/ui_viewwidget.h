/********************************************************************************
** Form generated from reading UI file 'viewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWWIDGET_H
#define UI_VIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QToolButton *tBtnUserLogin;
    QToolButton *tBtnSysConf;
    QToolButton *tBtnRecord;
    QToolButton *tBtnQuitApp;
    QStackedWidget *stackedWidgetBuild;

    void setupUi(QWidget *ViewWidget)
    {
        if (ViewWidget->objectName().isEmpty())
            ViewWidget->setObjectName(QStringLiteral("ViewWidget"));
        ViewWidget->setEnabled(true);
        ViewWidget->resize(1352, 702);
        ViewWidget->setStyleSheet(QString::fromUtf8("QWidget#ViewWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid  rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border-color: rgb(180, 180, 180);\n"
"background-color: rgb(180, 180, 180);\n"
"}\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */\n"
"border-top: 2px solid  rgb(64, 87, 97);\n"
"border: 2px solid  rgb(64, 87, 97);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QTabWidget::tab-bar {\n"
"left: 10px; /* move to the right by 5px */\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:2px solid rgb(64, 87, 97);\n"
"border-bottom-color: #C2C7CB; /* same as the pane color */\n"
"border-top-left-radius: 5px;\n"
"border-top-"
                        "right-radius: 5px;\n"
"width: 390px;\n"
"height: 30px;\n"
"padding: 2px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"color: rgb(255, 255, 255);\n"
"background-color:rgb(64, 87, 97);\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"border-color: #9B9B9B;\n"
"border-bottom-color: #C2C7CB; /* same as pane color */\n"
"}\n"
"QTabBar::tab:!selected {\n"
"margin-top: 2px; /* make non-selected tabs look smaller */\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"Line{\n"
"border:1px solid  rgb(0, 125, 165);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(ViewWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(ViewWidget);
        treeWidget->headerItem()->setText(0, QString());
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMinimumSize(QSize(220, 380));
        treeWidget->setMaximumSize(QSize(220, 16777215));
        treeWidget->setFocusPolicy(Qt::NoFocus);
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border:2px solid rgb(0,125,165);\n"
"border-radius:10px;\n"
"}\n"
"QScrollBar:vertical{\n"
"width:20px;\n"
"background:rgb(0,0,0,0%);\n"
"margin:0px,0px,0px,0px;\n"
"padding-top:25px;   \n"
"padding-bottom:25px;    \n"
"}\n"
"QScrollBar::handle:vertical{\n"
"width:10px;\n"
"background:rgb(0,0,0,25%);\n"
"background:rgb(0,125,165,100%);\n"
"border-radius:5px;\n"
"min-height:20px;\n"
"}\n"
"QScrollBar::handle:vertical:hover{\n"
"width:10px;\n"
"background:rgb(0,125,165,80%);\n"
"border-radius:5px;\n"
"min-height:20;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"height:20px;\n"
"background:rgb(0,0,0,0%);\n"
"margin:0px,0px,0px,0px;\n"
"padding-left:25px;   \n"
"padding-right:25px; \n"
"}\n"
"QScrollBar::handle:horizontal{\n"
"height:10px;\n"
"background:rgb(0,125,165,100%);\n"
"border-radius:5px;\n"
"min-width:20px;\n"
"}\n"
"QScrollBar::handle:horizontal:hover{\n"
"height:10px;\n"
"background:rgb(0,125,165,80%);\n"
"border-radius:"
                        "5px;\n"
"min-width:20;\n"
"}\n"
"\n"
"QTreeView::item:hover {\n"
"outline:0px;\n"
"color: rgb(255, 255, 255);\n"
"background:rgb(0,125,165,80%);\n"
"border: 1px solid rgb(0,125,165,80%);\n"
"border-radius:5px;\n"
"}\n"
"QTreeView::item:selected {\n"
"outline:0px;\n"
"color: rgb(255, 255, 255);\n"
"background:rgb(0,125,165,100%);\n"
"border: 1px solid rgb(0,125,165,100%);\n"
"border-radius:5px;\n"
"}\n"
""));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);

        tBtnUserLogin = new QToolButton(ViewWidget);
        tBtnUserLogin->setObjectName(QStringLiteral("tBtnUserLogin"));
        tBtnUserLogin->setMinimumSize(QSize(220, 45));
        tBtnUserLogin->setMaximumSize(QSize(220, 45));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/login.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnUserLogin->setIcon(icon);
        tBtnUserLogin->setIconSize(QSize(60, 60));
        tBtnUserLogin->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(tBtnUserLogin);

        tBtnSysConf = new QToolButton(ViewWidget);
        tBtnSysConf->setObjectName(QStringLiteral("tBtnSysConf"));
        tBtnSysConf->setEnabled(true);
        tBtnSysConf->setMinimumSize(QSize(220, 45));
        tBtnSysConf->setMaximumSize(QSize(220, 45));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/tools.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnSysConf->setIcon(icon1);
        tBtnSysConf->setIconSize(QSize(60, 60));
        tBtnSysConf->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(tBtnSysConf);

        tBtnRecord = new QToolButton(ViewWidget);
        tBtnRecord->setObjectName(QStringLiteral("tBtnRecord"));
        tBtnRecord->setEnabled(true);
        tBtnRecord->setMinimumSize(QSize(220, 45));
        tBtnRecord->setMaximumSize(QSize(220, 45));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/dataSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnRecord->setIcon(icon2);
        tBtnRecord->setIconSize(QSize(60, 60));
        tBtnRecord->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(tBtnRecord);

        tBtnQuitApp = new QToolButton(ViewWidget);
        tBtnQuitApp->setObjectName(QStringLiteral("tBtnQuitApp"));
        tBtnQuitApp->setMinimumSize(QSize(220, 45));
        tBtnQuitApp->setMaximumSize(QSize(220, 45));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnQuitApp->setIcon(icon3);
        tBtnQuitApp->setIconSize(QSize(60, 60));
        tBtnQuitApp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(tBtnQuitApp);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidgetBuild = new QStackedWidget(ViewWidget);
        stackedWidgetBuild->setObjectName(QStringLiteral("stackedWidgetBuild"));
        stackedWidgetBuild->setMinimumSize(QSize(1115, 690));
        stackedWidgetBuild->setStyleSheet(QString::fromUtf8("QStackedWidget{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"border:2px solid rgb(0,125,165);\n"
"border-radius:10px;\n"
"}"));

        horizontalLayout->addWidget(stackedWidgetBuild);


        retranslateUi(ViewWidget);

        QMetaObject::connectSlotsByName(ViewWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewWidget)
    {
        ViewWidget->setWindowTitle(QApplication::translate("ViewWidget", "Form", nullptr));
        tBtnUserLogin->setText(QApplication::translate("ViewWidget", " \347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        tBtnSysConf->setText(QApplication::translate("ViewWidget", " \347\263\273\347\273\237\351\205\215\347\275\256", nullptr));
        tBtnRecord->setText(QApplication::translate("ViewWidget", " \345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        tBtnQuitApp->setText(QApplication::translate("ViewWidget", " \351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewWidget: public Ui_ViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWIDGET_H
