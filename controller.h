#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QDebug>

#include <QObject>
#include <QDialog>
#include <QIcon>

#include "vnosobveznosti.h"
#include "statistic.h"
#include "proracun.h"

class Controller : public QObject
{
    Q_OBJECT

// PUBLIC VARS
public:
    enum class TypeOfWindow {
        VnosObveznosti = 0,
        Statistika,
        Proracun
    };

// PUBLIC METHODS
public:
    // Construst
    explicit Controller(QObject* parent = nullptr);
    // Destruct
    virtual ~Controller();
    // Methods
    void ShowWindow(TypeOfWindow windowType, bool setModal, QIcon& windowIcon);

// PRIVATE METHODS
private:
    template<typename T>void ExecWindow(T* type, bool setModal, QIcon& windowIcon, QString windowTitle);

// SIGNALS
signals:

};

#endif // CONTROLLER_H
