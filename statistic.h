#ifndef STATISTIC_H
#define STATISTIC_H

#include "ui_statistic.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Statistic; }
QT_END_NAMESPACE

class Statistic : public QDialog
{
public:
    Statistic();
    ~Statistic();

private:
    Ui::Statistic ui;
};

#endif // STATISTIC_H
