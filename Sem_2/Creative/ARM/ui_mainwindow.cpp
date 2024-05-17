#include "ui_mainwindow.h"
#include "ui_ui_mainwindow.h"

ui_MainWindow::ui_MainWindow(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::ui_MainWindow)
{
    ui->setupUi(this);
}

ui_MainWindow::~ui_MainWindow()
{
    delete ui;
}
