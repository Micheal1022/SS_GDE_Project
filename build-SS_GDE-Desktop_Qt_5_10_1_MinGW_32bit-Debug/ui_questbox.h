/********************************************************************************
** Form generated from reading UI file 'questbox.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTBOX_H
#define UI_QUESTBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_QuestBox
{
public:
    QToolButton *pBtn_ok;
    QToolButton *pBtn_cancel;
    QLabel *lb_title;
    QLabel *lb_context;

    void setupUi(QDialog *QuestBox)
    {
        if (QuestBox->objectName().isEmpty())
            QuestBox->setObjectName(QStringLiteral("QuestBox"));
        QuestBox->resize(434, 240);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        QuestBox->setFont(font);
        QuestBox->setStyleSheet(QString::fromUtf8("QDialog{\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:0px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QToolButton{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QLabel{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 122, 165);\n"
"}\n"
""));
        pBtn_ok = new QToolButton(QuestBox);
        pBtn_ok->setObjectName(QStringLiteral("pBtn_ok"));
        pBtn_ok->setGeometry(QRect(85, 175, 100, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        pBtn_ok->setIcon(icon);
        pBtn_ok->setIconSize(QSize(40, 30));
        pBtn_ok->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        pBtn_cancel = new QToolButton(QuestBox);
        pBtn_cancel->setObjectName(QStringLiteral("pBtn_cancel"));
        pBtn_cancel->setGeometry(QRect(255, 175, 100, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pBtn_cancel->setIcon(icon1);
        pBtn_cancel->setIconSize(QSize(40, 30));
        pBtn_cancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lb_title = new QLabel(QuestBox);
        lb_title->setObjectName(QStringLiteral("lb_title"));
        lb_title->setGeometry(QRect(0, 0, 434, 40));
        lb_title->setStyleSheet(QString::fromUtf8("font: 20pt \"\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 122, 165);"));
        lb_context = new QLabel(QuestBox);
        lb_context->setObjectName(QStringLiteral("lb_context"));
        lb_context->setGeometry(QRect(10, 55, 410, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lb_context->setFont(font1);
        lb_context->setStyleSheet(QString::fromUtf8("font: 16pt \"\346\245\267\344\275\223\";\n"
"color: rgb(0, 122, 165);"));
        lb_context->setAlignment(Qt::AlignCenter);

        retranslateUi(QuestBox);

        QMetaObject::connectSlotsByName(QuestBox);
    } // setupUi

    void retranslateUi(QDialog *QuestBox)
    {
        QuestBox->setWindowTitle(QApplication::translate("QuestBox", "Dialog", nullptr));
        pBtn_ok->setText(QApplication::translate("QuestBox", "\347\241\256\345\256\232", nullptr));
        pBtn_cancel->setText(QApplication::translate("QuestBox", "\345\217\226\346\266\210", nullptr));
        lb_title->setText(QString());
        lb_context->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuestBox: public Ui_QuestBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTBOX_H
