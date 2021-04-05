#include <stdio.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;


//函数的作用是输出对应的十六进制数
void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i = 0;i<len;i++){
        printf(" %.3d " , start[i]); 
        //printf函数无法直接输出二进制位
        //start[i] 表示start地址上的第i个内容
        //char是字节类型，每一个char占有一个的字节空间，也就是8位的空间，
    }
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x,sizeof(int));
    //如此，就将x这个整型，占有4个字节，一个字节有8个二进制位，四个二进制位又可以转换成
    //一个十六进制位，这样，每个start[i]由八位组成，就可以写成两个十六进制。由于内存是从小
    //访问到大的，通过检查输出的十六进制就可以确定系统内存的存储方式是大端还是小端。
}


int main(){
    show_int(123456); //0000 0000 0000 0001 1110 0010 0100 0000
   system("pause");
    return 0;
}
