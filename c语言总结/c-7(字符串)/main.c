/**
 * 字符串
 */

#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "nihaone";
    char str2[] = "c";
    char str3[14] ;
    char* we = "ewe";
    //复制，将str1复制到str3
    strcpy(str3 , str1);
    printf("str1->%s\n" , str1);
    printf("str3->%s\n" , str3); // 结果 nihao
    // 拼接
    strcat(str3 , str2);
    printf("str2->%s\n" , str2);
    printf("str3->%s\n" , str3);  // 结果：nihaoc
    // 查找字符h在str1中第一次出现的位置，最后一次出现的位置使用strrchr
    char* p = strchr(str1 , 'h');
    printf("str1的h第一次出现位置为->%s\n" , p);
    char* p1 = strrchr(str1 , 'n');
    printf("str1的n最后一次出现位置为->%s\n" , p1);

    // 字符串长度
    unsigned long len = strlen(str1);
    printf("str1的length->%lu\n" , len);

    // 查找字符串ao在str1中第一次出现的位置
    char* p2 = strstr(str1 , "ao");
    printf("str1的ao位置->%s\n" , p2);


    // 按自定字符串分割字符串
    char * p3 = strtok(str1 , "n");


    while (p3){
        printf("str1的split->%s\n" , p3);
        // 会在上一次调用strtok的基础上返回后续分割的字符串直到NULL
        p3 = strtok(NULL , "n");
    }
    printf("str1的split22->%s\n" , p3);

    // 返回str1第一个不在"n"中出现的字符角标
    size_t a = strspn(str1 , "n");
    printf("strspn->%lu\n" , a);   // 结果为1


    return 0;
}
