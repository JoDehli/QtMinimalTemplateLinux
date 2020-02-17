#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Main Window");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{
    qDebug("debug print");
}

void MainWindow::menu(QAction *action)
{
    QString a = action->objectName();

    if (a == "actionBeenden")
    {
        if (this->maybeSave())
        {
            this->close();
        }
    }
}

bool MainWindow::maybeSave()
{
    const QMessageBox::StandardButton ret = QMessageBox::warning(this, tr("Application"),
                                                                 tr("Schließen?"),
                                                                 QMessageBox::Yes | QMessageBox::Cancel);
    switch (ret)
    {
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}
