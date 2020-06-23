#ifndef VNOSOBVEZNOSTI_H
#define VNOSOBVEZNOSTI_H

#include "ui_vnosobveznosti.h"
#include <QValidator>


QT_BEGIN_NAMESPACE
namespace Ui { class VnosObveznosti; }
QT_END_NAMESPACE


class VnosObveznosti : public QDialog
{
    Q_OBJECT

public:
    VnosObveznosti();
    ~VnosObveznosti();
    const QString& GetData();

private:
    void Reset();
    void CheckLineEdit();

private slots:
    void on_lineEdit_upnik_textChanged(const QString &arg1);
    void on_lineEdit_znesek_textChanged(const QString &arg1);
    void on_pushButton_novVnos_clicked();


private:
    Ui::VnosObveznosti ui;
    bool m_upnikTrue;
    bool m_znesekTrue;
    QString m_dataText;
};

#endif // VNOSOBVEZNOSTI_H
