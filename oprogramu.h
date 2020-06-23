#ifndef OPROGRAMU_H
#define OPROGRAMU_H

#include "ui_oprogramu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OProgramu; }
QT_END_NAMESPACE


class OProgramu : public QDialog
{
public:
    OProgramu(const QString& verzija);
    ~OProgramu();

private:
    Ui::OProgramu ui;
};

#endif // OPROGRAMU_H
