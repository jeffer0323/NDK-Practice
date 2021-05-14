#include <iostream>
using namespace std;
// 声明函数
/**
 * 函数默认值
 * @param x
 * @param y
 * @return
 */
int getSum(int x, int y=20 );
// 内联函数
inline int getTotalCount(int x, int y){
    return x+y;
}

int main() {
    int x=10,y=30;
    int ret1 = getSum(10);
    int ret2 = getSum(x , y);
    cout<<ret1<<endl<<ret2<<endl;

    /**
     * // 完整语法
        [ capture-list ] ( params ) mutable(optional) constexpr(optional)(c++17) exception attribute -> ret { body }

        [ capture-list ]  外部传递的参数
        ( params ) 匿名函数的参数列表
        mutable  外部传递的参数是否可变（可选项）
        constexpr  常量表达式（c++17）(可选项)
        exception  可能会抛出的异常
        attribute  属性
        ret  返回值类型
        {body} 函数体

       // 可选的简化语法
        [ capture-list ] ( params ) -> ret { body }
        [ capture-list ] ( params ) { body }
        [ capture-list ] { body }


     */
     int a=10 , b = 50;
    auto sumFunc = [a, b](int x , int y)->int{return a+b+x+y;};
    auto ret3 = sumFunc(22 , 33);
    cout<<"ret3的值为"<<ret3<<endl;

    // 外部参数进行修改
    auto sumFunc2 = [a, b](int x , int y) mutable ->int{a=30;return a+b+x+y;};
    auto ret4 = sumFunc2(22 , 33);

    cout<<"ret4的值为"<<ret4<<endl<<a<<endl;

    // 泛型lambda表达式,采用类型自动推导，采用类型自动推导
    auto sumFunc3 = [](auto x, auto y) -> auto {return x+y;};
    int ret5 = sumFunc3(10 , 20);
    float ret6 = sumFunc3(10.2f , 10.6f);
    cout<<"ret5的值为"<<ret5<<endl<<"ret6的值为"<<ret6<<endl;

    //  内联函数调用
    auto ret7 = getTotalCount(10,20);
    cout<<ret7<<endl;
    return 0;
}


// 定义函数
int getSum(int x, int y){
    return x+y;
}


