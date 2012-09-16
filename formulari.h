/* 
 * File:   formulari.h
 * Author: xescriche
 *
 * Created on 16 de septiembre de 2012, 16:34
 */

#ifndef _FORMULARI_H
#define	_FORMULARI_H

#include "ui_formulari.h"

class formulari : public QDialog {
    Q_OBJECT
public:
    formulari();
    virtual ~formulari();
private:
    Ui::formulari widget;
};

#endif	/* _FORMULARI_H */
