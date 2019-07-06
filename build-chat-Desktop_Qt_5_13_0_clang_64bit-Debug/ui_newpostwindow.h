/********************************************************************************
** Form generated from reading UI file 'newpostwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPOSTWINDOW_H
#define UI_NEWPOSTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NewPostWindow
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextEdit *contentEdit;
    QLabel *label;
    QLineEdit *titleEdit;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewPostWindow)
    {
        if (NewPostWindow->objectName().isEmpty())
            NewPostWindow->setObjectName(QString::fromUtf8("NewPostWindow"));
        NewPostWindow->resize(422, 339);
        gridLayout_2 = new QGridLayout(NewPostWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        contentEdit = new QTextEdit(NewPostWindow);
        contentEdit->setObjectName(QString::fromUtf8("contentEdit"));

        gridLayout->addWidget(contentEdit, 1, 1, 1, 1);

        label = new QLabel(NewPostWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        titleEdit = new QLineEdit(NewPostWindow);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));

        gridLayout->addWidget(titleEdit, 0, 1, 1, 1);

        label_2 = new QLabel(NewPostWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewPostWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(NewPostWindow);
        QObject::connect(buttonBox, SIGNAL(rejected()), NewPostWindow, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), NewPostWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(NewPostWindow);
    } // setupUi

    void retranslateUi(QDialog *NewPostWindow)
    {
        NewPostWindow->setWindowTitle(QCoreApplication::translate("NewPostWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewPostWindow", "Title:", nullptr));
        label_2->setText(QCoreApplication::translate("NewPostWindow", "Content:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewPostWindow: public Ui_NewPostWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPOSTWINDOW_H
