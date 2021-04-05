#pragma once
#include <iostream>
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager 
{
    public:
        WorkerManager();//�������캯��

        ~WorkerManager();//������������

        void Show_Menu();//��ʾ�˵�

        void Exit_System();//�Ƴ�ϵͳ

        int m_EmpNum;//ְ��������

        Worker ** m_EmpArray; //����ָ��,ָ��ָ���ָ��

        void Add_Emp();//��ӳ�Ա

        void save();//�����ļ�

        bool m_FileIsEmpty; // �ж��ļ��Ƿ�Ϊ��

        int get_EmpNum();//��ȡְ��������

        void init_Emp();

        void show_Emp();

        void Del_Emp();

        int IsExist(int id);

        void Mod_Emp();
        
        
};


WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //�ļ�������
    if(!ifs.is_open())
    {
        cout<<"�ļ�������"<<endl;
        this->m_EmpNum=0;//��ʼ��ְ�������� 
        this->m_FileIsEmpty = true;
        this->m_EmpArray=NULL;//��ʼ������ָ��
        ifs.close();
        return;
    }

    //�ļ����ڵ�Ϊ��
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        //cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpNum=0;//��ʼ��ְ�������� 
        this->m_FileIsEmpty = true;
        this->m_EmpArray=NULL;//��ʼ������ָ��
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    //cout<<num;// ���Դ���
    this->m_EmpNum = num;
    
    this->m_EmpArray = new Worker *[this->m_EmpNum];

    init_Emp();

    // for (int i = 0; i < m_EmpNum; i++)
    // {
    //     cout<<"ְ����: "<<this->m_EmpArray[i]->m_id
    //         <<"ְ������: "<<this->m_EmpArray[i]->m_Name
    //         <<"����: "<<this->m_EmpArray[i]->m_DepName;     
    // }


}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray!=NULL)
    {
        delete[] this->m_EmpArray;//�ͷŶ���������
    }
}

void WorkerManager::Add_Emp()
{
    cout<<"������ְ��������: "<<endl;
    int addNum = 0;
    cin>>addNum;

    if(addNum > 0)
    {
        int NewSize = this->m_EmpNum + addNum;  //������Ӻ��ְ������

        Worker **newSpace = new Worker*[NewSize];  //�����µĿռ䴢�����е�ְ����Ϣ

    


        for(int i = 0;i < addNum; i++)
        {
            int id;
            string name;
            int deptSelect;

            cout<<"�������"<<i+1<<"��ְ���ı��: "<<endl;
            cin>>id;

            cout<<"�������"<<i+1<<"��ְ��������: "<<endl;
            cin>>name;

            cout<<"ѡ������ְ���ĸ�λ: "<<endl;
            cout<<"1.��ְͨ��"<<endl;
            cout<<"2.����"<<endl;
            cout<<"3.�ϰ�"<<endl;
            cin>>deptSelect;

            Worker *worker =NULL;
            switch (deptSelect)
            {
            case 1://Ա��
                worker = new Employee(id,name,1);
                break;
            case 2://����
                worker = new Manager(id,name,2);
                break;
            case 3://�ϰ�
                worker = new Boss(id,name,3);
                break;
            default:
                break;
            }

            newSpace[this->m_EmpNum+i]= worker;
        }


        delete[] this->m_EmpArray;//�ͷſռ�

        this->m_EmpArray = newSpace;//����ָ��

        this->m_EmpNum = NewSize;//����ְ����Ŀ

        this->m_FileIsEmpty = false;

        cout<<"ְ����ӳɹ�"<<endl;

        this->save();

    }

    else
    {
        cout<<"������������"<<endl;
    }

    system("pause");
    system("cls");

}

void WorkerManager::Show_Menu()
{
            cout<<"*******************************"<<endl;
            cout<<"*******Jerryְ������ϵͳ*******"<<endl;
            cout<<"*********0.�˳�����ϵͳ********"<<endl;
            cout<<"*********1.����ְ����Ϣ********"<<endl;
            cout<<"*********2.��ʾְ����Ϣ********"<<endl;
            cout<<"*********3.ɾ����ְԱ��********"<<endl;
            cout<<"*********4.�޸�ְ����Ϣ********"<<endl;
            cout<<"*********5.����ְ����Ϣ********"<<endl;
            cout<<"*********6.���ձ�Ų�ѯ********"<<endl;
            cout<<"*********7.��������ĵ�********"<<endl;
            cout<<"*******************************"<<endl;
            cout<<endl;
}

void WorkerManager::Exit_System()
{
    cout<<"��ӭ�´�ʹ��Jerryְ������ϵͳ"<<endl;
    system("pause");
    exit(0);
}
    
void WorkerManager::save()  
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for(int i = 0 ; i < this->m_EmpNum ; i++)
    {
        ofs <<this->m_EmpArray[i]->m_id<<" "
            <<this->m_EmpArray[i]->m_Name<<" "
            <<this->m_EmpArray[i]->m_DepName<<endl;
    }

    ofs.close();
}

int WorkerManager::get_EmpNum()    


{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    
    int id;
    string name;
    int did;

    int num = 0;

    while(ifs>>id&&ifs>>name&&ifs>>did)
    {
        //��¼����
        num++;
    }
    ifs.close();

    return num;

}

void WorkerManager::init_Emp()

{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int did;

    int index = 0;
    while(ifs>>id&&ifs>>name&&ifs>>did)
    {
        Worker * worker = NULL;

        if(did == 1)//һ��Ա��
        {
            worker = new Employee(id,name,did);
        }

        else if(did == 2)//����Ա��
        {
            worker = new Manager(id,name,did);
        }

        else if(did == 3)//һ��Ա��
        {
            worker = new Boss(id,name,did);
        }

        //�����������

        this->m_EmpArray[index] = worker;
        index++;
    }

   
}

void WorkerManager::show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ��в�����"<<endl;
    }
    else
    {
        for(int i= 0;i<m_EmpNum;i++)
        {
            this->m_EmpArray[i]->show_info();
        }
    }

    system("pause");
    system("cls");
}

void WorkerManager::Del_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"��������Ҫ��ְ����"<<endl;
        int id= 0;
        cin>>id;

        int index = this->IsExist(id);
        if(index != -1)
        {
            //ɾ��Ա��,��ʱ����Ա����ְ�����ɺ�һ��Ա��ְ���Ŵ���
            for(int i = index;i <this->m_EmpNum - 1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }

            this->m_EmpNum--;   //Ա������,��Ҫ����Ա������������
            
            this->save();//ͬ������
            cout<<"ɾ���ɹ�"<<endl;

        }
        else
        {
            cout<<"ɾ��ʧ��,δ�ҵ���ְ��"<<endl;
        }
    }

    system("pause");
    system("cls");
        
    }

int WorkerManager::IsExist(int id)
{
    int index = -1;

    for(int i=0;i<this->m_EmpNum;i++)
    {
        if(this->m_EmpArray[i]->m_id == id)
            {
                index = i;
                break;
            }

        return index;
    }
}

void WorkerManager::Mod_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
    }
    else
    {
        cout<<"�������޸�Ա����ְ�����"<<endl;
        int id = 0;
        cin>>id;

        int ret = this->IsExist(id);
        
        if(ret !=-1)
        {
            delete this->m_EmpArray[ret];
            
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//�������� ��������
			this->m_EmpArray[ret]= worker;
			
			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}
        
