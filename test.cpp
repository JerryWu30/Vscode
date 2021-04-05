#include <iostream>
#include <bitset>
using namespace std ;
int move1(int x){
    return x>>1;
}


int main(){
    cout<<bitset<32>(move1(2))<<endl;
    system("pause");
}