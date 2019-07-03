/********************************************************************************
** Form generated from reading UI file 'reg_two.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_TWO_H
#define UI_REG_TWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reg_two
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *talkphoto;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *problem_1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *answer_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *problem_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *answer_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *back;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *register_2;

    void setupUi(QWidget *reg_two)
    {
        if (reg_two->objectName().isEmpty())
            reg_two->setObjectName(QString::fromUtf8("reg_two"));
        reg_two->resize(502, 300);
        reg_two->setMinimumSize(QSize(502, 300));
        reg_two->setMaximumSize(QSize(502, 300));
        verticalLayout_3 = new QVBoxLayout(reg_two);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        talkphoto = new QLabel(reg_two);
        talkphoto->setObjectName(QString::fromUtf8("talkphoto"));
        talkphoto->setMinimumSize(QSize(500, 100));
        talkphoto->setMaximumSize(QSize(500, 100));

        horizontalLayout->addWidget(talkphoto);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(reg_two);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(80, 0));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_5);

        problem_1 = new QLineEdit(reg_two);
        problem_1->setObjectName(QString::fromUtf8("problem_1"));

        horizontalLayout_6->addWidget(problem_1);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(reg_two);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_4);

        answer_1 = new QLineEdit(reg_two);
        answer_1->setObjectName(QString::fromUtf8("answer_1"));

        horizontalLayout_5->addWidget(answer_1);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(reg_two);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_3);

        problem_2 = new QLineEdit(reg_two);
        problem_2->setObjectName(QString::fromUtf8("problem_2"));

        horizontalLayout_4->addWidget(problem_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(reg_two);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_2);

        answer_2 = new QLineEdit(reg_two);
        answer_2->setObjectName(QString::fromUtf8("answer_2"));

        horizontalLayout_3->addWidget(answer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        back = new QPushButton(reg_two);
        back->setObjectName(QString::fromUtf8("back"));

        horizontalLayout_7->addWidget(back);

        horizontalSpacer_4 = new QSpacerItem(120, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        register_2 = new QPushButton(reg_two);
        register_2->setObjectName(QString::fromUtf8("register_2"));

        horizontalLayout_7->addWidget(register_2);


        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(reg_two);

        QMetaObject::connectSlotsByName(reg_two);
    } // setupUi

    void retranslateUi(QWidget *reg_two)
    {
        reg_two->setWindowTitle(QCoreApplication::translate("reg_two", "Register", nullptr));
        talkphoto->setText(QString());
        label_5->setText(QCoreApplication::translate("reg_two", "PROBLEM1", nullptr));
        label_4->setText(QCoreApplication::translate("reg_two", "ANSWER1", nullptr));
        label_3->setText(QCoreApplication::translate("reg_two", "PROBLEM2", nullptr));
        label_2->setText(QCoreApplication::translate("reg_two", "ANSWER2", nullptr));
        back->setText(QCoreApplication::translate("reg_two", "BACK", nullptr));
        register_2->setText(QCoreApplication::translate("reg_two", "REGISTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg_two: public Ui_reg_two {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_TWO_H
