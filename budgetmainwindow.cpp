#include "budgetmainwindow.h"

BudgetMainWindow::BudgetMainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Proračun");
    this->setWindowIcon(m_controller.GetIcon(Controller::Icons::Icon_Budget));
    m_versionLabel.setText(m_controller.GetVersion());
    m_versionLabel.setAlignment(Qt::AlignCenter);
    this->statusBar()->addPermanentWidget(&m_versionLabel, 1);
}

BudgetMainWindow::~BudgetMainWindow()
{

}

// ON ACTION TRIGGERED
void BudgetMainWindow::on_action_vnosObveznosti_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfDialog::Vnos_Obveznosti, true);
}
void BudgetMainWindow::on_action_proracun_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfDialog::Proracun, true);
}
void BudgetMainWindow::on_action_statistika_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfDialog::Statistika, true);
}
void BudgetMainWindow::on_action_Oprogramu_triggered()
{
    m_controller.ShowWindow(Controller::TypeOfDialog::O_Programu, true);
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
