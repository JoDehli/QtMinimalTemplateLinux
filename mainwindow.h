#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void test();
    void menu(QAction* action);


private:
    Ui::MainWindow *ui;
    bool maybeSave();
};

#endif // MAINWINDOW_H
