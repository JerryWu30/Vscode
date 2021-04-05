#include <iostream>

using namespace std;


class Base
{
    public:
        virtual void display()
        {
            cout<<"base"<<endl;
        }
};

class FirstD : public Base
{
    void display()
    {
        cout<<"first"<<endl;
    }
};

class SecondD : public Base
{
    void display()
    {
        cout<<"second"<<endl;
    }
};

int main()
{
    Base *ptr = new FirstD;
    // Base b1;
    // FirstD f1;
    // SecondD s1;
    
    ptr->display();
    delete ptr;
    system("pause");
    return 0 ;
}

