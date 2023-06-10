#ifndef RECIPEDETAILSDIALOG_H
#define RECIPEDETAILSDIALOG_H

#include <QDialog>
#include "recipe.h"

namespace Ui {
class RecpeDetails;
}

class RecpeDetails : public QDialog
{
    Q_OBJECT

public:
    explicit RecpeDetails(QWidget *parent = nullptr, Recipe res = Recipe());
    QList<QString> changeRawData();
    ~RecpeDetails();

private slots:
    //    void on_buttonBox_rejected();

private slots:
    //    void on_buttonBox_accepted();


private:
    Ui::RecpeDetails *ui;
};

#endif // RECIPEDETAILSDIALOG_H
