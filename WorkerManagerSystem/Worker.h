#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工基类

class Worker
{
    public:
        
        //显示信息
        virtual void show_info() = 0; //定义纯虚数,方便不同类别的职工显示信息

        //岗位职称
        virtual string getDepName() = 0;

        int m_id;  //编号
        string m_Name;  //姓名
        int m_DepName;  //职工所在部门名称编号

};