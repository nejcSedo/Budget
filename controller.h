#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QDebug>

#include <QDialog>
#include <QIcon>
#include <QLabel>
#include <QFile>
#include <QTreeWidgetItem>
#include <QFileInfo>
#include <QAction>
#include <QMenu>

#include "vnosobveznosti.h"
#include "statistic.h"
#include "proracun.h"
#include "oprogramu.h"

class Controller : public QDialog
{
    Q_OBJECT

// PUBLIC VARS
public:
    enum class TypeOfDialog {
        Vnos_Obveznosti = 0,
        Statistika,
        Proracun,
        O_Programu
    };
    enum class ErrorType {
        Error_SaveData = 0,
        Error_DeleteData_atReadOnly,
        Error_DeleteData_atTruncate,
        Error_DeleteData_atWriteOnly,
        Error_InitTree,
        Error_Default
    };
    enum class Icons {
        Icon_Budget = 0,
        Icon_Oprogramu,
        Icon_Proracun,
        Icon_Statistika,
        Icon_VnosObveznosti,
        Icon_Delete,
    };

// PUBLIC METHODS
public:
    // Construst
    Controller();
    // Destruct
    ~Controller();
    // Methods
    void ShowWindow(const TypeOfDialog windowType, const bool setModal);
    QIcon& GetIcon(const Icons& iconName);
    const QString& GetVersion();
    const QList<QTreeWidgetItem*>& GetTreeItm();
    QFile& GetDataFile();

// SLOT
public slots:
    void SaveData(const QString& data);

// SIGNALS
signals:

// SLOT
private slots:
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);
    void DeleteData();

// PRIVATE METHODS
private:
    template<typename T>void ExecWindow(T& type, const bool setModal, const Icons& iconName, const QString windowTitle);
    void Error(ErrorType errorType);
    void ReadDataFile();
    void CheckDataFile();

// PROTECTED VARS
protected:
    QTreeWidgetItem* m_treeItem;

// PRIVAT VARS
private:
    QString m_verzija;
    QFile m_dataFile;
    QTextStream m_outStream;
    QIcon m_icon;
    QList<QTreeWidgetItem*> m_treeWidgetArray;
    short m_lineCounter;
    VnosObveznosti* m_obveznosti;
    Statistic* m_statistika;
    Proracun* m_proracun;
    OProgramu* m_info;
};

#endif // CONTROLLER_H
