

#include <iostream>
#include "Worker.h"
#include <string>
using namespace std;

class Employee: public Worker
{
    public:

        //雇员的构造函数
        Employee(int id,string name,int depid)
        {
            this->m_id = id;
            this->m_Name = name;
            this->m_DepName = depid;
        }

        //显示信息
        virtual void show_info()
        {
            cout<<"职工编号:"<<this->m_id
                <<"\t职工姓名:"<<this->m_Name
                <<"\t岗位:"<<this->m_DepName
                <<"\t岗位职责:完成经理下发的任务"<<endl;

        }

        virtual string getDepName()
        {
            return string("员工");
        }

};

