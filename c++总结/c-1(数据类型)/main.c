/**
* Author:Jeffer
* Date:2021/4/27
* Desc: 基本数据类型
**/
#include <stdio.h>

int main() {
    unsigned char a1;
    signed char a2;
    unsigned short b1;
    signed short b2;
    //unsigned int ...
    int8_t a = 'e';
    int16_t b = 22;
    int32_t x = 100;
    unsigned int c = 222222;
    unsigned long d = 38993;
    float y = 100.33f;
    double z = 100.12;
    printf("long->%d" ,c);
    printf("float->%f" ,y);
    // 无符号长整型
    /**
     * size_t/ssize_t 屏蔽了平台cpu位数差异性，保证数据存储不会溢出
     */
    size_t f = 1111;
    // 有符号长整型
    ssize_t g = 2222;
    /**
     * sizeof 查看数据类型字节数
     * 占位符 整型 %d 浮点型%f ， 当要打印sizeof时，则加入前缀z，避免打印出错
     * lu u代表打印无符号数据类型
     */
    printf("a->%zd b->%zd c->%zd d->%zd x->%zd f->%zd g->%zd y->%lu z->%lu" ,  sizeof(a) ,  sizeof(b) ,  sizeof(c),sizeof(d),sizeof(x),sizeof(f),sizeof(g),sizeof(y),sizeof(z));
    return 0;
}

