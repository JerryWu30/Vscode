#include <iostream>
#include<string>

using namespace std;
class Teacher
{
public:
    Teacher(string nam,int a,char s,string tit,string add,string t);
void display();
protected:
    string name;
    int age;
    char sex;
    string title;
    string address;
    string tel;
};
Teacher::Teacher(string nam,int a,char s,string tit,string add,string t): //构造函数
name(nam),age(a),sex(s),title(tit),address(add),tel(t){ }
void Teacher::display()  //类外构造成员函数
{   cout<<"name:"<<name<<endl;
    cout<<"age"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"title:"<<title<<endl;
    cout<<"address:"<<address<<endl;
    cout<<"tel:"<<tel<<endl;
}
class Cadre
{
public:
        Cadre(string nam,int a,char s,string p,string add,string t);
void display();
protected:
    string name;
    int age;
    char sex;
    string post;
    string address;
    string tel;
};
Cadre::Cadre(string nam,int a,char s,string p,string add,string t):
name(nam),age(a),sex(s),post(p),address(add),tel(t){}
void Cadre::display()
{   
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"post:"<<post<<endl;
    cout<<"address:"<<address<<endl;
    cout<<"tel:"<<tel<<endl;
}
class Teacher_Cadre:public Teacher,public Cadre //继承两个类
{
    public:
Teacher_Cadre(string nam,int a,char s,string tit,string p,string add,string t,float w);
void show( );
private:
float wages;
};
Teacher_Cadre::Teacher_Cadre(string nam,int a,char s,string t,string p,string add,string tel,float w):
Teacher(nam,a,s,t,add,tel),Cadre(nam,a,s,p,add,tel),wages(w) {}//继承之后只需要列出继承之后的变量
void Teacher_Cadre::show( ) //构造类的成员函数
{
    Teacher::display();//继承于Teacher类
    cout<<"post:"<<Cadre::post<<endl;
    cout<<"wages:"<<wages<<endl;
}
int main( )
{
    Teacher_Cadre  ca("Wangzhigang",30,'f',"teacher.","professional","SCAU","12345679",9999);
    ca.show( );
    system("pause");
    return 0;
}
