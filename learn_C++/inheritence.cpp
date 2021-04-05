#include <iostream>
using namespace std;

//虚函数的意义主要体现在指针上面

class Father
{
    public:
        virtual void show()
        {
            cout<<"Father的显示函数"<<endl;
        }
};

class Son: public Father
{
    public:
        void show()
        {
            cout<<"Son的显示函数"<<endl;
        }
};


class Son2: public Father
{
    public:
        void show()
        {
            cout<<"Son2的显示函数"<<endl;
        }
};

int main()
{
    Father *father=new Son;
    father->show();
    delete father;    
    system("pause");
    return 0;
}