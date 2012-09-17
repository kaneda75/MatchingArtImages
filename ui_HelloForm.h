/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created: Mon Sep 17 18:09:02 2012
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QLineEdit *nameEdit;
    QLineEdit *helloEdit;
    QLabel *label;
    QComboBox *comboBoxDetectorType;
    QComboBox *comboBoxDescriptorType;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QString::fromUtf8("HelloForm"));
        HelloForm->resize(386, 193);
        nameEdit = new QLineEdit(HelloForm);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(10, 30, 371, 22));
        helloEdit = new QLineEdit(HelloForm);
        helloEdit->setObjectName(QString::fromUtf8("helloEdit"));
        helloEdit->setGeometry(QRect(10, 60, 371, 22));
        label = new QLabel(HelloForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 311, 16));
        comboBoxDetectorType = new QComboBox(HelloForm);
        comboBoxDetectorType->setObjectName(QString::fromUtf8("comboBoxDetectorType"));
        comboBoxDetectorType->setGeometry(QRect(160, 90, 111, 26));
        comboBoxDescriptorType = new QComboBox(HelloForm);
        comboBoxDescriptorType->setObjectName(QString::fromUtf8("comboBoxDescriptorType"));
        comboBoxDescriptorType->setGeometry(QRect(160, 120, 111, 26));
        label_2 = new QLabel(HelloForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 96, 141, 16));
        label_3 = new QLabel(HelloForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 122, 141, 20));
        pushButton = new QPushButton(HelloForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 160, 114, 32));

        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "HelloForm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HelloForm", "Enter the name below:", 0, QApplication::UnicodeUTF8));
        comboBoxDetectorType->clear();
        comboBoxDetectorType->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "SURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SIFT", 0, QApplication::UnicodeUTF8)
        );
        comboBoxDescriptorType->clear();
        comboBoxDescriptorType->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "SURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SIFT", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("HelloForm", "Tipus de detector", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HelloForm", "Tipus de descriptor", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HelloForm", "Matching", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
