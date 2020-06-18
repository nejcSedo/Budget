#ifndef VNOSOBVEZNOSTI_H
#define VNOSOBVEZNOSTI_H

#include "ui_vnosobveznosti.h"

QT_BEGIN_NAMESPACE
namespace Ui { class VnosObveznosti; }
QT_END_NAMESPACE

class VnosObveznosti : public QDialog
{
public:
    explicit VnosObveznosti();
    virtual ~VnosObveznosti();

private:
    Ui::VnosObveznosti* ui;
};

#endif // VNOSOBVEZNOSTI_H
