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
        cout<<"��ӭʹ��Jerryְ������ϵͳ,����������ѡ����"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 0:
                wm.Exit_System();//�˳�ϵͳ
                break;
            case 1:
                wm.Add_Emp(); //���Ա��
                break;
            case 2:
                wm.show_Emp(); // ��ʾְ����Ϣ
                break;
            case 3:
                wm.Del_Emp();   //ɾ��Ա��
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