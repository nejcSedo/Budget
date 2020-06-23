#include "controller.h"

Controller::Controller() :
    m_verzija("v0.1"),
    m_dataFile("./data.txt"),
    m_outStream(&m_dataFile),
    m_icon(":/icons/budget.ico"),
    m_lineCounter(0),
    m_obveznosti(new VnosObveznosti()),
    m_statistika(new Statistic()),
    m_info(new OProgramu(m_verzija))
{
    m_outStream.setCodec("UTF-8");
    CheckDataFile();
    ReadDataFile();
    m_proracun = new Proracun(m_treeWidgetArray);
}

Controller::~Controller()
{
    delete m_obveznosti;
    delete m_statistika;
    delete m_proracun;
    delete m_info;
}

template<typename T>
void Controller::ExecWindow(T& type, const bool setModal,
                            const Icons& iconName, const QString windowTitle)
{
    type->setModal(setModal);
    type->setWindowIcon(GetIcon(iconName));
    type->setWindowTitle(windowTitle);
    type->exec();
}

void Controller::ShowWindow(const TypeOfDialog windowType,
                            const bool setModal)
{
    switch (windowType) {
        case TypeOfDialog::Vnos_Obveznosti: {
            ExecWindow(m_obveznosti, setModal, Icons::Icon_VnosObveznosti, "Vnos obveznosti");
            break;
        }
        case TypeOfDialog::Statistika: {
            ExecWindow(m_statistika, setModal, Icons::Icon_Statistika, "Statistika");
            break;
        }
        case TypeOfDialog::Proracun: {
            ExecWindow(m_proracun, setModal, Icons::Icon_Proracun, "Proracun");
            break;
        }
        case TypeOfDialog::O_Programu: {
            ExecWindow(m_info, setModal, Icons::Icon_Oprogramu, "O programu");
            break;
        }
    }
}

void Controller::Error(Controller::ErrorType errorType)
{
    switch (errorType) {
    case ErrorType::Error_SaveData: qDebug() << "Error open dataFile for writeOnly in SaveData()"; break;
    case ErrorType::Error_DeleteData_atReadOnly: qDebug() << "Error open dataFile for readOnly in DeleteData()"; break;
    case ErrorType::Error_DeleteData_atTruncate: qDebug() << "Error open dataFile for writeOnly - Truncate in DeleteData()"; break;
    case ErrorType::Error_DeleteData_atWriteOnly: qDebug() << "Error open dataFile for writeOnly in DeleteData()"; break;
    case ErrorType::Error_InitTree: qDebug() << "Error open dataFile for readOnly in InitTree()"; break;
    case ErrorType::Error_Default: qDebug() << "Neznana napaka"; break;
    }
}

void Controller::ReadDataFile()
{
    if(!m_dataFile.open(QIODevice::ReadOnly))
        Error(ErrorType::Error_InitTree);

    QString line;
    QStringList list;
    while (!m_dataFile.atEnd())
    {
        line = m_dataFile.readLine();
        list = line.split(";;");
        if(list.contains("DELETE"))
            continue;
        if(list.length() > 1)
        {
            QTreeWidgetItem* parent = new QTreeWidgetItem;
            parent->setTextAlignment(0, Qt::AlignCenter);
            parent->setTextAlignment(1, Qt::AlignCenter);
            parent->setText(0, list.at(0));
            parent->setText(1, "€ " + list.at(1));

            QTreeWidgetItem* child = new QTreeWidgetItem;
            child->setTextAlignment(0, Qt::AlignCenter);
            child->setText(0, list.at(2));
            parent->addChild(child);
            m_treeWidgetArray.append(parent);
            m_lineCounter++;
        }
    }
    m_dataFile.close();
}

void Controller::CheckDataFile()
{
    if(!QFileInfo::exists("./data.txt"))
    {
        m_dataFile.open(QIODevice::WriteOnly | QIODevice::Text);
        m_dataFile.write("Budget data:\n");
        m_dataFile.close();
    }
}

void Controller::SaveData(const QString& data)
{
    if (! m_dataFile.open(QIODevice::WriteOnly | QIODevice::Append))
        Error(ErrorType::Error_SaveData);
    m_outStream << data + QString::number(m_lineCounter) + ";;\n";
    m_dataFile.close();
}

QIcon& Controller::GetIcon(const Icons& iconName)
{
    switch(iconName)
    {
        case Icons::Icon_Budget: m_icon.addFile(":/icons/budget.ico"); break;
        case Icons::Icon_Oprogramu: m_icon.addFile(":/icons/O programu.ico"); break;
        case Icons::Icon_Proracun: m_icon.addFile(":/icons/Proracun.ico"); break;
        case Icons::Icon_Statistika: m_icon.addFile(":/icons/Statistika.ico"); break;
        case Icons::Icon_VnosObveznosti: m_icon.addFile(":/icons/Vnos obveznosti.ico"); break;
        case Icons::Icon_Delete: m_icon.addFile(":/icons/delete.ico"); break;
    }
    return m_icon;
}

const QString& Controller::GetVersion()
{
    return m_verzija;
}

const QList<QTreeWidgetItem*>& Controller::GetTreeItm()
{
    return m_treeWidgetArray;
}

QFile& Controller::GetDataFile()
{
    return m_dataFile;
}

void Controller::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QAction actDelete("Izbriši");
    QMenu menu(this);
    menu.addAction(&actDelete);
    actDelete.setData(QVariant(pos));
    actDelete.setIcon(GetIcon(Icons::Icon_Delete));
    connect(&actDelete, SIGNAL(triggered()), this, SLOT(DeleteData()));
    menu.exec(mapToGlobal(pos));
}

void Controller::DeleteData()
{
    m_treeItem = &m_proracun->GetCurrentTreeItem();
    if(m_treeItem != nullptr)
    {
        if(!m_dataFile.open(QIODevice::Text | QIODevice::ReadOnly))
            Error(ErrorType::Error_DeleteData_atReadOnly);

        QString allText = m_outStream.readAll();
        m_dataFile.close();

        QString oldProduct(m_treeItem->text(0) + ";;" + m_treeItem->text(1).remove("€ ") + ";;" + m_treeItem->child(0)->text(0));
        allText.replace(oldProduct, "DELETE;;DELETE;;DELETE");

        if(!m_dataFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
            Error(ErrorType::Error_DeleteData_atTruncate);

        m_dataFile.close();

        if(!m_dataFile.open(QIODevice::Text | QIODevice::WriteOnly))
            Error(ErrorType::Error_DeleteData_atWriteOnly);

        m_outStream << allText;
        m_dataFile.close();
    }
}
