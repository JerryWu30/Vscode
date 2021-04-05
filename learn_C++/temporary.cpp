#include <iostream>
using namespace std;
int func(int &b)   //使用引用相当于使用可以修改值的值传递
                    // 相当于指针
{
    
    int a=5;
    b = 10;
    return a+b;
}


int main()
{
    int x=19;
    int n= func(x);
    cout<<n<<endl;
    cout<<x;
    system("pause");
    return 0;


}