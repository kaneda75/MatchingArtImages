/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created: Mon Sep 17 12:05:40 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOFORM_H
#define UI_HELLOFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QLineEdit *nameEdit;
    QLineEdit *helloEdit;
    QLabel *label;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QString::fromUtf8("HelloForm"));
        HelloForm->resize(390, 94);
        nameEdit = new QLineEdit(HelloForm);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(10, 30, 371, 22));
        helloEdit = new QLineEdit(HelloForm);
        helloEdit->setObjectName(QString::fromUtf8("helloEdit"));
        helloEdit->setGeometry(QRect(10, 60, 371, 22));
        label = new QLabel(HelloForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 311, 16));

        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "HelloForm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HelloForm", "Enter the name below:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
