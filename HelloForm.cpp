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
}

HelloForm::~HelloForm() {
}

void HelloForm::on_pushButton_clicked() {
    
    string defaultQueryImageName = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/Sabata_1995_Antoni_T_pies creu.jpg";
    string defaultDirToSaveResImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/results";
    
    // All Tapies images
//    string defaultFileWithTrainImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/trainImagesAll.txt";
    // Only the same image
    string defaultFileWithTrainImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/trainImagesSame.txt";
    // Another Tapies cross image
//    string defaultFileWithTrainImages = "//Users/xescriche/Documents/MASTER LINUX/PFM/images/tapies/trainImagesAnother.txt";

    int id = 1;
    
    int color;
    if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_UNCHANGED") == 0) {
        color = -1;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_GRAYSCALE") == 0) {
        color = 0;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_COLOR") == 0) {
        color = 1;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_ANYDEPTH") == 0) {
        color = 2;
    } else if (widget.comboBoxColor->currentText().toStdString().compare("CV_LOAD_IMAGE_ANYCOLOR") == 0) {
        color = 4;
    }

    if (widget.comboBoxDetectorType->currentText().toStdString().compare("<Tots>") == 0) {
        for (int i = 1; i < 30; i++) {
            if (widget.comboBoxDescriptorType->currentText().toStdString().compare("<Tots>") == 0) {
                for (int j = 1; j < 8; j++) {
                    if (widget.comboBoxMatcherType->currentText().toStdString().compare("<Tots>") == 0) {
                        for (int k = 1; k < 5; k++) {
                            computeMatching(id,widget.comboBoxDetectorType->itemText(i).toStdString(),
                                    widget.comboBoxDescriptorType->itemText(j).toStdString(),
                                    widget.comboBoxMatcherType->itemText(k).toStdString(),
                                    defaultQueryImageName,
                                    defaultFileWithTrainImages,
                                    defaultDirToSaveResImages,
                                    color);
                            id++;
                        }
                    }
                }
            }
        }
    } else {
        computeMatching(id, widget.comboBoxDetectorType->currentText().toStdString(),
                widget.comboBoxDescriptorType->currentText().toStdString(),
                widget.comboBoxMatcherType->currentText().toStdString(),
                defaultQueryImageName,
                defaultFileWithTrainImages,
                defaultDirToSaveResImages,
                color);
        id++;
    }
}
