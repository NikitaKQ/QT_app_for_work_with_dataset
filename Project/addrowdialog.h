#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>
#include <QItemSelectionModel>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(QWidget *parent = nullptr);
    QList<QString> getRowData(/*int& count*/);
    ~AddRowDialog();

private:
    Ui::AddRowDialog *ui;
};

#endif // ADDROWDIALOG_H
