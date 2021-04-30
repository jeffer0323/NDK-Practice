
/**
 * 结构体、共用体、位域
 */
#include <stdio.h>
#include <string.h>
// 结构体
struct Student{
    char* name;
    unsigned int age :8; // :3代表位域，在内存中的体现就是限制age变量的使用位数为3位
    unsigned int sex:1;  //:1代表位域 ， 在内存中的体现就是限制sex变量的使用位数为1为，即非0即1
}student={"xiaohong" , 18 ,0};


union ClassRoom{
    int tables;
    int lights;
    char class_name[30];
};

int main() {
    printf("默认值：name->%s\n" , student.name);
    printf("默认值：age->%d\n" , student.age);
    printf("默认值：sex->%s\n" , student.sex==1?"男":"女");

    struct Student xiaoming;
    xiaoming.name = "小明";
    xiaoming.age = 20;
    xiaoming.sex = 1;
    printf("name->%s\n" , xiaoming.name);
    printf("age->%d\n" , xiaoming.age);
    printf("sex->%s\n" , xiaoming.sex==1?"男":"女");

    // 结构体指针通过->访问结构体成员变量
    struct Student *ptr ;
    ptr = &xiaoming;
    printf("结构体指针访问name->%s\n" , ptr->name);
    printf("结构体指针访问age->%du\n" , ptr->age);
    printf("结构体指针访问sex->%s\n" , ptr->sex==1?"男":"女");


    //共用体  其成员共用用一块内存空间，最大存储空间取决与内部成员最大存储空间
    union ClassRoom room1;
    strcpy(room1.class_name , "一年级");
    printf("class_name->%s\n" , room1.class_name);
    room1.lights = 20;
    printf("lights->%d\n" , room1.lights);

    room1.tables = 40;
    printf("tables->%d\n" , room1.tables);
    printf("lights->%d\n" , room1.lights);  //打印40 丢失真实数据 因为共用体最后一次赋值为40，覆盖了前面的内容
    printf("class_name->%s\n" , room1.class_name); // 打印未知


    union ClassRoom *cp;
    cp = &room1;
    printf("共用体指针访问tables->%d\n" , cp->lights);  // 这里打印的是40 ， 因为tables是最后一次赋值，将当前的内存块存储的内容变成了40


    return 2;
}
