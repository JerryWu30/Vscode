#include <iostream>
using namespace std;
#include <string>

class Animal
{
    public:
        Animal()
        {
            cout<<"animal�Ĺ��캯��"<<endl; 
        }
        
        virtual void shout() =0;
        virtual ~Animal()
        {
            cout<<"animal����������"<<endl;
        }

};

class Dog:public Animal
{
    public:
        Dog(string name)
        {
            cout<<"Don�Ĺ��캯��"<<endl;
            m_name= new string(name);
        }
    void shout()
    {
        cout<<"С����˵��"<<endl;

    }
    ~Dog()
    {
        cout<<"С���Ĺ��캯��"<<endl;
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