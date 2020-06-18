#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{

}

Controller::~Controller()
{

}

void Controller::ShowWindow(TypeOfWindow windowType, bool setModal, QIcon& windowIcon)
{
    switch (windowType) {
        case TypeOfWindow::VnosObveznosti: {
            VnosObveznosti* obveznosti = new VnosObveznosti();
            ExecWindow(obveznosti, setModal, windowIcon, "Vnos obveznosti");
            delete obveznosti;
            break;
        }
        case TypeOfWindow::Statistika: {
            Statistic* statistika = new Statistic();
            ExecWindow(statistika, setModal, windowIcon, "Statistika");
            delete statistika;
            break;
        }
        case TypeOfWindow::Proracun: {
            Proracun* proracun = new Proracun();
            ExecWindow(proracun, setModal, windowIcon, "Proračun");
            delete proracun;
            break;
        }
    }
}

template<typename T>
void Controller::ExecWindow(T* type, bool setModal, QIcon& windowIcon, QString windowTitle)
{
    type->setModal(setModal);
    type->setWindowIcon(windowIcon);
    type->setWindowTitle(windowTitle);
    type->exec();
}
