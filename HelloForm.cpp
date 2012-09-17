/*
 * File:   HelloForm.cpp
 * Author: xescriche
 *
 * Created on 17 de septiembre de 2012, 11:57
 */

#include "HelloForm.h"

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

void HelloForm::on_pushButton_clicked()
{
        widget.helloEdit->setText(widget.comboBoxDetectorType->currentText());
}
