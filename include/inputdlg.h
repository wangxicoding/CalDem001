#ifndef INPUTDLG_H
#define INPUTDLG_H

#include <QDialog>

namespace Ui {
class inputDlg;
}


class inputDlg : public QDialog
{
    Q_OBJECT

public:
    explicit inputDlg(QWidget *parent = 0);
    ~inputDlg();
public:
    double r;
    double thick;
    double density;
    double possion;
    double alpha;
    double beta;
    double c;
    double fc;
    double ft;
    double Ec;
    double miu;
    double zfc;
    double zft;
    double zEs;
    double zAs;
    double gfc;
    double gft;
    double gEs;
    double gAs;


private slots:
    void GetElementradius();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::inputDlg *ui;
};

#endif // INPUTDLG_H
