/**
* Author:Jeffer
* Date:2021/4/27
* Desc:  extern、static 关键字
**/
//
#include <stdio.h>
#include "extern_case.h"
size_t getSum(size_t z , size_t y);
static size_t a1 = 10;
void testStatic();
int main(){
    /**
     * 此处 extern 用于声明变量，注意不是定义变量。 作用是为变量提权，扩大其作用域
     */
    extern size_t x , y;
    size_t result = getSum(x , y);
    printf("ret->%lu\n" , result);



    /**
     * 从外部使用extern
     */
    size_t x1 = 20 , y1 = 30;
    size_t ret2 = getSum2(x1, y1);
    printf("ret2->%lu\n" , ret2);


    /**
     * static关键字使用
     */
    for (int i = 0; i < 10; ++i) {
        testStatic();
    }
    return 0;
}


size_t  x = 10 , y= 20;
size_t getSum(size_t x , size_t y){
    return x+y;
}


void testStatic(){
    static size_t aa = 10;
    printf("static-var->%lu\n" , ++aa);

    /**
     * 打印结果
     *  static-var->11
        static-var->12
        static-var->13
        static-var->14
        static-var->15
        static-var->16
        static-var->17
        static-var->18
        static-var->19
        static-var->20
     *
     * 循环调用testStatic方法可见aa变量是在变化的，不是10；
     * 说明 static关键字可以保持变量在当前作用域中的值，而不是销毁重建
     */
}

