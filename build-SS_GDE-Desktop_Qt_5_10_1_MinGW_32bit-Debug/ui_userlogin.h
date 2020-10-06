/********************************************************************************
** Form generated from reading UI file 'userlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

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

class Ui_UserLogin
{
public:
    QToolButton *tBtnAdmin;
    QToolButton *tBtnLogin;
    QToolButton *tBtnHide;
    QLabel *lbUser;
    QLabel *label_3;
    QLineEdit *lineEditPwd;
    QLabel *label;

    void setupUi(QDialog *UserLogin)
    {
        if (UserLogin->objectName().isEmpty())
            UserLogin->setObjectName(QStringLiteral("UserLogin"));
        UserLogin->resize(426, 300);
        UserLogin->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border: 0px solid rgb(0, 125, 126);\n"
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
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 122, 165);\n"
"border-radius:10px;\n"
"background-color: rgb(0, 125, 165);\n"
"}\n"
"QLineEdit{\n"
"font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(255, 255, 255);\n"
"border: 2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"}\n"
"QLabel{\n"
"font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color:rgb(15, 41, 68);\n"
"}\n"
"QDialog{\n"
"background-color: rgb(255, 255, 255);\n"
"border:2px solid rgb(0, 125, 165);\n"
"border-radius:10px;\n"
"}\n"
""));
        tBtnAdmin = new QToolButton(UserLogin);
        tBtnAdmin->setObjectName(QStringLiteral("tBtnAdmin"));
        tBtnAdmin->setGeometry(QRect(80, 80, 271, 50));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tBtnAdmin->sizePolicy().hasHeightForWidth());
        tBtnAdmin->setSizePolicy(sizePolicy);
        tBtnAdmin->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tBtnAdmin->setFont(font);
        tBtnAdmin->setFocusPolicy(Qt::NoFocus);
        tBtnAdmin->setAutoRepeat(true);
        tBtnLogin = new QToolButton(UserLogin);
        tBtnLogin->setObjectName(QStringLiteral("tBtnLogin"));
        tBtnLogin->setGeometry(QRect(80, 235, 120, 50));
        tBtnLogin->setFont(font);
        tBtnLogin->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnLogin->setIcon(icon);
        tBtnLogin->setIconSize(QSize(35, 35));
        tBtnLogin->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tBtnHide = new QToolButton(UserLogin);
        tBtnHide->setObjectName(QStringLiteral("tBtnHide"));
        tBtnHide->setEnabled(true);
        tBtnHide->setGeometry(QRect(225, 235, 120, 50));
        tBtnHide->setFont(font);
        tBtnHide->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        tBtnHide->setIcon(icon1);
        tBtnHide->setIconSize(QSize(35, 35));
        tBtnHide->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        lbUser = new QLabel(UserLogin);
        lbUser->setObjectName(QStringLiteral("lbUser"));
        lbUser->setGeometry(QRect(25, 80, 50, 50));
        lbUser->setStyleSheet(QLatin1String("\n"
"border-image: url(:/pic/login.png);"));
        label_3 = new QLabel(UserLogin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 50, 50));
        label_3->setStyleSheet(QStringLiteral("border-image: url(:/pic/pwd.png);"));
        lineEditPwd = new QLineEdit(UserLogin);
        lineEditPwd->setObjectName(QStringLiteral("lineEditPwd"));
        lineEditPwd->setGeometry(QRect(80, 160, 270, 50));
        lineEditPwd->setFocusPolicy(Qt::StrongFocus);
        lineEditPwd->setMaxLength(6);
        lineEditPwd->setEchoMode(QLineEdit::Password);
        lineEditPwd->setAlignment(Qt::AlignCenter);
        label = new QLabel(UserLogin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 15, 384, 46));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(UserLogin);

        QMetaObject::connectSlotsByName(UserLogin);
    } // setupUi

    void retranslateUi(QDialog *UserLogin)
    {
        UserLogin->setWindowTitle(QApplication::translate("UserLogin", "Dialog", nullptr));
        tBtnAdmin->setText(QApplication::translate("UserLogin", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
        tBtnLogin->setText(QApplication::translate("UserLogin", "\347\241\256\350\256\244", nullptr));
        tBtnHide->setText(QApplication::translate("UserLogin", "\345\205\263\351\227\255", nullptr));
        lbUser->setText(QString());
        label_3->setText(QString());
        lineEditPwd->setText(QString());
        lineEditPwd->setPlaceholderText(QApplication::translate("UserLogin", " \350\257\267\350\276\223\345\205\245\345\257\206\347\240\201......", nullptr));
        label->setText(QApplication::translate("UserLogin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\347\231\273\345\275\225\345\257\206\347\240\201!!!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserLogin: public Ui_UserLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
