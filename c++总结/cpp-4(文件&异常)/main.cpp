#include <iostream>
#include <fstream>
using namespace std;
// 声明函数
void tryFunc();
int main() {
    char data[30];
    fstream fstream1 , fstream2;
    // 输出流， 用于写入文件
    fstream1.open("../test.txt" , ios::out);
    fstream1<<"learning";
    fstream1.close();

    // 输入流  用于读取文件
    fstream2.open("../test.txt" , ios::in);
    fstream2>>data;
    cout<<data<<endl;
    fstream2.close();

    try {
        tryFunc();
    }catch (...){
        cout<<"try catch exception exp"<<endl;
    }

    // c++17  auto  类型自动推导

    // 动态内存
    int* a = new int;
    *a = 10;
    cout<<*a<<endl;
    // 释放a指针
    delete a;  // 释放的是 new int开辟的空间
    a = nullptr;
    cout<<a<<endl; // a  0x0

    int* b = new int[4];  // 创建int数组 长度4
    delete [] b;  // 释放b指向的数组
    b = nullptr;
    return 0;

}


void tryFunc(){
    cout<<"try catch"<<endl;
    throw "exception o";

}