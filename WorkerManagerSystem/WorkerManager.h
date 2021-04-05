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
        WorkerManager();//创建构造函数

        ~WorkerManager();//创建析构函数

        void Show_Menu();//显示菜单

        void Exit_System();//推出系统

        int m_EmpNum;//职工的数量

        Worker ** m_EmpArray; //二级指针,指向指针的指针

        void Add_Emp();//添加成员

        void save();//保存文件

        bool m_FileIsEmpty; // 判断文件是否为空

        int get_EmpNum();//获取职工的人数

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

    //文件不存在
    if(!ifs.is_open())
    {
        cout<<"文件不存在"<<endl;
        this->m_EmpNum=0;//初始化职工的人数 
        this->m_FileIsEmpty = true;
        this->m_EmpArray=NULL;//初始化数组指针
        ifs.close();
        return;
    }

    //文件存在但为空
    char ch;
    ifs>>ch;
    if(ifs.eof())
    {
        //cout<<"文件为空"<<endl;
        this->m_EmpNum=0;//初始化职工的人数 
        this->m_FileIsEmpty = true;
        this->m_EmpArray=NULL;//初始化数组指针
        ifs.close();
        return;
    }

    int num = this->get_EmpNum();
    //cout<<num;// 测试代码
    this->m_EmpNum = num;
    
    this->m_EmpArray = new Worker *[this->m_EmpNum];

    init_Emp();

    // for (int i = 0; i < m_EmpNum; i++)
    // {
    //     cout<<"职工号: "<<this->m_EmpArray[i]->m_id
    //         <<"职工姓名: "<<this->m_EmpArray[i]->m_Name
    //         <<"部门: "<<this->m_EmpArray[i]->m_DepName;     
    // }


}

WorkerManager::~WorkerManager()
{
    if(this->m_EmpArray!=NULL)
    {
        delete[] this->m_EmpArray;//释放堆区的数据
    }
}

void WorkerManager::Add_Emp()
{
    cout<<"请输入职工的数量: "<<endl;
    int addNum = 0;
    cin>>addNum;

    if(addNum > 0)
    {
        int NewSize = this->m_EmpNum + addNum;  //计算添加后的职工数量

        Worker **newSpace = new Worker*[NewSize];  //开辟新的空间储存所有的职工信息

    


        for(int i = 0;i < addNum; i++)
        {
            int id;
            string name;
            int deptSelect;

            cout<<"请输入第"<<i+1<<"个职工的编号: "<<endl;
            cin>>id;

            cout<<"请输入第"<<i+1<<"个职工的姓名: "<<endl;
            cin>>name;

            cout<<"选择这名职工的岗位: "<<endl;
            cout<<"1.普通职工"<<endl;
            cout<<"2.经理"<<endl;
            cout<<"3.老板"<<endl;
            cin>>deptSelect;

            Worker *worker =NULL;
            switch (deptSelect)
            {
            case 1://员工
                worker = new Employee(id,name,1);
                break;
            case 2://经理
                worker = new Manager(id,name,2);
                break;
            case 3://老板
                worker = new Boss(id,name,3);
                break;
            default:
                break;
            }

            newSpace[this->m_EmpNum+i]= worker;
        }


        delete[] this->m_EmpArray;//释放空间

        this->m_EmpArray = newSpace;//更换指向

        this->m_EmpNum = NewSize;//更新职工数目

        this->m_FileIsEmpty = false;

        cout<<"职工添加成功"<<endl;

        this->save();

    }

    else
    {
        cout<<"您的输入有误"<<endl;
    }

    system("pause");
    system("cls");

}

void WorkerManager::Show_Menu()
{
            cout<<"*******************************"<<endl;
            cout<<"*******Jerry职工管理系统*******"<<endl;
            cout<<"*********0.退出管理系统********"<<endl;
            cout<<"*********1.增加职工信息********"<<endl;
            cout<<"*********2.显示职工信息********"<<endl;
            cout<<"*********3.删除离职员工********"<<endl;
            cout<<"*********4.修改职工信息********"<<endl;
            cout<<"*********5.查找职工信息********"<<endl;
            cout<<"*********6.按照编号查询********"<<endl;
            cout<<"*********7.清空所有文档********"<<endl;
            cout<<"*******************************"<<endl;
            cout<<endl;
}

void WorkerManager::Exit_System()
{
    cout<<"欢迎下次使用Jerry职工管理系统"<<endl;
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
        //记录人数
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

        if(did == 1)//一号员工
        {
            worker = new Employee(id,name,did);
        }

        else if(did == 2)//二号员工
        {
            worker = new Manager(id,name,did);
        }

        else if(did == 3)//一号员工
        {
            worker = new Boss(id,name,did);
        }

        //存放在数组中

        this->m_EmpArray[index] = worker;
        index++;
    }

   
}

void WorkerManager::show_Emp()
{
    if(this->m_FileIsEmpty)
    {
        cout<<"文件夹不存在"<<endl;
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
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入想要的职工号"<<endl;
        int id= 0;
        cin>>id;

        int index = this->IsExist(id);
        if(index != -1)
        {
            //删除员工,此时空余员工的职工号由后一名员工职工号代替
            for(int i = index;i <this->m_EmpNum - 1;i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }

            this->m_EmpNum--;   //员工减少,需要将总员工的数量减少
            
            this->save();//同步数据
            cout<<"删除成功"<<endl;

        }
        else
        {
            cout<<"删除失败,未找到此职工"<<endl;
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
        cout<<"文件不存在或记录为空"<<endl;
    }
    else
    {
        cout<<"请输入修改员工的职工编号"<<endl;
        int id = 0;
        cin>>id;

        int ret = this->IsExist(id);
        
        if(ret !=-1)
        {
            delete this->m_EmpArray[ret];
            
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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

			//更改数据 到数组中
			this->m_EmpArray[ret]= worker;
			
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}
        
