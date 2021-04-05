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
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


void show_info(struct System *s)
{
    if(s->m_size==0)
    {
        cout<<"ͨѶ¼����ϵ��"<<endl;
    }   
    else
    {
        for(int i=0;i<s->m_size;i++)
        {
            cout<<"������"<<s->person[i].m_name<<"  "<<"�Ա�"<<(s->person[i].m_sex==1?"��":"Ů")
            <<"  "<<"�绰���룺"
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
                    return i;//�ǳ�����
                }
        }
    return -1;

}

void add_info(struct System *s)
{
    if(s->m_size==MAX)
    {
        cout<<"ͨѶ¼�������޷��������"<<endl;
    }
    else
    {
        string name;
        int sex;
        string number;
        cout<<"����������: ";
        cin>>name;
        s->person[s->m_size].m_name=name;
        // cout<<endl<<"�������Ա�('1'�������ԣ�'2'����Ů��): ";
        // cin>>sex;
        // s->person[s->m_size].m_sex=sex;
        while(true)
        {
            cout<<endl<<"�������Ա�('1'�������ԣ�'2'����Ů��):";
            cin>>sex;
            if(sex==1||sex==2)
            {
                s->person[s->m_size].m_sex=sex;
                break;
            }
            else
            {
                cout<<"������������������";
            }
        }
        cout<<endl<<"������绰���룺";
        cin>>number;
        s->person[s->m_size].m_number=number;
        s->m_size++;
        cout<<"��ӳɹ�";
        system("pause");
        system("cls");
    }
    
}


void find_info(struct System *s)
{
    cout<<"������������ҵĶ���"<<endl;
    string name;
    cin>>name;
    int res = isExist(s,name);
    if(res !=-1)
    {
        cout<<"������"<<s->person[res].m_name<<endl;
        cout<<"�Ա�"<<(s->person[res].m_sex==1?"��":"Ů")<<endl;
        cout<<"�绰���룺"<<s->person[res].m_number<<endl;
    }
    else
    {
        cout<<"���޴���"<<endl;
    }
    system("pause");
    system("cls");
    

}

void modify_info(struct System *s)
{
    cout<<"�����������޸ĵĶ���"<<endl;
    string name;
    cin>>name;
    int res = isExist(s,name);
    if(res!=-1)
    {
        string name;
        int sex;
        string number;
        cout<<"�������޸ĺ��������";
        cin>>name;
        s->person[res].m_name=name;
        while(true)
        {
            cout<<endl<<"�������Ա�('1'�������ԣ�'2'����Ů��):";
            cin>>sex;
            if(sex==1||sex==2)
            {
                s->person[res].m_sex=sex;
                break;
            }
            else
            {
                cout<<"������������������";
            }
        }
        
        cout<<endl<<"������绰���룺";
        cin>>number;
        s->person[res].m_number=number;
        
    }
    else
    {
        cout<<"���޴��ˣ��밴���������";
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
        case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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
