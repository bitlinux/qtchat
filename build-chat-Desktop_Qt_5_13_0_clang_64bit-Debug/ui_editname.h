/********************************************************************************
** Form generated from reading UI file 'editname.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITNAME_H
#define UI_EDITNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_editName
{
public:
    QLineEdit *id_input;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *editName)
    {
        if (editName->objectName().isEmpty())
            editName->setObjectName(QString::fromUtf8("editName"));
        editName->resize(400, 209);
        id_input = new QLineEdit(editName);
        id_input->setObjectName(QString::fromUtf8("id_input"));
        id_input->setGeometry(QRect(110, 90, 161, 31));
        pushButton = new QPushButton(editName);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 150, 89, 28));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(editName);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 50, 131, 20));

        retranslateUi(editName);

        QMetaObject::connectSlotsByName(editName);
    } // setupUi

    void retranslateUi(QDialog *editName)
    {
        editName->setWindowTitle(QCoreApplication::translate("editName", "Edit Name", nullptr));
        pushButton->setText(QCoreApplication::translate("editName", "OK", nullptr));
        label->setText(QCoreApplication::translate("editName", "Input New Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editName: public Ui_editName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITNAME_H
