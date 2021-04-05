#include <iostream>

using namespace std;


class A
{
    public:
        void fun()
        {
            cout<<"1";
        }
};

class B:public A

{
    public:
        void fun()
        {
            cout<<"2";
        }
};



int main()
{
    B a;
    a.fun();
    system("pause");
    return 0;
}