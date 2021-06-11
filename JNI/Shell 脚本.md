### Shell 脚本

##### 简述：

后缀.sh或不带后缀

弱类型语言，变量可以随意定义：

```shell
#!/bin/bash
# 第一行用于声明是一个shell脚本文件
T = 10  #声明变量T，并定义

echo $T # 打印变量T的值

```

---

执行shell脚本的三种方式

./demo.sh  这种必须要有执行权限，chmod +x
sh demo.sh
/bin/bash demo.sh

##### 一般语法：

1.条件语句：

 if(()) 代表算术运算，  if [  ] 代表执行指令

```shell
#!/bin/bash

AGE1=18
AGE2=20
# 判断两个年龄大小
if(($AGE1>$AGE2));then

        echo "if statement"
else
        echo "else statement"

fi # 结尾标志， 表示if结束

VAR1 = "nihao"
# 判断字符串是否为空
if [ $VAR1 ]
then
        echo "字符串不为空，值是 $VAR1 "
else
        echo "字符串为空"
fi
```



2.循环语句：

```shell
#!/bin/bash

#   `seq 1 20` seq是系统自带函数，取出1-20的自然数
for i in `seq 1 20`
do
        echo "循环遍历的数字是：$i"
done


```

3.函数：

```shell
#!/bin/bash


function func1() {
        echo "function1"
}
func1

# 函数中使用局部的变量
function func2() {
        NAME="xiaoming"
        echo $NAME
}
func2

# 函数携带参数
function func3(){
        echo "func3的第一个参数是:`expr $1`"
        echo $1
}
func3 20

```

##### 更多语法细节

可参见网上教程