/* 
 * File:   HelloForm.h
 * Author: xescriche
 *
 * Created on 17 de septiembre de 2012, 11:57
 */

#ifndef _HELLOFORM_H
#define	_HELLOFORM_H

#include "ui_HelloForm.h"

class HelloForm : public QDialog {
    Q_OBJECT
public:
    HelloForm();
    virtual ~HelloForm();
public slots:
    void textChanged(const QString& text);   
    void on_pushButton_clicked();
    
private:
    Ui::HelloForm widget;
};

#endif	/* _HELLOFORM_H */
