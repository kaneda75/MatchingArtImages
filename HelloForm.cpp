/*
 * File:   HelloForm.cpp
 * Author: xescriche
 *
 * Created on 17 de septiembre de 2012, 11:57
 */

#include "HelloForm.h"
#include "matchingImages.hpp"

HelloForm::HelloForm() {
    widget.setupUi(this);
//    connect(widget.nameEdit, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));
}

HelloForm::~HelloForm() {
}

//void HelloForm::textChanged(const QString& text) {
//    if (0 < text.trimmed().length()) {
//        widget.helloEdit->setText("Hello " + text.trimmed() + "!");
//    } else {
//        widget.helloEdit->clear();
//    }
//}

void HelloForm::on_pushButton_clicked() {
//    widget.helloEdit->setText(widget.comboBoxDetectorType->currentText());
//
//    const string defaultDetectorType = "SURF";
//    const string defaultDescriptorType = "SURF";
//    const string defaultMatcherType = "FlannBased";
    string defaultQueryImageName = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/Sabata_1995_Antoni_T_pies creu.jpg";
    string defaultFileWithTrainImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/trainImages.txt";
    string defaultDirToSaveResImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/results";

    int color;
    if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_UNCHANGED") != 0) {
        color = -1;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_GRAYSCALE") != 0) {
        color = 0;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_COLOR") != 0) {
        color = 1;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_ANYDEPTH") != 0) {
        color = 2;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_ANYCOLOR") != 0) {
        color = 4;
    }

    computeMatching(widget.comboBoxDetectorType->currentText().toStdString(), 
            widget.comboBoxDescriptorType->currentText().toStdString(), 
            widget.comboBoxMatcherType->currentText().toStdString(), 
            defaultQueryImageName, 
            defaultFileWithTrainImages, 
            defaultDirToSaveResImages,
            color);
}
