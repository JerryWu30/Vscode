

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
            cout<<"ְ�����:"<<this->m_id
                <<"\tְ������:"<<this->m_Name
                <<"\t��λ:"<<this->m_DepName
                <<"\t��λְ��:�ƹܹ�˾��������"<<endl;
        }

        virtual string getDepName()
        {
            return string("�ϰ�");
        }


};



