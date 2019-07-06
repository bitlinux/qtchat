/********************************************************************************
** Form generated from reading UI file 'bbsitem_detail.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BBSITEM_DETAIL_H
#define UI_BBSITEM_DETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_bbsitem_detail
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *reply_label;
    QLabel *title_label;
    QTextEdit *reply;
    QTextBrowser *content;
    QTextBrowser *comment;
    QLabel *comment_label;
    QPushButton *Delete;
    QLabel *time_label;

    void setupUi(QDialog *bbsitem_detail)
    {
        if (bbsitem_detail->objectName().isEmpty())
            bbsitem_detail->setObjectName(QString::fromUtf8("bbsitem_detail"));
        bbsitem_detail->resize(449, 361);
        QFont font;
        font.setPointSize(14);
        bbsitem_detail->setFont(font);
        buttonBox = new QDialogButtonBox(bbsitem_detail);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(280, 330, 161, 32));
        buttonBox->setCursor(QCursor(Qt::PointingHandCursor));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        reply_label = new QLabel(bbsitem_detail);
        reply_label->setObjectName(QString::fromUtf8("reply_label"));
        reply_label->setGeometry(QRect(280, 220, 59, 16));
        title_label = new QLabel(bbsitem_detail);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(10, 10, 261, 40));
        title_label->setMinimumSize(QSize(0, 18));
        reply = new QTextEdit(bbsitem_detail);
        reply->setObjectName(QString::fromUtf8("reply"));
        reply->setGeometry(QRect(280, 240, 161, 91));
        content = new QTextBrowser(bbsitem_detail);
        content->setObjectName(QString::fromUtf8("content"));
        content->setGeometry(QRect(10, 70, 431, 141));
        comment = new QTextBrowser(bbsitem_detail);
        comment->setObjectName(QString::fromUtf8("comment"));
        comment->setGeometry(QRect(10, 240, 251, 91));
        comment_label = new QLabel(bbsitem_detail);
        comment_label->setObjectName(QString::fromUtf8("comment_label"));
        comment_label->setGeometry(QRect(10, 220, 71, 16));
        Delete = new QPushButton(bbsitem_detail);
        Delete->setObjectName(QString::fromUtf8("Delete"));
        Delete->setGeometry(QRect(340, 10, 101, 32));
        Delete->setCursor(QCursor(Qt::PointingHandCursor));
        time_label = new QLabel(bbsitem_detail);
        time_label->setObjectName(QString::fromUtf8("time_label"));
        time_label->setGeometry(QRect(10, 50, 321, 16));
        time_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(bbsitem_detail);
        QObject::connect(buttonBox, SIGNAL(accepted()), bbsitem_detail, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), bbsitem_detail, SLOT(reject()));

        QMetaObject::connectSlotsByName(bbsitem_detail);
    } // setupUi

    void retranslateUi(QDialog *bbsitem_detail)
    {
        bbsitem_detail->setWindowTitle(QCoreApplication::translate("bbsitem_detail", "Post Detail", nullptr));
        reply_label->setText(QCoreApplication::translate("bbsitem_detail", "Reply", nullptr));
        title_label->setText(QCoreApplication::translate("bbsitem_detail", "Title", nullptr));
        comment_label->setText(QCoreApplication::translate("bbsitem_detail", "Comment", nullptr));
        Delete->setText(QCoreApplication::translate("bbsitem_detail", "Delete", nullptr));
        time_label->setText(QCoreApplication::translate("bbsitem_detail", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bbsitem_detail: public Ui_bbsitem_detail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BBSITEM_DETAIL_H
