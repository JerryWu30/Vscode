

#include <iostream>
#include "Worker.h"
#include <string>
using namespace std;

class Employee: public Worker
{
    public:

        //��Ա�Ĺ��캯��
        Employee(int id,string name,int depid)
        {
            this->m_id = id;
            this->m_Name = name;
            this->m_DepName = depid;
        }

        //��ʾ��Ϣ
        virtual void show_info()
        {
            cout<<"ְ�����:"<<this->m_id
                <<"\tְ������:"<<this->m_Name
                <<"\t��λ:"<<this->m_DepName
                <<"\t��λְ��:��ɾ����·�������"<<endl;

        }

        virtual string getDepName()
        {
            return string("Ա��");
        }

};

