/**
 * 数组、指针
 */
#include <stdio.h>

void printArrayElement(int* , int );
void pointArray(int[] ,int*[], int);
void pointArray2();
int main() {
    int monkeys[] = {199 ,1 , 43 , 3 , 4};
    /**
     * 数组是一个常量指针，即monkeys是一个指针类型，其默认存储的地址为数组的第一个元素的地址值。
     */
    printf("数组默认地址->%#x\n" ,(unsigned int )monkeys);

    int * ptr ;
    ptr = monkeys; // ptr为指向数组的指针，即数组的指针
    printf("指针地址->%#x\n" ,(unsigned int )ptr);
    for (int i = 0; i < 5; ++i) {
        printf("当前数组元素值->%d\n" ,*ptr);  //
        printf("当前数组元素内存地址->%#x\n" ,(unsigned int )ptr);  // 该地址连续内存空间
        printf("当前指针内存地址->%#x\n" ,(unsigned int )&ptr);  // 该地址一直不变
        printf("当前数组元素值by monkeys->%d\n" ,*(monkeys+i));  //
        ++ptr;
    }

    printArrayElement(monkeys , 5);

    // 测试指针数组，存放一串指针的数组
    int* ptr2[5];
    pointArray(monkeys , ptr2 , 5);

    //测试指针数组2
    pointArray2();
    return 0;
}

/**
 * 方法参数中传递指针
 * @param array
 * @param arraySize
 */
void  printArrayElement(int* array , int arraySize){
    for (int i = 0; i < arraySize; ++i) {
        printf("数组元素->%d\n" , *array);
        printf("数组元素地址->%#x\n" , (unsigned int)array);
        array++;
    }
}

/**
 * 指针数组
 * @param array
 * @param array2
 * @param arraySize
 */
void pointArray(int array[] , int* array2[] ,int arraySize){
    for (int i = 0; i < arraySize; ++i) {
        array2[i] = &(array[i]);
    }
    printf("指针数组默认存储地址->%#x\n" , array2);
    printf("指针数组的地址->%#x\n" , &array2);

    for (int i = 0; i < arraySize; ++i) {
        printf("指针数组元素的值->%d\n" , *array2[i]);
        printf("指针数组元素的地址->%#x\n" , (array2[i]));
    }
}

void pointArray2(){
    int a=1 , b=2 , c=3 , d=4;
    int *p[4]= {&a , &b , &c , &d};

    printf("指针数组2的默认首元素->%#x\n" , p[0]);
    printf("指针数组2的第一个元素地址->%#x\n" , &p[0]);
    printf("指针数组2的默认存储首地址->%#x\n" ,p);
    for (int i = 0; i < 4; ++i) {
        printf("指针数组2元素的值->%d\n" , *p[i]);
        printf("指针数组2元素的地址->%#x\n" , p[i]);
    }
}