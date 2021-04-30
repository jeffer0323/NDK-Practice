#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//#define PI 3.14  // 宏定义

#ifndef PI   // 如果没有定义PI 则为真，执行下面代码
    #define PI 3.14159
#endif   // 结束if，与if / if*成对出现
//#undef PI  // 取消宏定义

// 参数化宏定义
#define MAX(x , y) ((x)>(y)?(x):(y))

// #标识粘贴符号，x是什么则粘贴什么，比如字符串则直接粘贴带""号的字符串，如"222"
#define PRINTLN(x) \
            printf(#x"\n")
// ## 连接粘贴符号 ， outer连接x的值
#define PRINTLN2(x) \
            printf("outer"#x"=%d\n" , outer##x)

#if defined(MAX)
    #define DEBUG 1
#endif

int sum(int e, ...);
int main() {
    // 输入输出
    /*unsigned int num;
    printf("请输入一个正整数:\n");
    scanf("%d" , &num);
    printf("输入的内容为%d\n" ,num);*/

    // typedef  只能用于数据类型，不可用于字面量
    typedef int A;
    A a = 10;
    printf("a占用的字节大小%zd\n" , sizeof(a));

    // 预编译器 define ifdef ifndef endif if elif
    // 根本目的就是实现文本替换
    printf("PI代表%f\n" , PI);




    // 系统预置的一些宏定义
    printf("当前日期%s\n" , __DATE__);
    printf("当前时间%s\n" , __TIME__);
    printf("当前时间戳%s\n" , __TIMESTAMP__);
    printf("当前Long最大值%lu\n" , __LONG_MAX__);

    printf("%d和%d的最大值为%d" , 10 , 20 , MAX(10 , 20));

    PRINTLN(222);

    int outer32 = 100;
    PRINTLN2(32);

    PRINTLN(DEBUG);
    printf("DEBUG值为：%d\n" , DEBUG);
    // 可变参数
    int ret = sum(5 , 1 ,2 , 3 , 4 , 5);
    printf("可变参数和为%d\n" , ret);



    // 动态分配内存
    // calloc(int sum ,int size) 分配一块长度为sum大小为size的内存空间，其大小为 sum*size字节
    // malloc(int sum) 在堆区分配一块大小为sum的内存空间
    // realloc(void* address, int sum)  重新分配特定地址的内存， 用于扩容或减小内存容量
    // free(void*)  / 释放内存
    // 需要导入stdlib头文件

    char* content=NULL;
    // 动态分配 30字节的内存空间
    size_t a2 = sizeof(char);
    content = (char*) calloc(30 , sizeof(char));
    if (!content){
        fprintf(stderr , "alloc memory failed");
    }else{
        strcpy(content , "What a sunny day today!");
    }
    printf("content is : %s\n" , content);

    // 扩容到50字节
    content = (char*)realloc(content ,50* sizeof(char ));
    if (!content){
        // 扩容失败
        fprintf(stderr , "alloc memory failed");
    }else{
        strcat(content , "Its comfortable！");
    }
    strcat(content , "Its comfortable！");

    printf("content is after realloc : %s\n" , content);

    // 释放内存
    free(content);
    return 0;
}


/**
 * 可变参数
 * @param size  代表可变参数的个数
 * @param ...  代表可变参数值
 * @return
 */
int sum(int size , ...){
    va_list vaList;
    int sum =0;
    // 初始化一个参数列表
    va_start(vaList , size);
    for (int i = 0; i < size; ++i) {
        // va_arg遍历没一个值
        sum += va_arg(vaList , int );
    }
    va_end(vaList);
    return sum;
}
