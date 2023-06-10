#include "sortproxymodel.h"

SortProxyModel::SortProxyModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant SortProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex SortProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex SortProxyModel::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int SortProxyModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int SortProxyModel::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant SortProxyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
