### JNI

数据类型：

基本数据类型 jboolean 、jbyte、jchar、jint...

引用类型：jstring、jobject、jclass、jbooleanArray

---

#### 操作字符串

```cpp
extern "C"
JNIEXPORT void JNICALL
Java_com_example_testjni_TestNatvie_testJstring(JNIEnv *env, jobject instance,
                                                       jstring str_) {
    
  //（1）生成JNI String
    char const * str = "hello world!";
    jstring  jstring = env->NewStringUTF(str);

    // (2) jstring 转换成 const char * charstr
    const char *charstr = env->GetStringUTFChars(str_, 0);
    // (3) 释放 const char *
    env->ReleaseStringUTFChars(str_, charstr);

    //(4) 获取字符串子集
    char * subStr = new char;
    env->GetStringUTFRegion(str_,0,3,subStr);//截取字符串char*;


    env->ReleaseStringUTFChars(str_, subStr);
    
}

```

##### 操作数组

```cpp
extern "C"
JNIEXPORT void JNICALL
Java_com_example_testjni_TestNatvie_testIntArray(JNIEnv *env, jobject instance,
                                                     jintArray array_) {

    //----获取数组元素
    //(1)获取数组中元素
    jint * intArray = env->GetIntArrayElements(array_,NULL);

    int len = env->GetArrayLength(array_);//(2)获取数组长度

    LOGD("feifei len:%d",len);

    for(int i = 0; i < len;i++){
        jint item = intArray[i];
        LOGD("feifei item[%d]:%d",i,item);
    }

    env->ReleaseIntArrayElements(array_, intArray, 0);

    //----- 获取子数组
    jint *subArray = new jint;
    env->GetIntArrayRegion(array_,0,3,subArray);
    for(int i = 0;i<3;i++){
        subArray[i]= subArray[i]+5;
        LOGD("feifei subArray:[%d]:",subArray[i]);
    }

    //用子数组修改原数组元素
    env->SetIntArrayRegion(array_,0,3,subArray);

    env->ReleaseIntArrayElements(array_,subArray,0);//释放子数组元素


}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_feifei_TestNatvie_testObjectArray(JNIEnv *env, jobject instance,

                                                           jobjectArray strArr) {
    //获取数组长度
    int len = env->GetArrayLength(strArr);
    for(int i = 0;i< len;i++){
        //获取Object数组元素
        jstring item = (jstring)env->GetObjectArrayElement(strArr,i);

        const char * charStr = env->GetStringUTFChars(item, false);
        LOGD("feifei strArray item:%s",charStr);

        jstring jresult = env->NewStringUTF("HaHa");
        //设置Object数组元素
        env->SetObjectArrayElement(strArr,i,jresult);
        env->ReleaseStringUTFChars(item,charStr);
    }

}

```

##### 访问java类的方法和字段

都是通过反射进行访问的，具体需要方法和字段的签名

基本数据类型中特殊的Boolean -> Z   Long-> J

引用类型，Java 类 对应的签名为：Ljava类的类全名，如Ljava/lang/String;  注意是斜杠和分号是必须，不是点。

