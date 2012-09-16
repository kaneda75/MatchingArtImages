/********************************************************************************
** Form generated from reading UI file 'formulari.ui'
**
** Created: Sun Sep 16 16:35:08 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULARI_H
#define UI_FORMULARI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_formulari
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *formulari)
    {
        if (formulari->objectName().isEmpty())
            formulari->setObjectName(QString::fromUtf8("formulari"));
        formulari->resize(400, 300);
        buttonBox = new QDialogButtonBox(formulari);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(formulari);
        QObject::connect(buttonBox, SIGNAL(accepted()), formulari, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), formulari, SLOT(reject()));

        QMetaObject::connectSlotsByName(formulari);
    } // setupUi

    void retranslateUi(QDialog *formulari)
    {
        formulari->setWindowTitle(QApplication::translate("formulari", "formulari", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class formulari: public Ui_formulari {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULARI_H
