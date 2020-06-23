#include "proracun.h"

Proracun::Proracun(const QList<QTreeWidgetItem*>& treeItms)
{
    ui.setupUi(this);
    ui.treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);
    ui.treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    InsertIntoTree(treeItms);
}

Proracun::~Proracun()
{

}

QTreeWidgetItem& Proracun::GetCurrentTreeItem()
{
    return *ui.treeWidget->currentItem();
}

void Proracun::InsertIntoTree(const QList<QTreeWidgetItem*>& treeItms)
{
    ui.treeWidget->clear();
    ui.treeWidget->addTopLevelItems(treeItms);
}
