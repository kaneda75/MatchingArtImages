/********************************************************************************
** Form generated from reading UI file 'HelloForm.ui'
**
** Created: Sat Oct 27 16:58:24 2012
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
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QComboBox *comboBoxDetectorType;
    QComboBox *comboBoxDescriptorType;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QComboBox *comboBoxMatcherType;
    QLabel *label_5;
    QComboBox *comboBoxColor;

    void setupUi(QDialog *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QString::fromUtf8("HelloForm"));
        HelloForm->resize(402, 195);
        comboBoxDetectorType = new QComboBox(HelloForm);
        comboBoxDetectorType->setObjectName(QString::fromUtf8("comboBoxDetectorType"));
        comboBoxDetectorType->setGeometry(QRect(160, 8, 111, 26));
        comboBoxDescriptorType = new QComboBox(HelloForm);
        comboBoxDescriptorType->setObjectName(QString::fromUtf8("comboBoxDescriptorType"));
        comboBoxDescriptorType->setGeometry(QRect(160, 36, 111, 26));
        label_2 = new QLabel(HelloForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(21, 14, 141, 16));
        label_3 = new QLabel(HelloForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 38, 141, 20));
        pushButton = new QPushButton(HelloForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 150, 114, 32));
        label_4 = new QLabel(HelloForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(21, 66, 141, 20));
        comboBoxMatcherType = new QComboBox(HelloForm);
        comboBoxMatcherType->setObjectName(QString::fromUtf8("comboBoxMatcherType"));
        comboBoxMatcherType->setGeometry(QRect(160, 64, 111, 26));
        label_5 = new QLabel(HelloForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(24, 92, 141, 20));
        comboBoxColor = new QComboBox(HelloForm);
        comboBoxColor->setObjectName(QString::fromUtf8("comboBoxColor"));
        comboBoxColor->setGeometry(QRect(160, 90, 231, 26));

        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QDialog *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "HelloForm", 0, QApplication::UnicodeUTF8));
        comboBoxDetectorType->clear();
        comboBoxDetectorType->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "<Tots>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "FAST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "STAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SIFT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "ORB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "MSER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GFTT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "HARRIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "Dense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SimpleBlob", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridFAST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridSTAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridSIFT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridSURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridORB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridMSER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridGFTT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridHARRIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridDense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "GridSimpleBlob", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidFAST", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidSTAR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidSIFT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidSURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidORB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidMSER", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidGFTT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidHARRIS", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidDense", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "PyramidSimpleBlob", 0, QApplication::UnicodeUTF8)
        );
        comboBoxDescriptorType->clear();
        comboBoxDescriptorType->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "<Tots>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SIFT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "SURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "ORB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "BRIEF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "OpponentSIFT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "OpponentSURF", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "OpponentORB", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "OpponentBRIEF", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("HelloForm", "Tipus de detector", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HelloForm", "Tipus de descriptor", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("HelloForm", "Matching", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("HelloForm", "Tipus de matcher", 0, QApplication::UnicodeUTF8));
        comboBoxMatcherType->clear();
        comboBoxMatcherType->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "<Tots>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "BruteForce", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "BruteForce-L1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "BruteForce-Hamming", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "BruteForce-Hamming(2)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "FlannBased", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("HelloForm", "Tipus de color", 0, QApplication::UnicodeUTF8));
        comboBoxColor->clear();
        comboBoxColor->insertItems(0, QStringList()
         << QApplication::translate("HelloForm", "CV_LOAD_IMAGE_GRAYSCALE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "CV_LOAD_IMAGE_UNCHANGED", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "CV_LOAD_IMAGE_COLOR", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "CV_LOAD_IMAGE_ANYDEPTH", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("HelloForm", "CV_LOAD_IMAGE_ANYCOLOR", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
