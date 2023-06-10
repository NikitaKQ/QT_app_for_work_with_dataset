#include "recpedetails.h"
#include "ui_recpedetails.h"

RecpeDetails::RecpeDetails(QWidget *parent, Recipe res) :
    QDialog(parent),
    ui(new Ui::RecpeDetails)
{
    ui->setupUi(this);

    ui->recipeNameLine->setText(res.recipeName);
    ui->ratingLine->setText(res.rating);
    ui->servingsLine->setText(res.servings);
    ui->prepTimeLine->setText(res.prepTime);
    ui->cookTimeLine->setText(res.cookTime);
    ui->totalTimeLine->setText(res.totalTime);
    ui->ingredientsText->setPlainText(res.ingredients);
    ui->nutritionsText->setPlainText(res.nutrition);
    ui->directionText->setPlainText(res.direction);
}

QList<QString> RecpeDetails::changeRawData()
{
    QList<QString> newList(15, "No data");
    newList[1] = ui->recipeNameLine->text();
    newList[2] = ui->prepTimeLine->text();
    newList[3] = ui->cookTimeLine->text();
    newList[4] = ui->totalTimeLine->text();
    newList[5] = ui->servingsLine->text();
    newList[7] = ui->ingredientsText->toPlainText();
    newList[8] = ui->directionText->toPlainText();
    newList[9] = ui->ratingLine->text();
    newList[12] = ui->nutritionsText->toPlainText();
    return newList;
}

RecpeDetails::~RecpeDetails()
{
    delete ui;
}
