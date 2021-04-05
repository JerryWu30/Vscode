#include <iostream>
#include "Worker.h"
#include <string>
using namespace std;

class Manager : public Worker
{
        
    public:    
        Manager(int id,string name,int depid)
        {
            this->m_id = id;
            this->m_Name = name;
            this->m_DepName = depid;
        }

        virtual void show_info()
        {
            cout<<"职工编号:"<<this->m_id
                <<"\t职工姓名:"<<this->m_Name
                <<"\t岗位:"<<this->m_DepName
                <<"\t岗位职责:完成老板下发的 任务,并且下发给员工"<<endl;
        }

        virtual string getDepName()
        {
            return string("经理");
        }
};