#include <iostream>
using namespace std;
#include <string>

class Animal
{
    public:
        Animal()
        {
            cout<<"animal的构造函数"<<endl; 
        }
        
        virtual void shout() =0;
        virtual ~Animal()
        {
            cout<<"animal的析构函数"<<endl;
        }

};

class Dog:public Animal
{
    public:
        Dog(string name)
        {
            cout<<"Don的构造函数"<<endl;
            m_name= new string(name);
        }
    void shout()
    {
        cout<<"小狗在说话"<<endl;

    }
    ~Dog()
    {
        cout<<"小狗的构造函数"<<endl;
        if(this->m_name!=NULL)
        {
            delete m_name;
            m_name =NULL;
        }

    }

    public:
        string *m_name;
};


void test()
{
    Animal *animal = new Dog("Jerry");
    animal->shout();
    delete animal;
}

int main()
{
    test();
    system("pause");
    return 0;
}