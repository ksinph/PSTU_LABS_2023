QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FoodManagerApp
TEMPLATE = app

SOURCES += main.cpp \
           MainWindow.cpp \
           FoodManager.cpp \
           ui_mainwindow.cpp

HEADERS  += MainWindow.h \
            FoodManager.h \
            ui_mainwindow.h

FORMS    += MainWindow.ui \
    ui_mainwindow.ui
