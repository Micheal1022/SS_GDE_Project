/********************************************************************************
** Form generated from reading UI file 'userlgoin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLGOIN_H
#define UI_USERLGOIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_UserLgoin
{
public:
    QToolButton *tBtnAdmin;
    QToolButton *tBtnOk;
    QToolButton *tBtnSuper;
    QToolButton *tBtnBack;
    QLabel *lbUser;
    QLabel *label_3;
    QLineEdit *lineEditPwd;
    QLabel *label;

    void setupUi(QDialog *UserLgoin)
    {
        if (UserLgoin->objectName().isEmpty())
            UserLgoin->setObjectName(QStringLiteral("UserLgoin"));
        UserLgoin->resize(426, 300);
        UserLgoin->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"font: 18pt \"\346\245\267\344\275\223\";\n"
"border: 0px solid rgb(14, 237, 237);\n"
"border-radius:8px;\n"
"margin-top:10px;\n"
"}\n"
"QGroupBox:title{\n"
"color:white;\n"
"subcontrol-origin: margin;\n"
"subcontrol-position: top center;\n"
"left: 5px;\n"
"}\n"
"QToolButton{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QLineEdit{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"font: 20pt \"\346\245\267\344\275\223\";\n"
"color:rgb(15, 41, 68);\n"
"}\n"
"QDialog{\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"}\n"
""));
        tBtnAdmin = new QToolButton(UserLgoin);
        tBtnAdmin->setObjectName(QStringLiteral("tBtnAdmin"));
        tBtnAdmin->setGeometry(QRect(80, 80, 120, 50));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtnAdmin->sizePolicy().hasHeightForWidth());
        tBtnAdmin->setSizePolicy(sizePolicy);
        tBtnAdmin->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnAdmin->setFont(font);
        tBtnAdmin->setFocusPolicy(Qt::NoFocus);
        tBtnAdmin->setAutoRepeat(true);
        tBtnOk = new QToolButton(UserLgoin);
        tBtnOk->setObjectName(QStringLiteral("tBtnOk"));
        tBtnOk->setGeometry(QRect(80, 235, 120, 50));
        tBtnOk->setFont(font);
        tBtnOk->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnOk->setIcon(icon);
        tBtnOk->setIconSize(QSize(35, 35));
        tBtnOk->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnSuper = new QToolButton(UserLgoin);
        tBtnSuper->setObjectName(QStringLiteral("tBtnSuper"));
        tBtnSuper->setGeometry(QRect(225, 80, 120, 50));
        sizePolicy.setHeightForWidth(tBtnSuper->sizePolicy().hasHeightForWidth());
        tBtnSuper->setSizePolicy(sizePolicy);
        tBtnSuper->setMinimumSize(QSize(0, 0));
        tBtnSuper->setFont(font);
        tBtnSuper->setFocusPolicy(Qt::NoFocus);
        tBtnSuper->setAutoRepeat(true);
        tBtnBack = new QToolButton(UserLgoin);
        tBtnBack->setObjectName(QStringLiteral("tBtnBack"));
        tBtnBack->setEnabled(true);
        tBtnBack->setGeometry(QRect(225, 235, 120, 50));
        tBtnBack->setFont(font);
        tBtnBack->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnBack->setIcon(icon1);
        tBtnBack->setIconSize(QSize(35, 35));
        tBtnBack->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbUser = new QLabel(UserLgoin);
        lbUser->setObjectName(QStringLiteral("lbUser"));
        lbUser->setGeometry(QRect(25, 80, 50, 50));
        lbUser->setStyleSheet(QLatin1String("\n"
"border-image: url(:/pic/login.png);"));
        label_3 = new QLabel(UserLgoin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 50, 50));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/pwd.png);"));
        lineEditPwd = new QLineEdit(UserLgoin);
        lineEditPwd->setObjectName(QStringLiteral("lineEditPwd"));
        lineEditPwd->setGeometry(QRect(80, 160, 270, 50));
        lineEditPwd->setFocusPolicy(Qt::StrongFocus);
        lineEditPwd->setMaxLength(6);
        lineEditPwd->setEchoMode(QLineEdit::Password);
        lineEditPwd->setAlignment(Qt::AlignCenter);
        label = new QLabel(UserLgoin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 384, 46));

        retranslateUi(UserLgoin);

        QMetaObject::connectSlotsByName(UserLgoin);
    } // setupUi

    void retranslateUi(QDialog *UserLgoin)
    {
        UserLgoin->setWindowTitle(QApplication::translate("UserLgoin", "Dialog", nullptr));
        tBtnAdmin->setText(QApplication::translate("UserLgoin", "\347\256\241\347\220\206\345\221\230", nullptr));
        tBtnOk->setText(QApplication::translate("UserLgoin", "\347\241\256\350\256\244", nullptr));
        tBtnSuper->setText(QApplication::translate("UserLgoin", "\350\266\205\347\256\241\345\221\230", nullptr));
        tBtnBack->setText(QApplication::translate("UserLgoin", "\345\205\263\351\227\255", nullptr));
        lbUser->setText(QString());
        label_3->setText(QString());
        lineEditPwd->setText(QString());
        lineEditPwd->setPlaceholderText(QApplication::translate("UserLgoin", " \350\257\267\350\276\223\345\205\245\345\257\206\347\240\201......", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserLgoin: public Ui_UserLgoin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLGOIN_H
