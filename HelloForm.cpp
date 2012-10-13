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
    connect(widget.nameEdit, SIGNAL(textChanged(const QString&)), this, SLOT(textChanged(const QString&)));
}

HelloForm::~HelloForm() {
}

void HelloForm::textChanged(const QString& text) {
    if (0 < text.trimmed().length()) {
        widget.helloEdit->setText("Hello " + text.trimmed() + "!");
    } else {
        widget.helloEdit->clear();
    }
}

void HelloForm::on_pushButton_clicked() {
    widget.helloEdit->setText(widget.comboBoxDetectorType->currentText());

    const string defaultDetectorType = "SURF";
    const string defaultDescriptorType = "SURF";
    const string defaultMatcherType = "FlannBased";
    const string defaultQueryImageName = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/Sabata_1995_Antoni_T_pies creu.jpg";
    const string defaultFileWithTrainImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/trainImages.txt";
    const string defaultDirToSaveResImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/results";

    computeMatching(defaultDetectorType, defaultDescriptorType, defaultMatcherType, defaultQueryImageName, defaultFileWithTrainImages, defaultDirToSaveResImages);
}