引用类型，数组，int[] -> [I       String -> [Ljava/lang/String;

方法类型，（参数类型）返回值 类型，int sum(int a ,intb) -> (II)I

```cpp
extern "C"
JNIEXPORT void JNICALL
Java_com_example_testjni_TestNatvie_testCallJavaMethod(JNIEnv *env, jobject instance) {


    //获取类名
    jclass  clazz = env->GetObjectClass(instance);
    if(clazz == NULL) return;

    jmethodID  javaMethod = env->GetMethodID(clazz,"helloworld","(Ljava/lang/String;)V");
    if(javaMethod == NULL)return;
    const char * msg = "once";
    jstring  jmsg = env->NewStringUTF(msg);
    env->CallVoidMethod(instance,javaMethod,jmsg);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_testjni_TestNatvie_testCallStaticJavaMethod(JNIEnv *env, jobject instance) {

    //获取java类型
    jclass clazz = env->GetObjectClass(instance);
    if(clazz == NULL) return;
    jmethodID staticMethod = env->GetStaticMethodID(clazz,"helloworldStatic","(Ljava/lang/String;)V");
    if(staticMethod == NULL) return;

    jstring jmsg = env->NewStringUTF("twice");
    env->CallStaticVoidMethod(clazz,staticMethod,jmsg);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_testjni_TestNatvie_getJavaObjectField(JNIEnv *env, jobject instance,
                                                              jobject student) {

    jclass  clazz = env->GetObjectClass(student);
    if(clazz == NULL )return;

    // 获取Object 实例属性
    jfieldID  nameId = env->GetFieldID(clazz,"name","Ljava/lang/String;");
    jstring jname = (jstring)env->GetObjectField(student,nameId);

    jfieldID  ageId = env->GetFieldID(clazz,"age","I");
    jint jage = env->GetIntField(student,ageId);

    const char * name = env->GetStringUTFChars(jname,false);
    env->ReleaseStringUTFChars(jname,name);


    //获取java 类属性:

    jfieldID  gradeId = env->GetStaticFieldID(clazz,"grade","I");
    jint  jgrade = env->GetStaticIntField(clazz,gradeId);

    jfieldID  nickeNameID = env->GetStaticFieldID(clazz,"nickname","Ljava/lang/String;");
    jstring  jnickname = (jstring)env->GetStaticObjectField(clazz,nickeNameID);

    const char * nickeName = env->GetStringUTFChars(jnickname, false);
    env->ReleaseStringUTFChars(jnickname,nickeName);

    //JNI 设置 java对象属性
    env->SetObjectField(student,nameId,env->NewStringUTF("xiaoming"));
    //JNI 设置 java 类属性
    env->SetStaticObjectField(clazz,nickeNameID,env->NewStringUTF("xiaohei"));
    jstring jnameNew = (jstring)env->GetObjectField(student,nameId);
    jstring jnickNameNew = (jstring)env->GetStaticObjectField(clazz,nickeNameID);

    const char * newName = env->GetStringUTFChars(jnameNew, false);
    const char *newNickName = env->GetStringUTFChars(jnickNameNew, false);

    env->ReleaseStringUTFChars(jnameNew,newName);
    env->ReleaseStringUTFChars(jnickNameNew,newName);
   

}

```

---

##### JNI对象的全局引用和局部引用

局部引用：随着方法返回会自动释放， 也可通过代码手动释放

```cpp
 env->DeleteLocalRef(clazz);
```

全局引用qu

JNI对象的全局引用分为两种，一种是强全局引用，这种引用会阻止Java的垃圾回收器回收JNI代码引用的Java对象，另一种是弱全局引用，这种全局引用则不会阻止垃圾回收器回收JNI代码引用的Java对象。

##### 1、强全局引用

- NewGlobalRef用来创建强全局引用的JNI对象
- DeleteGlobalRef用来删除强全局引用的JNI对象

##### 2、弱全局引用

- NewWeakGlobalRef用来创建弱全局引用的JNI对象
- DeleteWeakGlobalRef用来删除弱全局引用的JNI对象
- IsSameObject用来判断两个JNI对象是否相同



##### JNI 和 Java对象的互相持久化

Java对象持久化c/c++对象

通常的做法是 将C++对象指针 强转为jlong 类型，保存在调用者java对象的long型变量中，一直持有。
当需要使用该C++对象时,从Java对象中的long变量，强转化为C++对象,进而使用。

C/C++ 持久化Java对象

创建全局引用，不需要时进行删除即可。





##### 动态注册和静态注册

区别是效率。静态注册，每次使用native方法时，都要去寻找；而动态注册，由于有张表的存在，因此查找效率高。

静态注册

根据函数名来建立 java 方法与 JNI 函数的一一对应关系；在Java虚拟机加载so库时，如果发现含有JNIEXPORT和 JNICALL两个宏定义的函数时就会链接到对应Java层的native方法

Java_packagename_classname_methodname(JNIEnv *env,jclass/jobject,...)

动态注册

是在JNi层实现的，JAVA层不需要关心，因为在system.load时就会去调用JNI_OnLoad，有就注册，没有就不注册。动态注册的原理：JNI 允许我们提供一个函数映射表，注册给 JVM，这样 JVM 就可以用函数映射表来调用相应的函数， 而不必通过函数名来查找相关函数(这个查找效率很低，函数名超级长)流程更加清晰可控，效率更高.。

```java
		public native String stringFromJNI(); 
    public static native int add(int a, int b);
```

```cpp

#include <jni.h>
#include <string>
#include "log.hpp"
 
extern "C" {
 
jstring stringFromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
 
jint add(JNIEnv *env, jclass clazz, jint a, jint b) {
    return a + b;
}
 
jint RegisterNatives(JNIEnv *env) {
    jclass clazz = env->FindClass("com/example/testjni/MainActivity");
    if (clazz == NULL) {
        LOGE("con't find class: com/example/testjni/MainActivity");
        return JNI_ERR;
    }
    JNINativeMethod methods_MainActivity[] = {
            {"stringFromJNI", "()Ljava/lang/String;", (void *) stringFromJNI},
            {"add",           "(II)I",                (void *) add}
    };
    // int len = sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]);
    return env->RegisterNatives(clazz, methods_MainActivity,
                                sizeof(methods_MainActivity) / sizeof(methods_MainActivity[0]));
}
 
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    jint result = RegisterNatives(env);
    LOGD("RegisterNatives result: %d", result);
    return JNI_VERSION_1_6;
}
 

```



JNINativeMethod是一个结构体

```cpp
typedef struct {
    const char* name; // native 的方法名
    const char* signature; // 方法签名，例如 ()Ljava/lang/String;
    void*       fnPtr; // 函数指针
} JNINativeMethod;
```

