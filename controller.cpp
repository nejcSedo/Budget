#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{

}

Controller::~Controller()
{

}

void Controller::ShowWindow(QDialog* newDialog, QString WindowTitle)
{
    newDialog->setWindowTitle(WindowTitle);
    newDialog->setModal(true);
    newDialog->show();
};
