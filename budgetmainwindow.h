#ifndef BUDGETMAINWINDOW_H
#define BUDGETMAINWINDOW_H

#include <QMainWindow>
#include "ui_budgetmainwindow.h"
#include "controller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class BudgetMainWindow; }
QT_END_NAMESPACE


class BudgetMainWindow : public QMainWindow
{
    Q_OBJECT

public:

// PUBLIC METHODS
public:
    explicit BudgetMainWindow(QWidget* parent = nullptr);
    ~BudgetMainWindow();

// PRIVATE SLOTS
private slots:
    // Actions
    void on_action_vnosObveznosti_triggered();
    void on_action_proracun_triggered();
    void on_action_statistika_triggered();
    void on_action_Oprogramu_triggered();
    void on_action_Izhod_triggered();
    // Buttons
    void on_pushButton_vnosObveznosti_clicked();
    void on_pushButton_proracun_clicked();
    void on_pushButton_statistika_clicked();
    void on_pushButton_izhod_clicked();

// PRIVAT VARS
private:
    Ui::BudgetMainWindow ui;
    QLabel m_versionLabel;
    Controller m_controller;
};

#endif // BUDGETMAINWINDOW_H
