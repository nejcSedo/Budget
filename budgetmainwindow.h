#ifndef BUDGETMAINWINDOW_H
#define BUDGETMAINWINDOW_H

#include <QMainWindow>
#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BudgetMainWindow; }
QT_END_NAMESPACE

class BudgetMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BudgetMainWindow(QWidget *parent = nullptr);
    ~BudgetMainWindow();

private slots:
    void on_actionVnost_obveznosti_triggered();

private:
    Ui::BudgetMainWindow *ui;
    Controller m_controller;
};
#endif // BUDGETMAINWINDOW_H
