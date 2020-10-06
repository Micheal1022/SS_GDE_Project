/********************************************************************************
** Form generated from reading UI file 'systemconf.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMCONF_H
#define UI_SYSTEMCONF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemConf
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbExplain;
    QSpacerItem *horizontalSpacer;
    QToolButton *tBtnDel;
    QToolButton *tBtnSave;
    QToolButton *tBtnAdd;
    QToolButton *tBtnBack;

    void setupUi(QWidget *SystemConf)
    {
        if (SystemConf->objectName().isEmpty())
            SystemConf->setObjectName(QStringLiteral("SystemConf"));
        SystemConf->resize(1599, 700);
        SystemConf->setStyleSheet(QString::fromUtf8("QWidget#SystemConf{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid  rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"\n"
"QLabel{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"QGroupBox{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"color:rgb(61, 68, 75);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border:2px solid rgb(61, 68, 75);\n"
"border-radius:8px;\n"
"margin-top:22px;\n"
"}\n"
"QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"left: 5px;\n"
"}\n"
"QLineEdit{\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(15, 41, 68);\n"
"border-radius:5px;\n"
"border:2px solid rgb(0, 125, 165);\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QCheckBox{\n"
"spacing: 5px;\n"
"font: 18pt \"\345\276\256\350\275\257"
                        "\351\233\205\351\273\221\";\n"
"color:rgb(15, 41, 68);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border:2px solid rgb(61, 68, 75);\n"
"border-radius:5px;\n"
"}\n"
"QCheckBox::indicator{\n"
"border:1px solid black;\n"
"width:25px;\n"
"height:25px;\n"
"margin-left:5px;\n"
"border-radius:2px;\n"
"image: url(:/Image/uncheck.png);\n"
"}\n"
"QCheckBox::indicator::unchecked {\n"
"image: url(:/Image/uncheck.png);\n"
"}\n"
"QCheckBox::indicator::checked {\n"
"image: url(:/Image/checked.png);\n"
"}\n"
"QTableWidget{\n"
"font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"gridline-color: rgb(0, 0, 0);\n"
"border:1px solid rgb(0, 122, 165);\n"
"border-radius:5px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QTableWidgetItem{\n"
"border:1px solid rgb(0, 0, 0);\n"
"}\n"
"\n"
"QGroupBox{\n"
"font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(0, 125, 165);\n"
"color:rgb(0,   0,   0);\n"
"border:1px solid rgb(0, 125, 165);\n"
"border-radius:5px;\n"
"margin-top:0px;\n"
"}\n"
""
                        "QGroupBox:title{\n"
"subcontrol-origin: margin;\n"
"left: 5px;\n"
"}"));
        verticalLayout = new QVBoxLayout(SystemConf);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        tableWidget = new QTableWidget(SystemConf);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbExplain = new QLabel(SystemConf);
        lbExplain->setObjectName(QStringLiteral("lbExplain"));
        lbExplain->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font: 16pt \"\346\245\267\344\275\223\";\n"
"}"));

        horizontalLayout_2->addWidget(lbExplain);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tBtnDel = new QToolButton(SystemConf);
        tBtnDel->setObjectName(QStringLiteral("tBtnDel"));
        tBtnDel->setMinimumSize(QSize(150, 60));
        tBtnDel->setMaximumSize(QSize(150, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnDel->setFont(font);
        tBtnDel->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/delDev.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnDel->setIcon(icon);
        tBtnDel->setIconSize(QSize(40, 40));
        tBtnDel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnDel);

        tBtnSave = new QToolButton(SystemConf);
        tBtnSave->setObjectName(QStringLiteral("tBtnSave"));
        tBtnSave->setMinimumSize(QSize(110, 60));
        tBtnSave->setMaximumSize(QSize(110, 60));
        tBtnSave->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnSave->setIcon(icon1);
        tBtnSave->setIconSize(QSize(40, 40));
        tBtnSave->setChecked(false);
        tBtnSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnSave);

        tBtnAdd = new QToolButton(SystemConf);
        tBtnAdd->setObjectName(QStringLiteral("tBtnAdd"));
        tBtnAdd->setMinimumSize(QSize(150, 60));
        tBtnAdd->setMaximumSize(QSize(150, 60));
        tBtnAdd->setFont(font);
        tBtnAdd->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Image/addDev.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnAdd->setIcon(icon2);
        tBtnAdd->setIconSize(QSize(40, 40));
        tBtnAdd->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnAdd);

        tBtnBack = new QToolButton(SystemConf);
        tBtnBack->setObjectName(QStringLiteral("tBtnBack"));
        tBtnBack->setMinimumSize(QSize(110, 60));
        tBtnBack->setMaximumSize(QSize(110, 60));
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Image/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon3);
        tBtnBack->setIconSize(QSize(40, 40));
        tBtnBack->setChecked(false);
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(tBtnBack);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 10);

        retranslateUi(SystemConf);

        QMetaObject::connectSlotsByName(SystemConf);
    } // setupUi

    void retranslateUi(QWidget *SystemConf)
    {
        SystemConf->setWindowTitle(QApplication::translate("SystemConf", "Form", nullptr));
        lbExplain->setText(QApplication::translate("SystemConf", "      1\357\274\211\351\205\215\347\275\256\347\232\204\347\253\257\345\217\243\344\270\216\344\270\273\346\234\272\347\232\204\345\233\236\350\267\257\347\233\270\345\257\271\345\272\224\357\274\214\351\205\215\347\275\256\347\253\257\345\217\243-1\357\274\214\345\257\271\345\272\224\344\270\273\346\234\272\347\232\204\345\233\236\350\267\257-1\357\274\233\n"
"\350\257\264\346\230\216\357\274\2322\357\274\211\347\253\257\345\217\243\351\205\215\347\275\256\344\270\2720\357\274\214\350\241\250\347\244\272\344\270\215\345\220\257\347\224\250\350\257\245\347\253\257\345\217\243\357\274\233\n"
"      3\357\274\211\345\220\257\347\224\250\347\212\266\346\200\201\345\210\227\350\241\250\347\244\272\345\257\271\345\272\224\347\233\221\346\216\247\344\270\273\346\234\272\347\232\204\347\275\221\347\273\234\345\212\237\350\203\275\346\230\257\345\220\246\345\220\257\347\224\250", nullptr));
        tBtnDel->setText(QApplication::translate("SystemConf", "\345\210\240\351\231\244\344\270\273\346\234\272", nullptr));
        tBtnSave->setText(QApplication::translate("SystemConf", "\344\277\235\345\255\230", nullptr));
        tBtnAdd->setText(QApplication::translate("SystemConf", "\345\242\236\345\212\240\344\270\273\346\234\272", nullptr));
        tBtnBack->setText(QApplication::translate("SystemConf", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemConf: public Ui_SystemConf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMCONF_H
