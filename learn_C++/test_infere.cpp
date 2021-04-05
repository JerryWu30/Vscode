#include <iostream>
using namespace std;


int &get(int *arr,int num)
{
    return arr[num];
}


int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    get(arr,2) = 66;
    cout<<arr[2]<<endl;
    system("pause");
    return 0 ;
    
}