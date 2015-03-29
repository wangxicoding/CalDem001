#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inputdlg.h"
#include "caculate.h"
#include "celement.h"
#include "contact.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    inputDlg wa;
    Caculate wb;

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_startCalc_clicked();

    void setProgressValue(int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
