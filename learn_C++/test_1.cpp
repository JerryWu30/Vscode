#include <iostream>
using namespace std;

int &changevalue(int &a,int &b)
{
   if(a<b)
    return a;
    else
        return b;
    
}

int main()
{
    
    int a=34;int b=35;
    int &n=changevalue(a,b);
    cout<<n;
    cout<<changevalue(a,b);
    system("pause");
}