#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QDebug>

#include <QObject>
#include <QDialog>
#include <QWidget>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    virtual ~Controller();
    void ShowWindow(QDialog*, QString);

signals:

};

#endif // CONTROLLER_H
