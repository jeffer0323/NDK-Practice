#include <stdio.h>

void getSum(int , int );
void getSum2(int , int (*p)(void));
int getSum3( );
int main() {
    // 函数指针
    void (*p)(int, int ) = &getSum;
    p(2 , 3);
    // 函数回调
    getSum2(2 , getSum3);
    return 0;
}

void getSum(int x, int y){
    int ret = x+y;
    printf("ret->%d\n" , ret);
}


/**
 *
 * @param a
 * @param p  指针函数
 */
void getSum2(int a , int (*p)(void)){
    // 调用指针函数
    a = a+p();
    printf("ret of a->%d\n" , a);
}

int getSum3(){
    int ret = 2;
    printf("ret->%d\n" , ret);
    return ret;
}
