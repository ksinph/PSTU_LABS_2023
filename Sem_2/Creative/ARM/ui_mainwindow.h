#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QDockWidget>

namespace Ui {
class ui_MainWindow;
}

class ui_MainWindow : public QDockWidget
{
    Q_OBJECT

public:
    explicit ui_MainWindow(QWidget *parent = nullptr);
    ~ui_MainWindow();

private:
    Ui::ui_MainWindow *ui;
};

#endif // UI_MAINWINDOW_H
