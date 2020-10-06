/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *tBtnLogo;
    QSpacerItem *horizontalSpacer;
    QLabel *lbSystemName;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *lbSystemTime;
    QLabel *lbCompany;
    QStackedWidget *stackedWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1366, 772);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#centralWidget{\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QDialog{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QToolButton{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 122, 165);\n"
"}\n"
"QToolButton:disabled{\n"
"font: 19pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(180, 180, 180);\n"
"border-color: rgb(180, 180, 180);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(8, 0, 8, 8);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tBtnLogo = new QToolButton(centralWidget);
        tBtnLogo->setObjectName(QStringLiteral("tBtnLogo"));
        tBtnLogo->setMinimumSize(QSize(216, 50));
        tBtnLogo->setMaximumSize(QSize(216, 50));
        tBtnLogo->setStyleSheet(QLatin1String("QToolButton{\n"
"border-image: url(:/Image/Sensor.png);\n"
"}\n"
""));
        tBtnLogo->setAutoRaise(false);

        horizontalLayout->addWidget(tBtnLogo);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lbSystemName = new QLabel(centralWidget);
        lbSystemName->setObjectName(QStringLiteral("lbSystemName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbSystemName->sizePolicy().hasHeightForWidth());
        lbSystemName->setSizePolicy(sizePolicy);
        lbSystemName->setMaximumSize(QSize(366, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(26);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lbSystemName->setFont(font);
        lbSystemName->setFocusPolicy(Qt::ClickFocus);
        lbSystemName->setStyleSheet(QString::fromUtf8("font: 26pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbSystemName->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout->addWidget(lbSystemName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbSystemTime = new QLabel(centralWidget);
        lbSystemTime->setObjectName(QStringLiteral("lbSystemTime"));
        sizePolicy.setHeightForWidth(lbSystemTime->sizePolicy().hasHeightForWidth());
        lbSystemTime->setSizePolicy(sizePolicy);
        lbSystemTime->setMinimumSize(QSize(380, 25));
        lbSystemTime->setMaximumSize(QSize(380, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lbSystemTime->setFont(font1);
        lbSystemTime->setFocusPolicy(Qt::ClickFocus);
        lbSystemTime->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbSystemTime->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        verticalLayout->addWidget(lbSystemTime);

        lbCompany = new QLabel(centralWidget);
        lbCompany->setObjectName(QStringLiteral("lbCompany"));
        sizePolicy.setHeightForWidth(lbCompany->sizePolicy().hasHeightForWidth());
        lbCompany->setSizePolicy(sizePolicy);
        lbCompany->setMinimumSize(QSize(380, 25));
        lbCompany->setMaximumSize(QSize(380, 25));
        lbCompany->setFont(font1);
        lbCompany->setFocusPolicy(Qt::ClickFocus);
        lbCompany->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        lbCompany->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(lbCompany);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(1350, 700));
        stackedWidget->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:10px;"));

        verticalLayout_2->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        tBtnLogo->setText(QString());
        lbSystemName->setText(QApplication::translate("MainWindow", "\345\233\276\345\275\242\346\230\276\347\244\272\350\275\257\344\273\266", nullptr));
        lbSystemTime->setText(QApplication::translate("MainWindow", "2020/10/02 15:25:23", nullptr));
        lbCompany->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
