#include "include/inputdlg.h"
#include "ui_inputdlg.h"
#include <QDebug>
#include <QMessageBox>

const double PI=3.1415926;

inputDlg::inputDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inputDlg)
{
    ui->setupUi(this);
    setWindowTitle(tr("参数输入"));
}

inputDlg::~inputDlg()
{
    delete ui;
}

void inputDlg::GetElementradius()
{

    bool ok;

    QString radiusvalue=this->ui->radiusLineEdit->text();
    r=radiusvalue.toDouble(&ok);
    if(radiusvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入单元半径！"));
        return;
    }
    qDebug()<<r;
    qDebug()<<r*r*PI;


   /* QString thickvalue=this->ui->cLineEdit_2->text();
    thick=thickvalue.toDouble(&ok);*/

    QString densityvalue=this->ui->densityLineEdit->text();
    density=densityvalue.toDouble(&ok);
    if(densityvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入单元密度！"));
        return;
    }
    qDebug()<<density;

    QString possionvalue=this->ui->possionLineEdit->text();
    possion=possionvalue.toDouble(&ok);
    if(possionvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入泊松比！"));
        return;
    }
    QString alphavalue=this->ui->alphaLineEdit->text();
    alpha=alphavalue.toDouble(&ok);
    if(alphavalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入粘滞阻尼系数alpha！"));
        return;
    }
    QString betavalue=this->ui->betaLineEdit->text();
    beta=betavalue.toDouble(&ok);
    if(betavalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入刚性阻尼系数beta！"));
        return;
    }
    QString cvalue=this->ui->cLineEdit->text();
    c=cvalue.toDouble(&ok);
    if(cvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入粘性系数！"));
        return;
    }
    QString fcvalue=this->ui->concretefcLineEdit->text();
    fc=fcvalue.toDouble(&ok);
    if(fcvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入混凝土抗压强度！"));
        return;
    }
    QString ftvalue=this->ui->concreteftLineEdit->text();
    ft=ftvalue.toDouble(&ok);
    if(ftvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入混凝土抗拉强度！"));
        return;
    }
    QString Ecvalue=this->ui->concreteEcLineEdit->text();
    Ec=Ecvalue.toDouble(&ok);
    if(Ecvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入混凝土弹性模量！"));
        return;
    }
    QString miuvalue=this->ui->concreteMiuLineEdit->text();
    miu=miuvalue.toDouble(&ok);
    if(miuvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入摩擦系数！"));
        return;
    }
    QString zfcvalue=this->ui->zjfcLineEdit->text();
    zfc=zfcvalue.toDouble(&ok);
    if(zfcvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入纵筋抗压强度！"));
        return;
    }
    QString zftvalue=this->ui->zjftLineEdit->text();
    zft=zftvalue.toDouble(&ok);
    if(zftvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入纵筋抗拉强度！"));
        return;
    }
    QString zEsvalue=this->ui->zjEsLineEdit->text();
    zEs=zEsvalue.toDouble(&ok);
    if(zEsvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入纵筋弹性模量！"));
        return;
    }
    QString zAsvalue=this->ui->zjAsLineEdit->text();
    zAs=zAsvalue.toDouble(&ok);
    if(zAsvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入纵筋截面面积！"));
        return;
    }
    QString gfcvalue=this->ui->gjfcLineEdit->text();
    gfc=gfcvalue.toDouble(&ok);
    if(gfcvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入箍筋抗压强度！"));
        return;
    }
    QString gftvalue=this->ui->gjftLineEdit->text();
    gft=gftvalue.toDouble(&ok);
    if(gftvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入箍筋抗拉强度！"));
        return;
    }
    QString gEsvalue=this->ui->gjEsLineEdit->text();
    gEs=gEsvalue.toDouble(&ok);
    if(gEsvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入箍筋弹性模量！"));
        return;
    }
    QString gAsvalue=this->ui->gjAsLineEdit->text();
    gAs=gAsvalue.toDouble(&ok);
    if(gAsvalue.isEmpty())
    {
        QMessageBox::information(this,tr("警告"),tr("请输入箍筋截面积！"));
        return;
    }
    this->close();

}



void inputDlg::on_pushButton_clicked()
{
    this->GetElementradius();


}

void inputDlg::on_pushButton_2_clicked()
{
    this->close();
}
