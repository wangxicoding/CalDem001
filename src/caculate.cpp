#include "caculate.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "celement.h"
#include "contact.h"
#include <fstream>
#include <QDebug>

using namespace std;

const int maxn = 10;

extern double slqh(double x, double y);

vector<CElement> unit;

Caculate::Caculate(QWidget *parent) : QWidget(parent)
{

}

Caculate::~Caculate()
{

}
void Caculate::unitInit()
{
    double r = 0.2;
    /** 初始化单元 **/
    for (int i = 0; i < maxn; i++)
    {
        CElement cElement(i, 10.0, r + 2*r*i);

        unit.push_back(cElement);

    }
    vector<CElement>::iterator it;
    for(it=unit.begin(); it!=unit.end(); ++it)
    {
        qDebug()<<"编号： "<<it->m_number<<" 质量： "<<it->m_mass<<" 圆心x： "<<it->m_x<<" 圆心y： "<<it->m_y<<"  vtt2  "<<it->vtt2[0]<<endl;
        qDebug()<<"关联列表： "<<endl;
    }

    /** 初始化接触对象 **/
    for (int i = 0; i < maxn -1; i++)
    {
        CONTACT contact(&unit[i + 1]);
        CONTACT contact1(&unit[i]);

        /** 接触,成对的出现  ╭(●｀∀´●)╯╰(●'◡'●)╮ 好基友,一辈子 **/
        contact.p_partner = &contact1;
        contact1.p_partner = &contact;

        unit[i].contactMap.insert(pair<int, CONTACT>(i + 1, contact));
        unit[i + 1].contactMap.insert(pair<int, CONTACT>(i, contact1));

        //cout<< unit[i+1].m_mass <<endl;
        //cout<< unit[i].m_moment <<endl;
        //cout<< unit[i].m_disn <<endl;
        //cout<<"单元 "<<i<<"的x坐标： "<< unit[i].m_x <<endl;
        //cout<<"单元 "<<i<<"的y坐标： "<< unit[i].m_y <<endl;

    }

}

void Caculate::calculate()
{
    for (int i = 0; i < maxn; i++)
    {
        CElement &iUnit = unit[i];
        for (int j = i + 1; j < maxn; j++)
        {

            CElement &jUnit = unit[j];
            map<int, CONTACT>::iterator itMap;

            itMap = iUnit.contactMap.find(j);
            if(iUnit.contactMap.end()==itMap)
            {
                //cout<<"无法找到键为"<<j<<"的数据对"<<endl;
            }
            else
            {
                //cout<<"找到键为"<<j<<"的数据对"<<endl;
                //cout<<"iUnit.m_x= "<<iUnit.m_x<<endl;
                //cout<<"iUnit.m_y= "<<iUnit.m_y<<endl;
                //cout<<"jUnit.m_x= "<<jUnit.m_x<<endl;
                //cout<<"jUnit.m_y= "<<jUnit.m_y<<endl;
                double D;
                D = slqh(iUnit.m_x - jUnit.m_x, iUnit.m_y - jUnit.m_y);
                //cout<<"D: "<<D<<endl;

                if (D > iUnit.m_r + jUnit.m_r) //如果大于
                {
                    if (itMap == iUnit.contactMap.end()) //没弹簧、没有碰撞
                    {
                        continue; //跳过
                    }
                    else // 有弹簧或者碰撞
                    {
                        CONTACT &contact = itMap->second;
                        if (contact.isSpring == false) //不是弹簧,是碰撞,删除contact
                        {
                            iUnit.contactMap.erase(itMap);
                            jUnit.contactMap.erase(i);

                            continue; //跳过
                        }
                        else //是弹簧,拉力
                        {
                            //计算弹簧力
                            iUnit.calContactForce(&jUnit, &contact);

                            cout<<iUnit.m_Fxsum<<endl;
                        }
                    } //end else
                } //end if
                else //如果小于, 那一定会有力
                {
                    if (itMap == iUnit.contactMap.end()) //没弹簧、没碰撞, 那么添加碰撞
                    {
                        CONTACT contact(&unit[j], false); //添加碰撞
                        CONTACT contact1(&unit[i], false); //添加碰撞

                        /** 接触,成对的出现  ╭(●｀∀´●)╯╰(●'◡'●)╮ 好基友,一辈子 **/
                        contact.p_partner = &contact1;
                        contact1.p_partner = &contact;

                        iUnit.contactMap.insert(pair<int, CONTACT>(j, contact));
                        jUnit.contactMap.insert(pair<int, CONTACT>(i, contact1));

                        //计算碰撞力
                        iUnit.calCollisionForce(&jUnit, &contact);

                        /*map<int, CONTACT>::iterator it;
                        for(it=iUnit.contactMap.begin(); it!=iUnit.contactMap.end(); ++it)
                        {
                            cout<<"  "<<it->second.m_fn<<endl;
                        }*/

                    }
                    else //有弹簧或者碰撞
                    {
                        CONTACT &contact = itMap->second;
                        if (contact.isSpring == false) //不是弹簧,是碰撞
                        {
                            //计算碰撞力
                            iUnit.calCollisionForce(&jUnit, &contact);
                        }
                        else //是弹簧
                        {
                            //计算弹簧力
                            iUnit.calContactForce(&jUnit, &contact);
                        }
                    } //end else
                } //end else
            }

        } //end for j

        // 计算完与所有单元接触的力
        /** 十二步以后的事儿 **/
        iUnit.union_lisan();


    } //end for i

}
void Caculate::maintemp()
{
    double maxStep = 100000; /**总步长,每一步长相当于每一时间间隔
                         *如果deltaTime = 1e-6,步长为 1e6
                         *那总时间为1s.
                         */

    CElement::staticInit();
    unitInit();
    cout<<"第0次迭代"<<endl;
    vector<CElement>::iterator it;
        for(it=unit.begin(); it!=unit.end(); ++it)
        {
            cout<<"单元 0的x坐标： "<< it->m_x <<endl;
            cout<<"单元 0的y坐标： "<< it->m_y <<endl;
        }
    for (int i = 0; i < maxStep; i++) //计算相应步长的单元离散过程
    {
        calculate();
        //output();

        cout<<"第"<<(i+1)<<"次迭代结果： "<<endl;
        vector<CElement>::iterator it;
        for(it=unit.begin(); it!=unit.end(); ++it)
        {
            if(i%10==0)
            {
                if(it->m_number==9)
                {
                    qDebug()<<"单元 "<<i<<"的x坐标： "<< it->m_x <<endl;
                    cout<<"单元 "<<i<<"的y坐标： "<< it->m_y <<endl;
                    ofstream SaveFile("output.txt", ios::app);
                    SaveFile<<it->m_number<<" "<<i*deltaTime<<" "<<it->m_x<<" "<<it->m_y<<endl;
                    SaveFile.close();
                }

            }
        }


    }
    //cout << "Hello world!" << endl;
    //return 0;
}

