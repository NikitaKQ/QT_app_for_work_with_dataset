#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new TableModel), proxyModel(new ProxyModel)/*, _userRecipes(new UserRecipesDialog)*/
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    for (int i = 0; i < 15; i++)
    {
        if (i == 0 || i == 6 || i == 10 || i == 11 || i == 13 || i == 14)
            ui->tableView->setColumnHidden(i, true);
    }

    createActions();
    createMenus();

    _translator = new QTranslator(this);

//    model->updateData();

    QObject::connect(actionEnglish, &QAction::triggered, this, &MainWindow::translateEnglish);
    QObject::connect(actionRussian, &QAction::triggered, this, &MainWindow::translateRussian);
//    QObject::connect(userRecipesAction, &QAction::triggered, this, &MainWindow::showUserRecipes);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::on_about);
    actionEnglish = new QAction(tr("&ENG"), this);
    actionRussian = new QAction(tr("&RUS"), this);
    userRecipesAction = new QAction(tr("&User's recipes"), this);
//    connect(userRecipes, &QAction::triggered, this, &MainWindow::displayUserRecipes);
}

void MainWindow::on_about()
{
    AboutDialog dialog;
    if (dialog.exec()) {}
}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&Menu"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(userRecipesAction);
    languageMenu = menuBar()->addMenu(tr("&Language"));
    languageMenu->addAction(actionEnglish);
    languageMenu->addAction(actionRussian);
}

void MainWindow::on_addRow_clicked()
{
    AddRowDialog dialog;
//    int rowCount = model->rowCount();
    if (dialog.exec())
    {
        QList<QString> dataRow = dialog.getRowData(/*rowCount*/);
        model->addRow(dataRow/*, rowCount*/);
    }
//    if (dialog.close()){}
}


void MainWindow::on_deletRow_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
//    qDebug()<<select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
    on_searchButton_clicked();
}


void MainWindow::on_searchButton_clicked()
{
    QString needToSearch = ui->searchLine->text();
    proxyModel->setName(needToSearch);
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[proxyModel->mapToSource(index).row()];
    Recipe res = {targetLine[1], targetLine[9], targetLine[5], targetLine[2], targetLine[3], targetLine[4], targetLine[7], targetLine[12], targetLine[8]};
    QItemSelectionModel *select = ui->tableView->selectionModel();

    RecpeDetails details(0,res);
    model->deleteRow(proxyModel->mapToSource(select->selectedIndexes()[0]).row());
    if (details.exec())
        model->addRow(details.changeRawData()/*, proxyModel->mapToSource(select->selectedIndexes()[0]).row()*/);
}

void MainWindow::on_resetButton_clicked()
{
    proxyModel->setName("");
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    ui->searchLine->setText("");
}

void MainWindow::translateEnglish()
{
    qApp->removeTranslator(_translator);
    ui->retranslateUi(this);
}

void MainWindow::translateRussian()
{
    if (_translator->load("ru"))
        qApp->installTranslator(_translator);
    ui->retranslateUi(this);
}

//void MainWindow::showUserRecipes()
//{
//    _userRecipes->showRecipes();
//}
