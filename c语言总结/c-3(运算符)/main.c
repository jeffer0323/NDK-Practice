/**
 * 运算符
 * 指针，取地址符
 */
#include <stdio.h>

int main() {
    size_t a = 10;
    size_t* a1 = &a;
    printf("a地址为->%#x\n" , (unsigned int )&a);
    printf("a1指针存放的地址为->%#x\n" , (unsigned int )a1);
    printf("a1指针的地址为->%#x\n" , (unsigned int )&a1);
    printf("a1指针的值->%lu\n" , *a1);
    return 0;
}
