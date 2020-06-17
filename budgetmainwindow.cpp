#include "budgetmainwindow.h"
#include "ui_budgetmainwindow.h"

BudgetMainWindow::BudgetMainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::BudgetMainWindow)
{
    ui->setupUi(this);
}

BudgetMainWindow::~BudgetMainWindow()
{
    delete ui;
}


void BudgetMainWindow::on_actionVnost_obveznosti_triggered()
{
    m_controller.ShowWindow(new QDialog(), "Vnos Obveznosti");
}
