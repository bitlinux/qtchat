/********************************************************************************
** Form generated from reading UI file 'postwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTWIDGET_H
#define UI_POSTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QTextBrowser *ContentBrowser;

    void setupUi(QWidget *PostWidget)
    {
        if (PostWidget->objectName().isEmpty())
            PostWidget->setObjectName(QString::fromUtf8("PostWidget"));
        PostWidget->resize(535, 120);
        verticalLayout = new QVBoxLayout(PostWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(PostWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        verticalLayout->addWidget(titleLabel);

        ContentBrowser = new QTextBrowser(PostWidget);
        ContentBrowser->setObjectName(QString::fromUtf8("ContentBrowser"));
        ContentBrowser->setOpenLinks(false);

        verticalLayout->addWidget(ContentBrowser);


        retranslateUi(PostWidget);

        QMetaObject::connectSlotsByName(PostWidget);
    } // setupUi

    void retranslateUi(QWidget *PostWidget)
    {
        PostWidget->setWindowTitle(QCoreApplication::translate("PostWidget", "Form", nullptr));
        titleLabel->setText(QCoreApplication::translate("PostWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostWidget: public Ui_PostWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTWIDGET_H
