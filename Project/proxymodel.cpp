#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent), _name("") {}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex nameIndex = sourceModel()->index(source_row, 1, source_parent);
    bool isContains = (((sourceModel()->data(nameIndex)).toString()).contains(_name, Qt::CaseInsensitive));
    if (isContains)
        return true;
    else
        return false;
}

void ProxyModel::setName(const QString& string)
{
    _name = string;
    invalidateFilter();
}
