#include <iostream>
#include <typeinfo>

using namespace std;

void print(char *name[],int n)
{
    int i=0;
    char *p;
    p=name[0];
    while (i<n)
    {
        p=*(name+i++);
        cout<<p<<endl;
    }
    
}

int main()
{
    const char *letter[] = {"abc","aaa","adah"};  //指针占的是四个字节
    // int n = sizeof(letter)/sizeof(char*);
    // cout<<sizeof(letter)<<endl;  //输出的是12,三个变量的数据类型是指针,3*4=12
    // print(letter,n);
    char *name1[] = {"a","b"};
    cout<<sizeof(name1)<<endl;
    cout<<typeid(name1).name()<<endl;
    cout<<*name1;
    system("pause");
    return 0;
}