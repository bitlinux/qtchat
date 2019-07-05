/********************************************************************************
** Form generated from reading UI file 'forget_one.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGET_ONE_H
#define UI_FORGET_ONE_H

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

class Ui_forget_one
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *talkphoto;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QTextBrowser *ID;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QTextBrowser *problem_1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *answer_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QTextBrowser *problem_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *answer_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *next;

    void setupUi(QWidget *forget_one)
    {
        if (forget_one->objectName().isEmpty())
            forget_one->setObjectName(QString::fromUtf8("forget_one"));
        forget_one->resize(502, 326);
        forget_one->setMinimumSize(QSize(502, 320));
        forget_one->setMaximumSize(QSize(522, 332));
        verticalLayout_3 = new QVBoxLayout(forget_one);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        talkphoto = new QLabel(forget_one);
        talkphoto->setObjectName(QString::fromUtf8("talkphoto"));
        talkphoto->setMinimumSize(QSize(500, 100));
        talkphoto->setMaximumSize(QSize(500, 100));

        horizontalLayout->addWidget(talkphoto);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        horizontalLayout_2->addLayout(horizontalLayout_6);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(forget_one);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_6);

        ID = new QTextBrowser(forget_one);
        ID->setObjectName(QString::fromUtf8("ID"));
        ID->setMinimumSize(QSize(0, 25));
        ID->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(ID);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(forget_one);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_5);

        problem_1 = new QTextBrowser(forget_one);
        problem_1->setObjectName(QString::fromUtf8("problem_1"));
        problem_1->setMinimumSize(QSize(0, 25));
        problem_1->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(problem_1);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(forget_one);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        answer_1 = new QLineEdit(forget_one);
        answer_1->setObjectName(QString::fromUtf8("answer_1"));
        answer_1->setMinimumSize(QSize(0, 25));
        answer_1->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(answer_1);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(forget_one);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        problem_2 = new QTextBrowser(forget_one);
        problem_2->setObjectName(QString::fromUtf8("problem_2"));
        problem_2->setMinimumSize(QSize(0, 25));
        problem_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(problem_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(forget_one);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        answer_2 = new QLineEdit(forget_one);
        answer_2->setObjectName(QString::fromUtf8("answer_2"));
        answer_2->setMinimumSize(QSize(0, 25));
        answer_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(answer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_9->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);

        next = new QPushButton(forget_one);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout_10->addWidget(next);


        verticalLayout->addLayout(horizontalLayout_10);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(forget_one);

        QMetaObject::connectSlotsByName(forget_one);
    } // setupUi

    void retranslateUi(QWidget *forget_one)
    {
        forget_one->setWindowTitle(QCoreApplication::translate("forget_one", "Forget Password", nullptr));
        talkphoto->setText(QString());
        label_6->setText(QCoreApplication::translate("forget_one", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("forget_one", "PROBLEM1", nullptr));
        label_4->setText(QCoreApplication::translate("forget_one", "ANSWER1", nullptr));
        label_3->setText(QCoreApplication::translate("forget_one", "PROBLEM2", nullptr));
        label_2->setText(QCoreApplication::translate("forget_one", "ANSWER2", nullptr));
        next->setText(QCoreApplication::translate("forget_one", "NEXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forget_one: public Ui_forget_one {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGET_ONE_H
