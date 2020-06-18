#include "budgetmainwindow.h"

BudgetMainWindow::BudgetMainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::BudgetMainWindow),
      m_icon(":icons/budget.ico")
{
    ui->setupUi(this);
    this->setWindowTitle("Osebni proračun");
    this->setWindowIcon(m_icon);
}

BudgetMainWindow::~BudgetMainWindow()
{
    delete ui;
}

// ON ACTION TRIGGERED
void BudgetMainWindow::on_action_vnosObveznosti_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfWindow::VnosObveznosti, true, m_icon);
}
void BudgetMainWindow::on_action_proracun_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfWindow::Proracun, true, m_icon);
}
void BudgetMainWindow::on_action_statistika_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfWindow::Statistika, true, m_icon);
}
void BudgetMainWindow::on_action_Izhod_triggered()
{
    QApplication::quit();
}

// PUSH BUTTONS
void BudgetMainWindow::on_pushButton_vnosObveznosti_clicked()
{
    on_action_vnosObveznosti_triggered();
}
void BudgetMainWindow::on_pushButton_proracun_clicked()
{
    on_action_proracun_triggered();
}
void BudgetMainWindow::on_pushButton_statistika_clicked()
{
    on_action_statistika_triggered();
}
void BudgetMainWindow::on_pushButton_izhod_clicked()
{
    on_action_Izhod_triggered();
}

