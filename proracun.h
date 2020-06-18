#ifndef PRORACUN_H
#define PRORACUN_H

#include "ui_proracun.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Proracun; }
QT_END_NAMESPACE

class Proracun : public QDialog
{
public:
    Proracun();
    virtual ~Proracun();

private:
    Ui::Proracun* ui;
};

#endif // PRORACUN_H
