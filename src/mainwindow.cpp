#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&wb, SIGNAL(sendProgressValue(int)), this, SLOT(setProgressValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    wa.exec();
}

void MainWindow::on_pushButton_8_clicked()
{
    this->close();
}

void MainWindow::on_startCalc_clicked()
{
    CElement::input = &wa;
    wb.maintemp();
}

void MainWindow::setProgressValue(int i)
{
    ui->progressBar->setValue(i);
}
