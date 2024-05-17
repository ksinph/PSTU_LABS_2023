#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->addByNoteButton, &QPushButton::clicked, this, &MainWindow::on_addByNoteButton_clicked);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::on_findButton_clicked);
    connect(ui->amountButton, &QPushButton::clicked, this, &MainWindow::on_amountButton_clicked);
    connect(ui->expireButton, &QPushButton::clicked, this, &MainWindow::on_expireButton_clicked);
    connect(ui->displayButton, &QPushButton::clicked, this, &MainWindow::on_displayButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    QString title = ui->titleLineEdit->text();
    double amount = ui->amountLineEdit->text().toDouble();
    QString expirationDate = ui->expirationDateLineEdit->text();

    if (!title.isEmpty() && amount > 0) {
        foodManager.add(title.toStdString(), amount, expirationDate.toStdString());
        ui->resultTextEdit->setText("Product added successfully.");
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid title and amount.");
    }
}

void MainWindow::on_addByNoteButton_clicked() {
    QString note = ui->noteTextEdit->toPlainText();
    if (!note.isEmpty()) {
        foodManager.addByNote(note.toStdString());
        ui->resultTextEdit->setText("Product added successfully by note.");
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid note.");
    }
}

void MainWindow::on_findButton_clicked() {
    QString needle = ui->titleLineEdit->text();
    if (!needle.isEmpty()) {
        std::vector<std::string> results = foodManager.find(needle.toStdString());
        QString resultText;
        for (const auto &result : results) {
            resultText += QString::fromStdString(result) + "\n";
        }
        ui->resultTextEdit->setText(resultText);
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid search string.");
    }
}

void MainWindow::on_amountButton_clicked() {
    QString needle = ui->titleLineEdit->text();
    if (!needle.isEmpty()) {
        double totalAmount = foodManager.amount(needle.toStdString());
        ui->resultTextEdit->setText("Total amount of " + needle + ": " + QString::number(totalAmount));
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid title.");
    }
}

void MainWindow::on_expireButton_clicked() {
    int days = ui->amountLineEdit->text().toInt();
    if (days >= 0) {
        std::vector<std::pair<std::string, double>> expiredItems = foodManager.expire(days);
        QString resultText = "Expired items:\n";
        for (const auto &item : expiredItems) {
            resultText += QString::fromStdString(item.first) + ": " + QString::number(item.second) + "\n";
        }
        ui->resultTextEdit->setText(resultText);
    } else {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number of days.");
    }
}

void MainWindow::on_displayButton_clicked() {
    QString resultText = QString::fromStdString(foodManager.display());
    ui->resultTextEdit->setText(resultText);
}
