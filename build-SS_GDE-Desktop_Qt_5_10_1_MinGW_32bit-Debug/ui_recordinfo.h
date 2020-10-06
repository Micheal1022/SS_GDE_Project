/********************************************************************************
** Form generated from reading UI file 'recordinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDINFO_H
#define UI_RECORDINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordInfo
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateTimeEdit *dateTimeEditStart;
    QLabel *label_2;
    QDateTimeEdit *dateTimeEditStop;
    QToolButton *tBtnManual;
    QToolButton *tBtnAuto;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QToolButton *tBtnCheck;
    QToolButton *tBtnAllDel;
    QToolButton *tBtnExport;
    QToolButton *tBtnPageUp;
    QToolButton *tBtnPageDown;
    QToolButton *tBtnBack;

    void setupUi(QWidget *RecordInfo)
    {
        if (RecordInfo->objectName().isEmpty())
            RecordInfo->setObjectName(QStringLiteral("RecordInfo"));
        RecordInfo->resize(1732, 690);
        RecordInfo->setStyleSheet(QString::fromUtf8("QWidget#RecordInfo{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLabel{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 0, 0);\n"
"}\n"
"QToolButton{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(180, 180, 180);\n"
"border:2px solid rgb(180, 180, 180);\n"
"border-radius:10px;\n"
"}\n"
"QTableWidget{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"gridline-color: rgb(0, 0, 0);\n"
"border:1px solid rgb(0, 125, 165);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QTableWidgetItem{\n"
"outline:0px;\n"
"border:1px solid rgb(0, 0, 0);\n"
"}\n"
"QDateTimeEdit{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-radius:5px;\n"
""
                        "border:1px solid rgb(0, 125, 165);\n"
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
"}"));
        verticalLayout = new QVBoxLayout(RecordInfo);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        tableWidget = new QTableWidget(RecordInfo);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QLatin1String("QTableWidget{\n"
"border:1px solid rgb(0,125,165);\n"
"border-radius:10px;\n"
"}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(RecordInfo);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 60));
        label->setMaximumSize(QSize(60, 60));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        dateTimeEditStart = new QDateTimeEdit(RecordInfo);
        dateTimeEditStart->setObjectName(QStringLiteral("dateTimeEditStart"));
        sizePolicy.setHeightForWidth(dateTimeEditStart->sizePolicy().hasHeightForWidth());
        dateTimeEditStart->setSizePolicy(sizePolicy);
        dateTimeEditStart->setMinimumSize(QSize(300, 60));
        dateTimeEditStart->setMaximumSize(QSize(300, 60));
        dateTimeEditStart->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        dateTimeEditStart->setDateTime(QDateTime(QDate(2020, 1, 1), QTime(0, 0, 0)));

        horizontalLayout_2->addWidget(dateTimeEditStart);

        label_2 = new QLabel(RecordInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 60));
        label_2->setMaximumSize(QSize(60, 60));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        dateTimeEditStop = new QDateTimeEdit(RecordInfo);
        dateTimeEditStop->setObjectName(QStringLiteral("dateTimeEditStop"));
        sizePolicy.setHeightForWidth(dateTimeEditStop->sizePolicy().hasHeightForWidth());
        dateTimeEditStop->setSizePolicy(sizePolicy);
        dateTimeEditStop->setMinimumSize(QSize(300, 60));
        dateTimeEditStop->setMaximumSize(QSize(300, 60));
        dateTimeEditStop->setStyleSheet(QStringLiteral(""));
        dateTimeEditStop->setButtonSymbols(QAbstractSpinBox::PlusMinus);

        horizontalLayout_2->addWidget(dateTimeEditStop);

        tBtnManual = new QToolButton(RecordInfo);
        tBtnManual->setObjectName(QStringLiteral("tBtnManual"));
        tBtnManual->setMinimumSize(QSize(120, 60));
        tBtnManual->setMaximumSize(QSize(120, 60));
        tBtnManual->setIconSize(QSize(40, 40));
        tBtnManual->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnManual);

        tBtnAuto = new QToolButton(RecordInfo);
        tBtnAuto->setObjectName(QStringLiteral("tBtnAuto"));
        tBtnAuto->setMinimumSize(QSize(120, 60));
        tBtnAuto->setMaximumSize(QSize(120, 60));
        tBtnAuto->setIconSize(QSize(40, 40));
        tBtnAuto->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnAuto);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(2, 1);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 10, -1);
        tBtnCheck = new QToolButton(RecordInfo);
        tBtnCheck->setObjectName(QStringLiteral("tBtnCheck"));
        tBtnCheck->setMinimumSize(QSize(110, 60));
        tBtnCheck->setMaximumSize(QSize(110, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/dataSearch.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnCheck->setIcon(icon);
        tBtnCheck->setIconSize(QSize(40, 40));
        tBtnCheck->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnCheck);

        tBtnAllDel = new QToolButton(RecordInfo);
        tBtnAllDel->setObjectName(QStringLiteral("tBtnAllDel"));
        tBtnAllDel->setMinimumSize(QSize(110, 60));
        tBtnAllDel->setMaximumSize(QSize(110, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/dataDel.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAllDel->setIcon(icon1);
        tBtnAllDel->setIconSize(QSize(40, 40));
        tBtnAllDel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnAllDel);

        tBtnExport = new QToolButton(RecordInfo);
        tBtnExport->setObjectName(QStringLiteral("tBtnExport"));
        tBtnExport->setMinimumSize(QSize(110, 60));
        tBtnExport->setMaximumSize(QSize(110, 60));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/dataExport.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnExport->setIcon(icon2);
        tBtnExport->setIconSize(QSize(40, 40));
        tBtnExport->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnExport);

        tBtnPageUp = new QToolButton(RecordInfo);
        tBtnPageUp->setObjectName(QStringLiteral("tBtnPageUp"));
        tBtnPageUp->setMinimumSize(QSize(110, 60));
        tBtnPageUp->setMaximumSize(QSize(110, 60));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnPageUp->setIcon(icon3);
        tBtnPageUp->setIconSize(QSize(40, 40));
        tBtnPageUp->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnPageUp);

        tBtnPageDown = new QToolButton(RecordInfo);
        tBtnPageDown->setObjectName(QStringLiteral("tBtnPageDown"));
        tBtnPageDown->setEnabled(true);
        tBtnPageDown->setMinimumSize(QSize(110, 60));
        tBtnPageDown->setMaximumSize(QSize(110, 60));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Image/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnPageDown->setIcon(icon4);
        tBtnPageDown->setIconSize(QSize(40, 40));
        tBtnPageDown->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnPageDown);

        tBtnBack = new QToolButton(RecordInfo);
        tBtnBack->setObjectName(QStringLiteral("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setMinimumSize(QSize(110, 60));
        tBtnBack->setMaximumSize(QSize(110, 60));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon5);
        tBtnBack->setIconSize(QSize(40, 40));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(tBtnBack);

        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);

        horizontalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);

        retranslateUi(RecordInfo);

        QMetaObject::connectSlotsByName(RecordInfo);
    } // setupUi

    void retranslateUi(QWidget *RecordInfo)
    {
        RecordInfo->setWindowTitle(QApplication::translate("RecordInfo", "Form", nullptr));
        label->setText(QApplication::translate("RecordInfo", "\345\274\200\345\247\213\n"
"\346\227\266\351\227\264", nullptr));
        dateTimeEditStart->setDisplayFormat(QApplication::translate("RecordInfo", "yyyy/MM/dd hh:mm:ss", nullptr));
        label_2->setText(QApplication::translate("RecordInfo", "\347\273\223\346\235\237\n"
"\346\227\266\351\227\264", nullptr));
        dateTimeEditStop->setDisplayFormat(QApplication::translate("RecordInfo", "yyyy/MM/dd hh:mm:ss", nullptr));
        tBtnManual->setText(QApplication::translate("RecordInfo", "\346\211\213\345\212\250\350\260\203\346\227\266", nullptr));
        tBtnAuto->setText(QApplication::translate("RecordInfo", "\350\207\252\345\212\250\350\260\203\346\227\266", nullptr));
        tBtnCheck->setText(QApplication::translate("RecordInfo", "\346\237\245\350\257\242", nullptr));
        tBtnAllDel->setText(QApplication::translate("RecordInfo", "\345\210\240\351\231\244", nullptr));
        tBtnExport->setText(QApplication::translate("RecordInfo", "\345\257\274\345\207\272", nullptr));
        tBtnPageUp->setText(QApplication::translate("RecordInfo", "\344\270\212\347\277\273", nullptr));
        tBtnPageDown->setText(QApplication::translate("RecordInfo", "\344\270\213\347\277\273", nullptr));
        tBtnBack->setText(QApplication::translate("RecordInfo", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordInfo: public Ui_RecordInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDINFO_H
