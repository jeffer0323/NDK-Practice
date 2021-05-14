#include <iostream>
#include <thread>
#include <pthread.h>
using namespace std;
void func(int i){
    cout<<i<<endl;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        thread t(func , i);
        //  detach 位于后台执行，异步执行  join是阻塞执行，同步执行
        //t.detach();
        t.join();
        cout<<"mainthread"<<i<<endl;
    }
    return 0;
}
