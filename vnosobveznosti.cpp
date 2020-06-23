#include "vnosobveznosti.h"

VnosObveznosti::VnosObveznosti() :
    m_upnikTrue(false),
    m_znesekTrue(false),
    m_dataText("")
{
    ui.setupUi(this);
    ui.lineEdit_upnik->setMaxLength(50);
    ui.lineEdit_znesek->setValidator(new QIntValidator(0, 100000, this));
    ui.lineEdit_opomba->setMaxLength(100);
    ui.pushButton_novVnos->setDisabled(true);
    Reset();
}

VnosObveznosti::~VnosObveznosti()
{

}

const QString &VnosObveznosti::GetData()
{
    return m_dataText;
}

void VnosObveznosti::Reset()
{
    ui.lineEdit_upnik->clear();
    ui.lineEdit_znesek->clear();
    ui.lineEdit_opomba->clear();
}

void VnosObveznosti::CheckLineEdit()
{
    m_upnikTrue && m_znesekTrue ? ui.pushButton_novVnos->setDisabled(false)
                                : ui.pushButton_novVnos->setDisabled(true);
}

void VnosObveznosti::on_pushButton_novVnos_clicked()
{
    m_dataText = ui.lineEdit_upnik->text() + ";;" + ui.lineEdit_znesek->text() + ";;" + ui.lineEdit_opomba->text() + ";;";
    Reset();
}

void VnosObveznosti::on_lineEdit_upnik_textChanged(const QString &arg1)
{
    arg1 == "" ? m_upnikTrue = false
               : m_upnikTrue = true;
    CheckLineEdit();
}

void VnosObveznosti::on_lineEdit_znesek_textChanged(const QString &arg1)
{
    arg1 == "" ? m_znesekTrue = false
               : m_znesekTrue = true;
    CheckLineEdit();
}
