/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *talkphoto;
    QHBoxLayout *horizontalLayout;
    QLabel *photo;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *ID;
    QPushButton *register_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *password;
    QPushButton *forget;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *remember;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *login_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(502, 300);
        login->setMinimumSize(QSize(502, 300));
        login->setMaximumSize(QSize(502, 300));
        verticalLayout_3 = new QVBoxLayout(login);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        talkphoto = new QLabel(login);
        talkphoto->setObjectName(QString::fromUtf8("talkphoto"));
        talkphoto->setMinimumSize(QSize(500, 100));
        talkphoto->setMaximumSize(QSize(500, 100));

        horizontalLayout_2->addWidget(talkphoto);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        photo = new QLabel(login);
        photo->setObjectName(QString::fromUtf8("photo"));
        photo->setMinimumSize(QSize(70, 70));

        horizontalLayout->addWidget(photo);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        ID = new QLineEdit(login);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(40, 20));

        horizontalLayout_3->addWidget(ID);

        register_2 = new QPushButton(login);
        register_2->setObjectName(QString::fromUtf8("register_2"));
        register_2->setMinimumSize(QSize(100, 0));
        register_2->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(register_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        password = new QLineEdit(login);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(0, 20));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(password);

        forget = new QPushButton(login);
        forget->setObjectName(QString::fromUtf8("forget"));
        forget->setMinimumSize(QSize(100, 0));
        forget->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(forget);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_2);

        label_2 = new QLabel(login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 50));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        remember = new QRadioButton(login);
        remember->setObjectName(QString::fromUtf8("remember"));
        remember->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(remember);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        login_2 = new QPushButton(login);
        login_2->setObjectName(QString::fromUtf8("login_2"));
        login_2->setMinimumSize(QSize(0, 20));

        horizontalLayout_6->addWidget(login_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Login", nullptr));
        talkphoto->setText(QString());
        photo->setText(QString());
        label_3->setText(QCoreApplication::translate("login", "Your ID:", nullptr));
        register_2->setText(QCoreApplication::translate("login", "Register", nullptr));
        label_4->setText(QCoreApplication::translate("login", "Password:", nullptr));
        forget->setText(QCoreApplication::translate("login", "Forget Psw", nullptr));
        label_2->setText(QString());
        remember->setText(QCoreApplication::translate("login", "Remember Me", nullptr));
        login_2->setText(QCoreApplication::translate("login", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
