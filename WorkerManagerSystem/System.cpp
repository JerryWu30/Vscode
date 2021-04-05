#include <iostream>
using namespace std;
#include "WorkerManager.h"

int main()
{
    WorkerManager wm;
    int choice=0;
    while(true)
    {
        wm.Show_Menu();
        cout<<"欢迎使用Jerry职工管理系统,请输入数字选择功能"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0:
                wm.Exit_System();//退出系统
                break;
            case 1:
                wm.Add_Emp(); //添加员工
                break;
            case 2:
                wm.show_Emp(); // 显示职工信息
                break;
            case 3:
                wm.Del_Emp();   //删除员工
                break;
            case 4:
                wm.Mod_Emp();
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
    }
    
}