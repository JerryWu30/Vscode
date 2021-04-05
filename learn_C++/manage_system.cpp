#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct Person_info
{
    string m_name;
    int m_sex;
    string m_number;
};

struct System
{
    struct Person_info person[MAX];
    int m_size;
};

void show_menu()
{
    cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


void show_info(struct System *s)
{
    if(s->m_size==0)
    {
        cout<<"通讯录无联系人"<<endl;
    }   
    else
    {
        for(int i=0;i<s->m_size;i++)
        {
            cout<<"姓名："<<s->person[i].m_name<<"  "<<"性别："<<(s->person[i].m_sex==1?"男":"女")
            <<"  "<<"电话号码："
                <<s->person[i].m_number<<endl;
        }
    }
    system("pause");
    system("cls");
    
}

int isExist(struct System *s,string name)
{
    for(int i= 0; i<s->m_size ; i++)
        {
            if(s->person[i].m_name==name)
                {
                    return i;//非常巧妙
                }
        }
    return -1;

}

void add_info(struct System *s)
{
    if(s->m_size==MAX)
    {
        cout<<"通讯录已满，无法继续添加"<<endl;
    }
    else
    {
        string name;
        int sex;
        string number;
        cout<<"请输入姓名: ";
        cin>>name;
        s->person[s->m_size].m_name=name;
        // cout<<endl<<"请输入性别('1'代表男性，'2'代表女性): ";
        // cin>>sex;
        // s->person[s->m_size].m_sex=sex;
        while(true)
        {
            cout<<endl<<"请输入性别('1'代表男性，'2'代表女性):";
            cin>>sex;
            if(sex==1||sex==2)
            {
                s->person[s->m_size].m_sex=sex;
                break;
            }
            else
            {
                cout<<"输入有误，请重新输入";
            }
        }
        cout<<endl<<"请输入电话号码：";
        cin>>number;
        s->person[s->m_size].m_number=number;
        s->m_size++;
        cout<<"添加成功";
        system("pause");
        system("cls");
    }
    
}


void find_info(struct System *s)
{
    cout<<"请输入你想查找的对象"<<endl;
    string name;
    cin>>name;
    int res = isExist(s,name);
    if(res !=-1)
    {
        cout<<"姓名："<<s->person[res].m_name<<endl;
        cout<<"性别："<<(s->person[res].m_sex==1?"男":"女")<<endl;
        cout<<"电话号码："<<s->person[res].m_number<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
    

}

void modify_info(struct System *s)
{
    cout<<"请输入你想修改的对象"<<endl;
    string name;
    cin>>name;
    int res = isExist(s,name);
    if(res!=-1)
    {
        string name;
        int sex;
        string number;
        cout<<"请输入修改后的姓名：";
        cin>>name;
        s->person[res].m_name=name;
        while(true)
        {
            cout<<endl<<"请输入性别('1'代表男性，'2'代表女性):";
            cin>>sex;
            if(sex==1||sex==2)
            {
                s->person[res].m_sex=sex;
                break;
            }
            else
            {
                cout<<"输入有误，请重新输入";
            }
        }
        
        cout<<endl<<"请输入电话号码：";
        cin>>number;
        s->person[res].m_number=number;
        
    }
    else
    {
        cout<<"查无此人，请按任意键返回";
    }
    
     system("pause");
        system("cls"); 
}



int main()
{
    struct System sys;
    sys.m_size=0;
    int input=0;
    
    
    while(true)
    {
        show_menu();
        cin>>input;
        switch (input)
        {
        case 1:
            add_info(&sys);
            break;
        case 2:
            show_info(&sys);
            break;
        case 3:
              break;
        case 4:
            find_info(&sys); 
            break;
        case 5:
            modify_info(&sys);
            break;
        case 6:
            break;
        case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
 
        
        default:
            break;
        }
    }
    system("pause");
	return 0;



}
