/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *adf_but;
    QPushButton *bbs_but;
    QPushButton *crgp_but;
    QLabel *id_label;
    QTabWidget *switch_bar;
    QWidget *friend_bar;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *friend_layout;
    QListWidget *friend_list;
    QWidget *group_bar;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QListWidget *group_list;
    QWidget *notice_bar;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QListWidget *notice_list;
    QPushButton *edit_name;
    QToolButton *edit_header;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(398, 683);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setDocumentMode(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        adf_but = new QPushButton(centralWidget);
        adf_but->setObjectName(QString::fromUtf8("adf_but"));
        adf_but->setGeometry(QRect(20, 640, 89, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("Google Sans"));
        adf_but->setFont(font);
        adf_but->setCursor(QCursor(Qt::PointingHandCursor));
        bbs_but = new QPushButton(centralWidget);
        bbs_but->setObjectName(QString::fromUtf8("bbs_but"));
        bbs_but->setGeometry(QRect(290, 640, 89, 25));
        bbs_but->setFont(font);
        bbs_but->setCursor(QCursor(Qt::PointingHandCursor));
        crgp_but = new QPushButton(centralWidget);
        crgp_but->setObjectName(QString::fromUtf8("crgp_but"));
        crgp_but->setGeometry(QRect(150, 640, 111, 25));
        crgp_but->setFont(font);
        crgp_but->setCursor(QCursor(Qt::OpenHandCursor));
        id_label = new QLabel(centralWidget);
        id_label->setObjectName(QString::fromUtf8("id_label"));
        id_label->setGeometry(QRect(130, 30, 121, 17));
        id_label->setFont(font);
        switch_bar = new QTabWidget(centralWidget);
        switch_bar->setObjectName(QString::fromUtf8("switch_bar"));
        switch_bar->setGeometry(QRect(20, 120, 361, 491));
        switch_bar->setFont(font);
        switch_bar->setTabShape(QTabWidget::Triangular);
        friend_bar = new QWidget();
        friend_bar->setObjectName(QString::fromUtf8("friend_bar"));
        verticalLayout_2 = new QVBoxLayout(friend_bar);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        friend_layout = new QVBoxLayout();
        friend_layout->setSpacing(6);
        friend_layout->setObjectName(QString::fromUtf8("friend_layout"));
        friend_list = new QListWidget(friend_bar);
        friend_list->setObjectName(QString::fromUtf8("friend_list"));

        friend_layout->addWidget(friend_list);


        verticalLayout_2->addLayout(friend_layout);

        switch_bar->addTab(friend_bar, QString());
        group_bar = new QWidget();
        group_bar->setObjectName(QString::fromUtf8("group_bar"));
        verticalLayout_4 = new QVBoxLayout(group_bar);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        group_list = new QListWidget(group_bar);
        group_list->setObjectName(QString::fromUtf8("group_list"));

        verticalLayout_3->addWidget(group_list);


        verticalLayout_4->addLayout(verticalLayout_3);

        switch_bar->addTab(group_bar, QString());
        notice_bar = new QWidget();
        notice_bar->setObjectName(QString::fromUtf8("notice_bar"));
        verticalLayout_6 = new QVBoxLayout(notice_bar);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        notice_list = new QListWidget(notice_bar);
        notice_list->setObjectName(QString::fromUtf8("notice_list"));

        verticalLayout_5->addWidget(notice_list);


        verticalLayout_6->addLayout(verticalLayout_5);

        switch_bar->addTab(notice_bar, QString());
        edit_name = new QPushButton(centralWidget);
        edit_name->setObjectName(QString::fromUtf8("edit_name"));
        edit_name->setGeometry(QRect(120, 60, 161, 28));
        edit_name->setCursor(QCursor(Qt::PointingHandCursor));
        edit_name->setFlat(true);
        edit_header = new QToolButton(centralWidget);
        edit_header->setObjectName(QString::fromUtf8("edit_header"));
        edit_header->setGeometry(QRect(40, 20, 25, 27));
        edit_header->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        switch_bar->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LinuxChat", nullptr));
        adf_but->setText(QCoreApplication::translate("MainWindow", "Add Friend", nullptr));
        bbs_but->setText(QCoreApplication::translate("MainWindow", "BBS", nullptr));
        crgp_but->setText(QCoreApplication::translate("MainWindow", "Create Group", nullptr));
        id_label->setText(QCoreApplication::translate("MainWindow", "id_label", nullptr));
        switch_bar->setTabText(switch_bar->indexOf(friend_bar), QCoreApplication::translate("MainWindow", "Friends", nullptr));
        switch_bar->setTabText(switch_bar->indexOf(group_bar), QCoreApplication::translate("MainWindow", "Groups", nullptr));
        switch_bar->setTabText(switch_bar->indexOf(notice_bar), QCoreApplication::translate("MainWindow", "Notifications", nullptr));
        edit_name->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        edit_header->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
