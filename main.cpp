/*
 * File:   main.cpp
 * Author: xescriche
 *
 * Created on 16 de septiembre de 2012, 13:49
 */
 

#include <QtGui/QApplication>
#include "HelloForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
 
    // create and show your widgets here
    HelloForm form;
    form.show();

    return app.exec();
}
