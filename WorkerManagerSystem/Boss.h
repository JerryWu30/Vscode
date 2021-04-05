

#include <iostream>
#include <string>
#include "Worker.h"

class Boss : public Worker

{
    public :

        Boss(int id,string name,int depid)
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
                <<"\t岗位职责:掌管公司所有事务"<<endl;
        }

        virtual string getDepName()
        {
            return string("老板");
        }


};



