#include <iostream>
using namespace std;
// 声明函数
/**
 * 引用作为函数参数
 * @param a
 * @param b
 */
void swap(int& a  , int& b);
int& getSum(int x  , int y);
// 定义全局变量
int sum=0;
int main() {
    int x = 10 , y = 20 , z;
    // 声明引用类型必须初始化，且只能初始化一次
    // 引用类型不能为空
    int& a =x;
    a = y;

    // 改变a的值
    a = 30;
    // 打印a和x的值
    cout<<"a的值为"<<a<<endl<<"x的值为"<<x<<endl; // 打印a->30 , x->30

    // 由此可见只能初始化一次，y的值是20，并不是30
    cout<<"x的值为"<<x<<endl<<"y的值为"<<y<<endl; // 打印x->30 , y->20

    // 形式参数会影响实际参数的值
    swap(x , y);
    cout<<"x的值为"<<x<<endl<<"y的值为"<<y<<endl; // 打印x->20 , y->30

    // 引用作为返回值 ， 在内存中不保存返回值的副本
    cout<<"未调用之前sum的值为"<<sum<<endl; //打印0
    int d = getSum(40 , 30)=100;
    cout<<"调用并赋值后sum的值为"<<d<<endl; // 打印100

    return 0;
}
// 定义函数
void swap(int& a , int& b){
    int temp = a;
    a = b;
    b = temp;
}

int& getSum(int x , int y){
    // 不能返回局部变量的引用，主要在于局部变量伴随着函数调用完毕会被系统自动销毁，而引用是不能为空的。
    sum = x+y;
    cout<<"调用后sum的值为"<<sum<<endl; // 打印70
    return sum;
}
