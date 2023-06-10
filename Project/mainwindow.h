#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include "tablemodel.h"
#include "proxymodel.h"
#include "recipe.h"
#include "addrowdialog.h"
#include <QTranslator>
#include <QEvent>
#include <QDir>
#include <QLocale>
#include <QActionGroup>
#include "aboutdialog.h"
#include "recpedetails.h"
//#include "userrecipesdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void on_about();

private slots:
    void on_resetButton_clicked();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private slots:
    void on_searchButton_clicked();

private slots:
    void on_addRow_clicked();

private slots:
    void on_deletRow_clicked();

private:

    Ui::MainWindow *ui;
    TableModel *model;
    ProxyModel *proxyModel;
//    UserRecipesDialog *_userRecipes;

    void translateEnglish();
    void translateRussian();
    void showUserRecipes();

private:
    QMenu *helpMenu;
    QAction *aboutAct;
    QMenu *languageMenu;
    QAction *actionRussian;
    QAction *actionEnglish;
    QTranslator *_translator;
    QAction *userRecipesAction;

    void createMenus();
    void createActions();
};
#endif // MAINWINDOW_H
