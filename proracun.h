#ifndef PRORACUN_H
#define PRORACUN_H

#include "ui_proracun.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Proracun; }
QT_END_NAMESPACE

class Proracun : public QDialog
{
public:
    explicit Proracun(const QList<QTreeWidgetItem*>& treeItms);
    ~Proracun();
    QTreeWidgetItem& GetCurrentTreeItem();

private slots:
    QTreeWidgetItem& on_treeWidget_itemSelectionChanged();

private:
    void InsertIntoTree(const QList<QTreeWidgetItem*>& treeItms);

private:
    Ui::Proracun ui;
};

#endif // PRORACUN_H
