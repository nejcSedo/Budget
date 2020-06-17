#include "budgetmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication BudgetApp(argc, argv);
    BudgetMainWindow BudgetWindow;
    BudgetWindow.show();
    return BudgetApp.exec();
}
