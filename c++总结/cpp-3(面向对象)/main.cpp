#include <iostream>
#include <string>
using namespace std;
class Driver{
private:
    unsigned int driveAge;
public:
    void drive(){
        cout<<"开车"<<endl;
    }
    //友元函数   可以访问私有成员
    friend void getDriveAge(Driver driver){
        cout<<"deliver"<<driver.driveAge<<endl;
    }
};

class People{

    string name;
    unsigned int age ;
    unsigned int sex :1;  // :1 代表位宽， 限制存储大小
public:

    string getName(){
        return this->name;
    }
    void setName(string name){
        this->name = name;
    }
    void setSex(unsigned int sex){
        this->sex = sex;
    }
    void setAge(unsigned int age){
        this->age = age;
    }
    int getAge(){
        return this->age;
    }
    string getSex(){
        return this->sex==0?"男":"女";
    }
    People(string name){
        this->name = name;
        cout<<"构造函数调用"<<endl;
    }
    ~People(){
        cout<<"析构函数调用"<<endl;
    }

    void toString(){
        cout<<"People->"<<"name->"<<getName()<<endl<<"age->"<<getAge()<<endl<<"sex->"<<getSex()<<endl;
    }

    // 纯虚函数， 即代表People类是一个抽象类  sleep方法是一个抽象函数
    virtual void sleep() = 0;


};
// 学生继承人
class Student :public People , public Driver{
public:
    void learn(){
        cout<<"student is learning"<<endl;
    }
    Student(string name, unsigned int age) : People(name) {
        this->setAge(age);
    }
    void sleep() override{
        cout<<"sleep"<<endl;
    }

    // 函数重写
    void drive(){
        cout<<"student driving the car."<<endl;
    }
    // 重载
    void drive(string name){
        cout<<name <<" driving the car."<<endl;
    }


};

int main() {

    Student student("mahua", 12);
    cout<<"构造函数调用完毕"<<endl;
    student.learn();
    student.sleep();
    student.drive();
    student.drive(student.getName());
    return 0;
}
