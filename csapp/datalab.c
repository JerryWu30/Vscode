#include <stdio.h>
#include <stdlib.h>

int main(){
    int x =3,y=4;
    printf("%d",(~(~x&~y)&~(x&y)));
    printf("%d",~3);
    system("pause");
    return 0;
}