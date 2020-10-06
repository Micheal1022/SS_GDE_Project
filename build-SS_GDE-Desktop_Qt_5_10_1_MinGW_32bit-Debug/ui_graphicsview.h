/********************************************************************************
** Form generated from reading UI file 'graphicsview.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSVIEW_H
#define UI_GRAPHICSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbNormal;
    QLabel *lbImageNormal;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbOffLine;
    QLabel *lbImageOffLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbError;
    QLabel *lbImageError;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbAlarm;
    QLabel *lbImageAlarm;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *tBtnEdit;
    QToolButton *tBtnSave;
    QToolButton *tBtnRestore;
    QToolButton *tBtnZoomIn;
    QToolButton *tBtnZoomOut;
    QToolButton *tBtnAlignLeft;
    QToolButton *tBtnAlignRight;
    QToolButton *tBtnAlignTop;
    QToolButton *tBtnAlignBottom;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidgetAlarm;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetError;

    void setupUi(QWidget *GraphicsView)
    {
        if (GraphicsView->objectName().isEmpty())
            GraphicsView->setObjectName(QStringLiteral("GraphicsView"));
        GraphicsView->resize(1744, 902);
        GraphicsView->setStyleSheet(QString::fromUtf8("QWidget#GraphicsView{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid  rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QLabel{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QGraphicsView{\n"
"color: rgb(255, 255, 255);\n"
"border:1px solid  rgb(0, 125, 165);\n"
"}\n"
"\n"
"QTableWidget{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"gridline-color: rgb(0, 0, 0);\n"
"border:1px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QTableWidgetItem{\n"
"outline:0px;\n"
"border:1px solid rgb(0, 0, 0);\n"
"}\n"
"\n"
"QGroupBox{\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(0, 125, 165);\n"
"color:rgb(0,   0,   0);\n"
"border:1px none rgb(0, 125, 165);\n"
"border-radius:5px;\n"
"margin-top:20p"
                        "x;\n"
"}\n"
"QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"left: 5px;\n"
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
"border-radius:5px;\n"
"min-width:20;\n"
"}\n"
"QToolTip{\n"
"font:9pt \"\346\245\267"
                        "\344\275\223\";\n"
"color:rgb(0, 0, 0);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(GraphicsView);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(5);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(30);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(10, -1, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lbNormal = new QLabel(GraphicsView);
        lbNormal->setObjectName(QStringLiteral("lbNormal"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbNormal->sizePolicy().hasHeightForWidth());
        lbNormal->setSizePolicy(sizePolicy);
        lbNormal->setMinimumSize(QSize(40, 50));
        lbNormal->setMaximumSize(QSize(40, 50));

        horizontalLayout_5->addWidget(lbNormal);

        lbImageNormal = new QLabel(GraphicsView);
        lbImageNormal->setObjectName(QStringLiteral("lbImageNormal"));
        sizePolicy.setHeightForWidth(lbImageNormal->sizePolicy().hasHeightForWidth());
        lbImageNormal->setSizePolicy(sizePolicy);
        lbImageNormal->setMinimumSize(QSize(55, 50));
        lbImageNormal->setMaximumSize(QSize(55, 50));
        lbImageNormal->setStyleSheet(QStringLiteral("border-image: url(:/Image/normal.png);"));

        horizontalLayout_5->addWidget(lbImageNormal);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, -1, -1);
        lbOffLine = new QLabel(GraphicsView);
        lbOffLine->setObjectName(QStringLiteral("lbOffLine"));
        sizePolicy.setHeightForWidth(lbOffLine->sizePolicy().hasHeightForWidth());
        lbOffLine->setSizePolicy(sizePolicy);
        lbOffLine->setMinimumSize(QSize(40, 50));
        lbOffLine->setMaximumSize(QSize(40, 50));

        horizontalLayout_2->addWidget(lbOffLine);

        lbImageOffLine = new QLabel(GraphicsView);
        lbImageOffLine->setObjectName(QStringLiteral("lbImageOffLine"));
        sizePolicy.setHeightForWidth(lbImageOffLine->sizePolicy().hasHeightForWidth());
        lbImageOffLine->setSizePolicy(sizePolicy);
        lbImageOffLine->setMinimumSize(QSize(55, 50));
        lbImageOffLine->setMaximumSize(QSize(55, 50));
        lbImageOffLine->setStyleSheet(QStringLiteral("border-image: url(:/Image/offLine.png);"));

        horizontalLayout_2->addWidget(lbImageOffLine);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbError = new QLabel(GraphicsView);
        lbError->setObjectName(QStringLiteral("lbError"));
        sizePolicy.setHeightForWidth(lbError->sizePolicy().hasHeightForWidth());
        lbError->setSizePolicy(sizePolicy);
        lbError->setMinimumSize(QSize(40, 50));
        lbError->setMaximumSize(QSize(40, 50));

        horizontalLayout_3->addWidget(lbError);

        lbImageError = new QLabel(GraphicsView);
        lbImageError->setObjectName(QStringLiteral("lbImageError"));
        sizePolicy.setHeightForWidth(lbImageError->sizePolicy().hasHeightForWidth());
        lbImageError->setSizePolicy(sizePolicy);
        lbImageError->setMinimumSize(QSize(55, 50));
        lbImageError->setMaximumSize(QSize(55, 50));
        lbImageError->setStyleSheet(QStringLiteral("border-image: url(:/Image/error.png);"));

        horizontalLayout_3->addWidget(lbImageError);


        horizontalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lbAlarm = new QLabel(GraphicsView);
        lbAlarm->setObjectName(QStringLiteral("lbAlarm"));
        sizePolicy.setHeightForWidth(lbAlarm->sizePolicy().hasHeightForWidth());
        lbAlarm->setSizePolicy(sizePolicy);
        lbAlarm->setMinimumSize(QSize(40, 50));
        lbAlarm->setMaximumSize(QSize(40, 50));

        horizontalLayout_4->addWidget(lbAlarm);

        lbImageAlarm = new QLabel(GraphicsView);
        lbImageAlarm->setObjectName(QStringLiteral("lbImageAlarm"));
        sizePolicy.setHeightForWidth(lbImageAlarm->sizePolicy().hasHeightForWidth());
        lbImageAlarm->setSizePolicy(sizePolicy);
        lbImageAlarm->setMinimumSize(QSize(55, 50));
        lbImageAlarm->setMaximumSize(QSize(55, 50));
        lbImageAlarm->setStyleSheet(QStringLiteral("border-image: url(:/Image/alarm.png);"));

        horizontalLayout_4->addWidget(lbImageAlarm);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 1);
        horizontalLayout_6->setStretch(3, 1);

        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        tBtnEdit = new QToolButton(GraphicsView);
        tBtnEdit->setObjectName(QStringLiteral("tBtnEdit"));
        tBtnEdit->setMinimumSize(QSize(100, 50));
        tBtnEdit->setMaximumSize(QSize(100, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnEdit->setIcon(icon);
        tBtnEdit->setIconSize(QSize(40, 40));
        tBtnEdit->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnEdit);

        tBtnSave = new QToolButton(GraphicsView);
        tBtnSave->setObjectName(QStringLiteral("tBtnSave"));
        tBtnSave->setMinimumSize(QSize(100, 50));
        tBtnSave->setMaximumSize(QSize(100, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnSave->setIcon(icon1);
        tBtnSave->setIconSize(QSize(40, 40));
        tBtnSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnSave);

        tBtnRestore = new QToolButton(GraphicsView);
        tBtnRestore->setObjectName(QStringLiteral("tBtnRestore"));
        tBtnRestore->setMinimumSize(QSize(100, 50));
        tBtnRestore->setMaximumSize(QSize(100, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/reset.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnRestore->setIcon(icon2);
        tBtnRestore->setIconSize(QSize(40, 40));
        tBtnRestore->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnRestore);

        tBtnZoomIn = new QToolButton(GraphicsView);
        tBtnZoomIn->setObjectName(QStringLiteral("tBtnZoomIn"));
        tBtnZoomIn->setMinimumSize(QSize(100, 50));
        tBtnZoomIn->setMaximumSize(QSize(100, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnZoomIn->setIcon(icon3);
        tBtnZoomIn->setIconSize(QSize(50, 50));
        tBtnZoomIn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnZoomIn);

        tBtnZoomOut = new QToolButton(GraphicsView);
        tBtnZoomOut->setObjectName(QStringLiteral("tBtnZoomOut"));
        tBtnZoomOut->setMinimumSize(QSize(100, 50));
        tBtnZoomOut->setMaximumSize(QSize(100, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Image/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnZoomOut->setIcon(icon4);
        tBtnZoomOut->setIconSize(QSize(50, 50));
        tBtnZoomOut->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnZoomOut);

        tBtnAlignLeft = new QToolButton(GraphicsView);
        tBtnAlignLeft->setObjectName(QStringLiteral("tBtnAlignLeft"));
        tBtnAlignLeft->setEnabled(true);
        tBtnAlignLeft->setMinimumSize(QSize(120, 50));
        tBtnAlignLeft->setMaximumSize(QSize(120, 50));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Image/AlignLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAlignLeft->setIcon(icon5);
        tBtnAlignLeft->setIconSize(QSize(40, 40));
        tBtnAlignLeft->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnAlignLeft);

        tBtnAlignRight = new QToolButton(GraphicsView);
        tBtnAlignRight->setObjectName(QStringLiteral("tBtnAlignRight"));
        tBtnAlignRight->setMinimumSize(QSize(120, 50));
        tBtnAlignRight->setMaximumSize(QSize(120, 50));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Image/AlignRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAlignRight->setIcon(icon6);
        tBtnAlignRight->setIconSize(QSize(40, 40));
        tBtnAlignRight->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnAlignRight);

        tBtnAlignTop = new QToolButton(GraphicsView);
        tBtnAlignTop->setObjectName(QStringLiteral("tBtnAlignTop"));
        tBtnAlignTop->setMinimumSize(QSize(120, 50));
        tBtnAlignTop->setMaximumSize(QSize(120, 50));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Image/AlignTop.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAlignTop->setIcon(icon7);
        tBtnAlignTop->setIconSize(QSize(40, 40));
        tBtnAlignTop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnAlignTop);

        tBtnAlignBottom = new QToolButton(GraphicsView);
        tBtnAlignBottom->setObjectName(QStringLiteral("tBtnAlignBottom"));
        tBtnAlignBottom->setMinimumSize(QSize(120, 50));
        tBtnAlignBottom->setMaximumSize(QSize(120, 50));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Image/AlignBottom.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAlignBottom->setIcon(icon8);
        tBtnAlignBottom->setIconSize(QSize(40, 40));
        tBtnAlignBottom->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(tBtnAlignBottom);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(horizontalLayout_8);

        graphicsView = new QGraphicsView(GraphicsView);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setStyleSheet(QStringLiteral(""));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        groupBox = new QGroupBox(GraphicsView);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(550, 130));
        groupBox->setStyleSheet(QLatin1String("QScrollBar:vertical{\n"
"width:25px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 5, 0, 5);
        tableWidgetAlarm = new QTableWidget(groupBox);
        tableWidgetAlarm->setObjectName(QStringLiteral("tableWidgetAlarm"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidgetAlarm->sizePolicy().hasHeightForWidth());
        tableWidgetAlarm->setSizePolicy(sizePolicy1);
        tableWidgetAlarm->setMinimumSize(QSize(535, 95));
        tableWidgetAlarm->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(tableWidgetAlarm);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(GraphicsView);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(550, 130));
        groupBox_2->setStyleSheet(QLatin1String("QScrollBar:vertical{\n"
"width:25px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 5, 0, 5);
        tableWidgetError = new QTableWidget(groupBox_2);
        tableWidgetError->setObjectName(QStringLiteral("tableWidgetError"));
        sizePolicy1.setHeightForWidth(tableWidgetError->sizePolicy().hasHeightForWidth());
        tableWidgetError->setSizePolicy(sizePolicy1);
        tableWidgetError->setMinimumSize(QSize(535, 95));

        verticalLayout_3->addWidget(tableWidgetError);


        horizontalLayout->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);
        verticalLayout->setStretch(2, 1);

        retranslateUi(GraphicsView);

        QMetaObject::connectSlotsByName(GraphicsView);
    } // setupUi

    void retranslateUi(QWidget *GraphicsView)
    {
        lbNormal->setText(QApplication::translate("GraphicsView", "\346\255\243\345\270\270\n"
"\347\212\266\346\200\201", nullptr));
        lbImageNormal->setText(QString());
        lbOffLine->setText(QApplication::translate("GraphicsView", "\346\216\211\347\272\277\n"
"\347\212\266\346\200\201", nullptr));
        lbImageOffLine->setText(QString());
        lbError->setText(QApplication::translate("GraphicsView", "\346\225\205\351\232\234\n"
"\347\212\266\346\200\201", nullptr));
        lbImageError->setText(QString());
        lbAlarm->setText(QApplication::translate("GraphicsView", "\346\212\245\350\255\246\n"
"\347\212\266\346\200\201", nullptr));
        lbImageAlarm->setText(QString());
        tBtnEdit->setText(QApplication::translate("GraphicsView", "\347\274\226\350\276\221", nullptr));
        tBtnSave->setText(QApplication::translate("GraphicsView", "\344\277\235\345\255\230", nullptr));
        tBtnRestore->setText(QApplication::translate("GraphicsView", "\346\201\242\345\244\215", nullptr));
        tBtnZoomIn->setText(QApplication::translate("GraphicsView", "\346\224\276\345\244\247", nullptr));
        tBtnZoomOut->setText(QApplication::translate("GraphicsView", "\347\274\251\345\260\217", nullptr));
        tBtnAlignLeft->setText(QApplication::translate("GraphicsView", "\345\267\246\345\257\271\351\275\220", nullptr));
        tBtnAlignRight->setText(QApplication::translate("GraphicsView", "\345\217\263\345\257\271\351\275\220", nullptr));
        tBtnAlignTop->setText(QApplication::translate("GraphicsView", "\351\241\266\345\257\271\351\275\220", nullptr));
        tBtnAlignBottom->setText(QApplication::translate("GraphicsView", "\345\272\225\345\257\271\351\275\220", nullptr));
        groupBox->setTitle(QApplication::translate("GraphicsView", "\346\212\245\350\255\246\344\277\241\346\201\257", nullptr));
        groupBox_2->setTitle(QApplication::translate("GraphicsView", "\346\225\205\351\232\234\344\277\241\346\201\257", nullptr));
        Q_UNUSED(GraphicsView);
    } // retranslateUi

};

namespace Ui {
    class GraphicsView: public Ui_GraphicsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSVIEW_H
