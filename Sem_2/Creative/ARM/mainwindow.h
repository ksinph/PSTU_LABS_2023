#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "foodmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_addByNoteButton_clicked();
    void on_findButton_clicked();
    void on_amountButton_clicked();
    void on_expireButton_clicked();
    void on_displayButton_clicked();

private:
    Ui::MainWindow *ui;
    FoodManager foodManager;
};

#endif // MAINWINDOW_H
