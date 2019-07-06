/********************************************************************************
** Form generated from reading UI file 'forget_two.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGET_TWO_H
#define UI_FORGET_TWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forget_two
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *talkphoto;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QTextBrowser *ID;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *again;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *reset;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *forget_two)
    {
        if (forget_two->objectName().isEmpty())
            forget_two->setObjectName(QString::fromUtf8("forget_two"));
        forget_two->resize(502, 276);
        forget_two->setMinimumSize(QSize(502, 275));
        forget_two->setMaximumSize(QSize(524, 276));
        verticalLayout_2 = new QVBoxLayout(forget_two);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        talkphoto = new QLabel(forget_two);
        talkphoto->setObjectName(QString::fromUtf8("talkphoto"));
        talkphoto->setMinimumSize(QSize(502, 100));
        talkphoto->setMaximumSize(QSize(502, 100));

        horizontalLayout_5->addWidget(talkphoto);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        label_4 = new QLabel(forget_two);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 25));
        label_4->setMaximumSize(QSize(80, 25));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_4);

        ID = new QTextBrowser(forget_two);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(0, 25));
        ID->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(ID);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_2 = new QLabel(forget_two);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(80, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_2);

        password = new QLineEdit(forget_two);
        password->setObjectName(QString::fromUtf8("password"));
        password->setMinimumSize(QSize(0, 25));
        password->setMaximumSize(QSize(16777215, 25));
        password->setEchoMode(QLineEdit::Password);

        horizontalLayout_6->addWidget(password);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(forget_two);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setMaximumSize(QSize(80, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_3);

        again = new QLineEdit(forget_two);
        again->setObjectName(QString::fromUtf8("again"));
        again->setMinimumSize(QSize(0, 25));
        again->setMaximumSize(QSize(16777215, 25));
        again->setEchoMode(QLineEdit::Password);

        horizontalLayout_7->addWidget(again);


        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_4->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        reset = new QPushButton(forget_two);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout->addWidget(reset);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(forget_two);

        QMetaObject::connectSlotsByName(forget_two);
    } // setupUi

    void retranslateUi(QWidget *forget_two)
    {
        forget_two->setWindowTitle(QCoreApplication::translate("forget_two", "Forget Password", nullptr));
        talkphoto->setText(QString());
        label_4->setText(QCoreApplication::translate("forget_two", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("forget_two", "Password:", nullptr));
        label_3->setText(QCoreApplication::translate("forget_two", "Again:", nullptr));
        reset->setText(QCoreApplication::translate("forget_two", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forget_two: public Ui_forget_two {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGET_TWO_H
