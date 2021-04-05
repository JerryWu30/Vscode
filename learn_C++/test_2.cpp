#include <iostream>

using namespace std;

int &square(const int &i)
{
    int s=i*i;
    int &squar=s;
    return squar;
}


int main()
{
    int &s=square(3);
    cout<<s;
    system("pause");
    return 0;
}