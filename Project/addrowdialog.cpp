#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

QList<QString> AddRowDialog::getRowData(/*int& count*/)
{
    QList<QString> newList(15, "No data");
//    newList[0] = QString::number(count);
    newList[1] = ui->recipeNameLine->text();
    newList[2] = ui->prepTimeLine->text();
    newList[3] = ui->cookTimeLine->text();
    newList[4] = ui->totalTimeLine->text();
    newList[5] = ui->servingsLine->text();
    newList[7] = ui->ingredientsLine->text();
    newList[8] = ui->directionsLine->text();
    newList[9] = ui->ratingLine->text();
    newList[12] = ui->nutritionLine->text();
    return newList;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
