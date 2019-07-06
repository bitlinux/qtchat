/********************************************************************************
** Form generated from reading UI file 'frienditem.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDITEM_H
#define UI_FRIENDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frienditem
{
public:
    QGridLayout *gridLayout;
    QToolButton *header_button;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *id_label;
    QLabel *name_label;
    QLabel *online_label;
    QLabel *px1;

    void setupUi(QWidget *frienditem)
    {
        if (frienditem->objectName().isEmpty())
            frienditem->setObjectName(QString::fromUtf8("frienditem"));
        frienditem->resize(424, 206);
        gridLayout = new QGridLayout(frienditem);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        header_button = new QToolButton(frienditem);
        header_button->setObjectName(QString::fromUtf8("header_button"));
        header_button->setCursor(QCursor(Qt::PointingHandCursor));

        gridLayout->addWidget(header_button, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        id_label = new QLabel(frienditem);
        id_label->setObjectName(QString::fromUtf8("id_label"));

        verticalLayout->addWidget(id_label);

        name_label = new QLabel(frienditem);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        verticalLayout->addWidget(name_label);


        horizontalLayout->addLayout(verticalLayout);

        online_label = new QLabel(frienditem);
        online_label->setObjectName(QString::fromUtf8("online_label"));
        online_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(online_label);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        px1 = new QLabel(frienditem);
        px1->setObjectName(QString::fromUtf8("px1"));
        px1->setMaximumSize(QSize(350, 1));
        px1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(px1, 1, 0, 1, 2);


        retranslateUi(frienditem);

        QMetaObject::connectSlotsByName(frienditem);
    } // setupUi

    void retranslateUi(QWidget *frienditem)
    {
        frienditem->setWindowTitle(QCoreApplication::translate("frienditem", "Form", nullptr));
        header_button->setText(QCoreApplication::translate("frienditem", "...", nullptr));
        id_label->setText(QCoreApplication::translate("frienditem", "0000000", nullptr));
        name_label->setText(QCoreApplication::translate("frienditem", "Linux", nullptr));
        online_label->setText(QCoreApplication::translate("frienditem", "offline", nullptr));
        px1->setText(QCoreApplication::translate("frienditem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frienditem: public Ui_frienditem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDITEM_H
