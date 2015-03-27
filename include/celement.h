#ifndef CELEMENT_H
#define CELEMENT_H

#include <QObject>
#include <QWidget>
#include <map>
#include "contact.h"
#include "inputdlg.h"
#include <iostream>
using namespace std;

class CONTACT;

const double g = 9.80665;
const double deltaTime = 1e-6;
const double PI = 3.1415926;
const double thickness = 0.01;
const double m_Feqx=5000;

class CElement
{

public:
    static inputDlg *input;

public:
    explicit CElement();
    ~CElement();
private:
    static double Kn;
    static double Ks;
    static double Cp;
    static double Ft;
    static double Fc;
    static double m;
    static double I;
private:
    static bool IsBreak(double nowFn, double nowFs, double tau);
public:
    static void staticInit();
public:
    //CElement();
    //        virtual ~CElement();
    int m_number; //单元的编号
    double m_moment; //单元的转动惯量
    double m_velx, m_vely, m_rotate; //x、y平动速度, 单元转动速度
    double m_disx, m_disy, m_diso; //x、y、转角方向的位移增量

    double vt_t2[4], vtt2[4], mtt2, mt_t2; //vt_t2和mt_t2分别表示t-△t/2时刻的速度和转动速度，vtt2和mtt2分别表示t+△t/2时刻的速度和转动速度
    double m_disn, m_diss; //分别表示单元法向方向位移增量，切向方向位移增量
    double tau; //极限切向力
    double m_ag; //地震加速度记录，从地震数据中读取
    double m_Feqx, m_Feqy; //x方向和y方向地震力
    double m_Fxsum, m_Fysum, m_Msum; //x和y方向和合力及合力矩

    //材料参数
    double m_young;//弹性模量
    double m_possion;//泊松比
    double m_thickness;//单元厚度
    double m_weight;//单元容重

    double moment;
    double m_o;

public:
    double m_mass; //单元的质量
    double m_x, m_y, m_r; //圆心x坐标, y坐标, 半径
    map<int, CONTACT> contactMap; //接触



public:
    CElement(int number, double coordX, double coordY);

    void union_lisan();
    void calContactForce(CElement* p2, CONTACT* cont1);
    void calCollisionForce(CElement* p2, CONTACT* cont1);

private:
    void addSumF(CElement *p2, CONTACT *cont1);
    void cal_vtt2();
    void cal_vt();
    void cal_dis();
    void cal_utt();
    void change_of_data();
    void calSumF();



};

#endif // CELEMENT_H
