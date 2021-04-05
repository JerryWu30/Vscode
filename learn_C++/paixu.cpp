#include <iostream>

using namespace std;

int main()
{
    int arr[10]={1,2,3,4,7,9,13,45,46,100}; //测试push
    int x;
    cin>>x;
    if(x>=arr[8])
        arr[9]=x;
    else
    {
        for(int i = 0;i<8;i++)
        {
            if(x<arr[i])
            {
                for(int j = 8;j>=i;j--)
                {
                    arr[j+1] = arr[j];
                }
                arr[i] = x;
                break;
                
            }

           
        }

    }

    for(int i = 0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }

        system("pause");
        return 0;
    
}
